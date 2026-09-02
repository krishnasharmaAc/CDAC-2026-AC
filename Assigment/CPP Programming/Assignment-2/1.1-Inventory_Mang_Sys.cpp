#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    Product(){
        productId = 0;
        name = "";
        price = 0;
        quantity = 0;
    }
    string getName() const{
        return name;
    }

    void acceptDetails(){
        cout << "Enter product ID: ";
        cin >> productId;

        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, name);

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter product price: ";
        cin >> price;
    }

    void displayDetails() const{
        cout << left
             << setw(7) << productId
             << setw(15) << name
             << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();

        if (isLowStock(10)) {
            cout << "<- LOW STOCK";
        }

        cout << endl;
    }
    double totalValue() const{
        return price*quantity;
    }
    bool isLowStock(int threshold) const{
        return quantity < threshold;
    }

};

int main(){
    Product p[100];
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    // Accept product details
    for (int i = 0; i < n; i++) {
        cout << "\n--- Product " << i + 1 << " ---" << endl;
        p[i].acceptDetails();
    }

    // Inventory Report
    cout << "\n\n===== INVENTORY REPORT =====" << endl;

    cout << left
         << setw(7) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;

    cout << "--------------------------------------------------------"
         << endl;

    // Display all products
    for (int i = 0; i < n; i++) {
        p[i].displayDetails();
    }

    // Find highest value product
    int highestIndex = 0;

    for (int i = 1; i < n; i++) {
        if (p[i].totalValue() >
            p[highestIndex].totalValue()) {

            highestIndex = i;
        }
    }

cout << "\nHighest Value Product : "<< p[highestIndex].getName()<< "  (Rs. "<< fixed << setprecision(2)<< p[highestIndex].totalValue()<< ")" << endl;

    // Low stock products
    int threshold = 10;
    cout << "Low Stock (threshold: "<< threshold << ") : ";
    bool found = false;
    for (int i = 0; i < n; i++) {

        if (p[i].isLowStock(threshold)) {
            if (found) {
                cout << ", ";
            }
            cout << p[i].getName();
            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }
    cout << endl;
    return 0;
}