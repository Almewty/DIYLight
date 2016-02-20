//#pragma once
//#include <cstdint>
//#include <cstring>
//
//#define __attribute__(...) 
//#define fract8 float
//#define fract16 double
//#define boolean bool
//#define memset8 memset
//#define EDitherMode uint8_t
//#define DISABLE_DITHER 0x00
//#define BINARY_DITHER 0x01
//#define FORCE_REFERENCE(var) 
//#define K255 255
//#define K171 171
//#define K85  85
//#define LIB8STATIC 
//
//#define QSUB8_C 1
//#define QADD8_C 1
//#define QMUL8_C 1
//#define MUL8_C 1
//#define SCALE8_C 1
//#define SCALE8_C 1
//#define SCALE16_C 1
//
//struct CHSV;
//struct CRGB;
//inline void hsv2rgb_rainbow(const CHSV& hsv, CRGB& rgb);
//LIB8STATIC uint8_t qadd8(uint8_t i, uint8_t j);
//LIB8STATIC uint8_t qsub8(uint8_t i, uint8_t j);
//LIB8STATIC uint8_t qmul8(uint8_t i, uint8_t j);
//LIB8STATIC void nscale8x3_video(uint8_t& r, uint8_t& g, uint8_t& b, fract8 scale);
//LIB8STATIC inline uint8_t scale8(uint8_t i, fract8 scale);
//LIB8STATIC void nscale8x3(uint8_t& r, uint8_t& g, uint8_t& b, fract8 scale);
//LIB8STATIC inline uint8_t scale8_LEAVING_R1_DIRTY(uint8_t i, fract8 scale);
//LIB8STATIC void cleanup_R1();
//LIB8STATIC inline uint8_t lerp8by8(uint8_t a, uint8_t b, fract8 frac);
//LIB8STATIC uint16_t lerp16by16(uint16_t a, uint16_t b, fract16 frac);
//LIB8STATIC uint16_t scale16(uint16_t i, fract16 scale);
//LIB8STATIC uint8_t scale8_video_LEAVING_R1_DIRTY(uint8_t i, fract8 scale);
//
///// RGB orderings, used when instantiating controllers to determine what
///// order the controller should send RGB data out in, RGB being the default
///// ordering.
//enum EOrder {
//	RGB = 0012,
//	RBG = 0021,
//	GRB = 0102,
//	GBR = 0120,
//	BRG = 0201,
//	BGR = 0210
//};
//
///// definitions for the spi chipset constants
//enum ESPIChipsets {
//	LPD8806,
//	WS2801,
//	WS2803,
//	SM16716,
//	P9813,
//	APA102,
//	DOTSTAR
//};
//
///// Pre-defined hue values for HSV objects
//typedef enum {
//	HUE_RED = 0,
//	HUE_ORANGE = 32,
//	HUE_YELLOW = 64,
//	HUE_GREEN = 96,
//	HUE_AQUA = 128,
//	HUE_BLUE = 160,
//	HUE_PURPLE = 192,
//	HUE_PINK = 224
//} HSVHue;
//
//typedef enum {
//	// Color correction starting points
//
//	/// typical values for SMD5050 LEDs
//	///@{
//	TypicalSMD5050 = 0xFFB0F0 /* 255, 176, 240 */,
//	TypicalLEDStrip = 0xFFB0F0 /* 255, 176, 240 */,
//	///@}
//
//	/// typical values for 8mm "pixels on a string"
//	/// also for many through-hole 'T' package LEDs
//	///@{
//	Typical8mmPixel = 0xFFE08C /* 255, 224, 140 */,
//	TypicalPixelString = 0xFFE08C /* 255, 224, 140 */,
//	///@}
//
//	/// uncorrected color
//	UncorrectedColor = 0xFFFFFF
//
//} LEDColorCorrection;
//
//typedef enum {
//	/// @name Black-body radiation light sources
//	/// Black-body radiation light sources emit a (relatively) continuous
//	/// spectrum, and can be described as having a Kelvin 'temperature'
//	///@{
//	/// 1900 Kelvin
//	Candle = 0xFF9329 /* 1900 K, 255, 147, 41 */,
//	/// 2600 Kelvin
//	Tungsten40W = 0xFFC58F /* 2600 K, 255, 197, 143 */,
//	/// 2850 Kelvin
//	Tungsten100W = 0xFFD6AA /* 2850 K, 255, 214, 170 */,
//	/// 3200 Kelvin
//	Halogen = 0xFFF1E0 /* 3200 K, 255, 241, 224 */,
//	/// 5200 Kelvin
//	CarbonArc = 0xFFFAF4 /* 5200 K, 255, 250, 244 */,
//	/// 5400 Kelvin
//	HighNoonSun = 0xFFFFFB /* 5400 K, 255, 255, 251 */,
//	/// 6000 Kelvin
//	DirectSunlight = 0xFFFFFF /* 6000 K, 255, 255, 255 */,
//	/// 7000 Kelvin
//	OvercastSky = 0xC9E2FF /* 7000 K, 201, 226, 255 */,
//	/// 20000 Kelvin
//	ClearBlueSky = 0x409CFF /* 20000 K, 64, 156, 255 */,
//	///@}
//
//	/// @name Gaseous light sources
//	/// Gaseous light sources emit discrete spectral bands, and while we can
//	/// approximate their aggregate hue with RGB values, they don't actually
//	/// have a proper Kelvin temperature.
//	///@{
//	WarmFluorescent = 0xFFF4E5 /* 0 K, 255, 244, 229 */,
//	StandardFluorescent = 0xF4FFFA /* 0 K, 244, 255, 250 */,
//	CoolWhiteFluorescent = 0xD4EBFF /* 0 K, 212, 235, 255 */,
//	FullSpectrumFluorescent = 0xFFF4F2 /* 0 K, 255, 244, 242 */,
//	GrowLightFluorescent = 0xFFEFF7 /* 0 K, 255, 239, 247 */,
//	BlackLightFluorescent = 0xA700FF /* 0 K, 167, 0, 255 */,
//	MercuryVapor = 0xD8F7FF /* 0 K, 216, 247, 255 */,
//	SodiumVapor = 0xFFD1B2 /* 0 K, 255, 209, 178 */,
//	MetalHalide = 0xF2FCFF /* 0 K, 242, 252, 255 */,
//	HighPressureSodium = 0xFFB74C /* 0 K, 255, 183, 76 */,
//	///@}
//
//	/// Uncorrected temperature 0xFFFFFF
//	UncorrectedTemperature = 0xFFFFFF
//} ColorTemperature;
//
///// Representation of an HSV pixel (hue, saturation, value (aka brightness)).
//struct CHSV {
//	union {
//		struct {
//			union {
//				uint8_t hue;
//				uint8_t h;
//			};
//			union {
//				uint8_t saturation;
//				uint8_t sat;
//				uint8_t s;
//			};
//			union {
//				uint8_t value;
//				uint8_t val;
//				uint8_t v;
//			};
//		};
//		uint8_t raw[3];
//	};
//
//	// default values are UNITIALIZED
//	inline CHSV() __attribute__((always_inline))
//	{
//	}
//
//	// allow construction from H, S, V
//	inline CHSV(uint8_t ih, uint8_t is, uint8_t iv) __attribute__((always_inline))
//		: h(ih), s(is), v(iv)
//	{
//	}
//
//	// allow copy construction
//	inline CHSV(const CHSV& rhs) __attribute__((always_inline))
//	{
//		h = rhs.h;
//		s = rhs.s;
//		v = rhs.v;
//	}
//
//	inline CHSV& operator= (const CHSV& rhs) __attribute__((always_inline))
//	{
//		h = rhs.h;
//		s = rhs.s;
//		v = rhs.v;
//		return *this;
//	}
//
//	inline CHSV& setHSV(uint8_t ih, uint8_t is, uint8_t iv) __attribute__((always_inline))
//	{
//		h = ih;
//		s = is;
//		v = iv;
//		return *this;
//	}
//};
//
///// Representation of an RGB pixel (Red, Green, Blue)
//struct CRGB {
//	union {
//		struct {
//			union {
//				uint8_t r;
//				uint8_t red;
//			};
//			union {
//				uint8_t g;
//				uint8_t green;
//			};
//			union {
//				uint8_t b;
//				uint8_t blue;
//			};
//		};
//		uint8_t raw[3];
//	};
//
//	inline uint8_t& operator[] (uint8_t x) __attribute__((always_inline))
//	{
//		return raw[x];
//	}
//
//	inline const uint8_t& operator[] (uint8_t x) const __attribute__((always_inline))
//	{
//		return raw[x];
//	}
//
//	// default values are UNINITIALIZED
//	inline CRGB() __attribute__((always_inline))
//	{
//	}
//
//	// allow construction from R, G, B
//	inline CRGB(uint8_t ir, uint8_t ig, uint8_t ib)  __attribute__((always_inline))
//		: r(ir), g(ig), b(ib)
//	{
//	}
//
//	// allow construction from 32-bit (really 24-bit) bit 0xRRGGBB color code
//	inline CRGB(uint32_t colorcode)  __attribute__((always_inline))
//		: r((colorcode >> 16) & 0xFF), g((colorcode >> 8) & 0xFF), b((colorcode >> 0) & 0xFF)
//	{
//	}
//
//	inline CRGB(LEDColorCorrection colorcode) __attribute__((always_inline))
//		: r((colorcode >> 16) & 0xFF), g((colorcode >> 8) & 0xFF), b((colorcode >> 0) & 0xFF)
//	{
//
//	}
//
//	inline CRGB(ColorTemperature colorcode) __attribute__((always_inline))
//		: r((colorcode >> 16) & 0xFF), g((colorcode >> 8) & 0xFF), b((colorcode >> 0) & 0xFF)
//	{
//
//	}
//
//	// allow copy construction
//	inline CRGB(const CRGB& rhs) __attribute__((always_inline))
//	{
//		r = rhs.r;
//		g = rhs.g;
//		b = rhs.b;
//	}
//
//	// allow construction from HSV color
//	inline CRGB(const CHSV& rhs) __attribute__((always_inline))
//	{
//		hsv2rgb_rainbow(rhs, *this);
//	}
//
//	// allow assignment from one RGB struct to another
//	inline CRGB& operator= (const CRGB& rhs) __attribute__((always_inline))
//	{
//		r = rhs.r;
//		g = rhs.g;
//		b = rhs.b;
//		return *this;
//	}
//
//	// allow assignment from 32-bit (really 24-bit) 0xRRGGBB color code
//	inline CRGB& operator= (const uint32_t colorcode) __attribute__((always_inline))
//	{
//		r = (colorcode >> 16) & 0xFF;
//		g = (colorcode >> 8) & 0xFF;
//		b = (colorcode >> 0) & 0xFF;
//		return *this;
//	}
//
//	// allow assignment from R, G, and B
//	inline CRGB& setRGB(uint8_t nr, uint8_t ng, uint8_t nb) __attribute__((always_inline))
//	{
//		r = nr;
//		g = ng;
//		b = nb;
//		return *this;
//	}
//
//	// allow assignment from H, S, and V
//	inline CRGB& setHSV(uint8_t hue, uint8_t sat, uint8_t val) __attribute__((always_inline))
//	{
//		hsv2rgb_rainbow(CHSV(hue, sat, val), *this);
//		return *this;
//	}
//
//	// allow assignment from just a Hue, saturation and value automatically at max.
//	inline CRGB& setHue(uint8_t hue) __attribute__((always_inline))
//	{
//		hsv2rgb_rainbow(CHSV(hue, 255, 255), *this);
//		return *this;
//	}
//
//	// allow assignment from HSV color
//	inline CRGB& operator= (const CHSV& rhs) __attribute__((always_inline))
//	{
//		hsv2rgb_rainbow(rhs, *this);
//		return *this;
//	}
//
//	// allow assignment from 32-bit (really 24-bit) 0xRRGGBB color code
//	inline CRGB& setColorCode(uint32_t colorcode) __attribute__((always_inline))
//	{
//		r = (colorcode >> 16) & 0xFF;
//		g = (colorcode >> 8) & 0xFF;
//		b = (colorcode >> 0) & 0xFF;
//		return *this;
//	}
//
//
//	// add one RGB to another, saturating at 0xFF for each channel
//	inline CRGB& operator+= (const CRGB& rhs)
//	{
//		r = qadd8(r, rhs.r);
//		g = qadd8(g, rhs.g);
//		b = qadd8(b, rhs.b);
//		return *this;
//	}
//
//	// add a contstant to each channel, saturating at 0xFF
//	// this is NOT an operator+= overload because the compiler
//	// can't usefully decide when it's being passed a 32-bit
//	// constant (e.g. CRGB::Red) and an 8-bit one (CRGB::Blue)
//	inline CRGB& addToRGB(uint8_t d)
//	{
//		r = qadd8(r, d);
//		g = qadd8(g, d);
//		b = qadd8(b, d);
//		return *this;
//	}
//
//	// subtract one RGB from another, saturating at 0x00 for each channel
//	inline CRGB& operator-= (const CRGB& rhs)
//	{
//		r = qsub8(r, rhs.r);
//		g = qsub8(g, rhs.g);
//		b = qsub8(b, rhs.b);
//		return *this;
//	}
//
//	// subtract a constant from each channel, saturating at 0x00
//	// this is NOT an operator+= overload because the compiler
//	// can't usefully decide when it's being passed a 32-bit
//	// constant (e.g. CRGB::Red) and an 8-bit one (CRGB::Blue)
//	inline CRGB& subtractFromRGB(uint8_t d)
//	{
//		r = qsub8(r, d);
//		g = qsub8(g, d);
//		b = qsub8(b, d);
//		return *this;
//	}
//
//	// subtract a constant of '1' from each channel, saturating at 0x00
//	inline CRGB& operator-- ()  __attribute__((always_inline))
//	{
//		subtractFromRGB(1);
//		return *this;
//	}
//
//	// subtract a constant of '1' from each channel, saturating at 0x00
//	inline CRGB operator-- (int DUMMY_ARG)  __attribute__((always_inline))
//	{
//		CRGB retval(*this);
//		--(*this);
//		return retval;
//	}
//
//	// add a constant of '1' from each channel, saturating at 0xFF
//	inline CRGB& operator++ ()  __attribute__((always_inline))
//	{
//		addToRGB(1);
//		return *this;
//	}
//
//	// add a constant of '1' from each channel, saturating at 0xFF
//	inline CRGB operator++ (int DUMMY_ARG)  __attribute__((always_inline))
//	{
//		CRGB retval(*this);
//		++(*this);
//		return retval;
//	}
//
//	// divide each of the channels by a constant
//	inline CRGB& operator/= (uint8_t d)
//	{
//		r /= d;
//		g /= d;
//		b /= d;
//		return *this;
//	}
//
//	// right shift each of the channels by a constant
//	inline CRGB& operator>>= (uint8_t d)
//	{
//		r >>= d;
//		g >>= d;
//		b >>= d;
//		return *this;
//	}
//
//	// multiply each of the channels by a constant,
//	// saturating each channel at 0xFF
//	inline CRGB& operator*= (uint8_t d)
//	{
//		r = qmul8(r, d);
//		g = qmul8(g, d);
//		b = qmul8(b, d);
//		return *this;
//	}
//
//	// scale down a RGB to N 256ths of it's current brightness, using
//	// 'video' dimming rules, which means that unless the scale factor is ZERO
//	// each channel is guaranteed NOT to dim down to zero.  If it's already
//	// nonzero, it'll stay nonzero, even if that means the hue shifts a little
//	// at low brightness levels.
//	inline CRGB& nscale8_video(uint8_t scaledown)
//	{
//		nscale8x3_video(r, g, b, scaledown);
//		return *this;
//	}
//
//	// %= is a synonym for nscale8_video.  Think of it is scaling down
//	// by "a percentage"
//	inline CRGB& operator%= (uint8_t scaledown)
//	{
//		nscale8x3_video(r, g, b, scaledown);
//		return *this;
//	}
//
//	// fadeLightBy is a synonym for nscale8_video( ..., 255-fadefactor)
//	inline CRGB& fadeLightBy(uint8_t fadefactor)
//	{
//		nscale8x3_video(r, g, b, 255 - fadefactor);
//		return *this;
//	}
//
//	// scale down a RGB to N 256ths of it's current brightness, using
//	// 'plain math' dimming rules, which means that if the low light levels
//	// may dim all the way to 100% black.
//	inline CRGB& nscale8(uint8_t scaledown)
//	{
//		nscale8x3(r, g, b, scaledown);
//		return *this;
//	}
//
//	// scale down a RGB to N 256ths of it's current brightness, using
//	// 'plain math' dimming rules, which means that if the low light levels
//	// may dim all the way to 100% black.
//	inline CRGB& nscale8(const CRGB & scaledown)
//	{
//		r = ::scale8(r, scaledown.r);
//		g = ::scale8(g, scaledown.g);
//		b = ::scale8(b, scaledown.b);
//		return *this;
//	}
//
//	inline CRGB scale8(const CRGB & scaledown)
//	{
//		CRGB out;
//		out.r = ::scale8(r, scaledown.r);
//		out.g = ::scale8(g, scaledown.g);
//		out.b = ::scale8(b, scaledown.b);
//		return out;
//	}
//
//	// fadeToBlackBy is a synonym for nscale8( ..., 255-fadefactor)
//	inline CRGB& fadeToBlackBy(uint8_t fadefactor)
//	{
//		nscale8x3(r, g, b, 255 - fadefactor);
//		return *this;
//	}
//
//	// "or" operator brings each channel up to the higher of the two values
//	inline CRGB& operator|= (const CRGB& rhs)
//	{
//		if (rhs.r > r) r = rhs.r;
//		if (rhs.g > g) g = rhs.g;
//		if (rhs.b > b) b = rhs.b;
//		return *this;
//	}
//	inline CRGB& operator|= (uint8_t d)
//	{
//		if (d > r) r = d;
//		if (d > g) g = d;
//		if (d > b) b = d;
//		return *this;
//	}
//
//	// "and" operator brings each channel down to the lower of the two values
//	inline CRGB& operator&= (const CRGB& rhs)
//	{
//		if (rhs.r < r) r = rhs.r;
//		if (rhs.g < g) g = rhs.g;
//		if (rhs.b < b) b = rhs.b;
//		return *this;
//	}
//	inline CRGB& operator&= (uint8_t d)
//	{
//		if (d < r) r = d;
//		if (d < g) g = d;
//		if (d < b) b = d;
//		return *this;
//	}
//
//	// this allows testing a CRGB for zero-ness
//	inline operator bool() const __attribute__((always_inline))
//	{
//		return r || g || b;
//	}
//
//	// invert each channel
//	inline CRGB operator- ()
//	{
//		CRGB retval;
//		retval.r = 255 - r;
//		retval.g = 255 - g;
//		retval.b = 255 - b;
//		return retval;
//	}
//
//#if (defined SmartMatrix_h || defined SmartMatrix3_h)
//	operator rgb24() const {
//		rgb24 ret;
//		ret.red = r;
//		ret.green = g;
//		ret.blue = b;
//		return ret;
//	}
//#endif
//
//	inline uint8_t getLuma()  const {
//		//Y' = 0.2126 R' + 0.7152 G' + 0.0722 B'
//		//     54            183       18 (!)
//
//		uint8_t luma = scale8_LEAVING_R1_DIRTY(r, 54) + \
//			scale8_LEAVING_R1_DIRTY(g, 183) + \
//			scale8_LEAVING_R1_DIRTY(b, 18);
//		cleanup_R1();
//		return luma;
//	}
//
//	inline uint8_t getAverageLight()  const {
//		const uint8_t eightysix = 86;
//		uint8_t avg = scale8_LEAVING_R1_DIRTY(r, eightysix) + \
//			scale8_LEAVING_R1_DIRTY(g, eightysix) + \
//			scale8_LEAVING_R1_DIRTY(b, eightysix);
//		cleanup_R1();
//		return avg;
//	}
//
//	inline void maximizeBrightness(uint8_t limit = 255) {
//		uint8_t max = red;
//		if (green > max) max = green;
//		if (blue > max) max = blue;
//		uint16_t factor = ((uint16_t)(limit)* 256) / max;
//		red = (red   * factor) / 256;
//		green = (green * factor) / 256;
//		blue = (blue  * factor) / 256;
//	}
//
//	inline CRGB lerp8(CRGB & other, fract8 frac)
//	{
//		CRGB ret;
//
//		ret.r = lerp8by8(r, other.r, frac);
//		ret.g = lerp8by8(g, other.g, frac);
//		ret.b = lerp8by8(b, other.b, frac);
//
//		return ret;
//	}
//
//	inline CRGB lerp16(CRGB & other, fract16 frac)
//	{
//		CRGB ret;
//
//		ret.r = lerp16by16(r << 8, other.r << 8, frac) >> 8;
//		ret.g = lerp16by16(g << 8, other.g << 8, frac) >> 8;
//		ret.b = lerp16by16(b << 8, other.b << 8, frac) >> 8;
//
//		return ret;
//	}
//
//	// getParity returns 0 or 1, depending on the
//	// lowest bit of the sum of the color components.
//	inline uint8_t getParity()
//	{
//		uint8_t sum = r + g + b;
//		return (sum & 0x01);
//	}
//
//	// setParity adjusts the color in the smallest
//	// way possible so that the parity of the color
//	// is now the desired value.  This allows you to
//	// 'hide' one bit of information in the color.
//	//
//	// Ideally, we find one color channel which already
//	// has data in it, and modify just that channel by one.
//	// We don't want to light up a channel that's black
//	// if we can avoid it, and if the pixel is 'grayscale',
//	// (meaning that R==G==B), we modify all three channels
//	// at once, to preserve the neutral hue.
//	//
//	// There's no such thing as a free lunch; in many cases
//	// this 'hidden bit' may actually be visible, but this
//	// code makes reasonable efforts to hide it as much
//	// as is reasonably possible.
//	//
//	// Also, an effort is made to have make it such that
//	// repeatedly setting the parity to different values
//	// will not cause the color to 'drift'.  Toggling
//	// the parity twice should generally result in the
//	// original color again.
//	//
//	inline void setParity(uint8_t parity)
//	{
//		uint8_t curparity = getParity();
//
//		if (parity == curparity) return;
//
//		if (parity) {
//			// going 'up'
//			if ((b > 0) && (b < 255)) {
//				if (r == g && g == b) {
//					r++;
//					g++;
//				}
//				b++;
//			}
//			else if ((r > 0) && (r < 255)) {
//				r++;
//			}
//			else if ((g > 0) && (g < 255)) {
//				g++;
//			}
//			else {
//				if (r == g && g == b) {
//					r ^= 0x01;
//					g ^= 0x01;
//				}
//				b ^= 0x01;
//			}
//		}
//		else {
//			// going 'down'
//			if (b > 1) {
//				if (r == g && g == b) {
//					r--;
//					g--;
//				}
//				b--;
//			}
//			else if (g > 1) {
//				g--;
//			}
//			else if (r > 1) {
//				r--;
//			}
//			else {
//				if (r == g && g == b) {
//					r ^= 0x01;
//					g ^= 0x01;
//				}
//				b ^= 0x01;
//			}
//		}
//	}
//
//	/// Predefined RGB colors
//	typedef enum {
//		AliceBlue = 0xF0F8FF,
//		Amethyst = 0x9966CC,
//		AntiqueWhite = 0xFAEBD7,
//		Aqua = 0x00FFFF,
//		Aquamarine = 0x7FFFD4,
//		Azure = 0xF0FFFF,
//		Beige = 0xF5F5DC,
//		Bisque = 0xFFE4C4,
//		Black = 0x000000,
//		BlanchedAlmond = 0xFFEBCD,
//		Blue = 0x0000FF,
//		BlueViolet = 0x8A2BE2,
//		Brown = 0xA52A2A,
//		BurlyWood = 0xDEB887,
//		CadetBlue = 0x5F9EA0,
//		Chartreuse = 0x7FFF00,
//		Chocolate = 0xD2691E,
//		Coral = 0xFF7F50,
//		CornflowerBlue = 0x6495ED,
//		Cornsilk = 0xFFF8DC,
//		Crimson = 0xDC143C,
//		Cyan = 0x00FFFF,
//		DarkBlue = 0x00008B,
//		DarkCyan = 0x008B8B,
//		DarkGoldenrod = 0xB8860B,
//		DarkGray = 0xA9A9A9,
//		DarkGrey = 0xA9A9A9,
//		DarkGreen = 0x006400,
//		DarkKhaki = 0xBDB76B,
//		DarkMagenta = 0x8B008B,
//		DarkOliveGreen = 0x556B2F,
//		DarkOrange = 0xFF8C00,
//		DarkOrchid = 0x9932CC,
//		DarkRed = 0x8B0000,
//		DarkSalmon = 0xE9967A,
//		DarkSeaGreen = 0x8FBC8F,
//		DarkSlateBlue = 0x483D8B,
//		DarkSlateGray = 0x2F4F4F,
//		DarkSlateGrey = 0x2F4F4F,
//		DarkTurquoise = 0x00CED1,
//		DarkViolet = 0x9400D3,
//		DeepPink = 0xFF1493,
//		DeepSkyBlue = 0x00BFFF,
//		DimGray = 0x696969,
//		DimGrey = 0x696969,
//		DodgerBlue = 0x1E90FF,
//		FireBrick = 0xB22222,
//		FloralWhite = 0xFFFAF0,
//		ForestGreen = 0x228B22,
//		Fuchsia = 0xFF00FF,
//		Gainsboro = 0xDCDCDC,
//		GhostWhite = 0xF8F8FF,
//		Gold = 0xFFD700,
//		Goldenrod = 0xDAA520,
//		Gray = 0x808080,
//		Grey = 0x808080,
//		Green = 0x008000,
//		GreenYellow = 0xADFF2F,
//		Honeydew = 0xF0FFF0,
//		HotPink = 0xFF69B4,
//		IndianRed = 0xCD5C5C,
//		Indigo = 0x4B0082,
//		Ivory = 0xFFFFF0,
//		Khaki = 0xF0E68C,
//		Lavender = 0xE6E6FA,
//		LavenderBlush = 0xFFF0F5,
//		LawnGreen = 0x7CFC00,
//		LemonChiffon = 0xFFFACD,
//		LightBlue = 0xADD8E6,
//		LightCoral = 0xF08080,
//		LightCyan = 0xE0FFFF,
//		LightGoldenrodYellow = 0xFAFAD2,
//		LightGreen = 0x90EE90,
//		LightGrey = 0xD3D3D3,
//		LightPink = 0xFFB6C1,
//		LightSalmon = 0xFFA07A,
//		LightSeaGreen = 0x20B2AA,
//		LightSkyBlue = 0x87CEFA,
//		LightSlateGray = 0x778899,
//		LightSlateGrey = 0x778899,
//		LightSteelBlue = 0xB0C4DE,
//		LightYellow = 0xFFFFE0,
//		Lime = 0x00FF00,
//		LimeGreen = 0x32CD32,
//		Linen = 0xFAF0E6,
//		Magenta = 0xFF00FF,
//		Maroon = 0x800000,
//		MediumAquamarine = 0x66CDAA,
//		MediumBlue = 0x0000CD,
//		MediumOrchid = 0xBA55D3,
//		MediumPurple = 0x9370DB,
//		MediumSeaGreen = 0x3CB371,
//		MediumSlateBlue = 0x7B68EE,
//		MediumSpringGreen = 0x00FA9A,
//		MediumTurquoise = 0x48D1CC,
//		MediumVioletRed = 0xC71585,
//		MidnightBlue = 0x191970,
//		MintCream = 0xF5FFFA,
//		MistyRose = 0xFFE4E1,
//		Moccasin = 0xFFE4B5,
//		NavajoWhite = 0xFFDEAD,
//		Navy = 0x000080,
//		OldLace = 0xFDF5E6,
//		Olive = 0x808000,
//		OliveDrab = 0x6B8E23,
//		Orange = 0xFFA500,
//		OrangeRed = 0xFF4500,
//		Orchid = 0xDA70D6,
//		PaleGoldenrod = 0xEEE8AA,
//		PaleGreen = 0x98FB98,
//		PaleTurquoise = 0xAFEEEE,
//		PaleVioletRed = 0xDB7093,
//		PapayaWhip = 0xFFEFD5,
//		PeachPuff = 0xFFDAB9,
//		Peru = 0xCD853F,
//		Pink = 0xFFC0CB,
//		Plaid = 0xCC5533,
//		Plum = 0xDDA0DD,
//		PowderBlue = 0xB0E0E6,
//		Purple = 0x800080,
//		Red = 0xFF0000,
//		RosyBrown = 0xBC8F8F,
//		RoyalBlue = 0x4169E1,
//		SaddleBrown = 0x8B4513,
//		Salmon = 0xFA8072,
//		SandyBrown = 0xF4A460,
//		SeaGreen = 0x2E8B57,
//		Seashell = 0xFFF5EE,
//		Sienna = 0xA0522D,
//		Silver = 0xC0C0C0,
//		SkyBlue = 0x87CEEB,
//		SlateBlue = 0x6A5ACD,
//		SlateGray = 0x708090,
//		SlateGrey = 0x708090,
//		Snow = 0xFFFAFA,
//		SpringGreen = 0x00FF7F,
//		SteelBlue = 0x4682B4,
//		Tan = 0xD2B48C,
//		Teal = 0x008080,
//		Thistle = 0xD8BFD8,
//		Tomato = 0xFF6347,
//		Turquoise = 0x40E0D0,
//		Violet = 0xEE82EE,
//		Wheat = 0xF5DEB3,
//		White = 0xFFFFFF,
//		WhiteSmoke = 0xF5F5F5,
//		Yellow = 0xFFFF00,
//		YellowGreen = 0x9ACD32,
//
//		// LED RGB color that roughly approximates
//		// the color of incandescent fairy lights,
//		// assuming that you're using FastLED
//		// color correction on your LEDs (recommended).
//		FairyLight = 0xFFE42D,
//		// If you are using no color correction, use this
//		FairyLightNCC = 0xFF9D2A
//
//	} HTMLColorCode;
//};
//
//inline void hsv2rgb_rainbow(const CHSV& hsv, CRGB& rgb)
//{
//	// Yellow has a higher inherent brightness than
//	// any other color; 'pure' yellow is perceived to
//	// be 93% as bright as white.  In order to make
//	// yellow appear the correct relative brightness,
//	// it has to be rendered brighter than all other
//	// colors.
//	// Level Y1 is a moderate boost, the default.
//	// Level Y2 is a strong boost.
//	const uint8_t Y1 = 1;
//	const uint8_t Y2 = 0;
//
//	// G2: Whether to divide all greens by two.
//	// Depends GREATLY on your particular LEDs
//	const uint8_t G2 = 0;
//
//	// Gscale: what to scale green down by.
//	// Depends GREATLY on your particular LEDs
//	const uint8_t Gscale = 0;
//
//
//	uint8_t hue = hsv.hue;
//	uint8_t sat = hsv.sat;
//	uint8_t val = hsv.val;
//
//	uint8_t offset = hue & 0x1F; // 0..31
//
//								 // offset8 = offset * 8
//	uint8_t offset8 = offset;
//	{
//#if defined(__AVR__)
//		// Left to its own devices, gcc turns "x <<= 3" into a loop
//		// It's much faster and smaller to just do three single-bit shifts
//		// So this business is to force that.
//		offset8 <<= 1;
//		asm volatile("");
//		offset8 <<= 1;
//		asm volatile("");
//		offset8 <<= 1;
//#else
//		// On ARM and other non-AVR platforms, we just shift 3.
//		offset8 <<= 3;
//#endif
//	}
//
//	uint8_t third = scale8(offset8, (256 / 3));
//
//	uint8_t r, g, b;
//
//	if (!(hue & 0x80)) {
//		// 0XX
//		if (!(hue & 0x40)) {
//			// 00X
//			//section 0-1
//			if (!(hue & 0x20)) {
//				// 000
//				//case 0: // R -> O
//				r = K255 - third;
//				g = third;
//				b = 0;
//				FORCE_REFERENCE(b);
//			}
//			else {
//				// 001
//				//case 1: // O -> Y
//				if (Y1) {
//					r = K171;
//					g = K85 + third;
//					b = 0;
//					FORCE_REFERENCE(b);
//				}
//				if (Y2) {
//					r = K171 + third;
//					//uint8_t twothirds = (third << 1);
//					uint8_t twothirds = scale8(offset8, ((256 * 2) / 3));
//					g = K85 + twothirds;
//					b = 0;
//					FORCE_REFERENCE(b);
//				}
//			}
//		}
//		else {
//			//01X
//			// section 2-3
//			if (!(hue & 0x20)) {
//				// 010
//				//case 2: // Y -> G
//				if (Y1) {
//					//uint8_t twothirds = (third << 1);
//					uint8_t twothirds = scale8(offset8, ((256 * 2) / 3));
//					r = K171 - twothirds;
//					g = K171 + third;
//					b = 0;
//					FORCE_REFERENCE(b);
//				}
//				if (Y2) {
//					r = K255 - offset8;
//					g = K255;
//					b = 0;
//					FORCE_REFERENCE(b);
//				}
//			}
//			else {
//				// 011
//				// case 3: // G -> A
//				r = 0;
//				FORCE_REFERENCE(r);
//				g = K255 - third;
//				b = third;
//			}
//		}
//	}
//	else {
//		// section 4-7
//		// 1XX
//		if (!(hue & 0x40)) {
//			// 10X
//			if (!(hue & 0x20)) {
//				// 100
//				//case 4: // A -> B
//				r = 0;
//				FORCE_REFERENCE(r);
//				//uint8_t twothirds = (third << 1);
//				uint8_t twothirds = scale8(offset8, ((256 * 2) / 3));
//				g = K171 - twothirds;
//				b = K85 + twothirds;
//
//			}
//			else {
//				// 101
//				//case 5: // B -> P
//				r = third;
//				g = 0;
//				FORCE_REFERENCE(g);
//				b = K255 - third;
//
//			}
//		}
//		else {
//			if (!(hue & 0x20)) {
//				// 110
//				//case 6: // P -- K
//				r = K85 + third;
//				g = 0;
//				FORCE_REFERENCE(g);
//				b = K171 - third;
//
//			}
//			else {
//				// 111
//				//case 7: // K -> R
//				r = K171 + third;
//				g = 0;
//				FORCE_REFERENCE(g);
//				b = K85 - third;
//
//			}
//		}
//	}
//
//	// This is one of the good places to scale the green down,
//	// although the client can scale green down as well.
//	if (G2) g = g >> 1;
//	if (Gscale) g = scale8_video_LEAVING_R1_DIRTY(g, Gscale);
//
//	// Scale down colors if we're desaturated at all
//	// and add the brightness_floor to r, g, and b.
//	if (sat != 255) {
//
//		nscale8x3_video(r, g, b, sat);
//
//		uint8_t desat = 255 - sat;
//		desat = scale8(desat, desat);
//
//		uint8_t brightness_floor = desat;
//		r += brightness_floor;
//		g += brightness_floor;
//		b += brightness_floor;
//	}
//
//	// Now scale everything down if we're at value < 255.
//	if (val != 255) {
//
//		val = scale8_video_LEAVING_R1_DIRTY(val, val);
//		nscale8x3_video(r, g, b, val);
//	}
//
//	// Here we have the old AVR "missing std X+n" problem again
//	// It turns out that fixing it winds up costing more than
//	// not fixing it.
//	// To paraphrase Dr Bronner, profile! profile! profile!
//	//asm volatile(  ""  :  :  : "r26", "r27" );
//	//asm volatile (" movw r30, r26 \n" : : : "r30", "r31");
//	rgb.r = r;
//	rgb.g = g;
//	rgb.b = b;
//}
//
//LIB8STATIC uint8_t qadd8(uint8_t i, uint8_t j)
//{
//#if QADD8_C == 1
//	unsigned int t = i + j;
//	if (t > 255) t = 255;
//	return t;
//#elif QADD8_AVRASM == 1
//	asm volatile(
//		/* First, add j to i, conditioning the C flag */
//		"add %0, %1    \n\t"
//
//		/* Now test the C flag.
//		If C is clear, we branch around a load of 0xFF into i.
//		If C is set, we go ahead and load 0xFF into i.
//		*/
//		"brcc L_%=     \n\t"
//		"ldi %0, 0xFF  \n\t"
//		"L_%=: "
//		: "+a" (i)
//		: "a"  (j));
//	return i;
//#elif QADD8_ARM_DSP_ASM == 1
//	asm volatile("uqadd8 %0, %0, %1" : "+r" (i) : "r" (j));
//	return i;
//#else
//#error "No implementation for qadd8 available."
//#endif
//}
//
//LIB8STATIC inline uint8_t qsub8(uint8_t i, uint8_t j)
//{
//#if QSUB8_C == 1
//	int t = i - j;
//	if (t < 0) t = 0;
//	return t;
//#elif QSUB8_AVRASM == 1
//
//	asm volatile(
//		/* First, subtract j from i, conditioning the C flag */
//		"sub %0, %1    \n\t"
//
//		/* Now test the C flag.
//		If C is clear, we branch around a load of 0x00 into i.
//		If C is set, we go ahead and load 0x00 into i.
//		*/
//		"brcc L_%=     \n\t"
//		"ldi %0, 0x00  \n\t"
//		"L_%=: "
//		: "+a" (i)
//		: "a"  (j));
//
//	return i;
//#else
//#error "No implementation for qsub8 available."
//#endif
//}
//
//LIB8STATIC inline uint8_t mul8(uint8_t i, uint8_t j)
//{
//#if MUL8_C == 1
//	return ((int)i * (int)(j)) & 0xFF;
//#elif MUL8_AVRASM == 1
//	asm volatile(
//		/* Multiply 8-bit i * 8-bit j, giving 16-bit r1,r0 */
//		"mul %0, %1          \n\t"
//		/* Extract the LOW 8-bits (r0) */
//		"mov %0, r0          \n\t"
//		/* Restore r1 to "0"; it's expected to always be that */
//		"clr __zero_reg__    \n\t"
//		: "+a" (i)
//		: "a"  (j)
//		: "r0", "r1");
//
//	return i;
//#else
//#error "No implementation for mul8 available."
//#endif
//}
//
//LIB8STATIC inline void nscale8x3_video(uint8_t& r, uint8_t& g, uint8_t& b, fract8 scale)
//{
//#if SCALE8_C == 1
//	uint8_t nonzeroscale = (scale != 0) ? 1 : 0;
//	r = (r == 0) ? 0 : (((int)r * (int)(scale)) >> 8) + nonzeroscale;
//	g = (g == 0) ? 0 : (((int)g * (int)(scale)) >> 8) + nonzeroscale;
//	b = (b == 0) ? 0 : (((int)b * (int)(scale)) >> 8) + nonzeroscale;
//#elif SCALE8_AVRASM == 1
//	nscale8_video_LEAVING_R1_DIRTY(r, scale);
//	nscale8_video_LEAVING_R1_DIRTY(g, scale);
//	nscale8_video_LEAVING_R1_DIRTY(b, scale);
//	cleanup_R1();
//#else
//#error "No implementation for nscale8x3 available."
//#endif
//}
//
//LIB8STATIC inline uint8_t scale8(uint8_t i, fract8 scale)
//{
//#if SCALE8_C == 1
//	return ((uint16_t)i * (uint16_t)(scale)) >> 8;
//#elif SCALE8_AVRASM == 1
//#if defined(LIB8_ATTINY)
//	uint8_t work = 0;
//	uint8_t cnt = 0x80;
//	asm volatile(
//		"LOOP_%=:                             \n\t"
//		/*"  sbrc %[scale], 0             \n\t"
//		"  add %[work], %[i]            \n\t"
//		"  ror %[work]                  \n\t"
//		"  lsr %[scale]                 \n\t"
//		"  clc                          \n\t"*/
//		"  sbrc %[scale], 0             \n\t"
//		"  add %[work], %[i]            \n\t"
//		"  ror %[work]                  \n\t"
//		"  lsr %[scale]                 \n\t"
//		"  lsr %[cnt]                   \n\t"
//		"brcc LOOP_%="
//		: [work] "+r" (work), [cnt] "+r" (cnt)
//		: [scale] "r" (scale), [i] "r" (i)
//		:
//		);
//	return work;
//#else
//	asm volatile(
//		/* Multiply 8-bit i * 8-bit scale, giving 16-bit r1,r0 */
//		"mul %0, %1          \n\t"
//		/* Move the high 8-bits of the product (r1) back to i */
//		"mov %0, r1          \n\t"
//		/* Restore r1 to "0"; it's expected to always be that */
//		"clr __zero_reg__    \n\t"
//
//		: "+a" (i)      /* writes to i */
//		: "a"  (scale)  /* uses scale */
//		: "r0", "r1"    /* clobbers r0, r1 */);
//
//	/* Return the result */
//	return i;
//#endif
//#else
//#error "No implementation for scale8 available."
//#endif
//}
//
//LIB8STATIC inline void nscale8x3(uint8_t& r, uint8_t& g, uint8_t& b, fract8 scale)
//{
//#if SCALE8_C == 1
//	r = ((int)r * (int)(scale)) >> 8;
//	g = ((int)g * (int)(scale)) >> 8;
//	b = ((int)b * (int)(scale)) >> 8;
//#elif SCALE8_AVRASM == 1
//	r = scale8_LEAVING_R1_DIRTY(r, scale);
//	g = scale8_LEAVING_R1_DIRTY(g, scale);
//	b = scale8_LEAVING_R1_DIRTY(b, scale);
//	cleanup_R1();
//#else
//#error "No implementation for nscale8x3 available."
//#endif
//}
//
//LIB8STATIC inline uint8_t scale8_LEAVING_R1_DIRTY(uint8_t i, fract8 scale)
//{
//#if SCALE8_C == 1
//	return ((int)i * (int)(scale)) >> 8;
//#elif SCALE8_AVRASM == 1
//	asm volatile(
//		/* Multiply 8-bit i * 8-bit scale, giving 16-bit r1,r0 */
//		"mul %0, %1    \n\t"
//		/* Move the high 8-bits of the product (r1) back to i */
//		"mov %0, r1    \n\t"
//		/* R1 IS LEFT DIRTY HERE; YOU MUST ZERO IT OUT YOURSELF  */
//		/* "clr __zero_reg__    \n\t" */
//
//		: "+a" (i)      /* writes to i */
//		: "a"  (scale)  /* uses scale */
//		: "r0", "r1"    /* clobbers r0, r1 */);
//
//	// Return the result
//	return i;
//#else
//#error "No implementation for scale8_LEAVING_R1_DIRTY available."
//#endif
//}
//
//LIB8STATIC inline void cleanup_R1()
//{
//#if CLEANUP_R1_AVRASM == 1
//	// Restore r1 to "0"; it's expected to always be that
//	asm volatile("clr __zero_reg__  \n\t" : : : "r1");
//#endif
//}
//
//LIB8STATIC inline uint8_t lerp8by8(uint8_t a, uint8_t b, fract8 frac)
//{
//	uint8_t result;
//	if (b > a) {
//		uint8_t delta = b - a;
//		uint8_t scaled = scale8(delta, frac);
//		result = a + scaled;
//	}
//	else {
//		uint8_t delta = a - b;
//		uint8_t scaled = scale8(delta, frac);
//		result = a - scaled;
//	}
//	return result;
//}
//
//LIB8STATIC uint16_t lerp16by16(uint16_t a, uint16_t b, fract16 frac)
//{
//	uint16_t result;
//	if (b > a) {
//		uint16_t delta = b - a;
//		uint32_t scaled = scale16(delta, frac);
//		result = a + scaled;
//	}
//	else {
//		uint16_t delta = a - b;
//		uint16_t scaled = scale16(delta, frac);
//		result = a - scaled;
//	}
//	return result;
//}
//
//LIB8STATIC uint16_t scale16(uint16_t i, fract16 scale)
//{
//#if SCALE16_C == 1
//	uint16_t result;
//	result = ((uint32_t)(i)* (uint32_t)(scale)) / 65536;
//	return result;
//#elif SCALE16_AVRASM == 1
//	uint32_t result = 0;
//	const uint8_t  zero = 0;
//	asm volatile(
//		// result.A-B  = i.A x scale.A
//		"  mul %A[i], %A[scale]                 \n\t"
//		//  save results...
//		// basic idea:
//		//"  mov %A[result], r0                 \n\t"
//		//"  mov %B[result], r1                 \n\t"
//		// which can be written as...
//		"  movw %A[result], r0                   \n\t"
//		// We actually need to do anything with r0,
//		// as result.A is never used again here, so we
//		// could just move the high byte, but movw is
//		// one clock cycle, just like mov, so might as
//		// well, in case we want to use this code for
//		// a generic 16x16 multiply somewhere.
//
//		// result.C-D  = i.B x scale.B
//		"  mul %B[i], %B[scale]                 \n\t"
//		//"  mov %C[result], r0                 \n\t"
//		//"  mov %D[result], r1                 \n\t"
//		"  movw %C[result], r0                   \n\t"
//
//		// result.B-D += i.B x scale.A
//		"  mul %B[i], %A[scale]                 \n\t"
//
//		"  add %B[result], r0                   \n\t"
//		"  adc %C[result], r1                   \n\t"
//		"  adc %D[result], %[zero]              \n\t"
//
//		// result.B-D += i.A x scale.B
//		"  mul %A[i], %B[scale]                 \n\t"
//
//		"  add %B[result], r0                   \n\t"
//		"  adc %C[result], r1                   \n\t"
//		"  adc %D[result], %[zero]              \n\t"
//
//		// cleanup r1
//		"  clr r1                               \n\t"
//
//		: [result] "+r" (result)
//		: [i] "r" (i),
//		[scale] "r" (scale),
//		[zero] "r" (zero)
//		: "r0", "r1"
//		);
//	result = result >> 16;
//	return result;
//#else
//#error "No implementation for scale16 available."
//#endif
//}
/////@}
//
//LIB8STATIC uint8_t qmul8(uint8_t i, uint8_t j)
//{
//#if QMUL8_C == 1
//	int p = ((int)i * (int)(j));
//	if (p > 255) p = 255;
//	return p;
//#elif QMUL8_AVRASM == 1
//	asm volatile(
//		/* Multiply 8-bit i * 8-bit j, giving 16-bit r1,r0 */
//		"  mul %0, %1          \n\t"
//		/* If high byte of result is zero, all is well. */
//		"  tst r1              \n\t"
//		"  breq Lnospill_%=    \n\t"
//		/* If high byte of result > 0, saturate low byte to 0xFF */
//		"  ldi %0,0xFF         \n\t"
//		"  rjmp Ldone_%=       \n\t"
//		"Lnospill_%=:          \n\t"
//		/* Extract the LOW 8-bits (r0) */
//		"  mov %0, r0          \n\t"
//		"Ldone_%=:             \n\t"
//		/* Restore r1 to "0"; it's expected to always be that */
//		"  clr __zero_reg__    \n\t"
//		: "+a" (i)
//		: "a"  (j)
//		: "r0", "r1");
//
//	return i;
//#else
//#error "No implementation for qmul8 available."
//#endif
//}
//
//
//
//LIB8STATIC uint8_t scale8_video_LEAVING_R1_DIRTY(uint8_t i, fract8 scale)
//{
//#if SCALE8_C == 1 || defined(LIB8_ATTINY)
//	uint8_t j = (((int)i * (int)scale) >> 8) + ((i&&scale) ? 1 : 0);
//	// uint8_t nonzeroscale = (scale != 0) ? 1 : 0;
//	// uint8_t j = (i == 0) ? 0 : (((int)i * (int)(scale) ) >> 8) + nonzeroscale;
//	return j;
//#elif SCALE8_AVRASM == 1
//	uint8_t j = 0;
//	asm volatile(
//		"  tst %[i]\n\t"
//		"  breq L_%=\n\t"
//		"  mul %[i], %[scale]\n\t"
//		"  mov %[j], r1\n\t"
//		"  breq L_%=\n\t"
//		"  subi %[j], 0xFF\n\t"
//		"L_%=: \n\t"
//		: [j] "+a" (j)
//		: [i] "a" (i), [scale] "a" (scale)
//		: "r0", "r1");
//
//	return j;
//	// uint8_t nonzeroscale = (scale != 0) ? 1 : 0;
//	// asm volatile(
//	//      "      tst %0           \n"
//	//      "      breq L_%=        \n"
//	//      "      mul %0, %1       \n"
//	//      "      mov %0, r1       \n"
//	//      "      add %0, %2       \n"
//	//      "      clr __zero_reg__ \n"
//	//      "L_%=:                  \n"
//
//	//      : "+a" (i)
//	//      : "a" (scale), "a" (nonzeroscale)
//	//      : "r0", "r1");
//
//	// // Return the result
//	// return i;
//#else
//#error "No implementation for scale8_video_LEAVING_R1_DIRTY available."
//#endif
//}
//
//class CLEDController {
//protected:
//	friend class CFastLED;
//	CRGB *m_Data;
//	CLEDController *m_pNext;
//	CRGB m_ColorCorrection;
//	CRGB m_ColorTemperature;
//	EDitherMode m_DitherMode;
//	int m_nLeds;
//	static CLEDController *m_pHead;
//	static CLEDController *m_pTail;
//
//	/// set all the leds on the controller to a given color
//	///@param data the crgb color to set the leds to
//	///@param nLeds the numner of leds to set to this color
//	///@param scale the rgb scaling value for outputting color
//	virtual void showColor(const struct CRGB & data, int nLeds, CRGB scale) = 0;
//
//	/// write the passed in rgb data out to the leds managed by this controller
//	///@param data the rgb data to write out to the strip
//	///@param nLeds the number of leds being written out
//	///@param scale the rgb scaling to apply to each led before writing it out
//	virtual void show(const struct CRGB *data, int nLeds, CRGB scale) = 0;
//
//#ifdef SUPPORT_ARGB
//	// as above, but every 4th uint8_t is assumed to be alpha channel data, and will be skipped
//	virtual void show(const struct CARGB *data, int nLeds, CRGB scale) = 0;
//#endif
//public:
//	/// create an led controller object, add it to the chain of controllers
//	CLEDController() : m_Data(NULL), m_ColorCorrection(UncorrectedColor), m_ColorTemperature(UncorrectedTemperature), m_DitherMode(BINARY_DITHER), m_nLeds(0) {
//		m_pNext = NULL;
//		if (m_pHead == NULL) { m_pHead = this; }
//		if (m_pTail != NULL) { m_pTail->m_pNext = this; }
//		m_pTail = this;
//	}
//
//	///initialize the LED controller
//	virtual void init() = 0;
//
//	///clear out/zero out the given number of leds.
//	virtual void clearLeds(int nLeds) = 0;
//
//	/// show function w/integer brightness, will scale for color correction and temperature
//	void show(const struct CRGB *data, int nLeds, uint8_t brightness) {
//		show(data, nLeds, getAdjustment(brightness));
//	}
//
//	/// show function w/integer brightness, will scale for color correction and temperature
//	void showColor(const struct CRGB &data, int nLeds, uint8_t brightness) {
//		showColor(data, nLeds, getAdjustment(brightness));
//	}
//
//	/// show function using the "attached to this controller" led data
//	void showLeds(uint8_t brightness = 255) {
//		show(m_Data, m_nLeds, getAdjustment(brightness));
//	}
//
//	/// show the given color on the led strip
//	void showColor(const struct CRGB & data, uint8_t brightness = 255) {
//		showColor(data, m_nLeds, getAdjustment(brightness));
//	}
//
//	/// get the first led controller in the chain of controllers
//	static CLEDController *head() { return m_pHead; }
//	/// get the next controller in the chain after this one.  will return NULL at the end of the chain
//	CLEDController *next() { return m_pNext; }
//
//#ifdef SUPPORT_ARGB
//	// as above, but every 4th uint8_t is assumed to be alpha channel data, and will be skipped
//	void show(const struct CARGB *data, int nLeds, uint8_t brightness) {
//		show(data, nLeds, getAdjustment(brightness))
//	}
//#endif
//
//	/// set the default array of leds to be used by this controller
//	CLEDController & setLeds(CRGB *data, int nLeds) {
//		m_Data = data;
//		m_nLeds = nLeds;
//		return *this;
//	}
//
//	/// zero out the led data managed by this controller
//	void clearLedData() {
//		if (m_Data) {
//			memset8((void*)m_Data, 0, sizeof(struct CRGB) * m_nLeds);
//		}
//	}
//
//	/// How many leds does this controller manage?
//	int size() { return m_nLeds; }
//
//	/// Pointer to the CRGB array for this controller
//	CRGB* leds() { return m_Data; }
//
//	/// Reference to the n'th item in the controller
//	CRGB &operator[](int x) { return m_Data[x]; }
//
//	/// set the dithering mode for this controller to use
//	inline CLEDController & setDither(uint8_t ditherMode = BINARY_DITHER) { m_DitherMode = ditherMode; return *this; }
//	/// get the dithering option currently set for this controller
//	inline uint8_t getDither() { return m_DitherMode; }
//
//	/// the the color corrction to use for this controller, expressed as an rgb object
//	CLEDController & setCorrection(CRGB correction) { m_ColorCorrection = correction; return *this; }
//	/// set the color correction to use for this controller
//	CLEDController & setCorrection(LEDColorCorrection correction) { m_ColorCorrection = correction; return *this; }
//	/// get the correction value used by this controller
//	CRGB getCorrection() { return m_ColorCorrection; }
//
//	/// set the color temperature, aka white point, for this controller
//	CLEDController & setTemperature(CRGB temperature) { m_ColorTemperature = temperature; return *this; }
//	/// set the color temperature, aka white point, for this controller
//	CLEDController & setTemperature(ColorTemperature temperature) { m_ColorTemperature = temperature; return *this; }
//	/// get the color temperature, aka whipe point, for this controller
//	CRGB getTemperature() { return m_ColorTemperature; }
//
//	/// Get the combined brightness/color adjustment for this controller
//	CRGB getAdjustment(uint8_t scale) {
//		return computeAdjustment(scale, m_ColorCorrection, m_ColorTemperature);
//	}
//
//	static CRGB computeAdjustment(uint8_t scale, const CRGB & colorCorrection, const CRGB & colorTemperature) {
//#if defined(NO_CORRECTION) && (NO_CORRECTION==1)
//		return CRGB(scale, scale, scale);
//#else
//		CRGB adj(0, 0, 0);
//
//		if (scale > 0) {
//			for (uint8_t i = 0; i < 3; i++) {
//				uint8_t cc = colorCorrection.raw[i];
//				uint8_t ct = colorTemperature.raw[i];
//				if (cc > 0 && ct > 0) {
//					uint32_t work = (((uint32_t)cc) + 1) * (((uint32_t)ct) + 1) * scale;
//					work /= 0x10000L;
//					adj.raw[i] = work & 0xFF;
//				}
//			}
//		}
//
//		return adj;
//#endif
//	}
//	virtual uint16_t getMaxRefreshRate() const { return 0; }
//};
//
//
//
//class CFastLED {
//	// int m_nControllers;
//	uint8_t  m_Scale; 				///< The current global brightness scale setting
//	uint16_t m_nFPS;					///< Tracking for current FPS value
//	uint32_t m_nMinMicros;		///< minimum µs between frames, used for capping frame rates.
//public:
//	CFastLED();
//
//
//	/// Add a CLEDController instance to the world.  Exposed to the public to allow people to implement their own
//	/// CLEDController objects or instances.  There are two ways to call this method (as well as the other addLeds)
//	/// variations.  The first is with 3 arguments, in which case the arguments are the controller, a pointer to
//	/// led data, and the number of leds used by this controller.  The seocond is with 4 arguments, in which case
//	/// the first two arguments are the same, the third argument is an offset into the CRGB data where this controller's
//	/// CRGB data begins, and the fourth argument is the number of leds for this controller object.
//	/// @param pLed - the led controller being added
//	/// @param data - base point to an array of CRGB data structures
//	/// @param nLedsOrOffset - number of leds (3 argument version) or offset into the data array
//	/// @param nLedsIfOffset - number of leds (4 argument version)
//	/// @returns a reference to the added controller
//	static CLEDController &addLeds(CLEDController *pLed, struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0);
//
//	/// @name Adding SPI based controllers
//	//@{
//	/// Add an SPI based  CLEDController instance to the world.
//	/// There are two ways to call this method (as well as the other addLeds)
//	/// variations.  The first is with 2 arguments, in which case the arguments are  a pointer to
//	/// led data, and the number of leds used by this controller.  The seocond is with 3 arguments, in which case
//	/// the first  argument is the same, the second argument is an offset into the CRGB data where this controller's
//	/// CRGB data begins, and the third argument is the number of leds for this controller object.
//	///
//	/// This method also takes a 1 to 5 template parameters for identifying the specific chipset, data and clock pins,
//	/// RGB ordering, and SPI data rate
//	/// @param data - base point to an array of CRGB data structures
//	/// @param nLedsOrOffset - number of leds (3 argument version) or offset into the data array
//	/// @param nLedsIfOffset - number of leds (4 argument version)
//	/// @tparam CHIPSET - the chipset type
//	/// @tparam DATA_PIN - the optional data pin for the leds (if omitted, will default to the first hardware SPI MOSI pin)
//	/// @tparam CLOCK_PIN - the optional clock pin for the leds (if omitted, will default to the first hardware SPI clock pin)
//	/// @tparam RGB_ORDER - the rgb ordering for the leds (e.g. what order red, green, and blue data is written out in)
//	/// @tparam SPI_DATA_RATE - the data rate to drive the SPI clock at, defined using DATA_RATE_MHZ or DATA_RATE_KHZ macros
//	/// @returns a reference to the added controller
//	template<ESPIChipsets CHIPSET, uint8_t DATA_PIN, uint8_t CLOCK_PIN, EOrder RGB_ORDER, uint8_t SPI_DATA_RATE > CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		switch (CHIPSET) {
//		case LPD8806: { static LPD8806Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//		case WS2801: { static WS2801Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//		case WS2803: { static WS2803Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//		case SM16716: { static SM16716Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//		case P9813: { static P9813Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//		case DOTSTAR:
//		case APA102: { static APA102Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER, SPI_DATA_RATE> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//		}
//	}
//
//	//template<ESPIChipsets CHIPSET, uint8_t DATA_PIN, uint8_t CLOCK_PIN > static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//	//	switch (CHIPSET) {
//	//	case LPD8806: { static LPD8806Controller<DATA_PIN, CLOCK_PIN> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case WS2801: { static WS2801Controller<DATA_PIN, CLOCK_PIN> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case WS2803: { static WS2803Controller<DATA_PIN, CLOCK_PIN> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case SM16716: { static SM16716Controller<DATA_PIN, CLOCK_PIN> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case P9813: { static P9813Controller<DATA_PIN, CLOCK_PIN> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case DOTSTAR:
//	//	case APA102: { static APA102Controller<DATA_PIN, CLOCK_PIN> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	}
//	//}
//
//	//template<ESPIChipsets CHIPSET, uint8_t DATA_PIN, uint8_t CLOCK_PIN, EOrder RGB_ORDER > static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//	//	switch (CHIPSET) {
//	//	case LPD8806: { static LPD8806Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case WS2801: { static WS2801Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case WS2803: { static WS2803Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case SM16716: { static SM16716Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case P9813: { static P9813Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	case DOTSTAR:
//	//	case APA102: { static APA102Controller<DATA_PIN, CLOCK_PIN, RGB_ORDER> c; return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset); }
//	//	}
//	//}
//
//#ifdef SPI_DATA
//	template<ESPIChipsets CHIPSET> static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		return addLeds<CHIPSET, SPI_DATA, SPI_CLOCK, RGB>(data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//	template<ESPIChipsets CHIPSET, EOrder RGB_ORDER> static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		return addLeds<CHIPSET, SPI_DATA, SPI_CLOCK, RGB_ORDER>(data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//	template<ESPIChipsets CHIPSET, EOrder RGB_ORDER, uint8_t SPI_DATA_RATE> static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		return addLeds<CHIPSET, SPI_DATA, SPI_CLOCK, RGB_ORDER, SPI_DATA_RATE>(data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//#endif
//	//@}
//
//#ifdef FASTLED_HAS_CLOCKLESS
//	/// @name Adding 3-wire led controllers
//	//@{
//	/// Add a clockless (aka 3wire, also DMX) based CLEDController instance to the world.
//	/// There are two ways to call this method (as well as the other addLeds)
//	/// variations.  The first is with 2 arguments, in which case the arguments are  a pointer to
//	/// led data, and the number of leds used by this controller.  The seocond is with 3 arguments, in which case
//	/// the first  argument is the same, the second argument is an offset into the CRGB data where this controller's
//	/// CRGB data begins, and the third argument is the number of leds for this controller object.
//	///
//	/// This method also takes a 2 to 3 template parameters for identifying the specific chipset, data pin, and rgb ordering
//	/// RGB ordering, and SPI data rate
//	/// @param data - base point to an array of CRGB data structures
//	/// @param nLedsOrOffset - number of leds (3 argument version) or offset into the data array
//	/// @param nLedsIfOffset - number of leds (4 argument version)
//	/// @tparam CHIPSET - the chipset type (required)
//	/// @tparam DATA_PIN - the optional data pin for the leds (required)
//	/// @tparam RGB_ORDER - the rgb ordering for the leds (e.g. what order red, green, and blue data is written out in)
//	/// @returns a reference to the added controller
//	template<template<uint8_t DATA_PIN, EOrder RGB_ORDER> class CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		static CHIPSET<DATA_PIN, RGB_ORDER> c;
//		return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//	template<template<uint8_t DATA_PIN, EOrder RGB_ORDER> class CHIPSET, uint8_t DATA_PIN>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		static CHIPSET<DATA_PIN, RGB> c;
//		return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//	template<template<uint8_t DATA_PIN> class CHIPSET, uint8_t DATA_PIN>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		static CHIPSET<DATA_PIN> c;
//		return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//#ifdef FASTSPI_USE_DMX_SIMPLE
//	template<EClocklessChipsets CHIPSET, uint8_t DATA_PIN, EOrder RGB_ORDER = RGB>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0)
//	{
//		switch (CHIPSET) {
//		case DMX: { static DMXController<DATA_PIN> controller; return addLeds(&controller, data, nLedsOrOffset, nLedsIfOffset); }
//		}
//	}
//#endif
//	//@}
//#endif
//
//	/// @name Adding 3rd party library controllers
//	//@{
//	/// Add a 3rd party library based CLEDController instance to the world.
//	/// There are two ways to call this method (as well as the other addLeds)
//	/// variations.  The first is with 2 arguments, in which case the arguments are  a pointer to
//	/// led data, and the number of leds used by this controller.  The seocond is with 3 arguments, in which case
//	/// the first  argument is the same, the second argument is an offset into the CRGB data where this controller's
//	/// CRGB data begins, and the third argument is the number of leds for this controller object. This class includes the SmartMatrix
//	/// and OctoWS2811 based controllers
//	///
//	/// This method also takes a 1 to 2 template parameters for identifying the specific chipset and rgb ordering
//	/// RGB ordering, and SPI data rate
//	/// @param data - base point to an array of CRGB data structures
//	/// @param nLedsOrOffset - number of leds (3 argument version) or offset into the data array
//	/// @param nLedsIfOffset - number of leds (4 argument version)
//	/// @tparam CHIPSET - the chipset type (required)
//	/// @tparam RGB_ORDER - the rgb ordering for the leds (e.g. what order red, green, and blue data is written out in)
//	/// @returns a reference to the added controller
//	//template<template<EOrder RGB_ORDER> class CHIPSET, EOrder RGB_ORDER>
//	//static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//	//	static CHIPSET<RGB_ORDER> c;
//	//	return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset);
//	//}
//
//	//template<template<EOrder RGB_ORDER> class CHIPSET>
//	//static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//	//	static CHIPSET<RGB> c;
//	//	return addLeds(&c, data, nLedsOrOffset, nLedsIfOffset);
//	//}
//
//#ifdef USE_OCTOWS2811
//	template<OWS2811 CHIPSET, EOrder RGB_ORDER>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0)
//	{
//		switch (CHIPSET) {
//		case OCTOWS2811: { static COctoWS2811Controller<RGB_ORDER> controller; return addLeds(&controller, data, nLedsOrOffset, nLedsIfOffset); }
//		case OCTOWS2811_400: { static COctoWS2811Controller<RGB_ORDER, true> controller; return addLeds(&controller, data, nLedsOrOffset, nLedsIfOffset); }
//		}
//	}
//
//	template<OWS2811 CHIPSET>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0)
//	{
//		return addLeds<CHIPSET, GRB>(data, nLedsOrOffset, nLedsIfOffset);
//	}
//
//#endif
//
//#ifdef SmartMatrix_h
//	template<ESM CHIPSET>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0)
//	{
//		switch (CHIPSET) {
//		case SMART_MATRIX: { static CSmartMatrixController controller; return addLeds(&controller, data, nLedsOrOffset, nLedsIfOffset); }
//		}
//	}
//#endif
//	//@}
//
//
//#ifdef FASTLED_HAS_BLOCKLESS
//
//	/// @name adding parallel output controllers
//	//@{
//	/// Add a block based CLEDController instance to the world.
//	/// There are two ways to call this method (as well as the other addLeds)
//	/// variations.  The first is with 2 arguments, in which case the arguments are  a pointer to
//	/// led data, and the number of leds used by this controller.  The seocond is with 3 arguments, in which case
//	/// the first  argument is the same, the second argument is an offset into the CRGB data where this controller's
//	/// CRGB data begins, and the third argument is the number of leds for this controller object.
//	///
//	/// This method also takes a 2 to 3 template parameters for identifying the specific chipset and rgb ordering
//	/// RGB ordering, and SPI data rate
//	/// @param data - base point to an array of CRGB data structures
//	/// @param nLedsOrOffset - number of leds (3 argument version) or offset into the data array
//	/// @param nLedsIfOffset - number of leds (4 argument version)
//	/// @tparam CHIPSET - the chipset/port type (required)
//	/// @tparam NUM_LANES - how many parallel lanes of output to write
//	/// @tparam RGB_ORDER - the rgb ordering for the leds (e.g. what order red, green, and blue data is written out in)
//	/// @returns a reference to the added controller
//	template<EBlockChipsets CHIPSET, int NUM_LANES, EOrder RGB_ORDER>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		switch (CHIPSET) {
//#ifdef PORTA_FIRST_PIN
//		case WS2811_PORTA: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTA_FIRST_PIN, NS(320), NS(320), NS(640), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//		case WS2811_400_PORTA: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTA_FIRST_PIN, NS(800), NS(800), NS(900), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//#endif
//#ifdef PORTB_FIRST_PIN
//		case WS2811_PORTB: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTB_FIRST_PIN, NS(320), NS(320), NS(640), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//		case WS2811_400_PORTB: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTB_FIRST_PIN, NS(800), NS(800), NS(900), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//#endif
//#ifdef PORTC_FIRST_PIN
//		case WS2811_PORTC: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTC_FIRST_PIN, NS(320), NS(320), NS(640), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//		case WS2811_400_PORTC: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTC_FIRST_PIN, NS(800), NS(800), NS(900), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//#endif
//#ifdef PORTD_FIRST_PIN
//		case WS2811_PORTD: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTD_FIRST_PIN, NS(320), NS(320), NS(640), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//		case WS2811_400_PORTD: return addLeds(new InlineBlockClocklessController<NUM_LANES, PORTD_FIRST_PIN, NS(800), NS(800), NS(900), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//#endif
//#ifdef HAS_PORTDC
//		case WS2811_PORTDC: return addLeds(new SixteenWayInlineBlockClocklessController<16, NS(320), NS(320), NS(640), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//		case WS2811_400_PORTDC: return addLeds(new SixteenWayInlineBlockClocklessController<16, NS(800), NS(800), NS(900), RGB_ORDER>(), data, nLedsOrOffset, nLedsIfOffset);
//#endif
//		}
//	}
//
//	template<EBlockChipsets CHIPSET, int NUM_LANES>
//	static CLEDController &addLeds(struct CRGB *data, int nLedsOrOffset, int nLedsIfOffset = 0) {
//		return addLeds<CHIPSET, NUM_LANES, GRB>(data, nLedsOrOffset, nLedsIfOffset);
//	}
//	//@}
//#endif
//
//	/// Set the global brightness scaling
//	/// @param scale a 0-255 value for how much to scale all leds before writing them out
//	void setBrightness(uint8_t scale) { m_Scale = scale; }
//
//	/// Get the current global brightness setting
//	/// @returns the current global brightness value
//	uint8_t getBrightness() { return m_Scale; }
//
//	/// Update all our controllers with the current led colors, using the passed in brightness
//	/// @param scale temporarily override the scale
//	void show(uint8_t scale);
//
//	/// Update all our controllers with the current led colors
//	void show() { show(m_Scale); }
//
//	/// clear the leds, optionally wiping the local array of data as well
//	/// @param writeData whether or not to write into the local data array as well
//	void clear(boolean writeData = false);
//
//	/// clear out the local data array
//	void clearData();
//
//	/// Set all leds on all controllers to the given color/scale
//	/// @param color what color to set the leds to
//	/// @param scale what brightness scale to show at
//	void showColor(const struct CRGB & color, uint8_t scale);
//
//	/// Set all leds on all controllers to the given color
//	/// @param color what color to set the leds to
//	void showColor(const struct CRGB & color) { showColor(color, m_Scale); }
//
//	/// Delay for the given number of milliseconds.  Provided to allow the library to be used on platforms
//	/// that don't have a delay function (to allow code to be more portable)
//	/// @param ms the number of milliseconds to pause for
//	//void delay(unsigned long ms);
//
//	/// Set a global color temperature.  Sets the color temperature for all added led strips, overriding whatever
//	/// previous color temperature those controllers may have had
//	/// @param temp A CRGB structure describing the color temperature
//	void setTemperature(const struct CRGB & temp);
//
//	/// Set a global color correction.  Sets the color correction for all added led strips,
//	/// overriding whatever previous color correction those controllers may have had.
//	/// @param correction A CRGB structure describin the color correction.
//	void setCorrection(const struct CRGB & correction);
//
//	/// Set the dithering mode.  Sets the dithering mode for all added led strips, overriding
//	/// whatever previous dithering option those controllers may have had.
//	/// @param ditherMode - what type of dithering to use, either BINARY_DITHER or DISABLE_DITHER
//	void setDither(uint8_t ditherMode = BINARY_DITHER);
//
//	/// Set the maximum refresh rate.  This is global for all leds.  Attempts to
//	/// call show faster than this rate will simply wait.  Note that the refresh rate
//	/// defaults to the slowest refresh rate of all the leds added through addLeds.  If
//	/// you wish to set/override this rate, be sure to call setMaxRefreshRate _after_
//	/// adding all of your leds.
//	/// @param refresh - maximum refresh rate in hz
//	/// @param constrain - constrain refresh rate to the slowest speed yet set
//	void setMaxRefreshRate(uint16_t refresh, bool constrain = false);
//
//	/// for debugging, will keep track of time between calls to countFPS, and every
//	/// nFrames calls, it will update an internal counter for the current FPS.
//	/// @todo make this a rolling counter
//	/// @param nFrames - how many frames to time for determining FPS
//	void countFPS(int nFrames = 25);
//
//	/// Get the number of frames/second being written out
//	/// @returns the most recently computed FPS value
//	uint16_t getFPS() { return m_nFPS; }
//
//	/// Get how many controllers have been registered
//	/// @returns the number of controllers (strips) that have been added with addLeds
//	int count();
//
//	/// Get a reference to a registered controller
//	/// @returns a reference to the Nth controller
//	CLEDController & operator[](int x);
//
//	/// Get the number of leds in the first controller
//	/// @returns the number of LEDs in the first controller
//	int size() { return (*this)[0].size(); }
//
//	/// Get a pointer to led data for the first controller
//	/// @returns pointer to the CRGB buffer for the first controller
//	CRGB *leds() { return (*this)[0].leds(); }
//};
//
//// WS2811@800khz 2 clocks, 5 clocks, 3 clocks
//template <uint8_t DATA_PIN, EOrder RGB_ORDER = RGB>
////class WS2812Controller800Khz : public ClocklessController<DATA_PIN, 2 * FMUL, 5 * FMUL, 3 * FMUL, RGB_ORDER> {};
//
////template<uint8_t DATA_PIN, EOrder RGB_ORDER> class WS2812B : public WS2812Controller800Khz<DATA_PIN, RGB_ORDER> {};
//
//
//
//CFastLED FastLED;