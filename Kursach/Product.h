#ifndef CURSOVAYA_PRODUCT_H
#define CURSOVAYA_PRODUCT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

class Product {
private:
    string name;
    string produceDate;
    int weight;
    double price;

public:
    Product();
    Product(const string& name,
        const string& produceDate,
        int weight,
        double price);

    virtual ~Product() {}

    const string& getName() const { return name; }
    const string& getProduceDate() const { return produceDate; }
    int getWeight() const { return weight; }
    double getPrice() const { return price; }

    virtual string Info() const = 0;

protected:
    string formatBaseInfo() const;
};

#endif //CURSOVAYA_PRODUCT_H
