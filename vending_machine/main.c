#include <stdio.h>
#include "vending.h"

typedef enum {
    IDLE,
    ACCEPTING_COINS,
    SELECTING,
    DISPENSING
} State;

int main() {
    Product products[5] = {
        {"Soda", 1.00, 5},
        {"Chips", 0.75, 5},
        {"Candy", 0.50, 5},
        {"Water", 0.65, 5},
        {"Juice", 1.25, 5}
    };

    State state = IDLE;
    float balance = 0;
    int selection;

    while (1) {
        switch (state) {

            case IDLE:
                printf("\nWelcome! (1 = start, 0 = exit): ");
                int input;
                scanf("%d", &input);

                if (input == 0) return 0;
                state = ACCEPTING_COINS;
                break;

            case ACCEPTING_COINS:
                while (insert_coin(&balance));
                state = SELECTING;
                break;

            case SELECTING:
                selection = select_product(products, 5, &balance);
                if (selection >= 0)
                    state = DISPENSING;
                else
                    state = IDLE;
                break;

            case DISPENSING:
                dispense(&products[selection], &balance);
                state = IDLE;
                break;
        }
    }

    return 0;
}
