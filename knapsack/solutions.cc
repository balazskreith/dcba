#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
    private:
        long weight;
        long value;

    public:
        Item(long w, long v);
        void add_weight(long w);
        void add_value(long v);
        long get_weight();
        long get_value();
        string state();
};

class BruteForceKnapSackSolver {
    private:
        int weight_limit;
        vector<Item> items;
        vector<int> solutions;
    
    public:
        long solve();
        long select_max();
         
};

BruteForceKnapSackSolver::BruteForceKnapSackSolver() {}
long BruteForceKnapSackSolver::solve() {}
long BruteForceKnapSackSolver::select_max() {}

void test_Item();
void test_BruteForceSolution();

Item::Item(long w, long v) {
    add_weight(w);
    add_value(v);

}

void Item::add_weight(long w) {
    if (w > 0) {
        weight = w;
    } else {
        cout << "Weight cannot be a negative number!\nSetting weight to 0." << endl;
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

long Item::get_weight() {
    return weight;
}

long Item::get_value() {
    return value;
}

string Item::state() {
    return "Weight: " + to_string(weight) + "\nValue: " + to_string(value);
}

void test_Item(long w, int v) {
    Item item = Item(w, v);
    if (w < 0) {
        assert(item.get_weight() == 0);
    } else {
        assert(item.get_weight() == w);
    }
    
    if (v < 0) {
        assert(item.get_value() == 0);
    } else {
        assert(item.get_value() == v);
    }
    assert(item.get_value() == v);
    assert(item.state() == "Weight: " + to_string(w) + "\nValue: " + to_string(v));
}

int main(){
    test_Item(1, 5);
    test_Item(20, 70);
    test_Item(0, 0);
    test_Item(0, 5);
    test_Item(5, 0);
    std::cout << "Tests Passed!" << std::endl;
}

