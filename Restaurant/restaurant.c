#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_ORDERS 10

// Structure for Menu Item
typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

// Structure for Order
typedef struct {
    int itemId;
    int quantity;
} Order;

// Function to display menu
void displayMenu(MenuItem menu[], int size) {
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to take order
int takeOrder(Order orders[], int orderCount, MenuItem menu[], int menuSize) {
    int itemId, quantity;
    printf("\nEnter Item ID to order (or 0 to finish): ");
    scanf("%d", &itemId);
    
    while (itemId != 0) {
        int valid = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].id == itemId) {
                valid = 1;
                break;
            }
        }
        if (!valid) {
            printf("Invalid Item ID. Try again.\n");
        } else {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            
            if (orderCount < MAX_ORDERS) {
                orders[orderCount].itemId = itemId;
                orders[orderCount].quantity = quantity;
                orderCount++;
            } else {
                printf("Order limit reached!\n");
            }
        }
        printf("\nEnter Item ID to order (or 0 to finish): ");
        scanf("%d", &itemId);
    }
    return orderCount;
}

// Function to calculate and print bill
void printBill(Order orders[], int orderCount, MenuItem menu[], int menuSize) {
    float total = 0;
    printf("\nBill:\n");
    for (int i = 0; i < orderCount; i++) {
        for (int j = 0; j < menuSize; j++) {
            if (menu[j].id == orders[i].itemId) {
                float cost = orders[i].quantity * menu[j].price;
                printf("%s x %d = $%.2f\n", menu[j].name, orders[i].quantity, cost);
                total += cost;
                break;
            }
        }
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    int choice;
    printf("Welcome to the Restaurant Ordering System!\n");
    printf("1. View Menu\n2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice != 1) {
        printf("Thank you! Have a great day!\n");
        return 0;
    }
    
    MenuItem menu[MAX_ITEMS] = {
        {1, "Burger", 5.99},
        {2, "Pizza", 8.99},
        {3, "Pasta", 7.49},
        {4, "Salad", 4.99},
        {5, "Soda", 1.99}
    };
    
    Order orders[MAX_ORDERS];
    int orderCount = 0;
    
    displayMenu(menu, MAX_ITEMS);
    orderCount = takeOrder(orders, orderCount, menu, MAX_ITEMS);
    printBill(orders, orderCount, menu, MAX_ITEMS);
    
    return 0;
}
