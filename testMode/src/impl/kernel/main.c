#include "functions.h"

extern long long errCode();

extern void restart();


void kernel_main() {
    print_clear();
    print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print("Welcome to Test Mode\n\n");


    print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    char* str[1000000];
    longLongToString(errCode(), str);
    print("Error code: ");
    print(str);
    delay(4000);
    print("Restarting your PC in 5 seconds");
    delay(5000);
    restart();

}

unsigned char customChar[] = {
    0x0A, // ->  # #
    0x0B, // -> ## #
    0x0C, // ->   ##
    0x0D, // -> # ##
    0x0E, // ->  ###
    0x0F, // -> ####
    0x00, // -> '\n'
    0x01, // -> #   
    0x02, // ->  #
    0x03  // -> ##
};

void kernel_main1() {
    print_clear();
    print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    print("Custom Character:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 8; j++) {
            if (customChar[i] & (1 << j)) {
                print("#");
            } else {
                print(" ");
            }
        }
        print("\n");
    }

    delay(10000);
    restart();

}