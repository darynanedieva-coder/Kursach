#ifndef CURSOVAYA_PRODUCT_H
#define CURSOVAYA_PRODUCT_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Product {
private:
    string name;
    string produceDate;
    int weight;
    int price;

public:
    Product();
    Product(const string& name,
        const string& produceDate,
        int weight,
        int price);

    virtual ~Product() {}

    const string& getName() const { return name; }
    const string& getProduceDate() const { return produceDate; }
    int getWeight() const { return weight; }
    int getPrice() const { return price; }

    virtual string Info() const;
};

#endif //CURSOVAYA_PRODUCT_H
