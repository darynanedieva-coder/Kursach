#include "Bread.h"


Bread::Bread() : flourType("wheat"), isWholeGrain(false) {}


Bread::Bread(const string& name,
    const string& produceDate,
    int weight,
    double price,
    const string& shelfLife,
    int amountCalories,
    string flourType,
    bool isWholeGrain)
    : ProductFood(name, produceDate, weight, price, shelfLife, amountCalories),
    flourType(flourType),
    isWholeGrain(isWholeGrain) {

    if (weight < 0) {
        throw invalid_argument("The weight of the bread cannot be negative.");
    }
    if (price < 0) {
        throw invalid_argument("The price of bread cannot be negative.");
    }
    if (amountCalories < 0) {
        throw invalid_argument("Calories cannot be negative.");
    }
}

string Bread::Info() const {
    string result;
    result = ProductFood::Info() +
        " Flour type: " + flourType +
        " Wholemeal: ";
    if (isWholeGrain)
        result = result + "Yes";
    else
        result = result + "No";
    return result;
}
