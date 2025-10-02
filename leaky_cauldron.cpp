#include <iostream>
using namespace std;


// ------------ YOU ARE NOT ALLOWED TO CHANGE THE FOLLOWING -------------- //

int GALLEON = 493;
int SICKLE = 29;
int KNUT = 1;

string ALL_TOPPINGS[] = {
    "Whipped Cream", 
    "Marshmallows", 
    "Chocolate Shavings", 
    "Cinnamon Stick", 
    "Caramel Drizzle", 
    "Nutmeg Sprinkle",
    "Crushed Candy Cane"
};

// structure to keep track of the order
struct WizardOrder{
    string name;
    string drink;
    char drink_size;
    int toppingList[3];
    int *coin;
};



// ------------- You can change anything below this line -------------- //


// shows the order for the wizard
void showOrder(WizardOrder *order){
    cout << "Wizard: " << (*order).name << endl;
    cout << "Drink: " << (*order).drink << " (" << (*order).drink_size << ")" << endl;
    cout << "Toppings: ";

    cout << "| ";
    for (const auto &topping : (*order).toppingList) {
        cout << ALL_TOPPINGS[topping] << " | ";
    }
    cout << endl;
    cout << "Price: " << (*(*order).coin) << "c" << endl;       // de-referenced, de-reference
    cout << endl;
}

int main(){
    // set prices
    int *small_price = new int(KNUT*20);
    int *med_price = new int(SICKLE*2);
    int *large_price = new int(GALLEON/5);

    // create orders
    WizardOrder harry = WizardOrder{"Harry", "Felix Felicis Espresso Shot", 'S', {2}, small_price};     // toppings: Chocolate Shavings
    WizardOrder ron = WizardOrder{"Ron", "Butterbeer Latte", 'L', {0,4,6}, large_price};                // toppings: Whipped Cream, Caramel Drizzle, Crushed Candy Cane
    WizardOrder hermione = WizardOrder{"Hermione", "Pumpkin Juice Smoothie", 'M', {1,5}, med_price};    // toppings: Marshmallows, Nutmeg Sprinkle
    WizardOrder draco = WizardOrder{"Draco", "Gillywater Spritzer", 'M', {8,10}, med_price};            // toppings: (Nothing)

    // add each wizard
    WizardOrder *all_orders = new WizardOrder[4];
    all_orders[0] = harry;
    all_orders[1] = ron;
    all_orders[2] = hermione;
    all_orders[3] = draco;

    //show the orders
    for(int i=0; i<4; i++){
        showOrder(&all_orders[i]);
    }
}