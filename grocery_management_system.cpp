//  grocery management
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    Item(string name, double price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

class Grocery {
private:
    vector<Item> products;

public:

    void addProduct(string name, double price, int quantity) {
        products.push_back(Item(name, price, quantity));
        cout << "Item added successfully." << endl;
    }

    void listProducts() {
        if (products.empty()) {
            cout << "No products available." << endl;
            return;
        }

        cout << "\nAvailable Products:" << endl;
        cout << "-------------------" << endl;
        cout << "Name\t\tPrice\t\tQuantity" << endl;
        for (const Item& product : products) {
            cout << product.name << "\t\tRs." << product.price << "\t\t" << product.quantity << endl;
        }
    }

    void sellProduct(string name, int quantity) {
        for (Item& product : products) {
            if (product.name == name) {
                if (product.quantity >= quantity) {
                    product.quantity -= quantity;
                    cout << "Sold " << quantity << " " << name << " for Rs." << product.price * quantity << "." << endl;
                } else {
                    cout << "Insufficient quantity of " << name << " in stock." << endl;
                }
                return;
            }
        }
        cout << "Item not found." << endl;
    }
};

int main() {
    Grocery store;

    while (true) {
        cout << "\nGrocery Management System" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. List Products" << endl;
        cout << "3. Sell Item" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        string name;
        double price;
        int quantity;
        switch (choice) {
            case 1: {
                
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter product price: Rs.";
                cin >> price;
                cout << "Enter initial quantity: ";
                cin >> quantity;
                store.addProduct(name, price, quantity);
                break;
            }
            case 2:
                store.listProducts();
                break;
            case 3: {
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter quantity to sell: ";
                cin >> quantity;
                store.sellProduct(name, quantity);
                break;
            }
            case 4:
                cout << "Thank you for visiting my store." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    }

    return 0;
}


//  Algorithm
/*
Create a class Item to represent a product with attributes: name, price, and quantity.

Create a class Grocery to manage the grocery store's inventory. It has a private member products, which is a vector of Item objects.

Implement the addProduct method in the Grocery class to add a product to the inventory. It takes name, price, and quantity as parameters and appends a new Item to the products vector.

Implement the listProducts method in the Grocery class to display a list of available products. It checks if the products vector is empty and, if not, iterates through the products to display their names, prices, and quantities.

Implement the sellProduct method in the Grocery class to sell a product. It takes the name of the product and the quantity to sell. It searches for the product by name in the products vector and, if found, reduces the quantity if there is sufficient stock. It then displays the sale information.

In the main function, create a Grocery object called store.

Enter a while loop that displays a menu of options to the user and reads their choice.

In the loop:
a. If the user selects option 1, the program prompts for the product's name, price, and quantity and calls the addProduct method to add the product to the inventory.
b. If the user selects option 2, the program calls the listProducts method to display the available products.
c. If the user selects option 3, the program prompts for the product name and the quantity to sell and calls the sellProduct method to handle the sale.
d. If the user selects option 4, the program prints a closing message and exits.

If the user enters an invalid choice, they receive an error message and the loop continues.

The program continues to display the menu until the user chooses to exit (option 4).
*/


//  Output
/*
Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 1

Enter product name: Cornflakes
Enter product price: Rs.60
Enter initial quantity: 20
Item added successfully.

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 1

Enter product name: Almonds
Enter product price: Rs.70
Enter initial quantity: 15
Item added successfully.

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 1

Enter product name: Honey
Enter product price: Rs.80
Enter initial quantity: 25
Item added successfully.

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 1

Enter product name: Sugar
Enter product price: Rs.40
Enter initial quantity: 18
Item added successfully.

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 1

Enter product name: Dark Chocolate
Enter product price: Rs.55
Enter initial quantity: 30
Item added successfully.

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 2

Available Products:
-------------------
Name            Price      Quantity
Cornflakes      Rs.60      20
Almonds         Rs.70      15
Honey           Rs.80      25
Sugar           Rs.40      18
Dark Chocolate  Rs.55      30

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 3

Enter product name: Almonds
Enter quantity to sell: 5
Sold 5 Almonds for Rs.350.

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 2

Available Products:
-------------------
Name            Price      Quantity
Cornflakes      Rs.60      20
Almonds         Rs.70      10
Honey           Rs.80      25
Sugar           Rs.40      18
Dark Chocolate  Rs.55      30

Grocery Management System
1. Add Item
2. List Products
3. Sell Item
4. Exit
Enter your choice: 4

Thank you for visiting my store.

*/
