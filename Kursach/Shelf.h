#ifndef CURSOVAYA_SHELF_H
#define CURSOVAYA_SHELF_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "ProductFood.h"

using namespace std;

class Shelf {
private:
    int capacity;
    int damage;
    double amountMoney;
    vector<const ProductFood*> vecAmountProduct;

public:
    Shelf();
    ~Shelf();

    int getCapacity() const { return capacity; }
    double getAmountMoney() const { return amountMoney; }
    int getDamageProduct() const { return damage; }

    void sumPrice(double gain) { amountMoney += gain; }

    void setCapacityIncrease(int gain) { capacity += gain; }
    void setCapacityReduce(int gain) { capacity -= gain; }

    void addProductFood(const ProductFood* product, int quantity);
    void loseShelfLifeProductFood(const string& date);
    void sortProductPriceAscending();
    void sortProductPriceDescending();
    void buyProduct(const string& name);
    void buyAllProduct();
    void checkIntegrity(const string& name);
    void checkAllIntegrity();
    void printProductFood();
};

#endif //CURSOVAYA_SHELF_H