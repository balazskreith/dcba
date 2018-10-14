#include <vector>
#include "BruteForceKnapSackSolver.h"

BruteForceKnapSackSolver::BruteForceKnapSackSolver(long weight_lim, 
                                                   std::vector<Item> items) {
    weight_limit = weight_lim;
    items = items;
    // solutions = vector<long>(items.size)
}
long BruteForceKnapSackSolver::solve() {}
long BruteForceKnapSackSolver::select_max() {}
std::vector<Item> BruteForceKnapSackSolver::get_items() {
    return items;
}