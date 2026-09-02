#include <iostream>
#include <iomanip>
using namespace std;


// integer quantity
double reorderCost(int qty, double unitPrice){
    return qty * unitPrice;
}          

// fractional (by weight)
double reorderCost(double qty, double unitPrice){
     return qty * unitPrice;
}        

// Quantity with tax
double reorderCost(int qty, double unitPrice, double taxRate){
    double cost = qty * unitPrice;
     return cost + (cost * taxRate/100);
}


// Default argument
double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * discountPercent / 100);
}

int main(){
    cout<<fixed << setprecision(2);

    //Integer
    cout<<endl<<"Reorder Cost(Integer) : "<<reorderCost(8,250.00)<<endl;

    //fractional
    cout<<endl<<"Reorder Cost( By weights ) : "<<reorderCost(8.5,250.00)<<endl;

    //tax 
    cout<<endl<<"Reorder Cost(with Tax) : "<<reorderCost(8,250.00,18.0)<<endl;

    //calling default argument version
    cout<<endl<<"Discounted Price (Default 10%) : "<<applyDiscount(250.00)<<endl;

    //calling with aspecific disount
    cout<<endl<<"Discounted price (given 20%) : "<<applyDiscount(250.00,20.0)<<endl;

    return 0;
}