#pragma once

#include "Compat.h"
#include "ArduSim.h"

// message command bytes (128-255/0x80-0xFF)
#define DIGITAL_MESSAGE         0x90 // send data for a digital port (collection of 8 pins)
#define ANALOG_MESSAGE          0xE0 // send data for an analog pin (or PWM)
#define REPORT_ANALOG           0xC0 // enable analog input by pin #
#define REPORT_DIGITAL          0xD0 // enable digital input by port pair
//
#define SET_PIN_MODE            0xF4 // set a pin to INPUT/OUTPUT/PWM/etc
#define SET_DIGITAL_PIN_VALUE   0xF5 // set value of an individual digital pin
//
#define REPORT_VERSION          0xF9 // report protocol version
#define SYSTEM_RESET            0xFF // reset from MIDI
//
#define START_SYSEX             0xF0 // start a MIDI Sysex message
#define END_SYSEX               0xF7 // end a MIDI Sysex message
#define FIRMATA_FIRMWARE_MAJOR_VERSION 1
#define FIRMATA_FIRMWARE_MINOR_VERSION 1
#define MAX_DATA_BYTES 64

typedef void(sysExCallback)(byte command, byte argc, byte *argv);
typedef void(*callbackFunction)(byte, int);

class CFirmata
{
private:
	sysExCallback *currentSysexCallback = nullptr;
	boolean parsingSysex;
	int sysexBytesRead;
	byte storedInputData[MAX_DATA_BYTES]; // multi-byte data
	byte waitForData; // this flag says the next serial input will be data
	byte executeMultiByteCommand; // execute this after getting multi-byte data
	callbackFunction currentAnalogCallback;
	callbackFunction currentDigitalCallback;
	callbackFunction currentReportAnalogCallback;
	callbackFunction currentReportDigitalCallback;
	callbackFunction currentPinModeCallback;
	callbackFunction currentPinValueCallback;
	byte multiByteChannel; // channel data for multiByteCommands

	void processSysexMessage()
	{
		switch (storedInputData[0]) { //first byte in buffer is command
		default:
			if (currentSysexCallback)
				(*currentSysexCallback)(storedInputData[0], sysexBytesRead - 1, storedInputData + 1);
		}
	}
public:
	bool available()
	{
		return true;
	}

	void processInput()
	{
		int inputData = read(); // this is 'int' to handle -1 when no data
		int command;

		// TODO make sure it handles -1 properly

		if (parsingSysex) {
			if (inputData == END_SYSEX) {
				//stop sysex byte
				parsingSysex = false;
				//fire off handler function
				processSysexMessage();
			}
			else {
				//normal data byte - add to buffer
				storedInputData[sysexBytesRead] = inputData;
				sysexBytesRead++;
			}
		}
		else if ((waitForData > 0) && (inputData < 128)) {
			waitForData--;
			storedInputData[waitForData] = inputData;
			if ((waitForData == 0) && executeMultiByteCommand) { // got the whole message
				switch (executeMultiByteCommand) {
				case ANALOG_MESSAGE:
					if (currentAnalogCallback) {
						(*currentAnalogCallback)(multiByteChannel,
							(storedInputData[0] << 7)
							+ storedInputData[1]);
					}
					break;
				case DIGITAL_MESSAGE:
					if (currentDigitalCallback) {
						(*currentDigitalCallback)(multiByteChannel,
							(storedInputData[0] << 7)
							+ storedInputData[1]);
					}
					break;
				case SET_PIN_MODE:
					if (currentPinModeCallback)
						(*currentPinModeCallback)(storedInputData[1], storedInputData[0]);
					break;
				case SET_DIGITAL_PIN_VALUE:
					if (currentPinValueCallback)
						(*currentPinValueCallback)(storedInputData[1], storedInputData[0]);
					break;
				case REPORT_ANALOG:
					if (currentReportAnalogCallback)
						(*currentReportAnalogCallback)(multiByteChannel, storedInputData[0]);
					break;
				case REPORT_DIGITAL:
					if (currentReportDigitalCallback)
						(*currentReportDigitalCallback)(multiByteChannel, storedInputData[0]);
					break;
				}
				executeMultiByteCommand = 0;
			}
		}
		else {
			// remove channel info from command byte if less than 0xF0
			if (inputData < 0xF0) {
				command = inputData & 0xF0;
				multiByteChannel = inputData & 0x0F;
			}
			else {
				command = inputData;
				// commands in the 0xF* range don't use channel data
			}
			switch (command) {
			case START_SYSEX:
				parsingSysex = true;
				sysexBytesRead = 0;
				break;
			}
		}
	}
	void setFirmwareVersion(int major, int minor)
	{

	}

	void attach(byte command, sysExCallback callback)
	{
		switch (command)
		{
		case START_SYSEX:
			currentSysexCallback = *callback;
			break;
		}
	}

	void begin(int baud)
	{

	}

	void write(byte data)
	{

	}
};

CFirmata Firmata;