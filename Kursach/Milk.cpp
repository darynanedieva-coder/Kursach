#include "Milk.h"
#include <stdexcept>
#include <string>

using namespace std;

Milk::Milk() :
    ProductFood(),
    fat(2.5),
    packageType("bottle") {
}

Milk::Milk(const string& nameMilk,
    const string& produceDateMilk,
    int weight,
    int price,
    const string& shelfLifeMilk,
    int amountCalories,
    double fat,
    string packageType) :
    ProductFood(nameMilk, produceDateMilk, weight, price, shelfLifeMilk, amountCalories),
    fat(fat),
    packageType(packageType)
{
    if (weight < 0) {
        throw invalid_argument("The weight of the bread cannot be negative.");
    }
    if (price < 0) {
        throw invalid_argument("The price of bread cannot be negative.");
    }
    if (amountCalories < 0) {
        throw invalid_argument("Calories cannot be negative.");
    }
    if (fat < 0) {
        throw invalid_argument("You have injected a milk fat content of less than 0%");
    }
    if (fat > 4) {
        throw invalid_argument("You have indicated that the fat content in milk exceeds 4%");

   
    }


}

void Milk::setFat(double newFat) {
    if (newFat < 0 || newFat > 4) {
        throw invalid_argument("The fat content should be between 0% and 4%");
    }
    fat = newFat;

}

string Milk::Info() const {
    string out;

    out = ProductFood::Info() +
        " Fat: " + to_string(getFat()) + "%" +
        " PackageType: " + getPackageType();

    return out;
}
