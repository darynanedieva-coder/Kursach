#include "Shelf.h"

using namespace std;




Shelf::Shelf() : capacity(6), damage(0), amountMoney(0) {}


Shelf::~Shelf() {
    for (int i = 0; i < vecAmountProduct.size(); i++) {
        delete vecAmountProduct[i];
    }
}

// Додати продукт
void Shelf::addProductFood(const ProductFood* product, int count) {
    if (count < 0) {
        throw invalid_argument("You cannot add a negative quantity.");
    }
    if (count > capacity) {
        throw invalid_argument("There is not enough space on the shelf.");
    }
    for (int i = 0; i < count; i++) {
        vecAmountProduct.push_back(product);
        capacity--;
    }
}

// Видалити прострочені продукти
void Shelf::loseShelfLifeProductFood(const string& date) {
    if (vecAmountProduct.size() == 0) {
        cout << "There are no products on the shelf" << endl;
        return;
    }
    damage = 0;
    for (int i = 0; i < vecAmountProduct.size(); i++) {
        if (vecAmountProduct[i]->isShelfLifeGood(date) == false) {
            delete vecAmountProduct[i];
            vecAmountProduct.erase(vecAmountProduct.begin() + i);
            capacity++;
            damage++;
            i--;
        }
    }
    if (damage > 0) {
        cout << "Found expired products: " << damage << endl;
    }
    else {
        cout << "There are no expired products" << endl;
    }
}

// СОРТУВАННЯ за зростанням ціни
void Shelf::sortProductPriceAscending() {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf. Unable to sort." << endl;
        return;
    }
    int n = vecAmountProduct.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vecAmountProduct[j]->getPrice() > vecAmountProduct[j + 1]->getPrice()) {
                const ProductFood* temp = vecAmountProduct[j];
                vecAmountProduct[j] = vecAmountProduct[j + 1];
                vecAmountProduct[j + 1] = temp;
            }
        }
    }
    cout << "Products are sorted (from cheap to expensive)." << endl;
}

// СОРТУВАННЯ за спаданням ціни
void Shelf::sortProductPriceDescending() {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf. Unable to sort." << endl;
        return;
    }
    int n = vecAmountProduct.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vecAmountProduct[j]->getPrice() < vecAmountProduct[j + 1]->getPrice()) {
                const ProductFood* temp = vecAmountProduct[j];
                vecAmountProduct[j] = vecAmountProduct[j + 1];
                vecAmountProduct[j + 1] = temp;
            }
        }
    }
    cout << "Products are sorted (from expensive to cheap)." << endl;
}

// Купити один продукт за назвою
void Shelf::buyProduct(const string& name) {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf." << endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < vecAmountProduct.size(); i++) {
        if (vecAmountProduct[i]->getName() == name) {
            sumPrice(vecAmountProduct[i]->getPrice());
            delete vecAmountProduct[i];
            vecAmountProduct.erase(vecAmountProduct.begin() + i);
            capacity++;
            found = true;
            break;
        }
    }
    if (found) {
        cout << "You bought " << name << "." << endl;
    }
    else {
        cout << "Product '" << name << "Not found." << endl;
    }
}

// Купити всі продукти
void Shelf::buyAllProduct() {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf." << endl;
        return;
    }
    for (int i = 0; i < vecAmountProduct.size(); ) {
        sumPrice(vecAmountProduct[i]->getPrice());
        delete vecAmountProduct[i];
        vecAmountProduct.erase(vecAmountProduct.begin() + i);
        capacity++;
    }
    cout << "You bought all the products." << endl;
}

// Перевірка цілісності одного продукту (без випадковості)
void Shelf::checkIntegrity(const string& name) {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf." << endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < vecAmountProduct.size(); i++) {
        if (vecAmountProduct[i]->getName() == name) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Product '" << name << "' whole. No damage." << endl;
    }
    else {
        cout << "Product '" << name << "' not found." << endl;
    }
}

// Перевірка всіх продуктів (без випадковості)
void Shelf::checkAllIntegrity() {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf." << endl;
        return;
    }
    cout << "All products on the shelf are intact. No damage was found." << endl;
}

// Вивести всі продукти
void Shelf::printProductFood() {
    if (vecAmountProduct.empty()) {
        cout << "There are no products on the shelf." << endl;
    }
    else {
        for (int i = 0; i < vecAmountProduct.size(); i++) {
            cout << vecAmountProduct[i]->Info() << endl;
        }
    }
}


