#include "UserInterface.h"

void UserInterface::SystemMenu() {
    int weight, fat, price, amountCalories, amount, gain, selection, isWholeGrain;
    string name, inside, packageType, produceDate, todayDate, shelfLife, flourType;
    string CurrentDate = "27/05/2026";
    Yogurt* yogurt;
    Milk* milk;
    Bread* bread;
    ProductFood productFood;
    Shelf shelf;


    cout << "|=========================================|\n"
        "|           WELCOME TO THE STORE          |\n";
    do {
        cout << "|=========================================|\n"
            "| Select product:                         |\n"
            "|=========================================|\n"
            "| 1. Yogurt.                              |\n"
            "| 2. Milk.                                |\n"
            "| 3. Bred.                                |\n"
            "|=========================================|\n"
            "| Select operation:                       |\n"
            "|=========================================|\n"
            "| 4. Expiry date check.                   |\n"
            "| 5. Sorting products on the shelf.       |\n"
            "| 6. Buy goods                            |\n"
            "| 7. Revenue from sold goods.             |\n"
            "| 8. Checking the product for integrity.  |\n"
            "| 9. Taking goods to the shelf.           |\n"
            "|=========================================|\n"
            "| 10. Shelf information.                  |\n"
            "| 11. Exit from the program.              |\n"
            "| Today's date "; cout << CurrentDate; cout << "                 |\n";
        cout << "|=========================================|\n"
            "|    Select any item                      |\n"
            "|   and follow the hints. Have a nice day!|\n"
            "|=========================================|\n";

        cout << "\nYour choice:\n"; cin >> selection;
        switch (selection) {
        case 1:
            try {
                cout << "You chose yogurt, let's add it to the shelf.\n";
                cout << "Enter yogurt name:\n"; cin.ignore(); getline(cin, name);
                cout << "Add the production date as (DD/MM/YYYY):\n"; cin.ignore(); getline(cin, produceDate);
                cout << "Enter weight in grams (not less than 0):\n"; cin >> weight;
                cout << "Enter price (UAH):\n"; cin >> price;
                cout << "Enter the expiration date (DD/MM/YYYY):\n"; cin.ignore(); getline(cin, shelfLife);
                cout << "Enter the number of calories (kcal) at least 0:\n"; cin >> amountCalories;
                cout << "Inject the fat content of the yogurt (0% to 10%) :\n"; cin >> fat;
                cout << "Inject the yogurt filling (strawberry, apple and other fruit):\n"; cin.ignore(); getline(cin, inside);
                cout << "Free places on the shelf: " << shelf.getCapacity() << ".\n";
                cout << "Product quantity:\n"; cin >> amount;

                yogurt = new Yogurt(name, produceDate, weight, price, shelfLife, amountCalories, fat, inside);
                shelf.addProductFood(yogurt, amount);
                if (amount > 1) {
                    cout << " " << amount << " yogurts have been added to the shelf.\n";
                }
                else {
                    cout << " " << amount << " yogurt was added to the shelf.\n";
                }
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }
            break;
        case 2:
            try {
                cout << "You have selected milk, we will add it to the shelf.\n";
                cout << "Enter the name of the milk:\n"; cin.ignore(); getline(cin, name);
                cout << "Add the production date as (DD/MM/YYYY): \n"; cin.ignore(); getline(cin, produceDate);
                cout << "Enter weight in grams (not less than 0):\n"; cin >> weight;
                cout << "Enter price (UAH):\n"; cin >> price;
                cout << "Enter the expiration date (DD/MM/YYYY):\n"; cin.ignore(); getline(cin, shelfLife);
                cout << "Enter the number of calories (kcal) at least 0:\n"; cin >> amountCalories;
                cout << "Enter the fat content of the milk (from 0% to 4%) t:\n"; cin >> fat;
                cout << "Enter the type of packaging (Bottle, pure pack, pillow):\n"; cin.ignore(); getline(cin, packageType);
                cout << "Free places on the shelf: " << shelf.getCapacity() << ".\n";
                cout << "Product quantity:\n"; cin >> amount;

                milk = new Milk(name, produceDate, weight, price, shelfLife, amountCalories, fat, packageType);
                shelf.addProductFood(milk, amount);
                cout << " " << amount << "  " "milk" << packageType << " were added to the shelf.\n";
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }
            break;
        case 3:
            try {
                cout << "You chose bread, let's add it to the shelf.\n";
                cout << "Enter the name of the bread:\n"; cin.ignore(); getline(cin, name);;
                cout << "Add the production date as (DD/MM/YYYY):\n"; cin.ignore(); getline(cin, produceDate);
                cout << "Enter weight in grams (not less than 0):\n"; cin >> weight;
                cout << "Enter price (UAH):\n"; cin >> price;
                cout << "Enter the expiration date (DD/MM/YYYY):\n"; cin.ignore(); getline(cin, shelfLife);;
                cout << "Enter the number of calories (kcal) at least 0:\n"; cin >> amountCalories;;
                cout << "Ведіть тип борошна (пшеничне, житнє, гречане):\n"; cin.ignore(); getline(cin, flourType);
                cout << "Введіть якщо він цільнозерновий - 1, якщо ні - 0.\n"; int wholeGrainInt;
                cin >> wholeGrainInt;
                bool isWholeGrain = (wholeGrainInt == 1);
                cout << "Free places on the shelf: " << shelf.getCapacity() << ".\n";
                cout << "product quantity:\n"; cin >> amount;

                bread = new Bread(name, produceDate, weight, price, shelfLife, amountCalories, flourType, isWholeGrain);
                shelf.addProductFood(bread, amount);
                cout << " Added " << amount << " bread loaf.\n";
            }
            catch (exception& ex) {
                cout << ex.what() << endl;
            }
            break;

        case 4:
            cout << "Checking the shelf life of goods.\n";
            shelf.loseShelfLifeProductFood(CurrentDate);
            break;
        case 5:
            cout << "Sorting products by price.\n"
                "You can sort products by price."; cout << endl;
            do {
                cout << "\nYou can sort products in ascending order by clicking - 1.\n"
                    "You can sort products in descending order by clicking - 2.\n"
                    "You can exit by clicking - 3.\n"
                    "\nEnter your choice:\n"; cin >> selection;
                switch (selection) {
                case 1:
                    shelf.sortProductPriceAscending();
                    break;
                case 2:
                    shelf.sortProductPriceDescending();
                    break;
                case 3:
                    cout << " You left case 5.\n";
                    break;
                default:
                    cout << "\n";
                }
            } while (selection != 3);
            break;
        case 6:
            cout << "In this subsection, you can purchase the product that is on the shelf.\n";
            do {
                cout << "\nYou can buy a product by name by clicking - 1.\n"
                    "You can buy all products at once by clicking - 2.\n"
                    "You can exit by pressing - 3.\n"
                    "\nEnter your choice:\n"; cin >> selection;
                switch (selection) {
                case 1:
                    cout << "Enter product name:\n"; cin.ignore(); getline(cin, name);
                    shelf.buyProduct(name);
                    break;
                case 2:
                    shelf.buyAllProduct();
                    break;
                case 3:
                    cout << " You left case 6.\n";
                    break;
                default:
                    cout << "\n";
                }
            } while (selection != 3);
            break;
        case 7:
            if (shelf.getAmountMoney() == 0) {
                cout << " You have not sold any products." << "\n";
            }
            else {
                cout << " You sold products worth " << shelf.getAmountMoney() << "  UAH\n";
            }
            break;
        case 8:
            cout << "In this subsection, you can check products for integrity.\n";
            do {
                cout << "\nYou can check the integrity of the product by name by clicking - 1.\n"
                    "You can check all products for integrity at once by clicking - 2.\n"
                    "You can exit by pressing - 3.\n"
                    "\nEnter your choice:\n"; cin >> selection;
                switch (selection) {
                case 1:
                    cout << "Enter the product name:\n"; cin.ignore(); getline(cin, name);
                    shelf.checkIntegrity(name);
                    break;
                case 2:
                    shelf.checkAllIntegrity();
                    break;
                case 3:
                    cout << " You left case 8.\n";
                    break;
                default:
                    cout << "\n";
                }
            } while (selection != 3);
            break;
        case 9:
            cout << " Products on the shelf:\n";
            shelf.printProductFood();
            break;
        case 10:
            do {
                cout << "\nYou can increase the number of shelf spaces by clicking - 1.\n";
                "You can reduce the number of shelf spaces by clicking - 2.\n"
                    "You can view the standard number of shelf slots by clicking - 3.\n"
                    "You can exit by clicking - 4.\n"
                    "\nEnter your choice:\n"; cin >> selection;
                switch (selection) {
                case 1:
                    cout << "Enter gain: " << "\n"; cin >> gain;
                    shelf.setCapacityIncrease(gain);
                    break;
                case 2:
                    cout << "Enter gain: " << "\n"; cin >> gain;
                    if (gain > shelf.getCapacity()) {
                        cout << "You can't make shelf capacity less than zero." << "\n";
                    }
                    else {
                        shelf.setCapacityReduce(gain);
                    }
                    break;
                case 3:
                    cout << "Shelf seat now: " << shelf.getCapacity() << ".\n";
                    break;
                case 4:
                    cout << " You leave the case 10.\n";
                    break;
                default:
                    cout << "\n";
                }
            } while (selection != 4);
            break;
        case 11:
            cout << "\nThank you for using the program. Farewell!\n";
            exit(0);
        default:
            cout << "\nYou made the wrong choice.\n";
        }
    } while (selection != 0);
}