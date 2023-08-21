#include "functions.h"

extern long long examples();

extern void restart();


void kernel_main() {
    print_clear();
    print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print("Welcome to Safe Mode\n\n");


    print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    char* str[1000000];
    longLongToString(examples(), str);
    print("Error code: ");
    print(str);

    delay(10000);
    restart();
}