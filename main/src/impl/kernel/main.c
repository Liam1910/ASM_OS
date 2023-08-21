#include "functions.h"

extern void restart();
extern void keyboard32();
extern void keyboard64();

extern long long examples();


void kernel_main() {
    print_clear();
    print_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print("Welcome to my 64 Bit Kernel!\n\n");
    print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print("_________________________________________________\n");
    delay(100);
    print("|      This 64 Bit Kernel was coded by Liam     |\n");
    delay(100);
    print("|                                               |\n");
    delay(100);
    print("|   It was very fun and i hope you like it :)   |\n");
    delay(100);
    print("|                                               |\n");
    delay(100);
    print("|                                               |\n");
    delay(100);
    print("|  In 10 Seconds Restarting your Computer, Bye  |\n");
    delay(100);
    print("|_______________________________________________|\n\n");


    char* num[1000000];
    longLongToString(examples(), num);
    if (num == '0') {
        print("Error code: 0");
    } else {
        print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
        print("Error code: ");
        print(num);
    }
    delay(2000);
    keyboard64();
    print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    delay(10000);
    print("\n\nRESTARTING!");
    delay(500);
    restart();
}