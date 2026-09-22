#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void displayError(string message);
void displayMenu();
int inputQuantity();
double processPurchase(int choice, double totalPayment);
int processPayment(double totalPayment);
int runShop(int choice, double totalPayment);

int main() {
    cout << fixed << setprecision(2);
    return runShop(0, 0.00);
}



// Function Category: Display Functions

void displayError(string message) {
    cout << "Error: " << message << "\n";
}

void displayMenu() {
    cout << "********************\n";
    cout << "Welcome to Mike Shop\n";
    cout << "********************\n";
    cout << "1. Soap        RM3.50\n";
    cout << "2. Shampoo     RM6.80\n";
    cout << "3. Detergent   RM11.20\n";
    cout << "4. Payment\n";
}

int inputQuantity() {
    int quantity;
    cout << "Enter quantity: ";
    if (!(cin >> quantity) || quantity <= 0) {
        displayError("Invalid quantity.");
        return -1;
    }
    return quantity;
}

double processPurchase(int choice, double totalPayment) {
    double price;
    string itemName;

    if (choice == 1) {
        price = 3.50;
        itemName = "Soap";
    } else if (choice == 2) {
        price = 6.80;
        itemName = "Shampoo";
    } else {
        price = 11.20;
        itemName = "Detergent";
    }

    int quantity = inputQuantity();
    if (quantity < 0) {
        return -1;
    }

    double cost = price * quantity;
    cout << "Total price for " << quantity << " " << itemName
         << " is RM" << cost << "\n\n";
    return totalPayment + cost;
}

int processPayment(double totalPayment) {
    double payment;
    cout << "Total payment is RM" << totalPayment << "\n";

    while (true) {
        cout << "Your payment:RM";
        if (!(cin >> payment)) {
            displayError("Invalid payment. Please enter a number.");
            return 1;
        }

        if (payment >= totalPayment) {
            double balance = payment - totalPayment;
            cout << "Payment received: RM" << payment << "\n";
            cout << "Thank you, your balance is RM" << balance << "\n";
            return 0;
        }

        displayError("Not enough. Make a new payment.");
    }
}

int runShop(int choice, double totalPayment) {
    totalPayment = 0.00;

    do {
        displayMenu();
        cout << "Enter your choice (1/2/3/4):";
        if (!(cin >> choice)) {
            displayError("Invalid input. Please enter a number.");
            return 1;
        }

        if (choice >= 1 && choice <= 3) {
            totalPayment = processPurchase(choice, totalPayment);
            if (totalPayment < 0) {
                return 1;
            }
        } else if (choice == 4) {
            return processPayment(totalPayment);
        } else {
            displayError("Invalid choice! Please try again.");
            cout << "\n";
        }
    } while (true);
}