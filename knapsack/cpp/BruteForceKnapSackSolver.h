#include <vector>
#include <string>

using std::vector, std::string;

class BruteForceKnapSackSolver {
    private:
        long weight_limit;
        vector<Item> items;
        vector<long> solutions;
    
    public:
        BruteForceKnapSackSolver(long capacity, vector<Item> items);
        long solve();
        long select_max();
        vector<Item> get_items();
        vector<Item> get_weight_limit();
        vector<long> get_solutions();
        string state();
         
};