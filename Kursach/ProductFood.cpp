#include "ProductFood.h"

ProductFood::ProductFood() :
    shelfLife("DD/MM/YYYY"),
    amountCalories(500) {
}

ProductFood::ProductFood(const string& name,
    const string& produceDate,
    int weight,
    int price,
    const string& shelfLife,
    int amountCalories) :
    Product(name, produceDate, weight, price),
    shelfLife(shelfLife),
    amountCalories(amountCalories) {
    ProductFood::dateComparison(produceDate, shelfLife);
}

int ProductFood::convertDate(const std::string& date) {
    if (date.size() < 10 || date[2] != '/' || date[5] != '/') {
        throw std::invalid_argument("Date must be in format DD/MM/YYYY");
    }

    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 +
        (date[8] - '0') * 10 + (date[9] - '0');

    return year * 10000 + month * 100 + day;
}

bool ProductFood::dateComparison(const string& ProduceDate, const string& ShelfLife) {
    int produceDate = convertDate(ProduceDate);
    int shelfLife = convertDate(ShelfLife);

    if (produceDate > shelfLife) {
        throw invalid_argument("You have entered a production date less than the expiration date. This cannot be.");
    }
    return true;
}

bool ProductFood::isShelfLifeGood(const string& currentDate) const {
    int shelfLifeDate = convertDate(getShelfLife());
    int currentDateNum = convertDate(currentDate);

    return shelfLifeDate >= currentDateNum;
}

string ProductFood::Info() const {
    string out;

    out = Product::Info() +
        " Ends " + getShelfLife() +
        " Calories : " + to_string(getAmountCalories()) + " call";

    return out;
}