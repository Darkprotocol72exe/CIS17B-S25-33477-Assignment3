// Hugo Willis 
// CIS-17B
// LMD: 03/23/25

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

// Exception for negative deposit attempts
class NegativeDepositException : public exception {
public:
    const char* what() const noexcept override {
        return "Negative deposit is not allowed.";
    }
};

// Exception for overdraw attempts
class OverdrawException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds for withdrawal.";
    }
};

// Exception for invalid operations on a closed account
class InvalidAccountOperationException : public exception {
public:
    const char* what() const noexcept override {
        return "Operation not allowed on a closed account.";
    }
};

class BankAccount {
private:
    string accountNumber;
    double balance;
    bool isActive;

public:
    // Constructor
    BankAccount(const string& accNum, double initBalance)
        : accountNumber(accNum), balance(initBalance), isActive(true) {}

    // Deposit funds into the account
    void deposit(double amount) {
        if (!isActive) {
            throw InvalidAccountOperationException();
        }
        if (amount < 0) {
            throw NegativeDepositException();
        }
        balance += amount;
    }

    // Withdraw funds from the account
    void withdraw(double amount) {
        if (!isActive) {
            throw InvalidAccountOperationException();
        }
        if (amount > balance) {
            throw OverdrawException();
        }
        balance -= amount;
    }

    // Get the current balance
    double getBalance() const {
        return balance;
    }

    // Close the account
    void closeAccount() {
        isActive = false;
    }
};

int main() {
    // Create an instance of BankAccount using a smart pointer
    auto account = make_unique<BankAccount>("123456", 1000.0);
    int choice = 0;
    double amount = 0.0;

    while (true) {
        cout << "--- Norco Bank ---" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Close Account and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        try {
            if (choice == 1) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
                cout << "Deposit successful. New balance: " << account->getBalance() << endl;
            }
            else if (choice == 2) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                cout << "Withdrawal successful. New balance: " << account->getBalance() << endl;
            }
            else if (choice == 3) {
                cout << "Current balance: " << account->getBalance() << endl;
            }
            else if (choice == 4) {
                account->closeAccount();
                cout << "Account closed. Exiting program." << endl;
                break;
            }
            else {
                cout << "Invalid option. Please choose between 1 and 4." << endl;
            }
        }
        catch (const NegativeDepositException& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (const OverdrawException& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (const InvalidAccountOperationException& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (const exception& ex) {
            cout << "Unhandled exception: " << ex.what() << endl;
        }
    }
    
    return 0;
}
