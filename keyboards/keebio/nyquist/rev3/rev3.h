#pragma once

#include "nyquist.h"
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
	L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
	L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
	L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
	L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45 \
	) \
	{ \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 }, \
		{ L40, L41, L42, L43, L44, L45 }, \
		{ R00, R01, R02, R03, R04, R05 }, \
		{ R10, R11, R12, R13, R14, R15 }, \
		{ R20, R21, R22, R23, R24, R25 }, \
		{ R30, R31, R32, R33, R34, R35 }, \
		{ R40, R41, R42, R43, R44, R45 } \
	}

#define LAYOUT_ortho_4x12( \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35 \
    ) \
	{ \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 }, \
		{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
		{ R00, R01, R02, R03, R04, R05 }, \
		{ R10, R11, R12, R13, R14, R15 }, \
		{ R20, R21, R22, R23, R24, R25 }, \
		{ R30, R31, R32, R33, R34, R35 }, \
		{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
	}
	
#define LAYOUT_ortho_5x6( \
	K00, K01, K02, K03, K04, K05, \
	K10, K11, K12, K13, K14, K15, \
	K20, K21, K22, K23, K24, K25, \
	K30, K31, K32, K33, K34, K35, \
    K40, K41, K42, K43, K44, K45 \
	) \
	{ \
		{ K00, K01, K02, K03, K04, K05 }, \
		{ K10, K11, K12, K13, K14, K15 }, \
		{ K20, K21, K22, K23, K24, K25 }, \
		{ K30, K31, K32, K33, K34, K35 }, \
		{ K40, K41, K42, K43, K44, K45 } \
	}
#define LAYOUT_ortho_5x12 LAYOUT
