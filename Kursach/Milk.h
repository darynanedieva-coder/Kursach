#ifndef CURSOVAYA_MILK_H
#define CURSOVAYA_MILK_H

#include "Product.h"
#include "ProductFood.h"
#include <string>      
#include <stdexcept>  
using namespace std;

class Milk : public ProductFood {
private:
    double fat;
    string packageType;
public:
    Milk();
    Milk(const string& nameMilk,
        const string& produceDate,
        int weight,
        double price,
        const string& shelfLife,
        int amountCalories,
        double fat,
        string packageType);

    double getFat() const { return fat; }
    string getPackageType() const { return packageType; }

    void setFat(double newFat);

    string Info() const override;
};


#endif //CURSOVAYA_MILK_H
