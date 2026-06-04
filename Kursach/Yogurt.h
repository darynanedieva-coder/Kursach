#ifndef CURSOVAYA_YOGURT_H
#define CURSOVAYA_YOGURT_H

#include "ProductFood.h"

class Yogurt : public ProductFood {
private:
    int fat;
    string inside;
public:
    Yogurt();
    Yogurt(const string& nameYogurt,
        const string& produceDate,
        int weight,
        int price,
        const string& shelfLife,
        int amountCalories,
        int fat,
        string inside);

    int getFat() const { return fat; }
    string getInside() const { return inside; }

    string Info() const override;
};

#endif //CURSOVAYA_YOGURT_H
