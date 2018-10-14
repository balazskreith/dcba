#include <utility>
#include <vector>
#include "BruteForceKnapSackSolver.h"
#include "Item.h"

BruteForceKnapSackSolver::BruteForceKnapSackSolver(long weight_lim, 
                                                   std::vector<Item>& it) {
    weight_limit = weight_lim;
    items = new vector<Item>(it);
    solutions = vector<int>(items->size());
}
BruteForceKnapSackSolver::~BruteForceKnapSackSolver() {
    delete items;
}
std::pair<long, vector<int>> BruteForceKnapSackSolver::solve() {
    std::pair<long, vector<int>> result(select_max(0, 0, 0, solutions));
    
    return result;
}
std::pair<long, vector<int>> BruteForceKnapSackSolver::select_max(long actual_weight, 
    long actual_value, int actual_index, vector<int>& actual_trace) {
    if (weight_limit <= actual_weight || items->size() <= actual_index) {
        return std::pair<long, vector<int>>(actual_value, actual_trace);
    }
    Item item = items->at(actual_index);
    vector<int> current_trace(actual_trace);
    std::pair<long, vector<int>> not_including = select_max(actual_weight, actual_value, 
                                                             actual_index+1, current_trace);
    std::pair<long, vector<int>> including = std::pair<long, vector<int>>(0, current_trace);

    long current_weight = actual_weight + item.get_weight();
    long current_value = actual_value + item.get_value();
    if (current_weight <= get_weight_limit()) {
        current_trace[actual_index] = 1;
        including = select_max(current_weight, current_value, 
                               actual_index + 1, current_trace);
        if (including.first < not_including.first) {
            return not_including;
        } else {
            return including;
        }
    }
    return not_including;
    
}

std::vector<Item> BruteForceKnapSackSolver::get_items() {
    return *items;
}

long BruteForceKnapSackSolver::get_weight_limit() {
    return weight_limit;
}