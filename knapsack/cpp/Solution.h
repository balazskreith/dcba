#include <string>
#include <iostream>
#include "Item.h"

using std::cout, std::endl, std::vector, std::to_string, std::equal;

void test_Item();
void test_item_weight(const Item& item, long w);
void test_item_value(const Item& item, long v);
void test_item_state(const Item& item, long w, long v);
void test_BruteForceKnapSackSolver(long weight_limit, vector<Item>& items,
                                   const std::pair<long, vector<int>>& expectation);
std::pair<long, vector<int>> run_solver(long weight_limit, vector<Item>& items);
