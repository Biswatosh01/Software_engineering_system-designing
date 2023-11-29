#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
public:
    string accountNumber;
    string accountHolderName;
    double balance;

    Account(string number, string holderName, double initialBalance)
        : accountNumber(number), accountHolderName(holderName), balance(initialBalance) {}

    void displayBalance() {
        cout << "Account Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit Successful. New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful. New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }
};

class Bank {
public:
    vector<Account> accounts;

    void createAccount(string accountNumber, string accountHolderName, double initialBalance) {
        Account newAccount(accountNumber, accountHolderName, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully." << endl;
    }

    void displayAllAccounts() {
        cout << "All Accounts:" << endl;
        for (const auto& account : accounts) {
            cout << "Account Number: " << account.accountNumber << ", Holder: " << account.accountHolderName << ", Balance: $" << account.balance << endl;
        }
    }

    Account* findAccount(string accountNumber) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;

    // Creating sample accounts
    bank.createAccount("123456", "John Doe", 1000.0);
    bank.createAccount("789012", "Jane Smith", 2000.0);

    // Displaying all accounts
    bank.displayAllAccounts();

    // Performing transactions
    string accountNumber = "123456";
    Account* johnsAccount = bank.findAccount(accountNumber);

    if (johnsAccount != nullptr) {
        johnsAccount->displayBalance();
        johnsAccount->deposit(500.0);
        johnsAccount->withdraw(200.0);
    } else {
        cout << "Account not found." << endl;
    }

    return 0;
}
