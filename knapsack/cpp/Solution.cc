#include "Solution.h"
#include "Item.cc"
#include "BruteForceKnapSackSolver.cc"

void test_item_weight(Item item, long w) {
    if (w < 0) {
        assert(item.get_weight() == 0);
    } else {
        assert(item.get_weight() == w);
    }
}
void test_item_value(Item item, long v) {
    if (v < 0) {
        assert(item.get_value() == 0);
    } else {
        assert(item.get_value() == v);
    }
}

void test_item_state(Item item, long w, long v) {
    assert(item.state() == "Weight: " + to_string(w) + "\nValue: " + to_string(v));
}

void test_Item(long w, int v) {
    Item item = Item(w, v);
    test_item_weight(item, w);
    test_item_value(item, v);
    test_item_state(item, w, v);
}

int main(){
    test_Item(1, 5);
    test_Item(20, 70);
    test_Item(0, 0);
    test_Item(0, 5);
    test_Item(5, 0);
    cout << "Tests Passed!" << endl;
}

