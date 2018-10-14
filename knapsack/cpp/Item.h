#include <string>
#include <iostream>
#ifndef ITEM_H
#define ITEM_H

using std::cout, std::endl, std::string, std::to_string;

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
        std::string state();
};

#endif /* !ITEM_H */