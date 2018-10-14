#include <vector>
#include <string>
#include "Item.h"

using std::vector, std::string;

class BruteForceKnapSackSolver {
    private:
        long weight_limit;
        vector<Item>* items;
        vector<int> solutions;
    
    public:
        BruteForceKnapSackSolver(long weight_lim, 
                                 vector<Item>& items);
        ~BruteForceKnapSackSolver();
        string state();
        long get_weight_limit();
        vector<Item> get_items();
        vector<long> get_solutions();
        std::pair<long, vector<int>> solve();
        std::pair<long, vector<int>> select_max(long actual_weight, long actual_value, 
                                                int actual_index, vector<int>& actual_trace);
        std::pair<long, vector<int>> update_trace(Item item, long actual_weight, 
                                                  long actual_value, int actual_index, 
                                                  vector<int>& current_trace,
                                                  std::pair<long, vector<int>>& including, 
                                                  std::pair<long, vector<int>>& not_including);
         
};