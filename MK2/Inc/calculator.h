#ifndef Calculator
#define Calculator

enum Mode {
	FIRST_OPERAND,
	FUNCTION,
	SECOND_OPERAND
};

enum Key {
	ZERO = 0,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	EQ,
	FUN,
	NOT_PRESSED
};

enum Operation {
	PLUS = 0,
	MINUS,
	MUL
};

void run(void);

#endif
