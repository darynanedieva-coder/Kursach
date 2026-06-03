#include "Product.h"

Product::Product() :
    name("Normal"),
    produceDate("DD/MM/YYYY"),
    weight(0),
    price(0) {
}

Product::Product(const string& name,
    const string& produceDate,
    int weight,
    int price) :
    name(name),
    produceDate(produceDate),
    weight(weight),
    price(price) {
}

string Product::Info() const {
    string out;

    out = "Name: " + getName() + "." +
        " Produced " + getProduceDate() +
        " Weight: " + to_string(getWeight()) + "(g)" +
        " Price " + to_string(getPrice()) + "$";

    return out;
}