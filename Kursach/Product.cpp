#include "Product.h"

Product::Product() :
    name("Normal"),
    produceDate("DD/MM/YYYY"),
    weight(0),
    price(0.0) {
}

Product::Product(const string& name,
    const string& produceDate,
    int weight,
    double price) :
    name(name),
    produceDate(produceDate),
    weight(weight),
    price(price) {
}

string Product::formatBaseInfo() const {
    stringstream ss;
    ss << getPrice();
    return "Name: " + getName() + "." +
        " Produced " + getProduceDate() +
        " Weight: " + to_string(getWeight()) + "(g) " +
        " Price " + ss.str() + " UAH";
}