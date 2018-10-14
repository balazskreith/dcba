#include "Item.h"

Item::Item(long w, long v) {
    add_weight(w);
    add_value(v);
}

void Item::add_weight(long w) {
    if (w > 0) {
        weight = w;
    } else {
        cout << "Weight cannot be zero or a negative number!\nSetting weight to 0." << endl;
        weight = 0;
    }
}

void Item::add_value(long v) { 
    if (v > 0) {
        value = v;
    } else {
        cout << "Value cannot be zero or a negative number!\nSetting value to 0." << endl;
        value = 0;
    }
}

long Item::get_weight() const {
    return weight;
}

long Item::get_value() const {
    return value;
}

string Item::state() const {
    return "Weight: " + to_string(weight) + "\nValue: " + to_string(value);
}