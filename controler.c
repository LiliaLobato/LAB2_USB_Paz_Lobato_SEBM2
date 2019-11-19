#include "controler.h"

#define KEYBOARD_DELAY 900000U
#define MOUSE_DELAY 10000U

static dir_t direction = IZQ;
static state_t state = STATE_0;

static int8_t x = 0U;
static int8_t y = 0U;

void delay(uint32_t max) {
	uint32_t delay_counter = 0;
	while (max > delay_counter)
		delay_counter++;
}

flag_t squareTest(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0:
		/* Move right */
		bufferMouseOrKey[0] = 1U;
		bufferMouseOrKey[2] = 2U;
		bufferMouseOrKey[3] = 0U;

		x++;
		if (x > 99U) {
			state++;
		}
		break;

	case STATE_1:
		/* Move down */
		bufferMouseOrKey[0] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = 2U;
		y++;
		if (y > 99U) {
			state++;
		}
		break;
	case STATE_2:
		/* Move left */
		bufferMouseOrKey[0] = 1U;
		bufferMouseOrKey[2] = (uint8_t) (-2);
		bufferMouseOrKey[3] = 0U;
		x--;
		if (x < 2U) {
			state++;
		}
		break;
	case STATE_3:
		/* Move up */
		bufferMouseOrKey[0] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = (uint8_t) (-2);
		y--;
		if (y < 2U) {
			state = STATE_0;
			flag = COMPLETE;
		}
		break;
	default:
		break;
	}

	return flag;
}

