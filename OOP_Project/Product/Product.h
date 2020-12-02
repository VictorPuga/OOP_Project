#pragma once

#include <string>
using namespace std;

class Product {
private:
    int _id;
    string _name;
    int _quantity;
    float _price;

public:
    Product();
    
    // set all the properties at once
    void setData(int id, string name, int quantity, float price);
    
    int getId();
    string getName();
    int getQuantity();
    float getPrice();
    
    bool isAvailable();
    void sell();
};
