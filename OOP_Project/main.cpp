#include <iostream>
#include <string>
using namespace std;

#include "Store.h"
#include "Product.h"
#include "PaymentMethod.h"
#include "Client.h"

void noStock() {
    cout << "This product is sold out" << endl << endl;
}

void noBalance() {
    cout << "This payment method does't have enough balance" << endl << endl;
}

void success(string card, float balance) {
    cout
        << "Payment successfull" << endl
        << "You now have $" << balance << " in " << card << " card" << endl << endl;
}

int main() {
    Store walmart;
    Client client("John", 300, 50);
    
    int prodId;
    string method;
    
    walmart.open();
    cout << "Welcome to Walmart Online Store, what do you want to buy?" << endl;
    walmart.showProducts();
    
    // try to buy product with id 2 with credit card
    // expected: success
    prodId = 2;
    method = "CREDIT";
    
    Product prod1 = walmart.getProduct(prodId);
    // this can't be a function, because we would need to pass pointers
    // to update the quantities and balances
    if (prod1.isAvailable()) {
        if (client.canBuy(method, prod1.getPrice())) {
            client.buy(method, prod1.getPrice());
            walmart.registerSale(prodId);
            
            success(method, client.getBalance(method));
        } else {
            noBalance();
        }
    } else {
        noStock();
    }
    
    // try to buy product with id 3 with gift card
    // expected: success
    prodId = 3;
    method = "GIFT";
    
    Product prod2 = walmart.getProduct(prodId);
    
    if (prod2.isAvailable()) {
        if (client.canBuy(method, prod2.getPrice())) {
            client.buy(method, prod2.getPrice());
            walmart.registerSale(prodId);

            success(method, client.getBalance(method));
        } else {
            noBalance();
        }
    } else {
        noStock();
    }
    
    // try to buy product with id 0 with credit card
    // expected: no stock
    prodId = 0;
    method = "CREDIT";
    
    Product prod3 = walmart.getProduct(prodId);
    
    if (prod3.isAvailable()) {
        if (client.canBuy(method, prod3.getPrice())) {
            client.buy(method, prod3.getPrice());
            walmart.registerSale(prodId);
            
            success(method, client.getBalance(method));
        } else {
            noBalance();
        }
    } else {
        noStock();
    }
    
    // try to buy product with id 5 with gift card
    // expected: success
    prodId = 5;
    method = "GIFT";
    
    Product prod4 = walmart.getProduct(prodId);

    if (prod4.isAvailable()) {
        if (client.canBuy(method, prod4.getPrice())) {
            client.buy(method, prod4.getPrice());
            walmart.registerSale(prodId);

            success(method, client.getBalance(method));
        } else {
            noBalance();
        }
    } else {
        noStock();
    }
    
    // try to buy product with id 9 with gift card
    // expected: no balance
    prodId = 9;
    method = "GIFT";
    
    Product prod5 = walmart.getProduct(prodId);

    if (prod5.isAvailable()) {
        if (client.canBuy(method, prod5.getPrice())) {
            client.buy(method, prod5.getPrice());
            walmart.registerSale(prodId);

            success(method, client.getBalance(method));
        } else {
            noBalance();
        }
    } else {
        noStock();
    }
    
    // try to buy product with id 9 with credit card
    // expected: success
    prodId = 9;
    method = "CREDIT";
    
    Product prod6 = walmart.getProduct(prodId);

    if (prod6.isAvailable()) {
        if (client.canBuy(method, prod6.getPrice())) {
            client.buy(method, prod6.getPrice());
            walmart.registerSale(prodId);

            success(method, client.getBalance(method));
        } else {
            noBalance();
        }
    } else {
        noStock();
    }
    
    cout
        << "Thanks for visiting Walmart. See you soon :)"
        << endl;
    
    walmart.close();
    
    cout
        << endl
        << "Sales report:" << endl
        << "$" << walmart.getTodayBalance() << " sold today" << endl;
    return 0;
}
