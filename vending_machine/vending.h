#ifndef VENDING_H
#define VENDING_H

typedef struct {
    char name[30];
    float price;
    int quantity;
} Product;

void display_menu(Product products[], int count);
int insert_coin(float *balance);
int select_product(Product products[], int count, float *balance);
void dispense(Product *product, float *balance);

#endif