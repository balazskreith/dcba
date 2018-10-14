#include "Solution.h"
#include "Item.cc"
#include "BruteForceKnapSackSolver.cc"
#include <iostream>

void test_item_weight(const Item& item, long w) {
    if (w < 0) {
        assert(item.get_weight() == 0);
    } else {
        assert(item.get_weight() == w);
    }
}
void test_item_value(const Item& item, long v) {
    if (v < 0) {
        assert(item.get_value() == 0);
    } else {
        assert(item.get_value() == v);
    }
}

void test_item_state(const Item& item, long w, long v) {
    assert(item.state() == "Weight: " + to_string(w) + "\nValue: " + to_string(v));
}

void test_Item(long w, int v) {
    Item item = Item(w, v);
    test_item_weight(item, w);
    test_item_value(item, v);
    test_item_state(item, w, v);
}

void test_BruteForceKnapSackSolver(long weight_limit, vector<Item>& items,
                                   const std::pair<long, vector<int>>& expectation) {
    std::pair<long, vector<int>> solution = run_solver(weight_limit, items);
    assert(solution.first == expectation.first);
    assert(solution.second == expectation.second);
}   

std::pair<long, vector<int>> run_solver(long weight_limit, vector<Item>& items) {
    BruteForceKnapSackSolver solver = BruteForceKnapSackSolver(weight_limit, items);
    assert(solver.get_weight_limit() == weight_limit);
    std::pair<long, vector<int>> solution = solver.solve();
    return solution;
}

int main(){
    test_Item(1, 5);
    test_Item(20, 70);
    test_Item(0, 0);
    test_Item(0, 5);
    test_Item(5, 0);

    vector<Item> items { Item(30, 100), Item(20, 150), 
                         Item(10, 200), Item(15, 500), 
                         Item(5, 300) };
    long weight_limit = 30;
    std::pair<long, vector<int>> expectation = std::make_pair(1000, vector<int> {0, 0, 1, 1, 1});
    test_BruteForceKnapSackSolver(weight_limit, items, expectation);
    cout << "Tests Passed!" << endl;
}

