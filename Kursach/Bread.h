#ifndef CURSOVAYA_BREAD_H
#define CURSOVAYA_BREAD_H

#include "ProductFood.h"

class Bread : public ProductFood {
private:
    string flourType;
    bool isWholeGrain;
public:
    Bread();
    Bread(const string& name,
        const string& produceDate,
        int weight,
        int price,
        const string& shelfLife,
        int amountCalories,
        string flourType,
        bool isWholeGrain);

    string getFlourType() const { return flourType; }
    bool getIsWholeGrain() const { return isWholeGrain; }

    string Info() const override;
};

#endif //CURSOVAYA_BREAD_H
