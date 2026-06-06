#ifndef CURSOVAYA_PRODUCTFOOD_H
#define CURSOVAYA_PRODUCTFOOD_H

#include "Product.h"

class ProductFood : public Product {
private:
    string shelfLife;
    int amountCalories;
public:
    ProductFood();
    ProductFood(const string& name,
        const string& produceDate,
        int weight,
        double price,
        const string& shelfLife,
        int amountCalories);

    bool isShelfLifeGood(const string& currentDate) const;
    static int convertDate(const string& date);
    static bool dateComparison(const string& ProduceDate, const string& ShelfLife);
    string getShelfLife() const { return shelfLife; }
    int getAmountCalories() const { return amountCalories; }

    string Info() const override;


};


#endif //CURSOVAYA_PRODUCTFOOD_H
