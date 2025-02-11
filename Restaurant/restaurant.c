#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 50
#define MAX_NAME_LENGTH 50
#define MAX_MENU_ITEMS 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int tableNumber;
    int numberOfPeople;
} Reservation;

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    float price;
} MenuItem;

Reservation reservations[MAX_CUSTOMERS];
MenuItem menu[MAX_MENU_ITEMS];
int reservationCount = 0;
int menuCount = 0;

void addReservation() {
    if (reservationCount >= MAX_CUSTOMERS) {
        printf("Reservation list is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %49[^"]", reservations[reservationCount].name);
    printf("Enter table number: ");
    scanf("%d", &reservations[reservationCount].tableNumber);
    printf("Enter number of people: ");
    scanf("%d", &reservations[reservationCount].numberOfPeople);
    reservationCount++;
    printf("Reservation added successfully.\n");
}

void viewReservations() {
    if (reservationCount == 0) {
        printf("No reservations available.\n");
        return;
    }
    for (int i = 0; i < reservationCount; i++) {
        printf("%d. Name: %s, Table: %d, People: %d\n", i + 1, reservations[i].name, reservations[i].tableNumber, reservations[i].numberOfPeople);
    }
}

void cancelReservation() {
    if (reservationCount == 0) {
        printf("No reservations to cancel.\n");
        return;
    }
    int index;
    printf("Enter reservation number to cancel: ");
    scanf("%d", &index);
    if (index < 1 || index > reservationCount) {
        printf("Invalid reservation number.\n");
        return;
    }
    for (int i = index - 1; i < reservationCount - 1; i++) {
        reservations[i] = reservations[i + 1];
    }
    reservationCount--;
    printf("Reservation cancelled successfully.\n");
}

void addMenuItem() {
    if (menuCount >= MAX_MENU_ITEMS) {
        printf("Menu is full.\n");
        return;
    }
    printf("Enter item name: ");
    scanf(" %49[^"]", menu[menuCount].itemName);
    printf("Enter price: ");
    scanf("%f", &menu[menuCount].price);
    menuCount++;
    printf("Menu item added successfully.\n");
}

void viewMenu() {
    if (menuCount == 0) {
        printf("No menu items available.\n");
        return;
    }
    for (int i = 0; i < menuCount; i++) {
        printf("%d. Item: %s, Price: $%.2f\n", i + 1, menu[i].itemName, menu[i].price);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nRestaurant Management System\n");
        printf("1. Add Reservation\n");
        printf("2. View Reservations\n");
        printf("3. Cancel Reservation\n");
        printf("4. Add Menu Item\n");
        printf("5. View Menu\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                addMenuItem();
                break;
            case 5:
                viewMenu();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
