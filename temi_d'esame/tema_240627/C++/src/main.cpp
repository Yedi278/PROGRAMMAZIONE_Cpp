#include "Multiset.hpp"

struct comp_int_eq {
    bool operator()(const int& a, const int& b) const {
        return a == b;
    }
};

struct comp_int {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

int main(int argc, char* argv[]) {

    Multiset<int, comp_int, comp_int_eq> m;

    m.add(1);
    m.add(2);

    m.print();

    return 0;
}