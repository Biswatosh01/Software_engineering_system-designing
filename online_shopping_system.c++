#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
public:
    string productId;
    string name;
    double price;
    int quantity;

    Product(string id, string productName, double productPrice, int initialQuantity)
        : productId(id), name(productName), price(productPrice), quantity(initialQuantity) {}

    void displayProduct() const {
        cout << "Product ID: " << productId << ", Name: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};


class ShoppingCart {
public:
    vector<Product> items;

    void addToCart(const Product& product, int quantity) {
        // Check if the product is already in the cart
        for (auto& item : items) {
            if (item.productId == product.productId) {
                item.quantity += quantity;
                cout << "Added " << quantity << " " << product.name << "(s) to the cart." << endl;
                return;
            }
        }

        // If the product is not in the cart, add it
        Product newItem = product;
        newItem.quantity = quantity;
        items.push_back(newItem);
        cout << "Added " << quantity << " " << product.name << "(s) to the cart." << endl;
    }

    void displayCart() {
        if (items.empty()) {
            cout << "Shopping Cart is empty." << endl;
            return;
        }

        cout << "Shopping Cart:" << endl;
        for (const auto& item : items) {
            item.displayProduct();
        }
    }
};

class OnlineStore {
public:
    vector<Product> products;

    void addProduct(string productId, string productName, double productPrice, int initialQuantity) {
        Product newProduct(productId, productName, productPrice, initialQuantity);
        products.push_back(newProduct);
        cout << "Product added successfully." << endl;
    }

    void displayAllProducts() {
        cout << "All Products:" << endl;
        for (const auto& product : products) {
            product.displayProduct();
        }
    }

    Product* findProduct(string productId) {
        for (auto& product : products) {
            if (product.productId == productId) {
                return &product;
            }
        }
        return nullptr;
    }
};

int main() {
    OnlineStore store;

    // Adding sample products
    store.addProduct("P001", "Laptop", 999.99, 10);
    store.addProduct("P002", "Smartphone", 499.99, 20);

    // Displaying all products
    store.displayAllProducts();

    // Creating a shopping cart
    ShoppingCart cart;

    // Adding products to the cart
    string productId = "P001";
    Product* laptop = store.findProduct(productId);

    if (laptop != nullptr) {
        cart.addToCart(*laptop, 2);
        cart.displayCart();
    } else {
        cout << "Product not found." << endl;
    }

    return 0;
}