flag_t openPaint(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;
	switch (state) {
	case STATE_0: {
		/* WINDOWS + R*/
		bufferMouseOrKey[3] = KEY_LEFT_GUI;
		bufferMouseOrKey[4] = KEY_R;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_1: {
		/* write M*/
		bufferMouseOrKey[3] = KEY_M;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_2: {
		/* write S*/
		bufferMouseOrKey[3] = KEY_S;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_3: {
		/* write P*/
		bufferMouseOrKey[3] = KEY_P;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_4: {
		/* write A*/
		bufferMouseOrKey[3] = KEY_A;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_5: {
		/* write I*/
		bufferMouseOrKey[3] = KEY_I;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_6: {
		/* write N*/
		bufferMouseOrKey[3] = KEY_N;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_7: {
		/* write T*/
		bufferMouseOrKey[3] = KEY_T;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_8:
		/* ENTER*/
		bufferMouseOrKey[3] = KEY_ENTER;
		delay(KEYBOARD_DELAY);
		break;
	case STATE_9:
		delay(10 * KEYBOARD_DELAY);
		flag = COMPLETE;
		break;
	default:
		break;
	}

	if (state == STATE_9) {
		state = STATE_0;
	} else {
		state++;
	}

	return flag;
}

flag_t drawFigure(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0:
		/* Move right */
		bufferMouseOrKey[1] = 1U;
		bufferMouseOrKey[2] = 2U;
		bufferMouseOrKey[3] = 0U;

		x++;
		if (x > 99U) {
			state++;
		}
		break;

	case STATE_1:
		/* Move down */
		bufferMouseOrKey[1] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = 2U;
		y++;
		if (y > 99U) {
			state++;
		}
		break;
	case STATE_2:
		/* Move left */
		bufferMouseOrKey[1] = 1U;
		bufferMouseOrKey[2] = (uint8_t) (-2);
		bufferMouseOrKey[3] = 0U;
		x--;
		if (x < 2U) {
			state++;
		}
		break;
	case STATE_3:
		/* Move up */
		bufferMouseOrKey[1] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = (uint8_t) (-2);
		y--;
		if (y < 2U) {
			state++;
		}
		break;
	case STATE_4:
		/* CLICK */
		bufferMouseOrKey[0] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = 0U;
		y--;
		if (y < 2U) {
			state = STATE_0;
			flag = COMPLETE;
		}
		break;
	default:
		break;
	}

	return flag;
}

flag_t openNotepad(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;
	switch (state) {
	case STATE_0: {
		/* WINDOWS + R*/
		bufferMouseOrKey[3] = KEY_LEFT_GUI;
		bufferMouseOrKey[4] = KEY_R;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_1: {
		/* write N*/
		bufferMouseOrKey[3] = KEY_N;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_2: {
		/* write O*/
		bufferMouseOrKey[3] = KEY_O;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_3: {
		/* write T*/
		bufferMouseOrKey[3] = KEY_T;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_4: {
		/* write E*/
		bufferMouseOrKey[3] = KEY_E;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_5: {
		/* write P*/
		bufferMouseOrKey[3] = KEY_P;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_6: {
		/* write A*/
		bufferMouseOrKey[3] = KEY_A;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_7: {
		/* write D*/
		bufferMouseOrKey[3] = KEY_D;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_8:
		/* ENTER*/
		bufferMouseOrKey[3] = KEY_ENTER;
		delay(KEYBOARD_DELAY);
		break;
	case STATE_9:
		delay(4 * KEYBOARD_DELAY);
		//notepad 1
		if (IZQ == direction) {
			/* CTRL + <- */
			bufferMouseOrKey[3] = KEY_LEFT_GUI;
			bufferMouseOrKey[4] = KEY_LEFTARROW;
			delay(KEYBOARD_DELAY);
			break;
		} else { //notepad 2
			/* CTRL + ->*/
			bufferMouseOrKey[3] = KEY_LEFT_GUI;
			bufferMouseOrKey[4] = KEY_RIGHTARROW;
			delay(KEYBOARD_DELAY);
			break;
		}
	case STATE_10:
		delay(10 * KEYBOARD_DELAY);
		break;
	default:
		break;
	}

	if (state == STATE_10 && direction == IZQ) {
		direction = DER;
		state = STATE_0;
	} else if (state == STATE_10 && direction == DER) {
		state = STATE_0;
		direction = IZQ;
		flag = COMPLETE;
	} else {
		state++;
	}

	return flag;
}

flag_t moveLeft(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0:
		/* Move left */
		bufferMouseOrKey[1] = 0U;
		bufferMouseOrKey[2] = (uint8_t) (-2);
		bufferMouseOrKey[3] = 0U;
		delay(MOUSE_DELAY);
		x++;
		if (x > 99U) {
			state++;
		}
		break;
	case STATE_1:
		/* Click */
		bufferMouseOrKey[1] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = 0U;
		delay(MOUSE_DELAY);
		state++;
		break;
	case STATE_2:
		delay(10 * KEYBOARD_DELAY);
		state = STATE_0;
		flag = COMPLETE;
		break;
	default:
		break;
	}

	return flag;
}

flag_t writeText(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0: {
		/*  write H*/
		bufferMouseOrKey[3] = KEY_H;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_1: {
		/*  write A*/
		bufferMouseOrKey[3] = KEY_A;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_2: {
		/*  write I*/
		bufferMouseOrKey[3] = KEY_I;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_3: {
		/*  write L*/
		bufferMouseOrKey[3] = KEY_L;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_4: {
		/*  SPACEBAR */
		bufferMouseOrKey[3] = KEY_SPACEBAR;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_5: {
		/*  write P*/
		bufferMouseOrKey[3] = KEY_P;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_6: {
		/*  write I*/
		bufferMouseOrKey[3] = KEY_I;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_7: {
		/*  write Z*/
		bufferMouseOrKey[3] = KEY_Z;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_8: {
		/*  write A*/
		bufferMouseOrKey[3] = KEY_A;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_9: {
		/*  write N*/
		bufferMouseOrKey[3] = KEY_N;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_10: {
		/*  write O*/
		bufferMouseOrKey[3] = KEY_O;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_12:
		delay(10 * KEYBOARD_DELAY);
		flag = COMPLETE;
		break;
	default:
		break;
	}

	if (state == STATE_12) {
		state = STATE_0;
	} else {
		state++;
	}

	return flag;
}

flag_t moveRight(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0:
		/* Move right */
		bufferMouseOrKey[1] = 0U;
		bufferMouseOrKey[2] = 2U;
		bufferMouseOrKey[3] = 0U;
		delay(MOUSE_DELAY);
		x--;
		if (x < 2U) {
			state++;
		}
		break;
	case STATE_1:
		/* Click */
		bufferMouseOrKey[1] = 1U;
		bufferMouseOrKey[2] = 0U;
		bufferMouseOrKey[3] = 0U;
		delay(MOUSE_DELAY);
		state++;
		break;
	case STATE_2:
		delay(5 * KEYBOARD_DELAY);
		state = STATE_0;
		flag = COMPLETE;
		break;
	default:
		break;
	}

	return flag;
}

flag_t copyText(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0: {
		/* CRTL */
		bufferMouseOrKey[3] = KEY_LEFTCONTROL;
		/* DependS on the language of the computer, it could be KEY_A or KEY_E*/
		bufferMouseOrKey[4] = KEY_E;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_2:
		delay(10 * KEYBOARD_DELAY);
		break;
	case STATE_3: {
		/*  CTRL + C*/
		bufferMouseOrKey[3] = KEY_LEFTCONTROL;
		bufferMouseOrKey[4] = KEY_C;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_4:
		delay(10 * KEYBOARD_DELAY);
		flag = COMPLETE;
		break;
	default:
		break;
	}

	if (state == STATE_4) {
		state = STATE_0;
	} else {
		state++;
	}

	return flag;
}

flag_t pasteText(uint8_t* bufferMouseOrKey) {
	static flag_t flag = INCOMPLETE;

	switch (state) {
	case STATE_0: {
		bufferMouseOrKey[3] = KEY_LEFTCONTROL;
		bufferMouseOrKey[4] = KEY_V;
		delay(KEYBOARD_DELAY);
	}
		break;
	case STATE_2:
		delay(10 * KEYBOARD_DELAY);
		flag = COMPLETE;
		break;
	default:
		break;
	}

	if (state == STATE_2) {
		state = STATE_0;
	} else {
		state++;
	}

	return flag;
}
