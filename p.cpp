#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(const string& accNumber, const string& accHolder, double initialBalance)
        : accountNumber(accNumber), accountHolder(accHolder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
             cout<< "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    void displayBalance() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    string accNumber;
    string accHolder;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNumber;

    cout << "Enter account holder's name: ";
    cin.ignore(); // Clear newline left in the input buffer
    getline(cin, accHolder);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accNumber, accHolder, initialBalance);

    int choice;
    double amount;

    do {
        cout << "Bank Account Menu:" << endl;
        cout << "1. Display Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.displayBalance();
                break;
            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." <<endl;
        }
    } while (choice != 4);

    return 0;
}
