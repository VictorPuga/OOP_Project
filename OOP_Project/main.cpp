#include <iostream>
#include <string>
using namespace std;

#include "Store.h"
#include "Product.h"
#include "PaymentMethod.h"
#include "Client.h"

int main() {
    Store walmart;
    Client client("John", 300, 5);
    
    walmart.open();
    cout << "Welcome to Walmart Online Store, what do you want to buy?" << endl;
    walmart.showProducts();
    
    int prodId;
    Product prod;
    bool buy = true;
    
    while (true) {
        cout << "Select a number: ";
        cin >> prodId;

        if (prodId >= 0 && prodId <= 9) {
           prod = walmart.getProduct(prodId);
            if (prod.isAvailable()) {
                break;
            }
            else {
                string another;
                cout
                    << "This product is out of stock. Do you want to buy another one?" << endl
                    << "(Y/N): ";
                cin >> another;
                if (another == "N") {
                    buy = false;
                    break;
                }
            }
        }
    }
    
    // if they select `N`, this will be skipped
    if (buy) {
        cout
            << endl
            << "Choose a payment method" << endl
            << "0) Credit card" << endl
            << "1) Gift card" << endl;
        
        int method;
        
        while (true) {
            cout << "Select a number: ";
            cin >> method;
            
            if (method == 0) {
                PaymentMethod card = client.getCreditCard();
                // this can't be separated into a function because we need to update the objects
                if (card.canBuy(prod.getPrice())) {
                    card.makePayment(prod.getPrice());
                    prod.sell();
                    walmart.registerSale(prod.getPrice());
                    
                    cout
                        << "Payment successful" << endl
                        << "Your new balance is $" << card.getBalance() << endl;
                }
                else {
                    cout << "This payment method doesn't have enough funds to buy" << endl;
                }
                break;
            }
            else if (method == 1) {
                PaymentMethod card = client.getCreditCard();
                if (card.canBuy(prod.getPrice())) {
                    card.makePayment(prod.getPrice());
                    prod.sell();
                    walmart.registerSale(prod.getPrice());
                    
                    cout
                        << "Payment successful" << endl
                        << "Your new balance is $" << card.getBalance() << endl;
                }
                else {
                    cout << "This payment method doesn't have enough funds to buy" << endl;
                }
                break;
            }
        }
    }
    
    
    cout
        << endl
        << "Thanks for visiting Walmart. See you soon :)"
        << endl;

    walmart.close();
    
    cout
        << endl
        << "Sales report:" << endl
        << "$" << walmart.getTodayBalance() << " sold today" << endl;
    
    return 0;
}
