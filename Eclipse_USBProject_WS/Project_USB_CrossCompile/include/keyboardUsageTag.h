/*
 *  keyboardUsageTag.h
 *
 *  Created on: 22 Oca 2026
 *      Author: bahri
 */

#ifndef KEYBOARDUSAGETAG_H_
#define KEYBOARDUSAGETAG_H_

typedef enum
{
	KEY_A = 0x4u,
	KEY_B = 0x5u,
	KEY_C = 0x6u,
	KEY_D = 0x7u,
	KEY_E = 0x8u,
	KEY_F = 0x9u,
	KEY_G = 0xAu,
	KEY_H = 0xBu,
	KEY_I = 0xCu,
	KEY_J = 0xDu,
	KEY_K = 0xEu,
	KEY_L = 0xFu,
	KEY_M = 0x10u,
	KEY_N = 0x11u,
	KEY_O = 0x12u,
	KEY_P = 0x13u,
	KEY_Q = 0x14u,
	KEY_R = 0x15u,
	KEY_S = 0x16u,
	KEY_T = 0x17u,
	KEY_U = 0x18u,
	KEY_V = 0x19u,
	KEY_W = 0x1Au,
	KEY_X = 0x1Bu,
	KEY_Y = 0x1Cu,
	KEY_Z = 0x1Du,
	KEY_1 = 0x1Eu,
	KEY_2 = 0x1Fu,
	KEY_3 = 0x20u,
	KEY_4 = 0x21u,
	KEY_5 = 0x22u,
	KEY_6 = 0x23u,
	KEY_7 = 0x24u,
	KEY_8 = 0x25u,
	KEY_9 = 0x26u,
	KEY_0 = 0x27u,
	KEY_F1 = 0x3A,
	KEY_F2 = 0x3B,
	KEY_F3 = 0x3C,
	KEY_F4 = 0x3D,
	KEY_F5 = 0x3E,
	KEY_F6 = 0x3F,
	KEY_F7 = 0x40,
	KEY_F8 = 0x41,
	KEY_F9 = 0x42,
	KEY_F10 = 0x43,
	KEY_F11 = 0x44,
	KEY_F12 = 0x45,
	KEY_F13 = 0x68,
	KEY_F14 = 0x69,
	KEY_F15 = 0x6A,
	KEY_F16 = 0x6B,
	KEY_F17 = 0x6C,
	KEY_F18 = 0x6D,
	KEY_F19 = 0x6E,
	KEY_F20 = 0x6F,
	KEY_F21 = 0x70,
	KEY_F22 = 0x71,
	KEY_F23 = 0x72,
	KEY_F24 = 0x73
}KeyCode_type;

typedef enum
{
	MOD_NO 			= (uint8)0x00,
	MOD_CTRL_LEFT 	= (uint8)0x01,
	MOD_SHIFT_LEFT 	= (uint8)0x02,
	MOD_ALT_LEFT 	= (uint8)0x04,
	MOD_GUI_LEFT 	= (uint8)0x08,
	MOD_CTRL_RIGHT 	= (uint8)0x10,
	MOD_SHIFT_RIGHT = (uint8)0x20,
	MOD_ALT_RIGHT 	= (uint8)0x40,
	MOD_GUI_RIGHT 	= (uint8)0x80
}ModifierCode_type;

#endif /* KEYBOARDUSAGETAG_H_ */
