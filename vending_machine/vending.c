#include <stdio.h>
#include "vending.h"

void display_menu(Product products[], int count) {
    printf("\n--- MENU ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f (Qty: %d)\n",
               i + 1,
               products[i].name,
               products[i].price,
               products[i].quantity);
    }
}

int insert_coin(float *balance) {
    float coin;

    printf("Insert coin (0.25, 0.50, 1.00) or 0 to stop: ");
    scanf("%f", &coin);

    if (coin == 0)
        return 0;

    if (coin == 0.25 || coin == 0.50 || coin == 1.00) {
        *balance += coin;
        printf("Balance: $%.2f\n", *balance);
        return 1;
    } else {
        printf("Invalid coin\n");
        return 1;
    }
}

int select_product(Product products[], int count, float *balance) {
    int choice;

    display_menu(products, count);
    printf("Select product: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid selection\n");
        return -1;
    }

    Product *p = &products[choice - 1];

    if (p->quantity <= 0) {
        printf("Out of stock\n");
        return -1;
    }

    if (*balance < p->price) {
        printf("Not enough balance\n");
        return -1;
    }

    return choice - 1;
}

void dispense(Product *product, float *balance) {
    product->quantity--;
    *balance -= product->price;

    printf("Dispensing %s...\n", product->name);

    if (*balance > 0) {
        printf("Change returned: $%.2f\n", *balance);
        *balance = 0;
    }
}