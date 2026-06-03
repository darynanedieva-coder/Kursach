#include "Yogurt.h"


Yogurt::Yogurt() : fat(6), inside("Strawberry") {}


Yogurt::Yogurt(const string& nameYogurt,
    const string& produceDate,
    int weight,
    int price,
    const string& shelfLife,
    int amountCalories,
    int fat,
    string inside)
    : ProductFood(nameYogurt, produceDate, weight, price, shelfLife, amountCalories),
    fat(fat),
    inside(inside) {

    // Перевірки на коректність даних
    if (weight < 0) {
        throw invalid_argument("The weight of yogurt cannot be negative.");
    }
    if (price < 0) {
        throw invalid_argument("The price of yogurt cannot be negative.");
    }
    if (amountCalories < 0) {
        throw invalid_argument("Several calories cannot be negative.");
    }
    if (fat < 0) {
        throw invalid_argument("Yogurt fat content cannot be negative.");
    }
    if (fat > 10) {
        throw invalid_argument("The fat content of yogurt cannot exceed 10%.");
    }
}

string Yogurt::Info() const {
    string result;
    result = ProductFood::Info() +
        " Fat: " + to_string(fat) + "%" +
        " Filler: " + inside;
    return result;
}