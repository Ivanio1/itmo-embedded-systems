#include "calculator.h"
#include "inttypes.h"
#include "oled.h"
#include "kb.h"

void write_number(int64_t number) {
	char charsFromA[18] = { 0 };
	uint16_t index = 0;
	uint16_t isMinus = 0;
	if (number < 0) {
		isMinus = 1;
		number = number * -1;
	}
	while (number > 0) {
		charsFromA[index] = number % 10 + '0';
		number = number / 10;
		index++;
	}
	if (index == 0) {
		index = 1;
		charsFromA[0] = '0';
	}
	if (isMinus == 1) {
		charsFromA[index] = '-';
		index++;
	}
	while (index > 0) {
		index--;
		oled_WriteChar(charsFromA[index], Font_7x10, White);
	}
}

void run(void) {
	oled_Reset();
	oled_WriteString("Hello there!", Font_11x18, White);
	oled_UpdateScreen();

	int64_t a = 0, b = 0, lenA = 0, lenB = 0;
	uint8_t rows[4] = {ROW4, ROW3, ROW2, ROW1}, checkedRow;
	enum Key newKey = NOT_PRESSED;
	enum Mode mode = FIRST_OPERAND;
	enum Operation operation = PLUS;
	char charsFromA[18];

	while (1) {
		for (int i = 0; i < 4; i++) {
			checkedRow = Check_Row(rows[i]);
			switch (i) {
			case 0:
				switch (checkedRow) {
				case 0x01:
					newKey = FUN;
					break;

				case 0x02:
					newKey = EQ;
					break;

				case 0x04:
					newKey = ZERO;
					break;
				}
				break;

			case 1:
				switch (checkedRow) {
				case 0x01:
					newKey = THREE;
					break;

				case 0x02:
					newKey = TWO;
					break;

				case 0x04:
					newKey = ONE;
					break;
				}
				break;

			case 2:
				switch (checkedRow) {
				case 0x01:
					newKey = SIX;
					break;

				case 0x02:
					newKey = FIVE;
					break;

				case 0x04:
					newKey = FOUR;
					break;
				}
				break;

			case 3:
				switch (checkedRow) {
				case 0x01:
					newKey = NINE;
					break;

				case 0x02:
					newKey = EIGHT;
					break;

				case 0x04:
					newKey = SEVEN;
					break;
				}
				break;

			}
		}

		if (newKey != NOT_PRESSED) {
			switch (mode) {
			case FIRST_OPERAND:
				if (lenA == 0) {
					oled_Reset();
				}
				switch (newKey) {
				case EQ:
					break;
				case FUN:
					if (lenA == 0) {
						oled_SetCursor(0, 0);
						oled_WriteChar('0', Font_7x10, White);
					}
					operation = PLUS;
					mode = FUNCTION;
					oled_SetCursor(0, 10);
					oled_WriteChar('+', Font_7x10, White);
					break;
				default:
					lenA++;
					a *= 10;
					a += newKey;
					oled_WriteChar(newKey + '0', Font_7x10, White);

					break;
				}
				break;
			case FUNCTION:
				switch (newKey) {
				case EQ:
					switch (operation) {
					case PLUS:
						break;
					case MINUS:
						a *= -1;
						break;
					case MUL:
						a = a * a;
						break;
					}
					oled_Reset();
					write_number(a);
					operation = PLUS;
					oled_SetCursor(0, 10);
					oled_WriteChar('+', Font_7x10, White);
					break;
				case FUN:
					operation = (operation + 1) % 3;
					oled_SetCursor(0, 10);
					switch (operation) {
					case PLUS:
						oled_WriteChar('+', Font_7x10, White);
						break;
					case MINUS:
						oled_WriteChar('-', Font_7x10, White);
						break;
					case MUL:
						oled_WriteChar('*', Font_7x10, White);
						break;
					}
					break;
				default:
					lenB = 1;
					b = newKey;
					mode = SECOND_OPERAND;
					oled_SetCursor(0, 20);
					oled_WriteChar('0' + newKey, Font_7x10, White);
					break;
				}
				break;
			case SECOND_OPERAND:
				switch (newKey) {
				case EQ:

				case FUN:
					switch (operation) {
					case PLUS:
						a += b;
						break;
					case MINUS:
						a -= b;
						break;
					case MUL:
						a *= b;
						break;
					}

					oled_Reset();
					write_number(a);
					operation = PLUS;
					mode = FUNCTION;
					oled_SetCursor(0, 10);
					oled_WriteChar('+', Font_7x10, White);
					break;
				default:
					lenB++;
					b *= 10;
					b += newKey;
					oled_WriteChar(newKey + '0', Font_7x10, White);
					break;

				}
				break;

			}
			oled_UpdateScreen();
		}

		newKey = NOT_PRESSED;

		HAL_Delay(500);
	}
}



