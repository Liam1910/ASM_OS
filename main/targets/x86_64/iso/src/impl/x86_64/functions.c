#include "functions.h"


// print.h / print.c
const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;


void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
} // clears the row that you are on


void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
} // clears the howle screen (all that was printed out)

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
} // basicly \n


void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
} // Prints a single character


void print(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }

        print_char(character);
    }
} // prints string (char sequens)


void print_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
} // sets the foreground and background color



// delay.h / delay.c
void delay(int milliseconds) {
	int count = milliseconds * 1000000 / 8;
	while (count--) {
		asm("nop");
	}
} //sets a delay (arround 1000 = 1s, 100 = 100ms and so on)


void reverseString(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void longLongToString(long long num, char* str) {
    int isNegative = 0;
    int index = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    do {
        str[index++] = (num % 10) + '0';
        num /= 10;
    } while (num != 0);

    if (isNegative) {
        str[index++] = '-';
    }

    str[index] = '\0';

    reverseString(str, index);
}