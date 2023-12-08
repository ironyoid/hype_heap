#include <functional>
#include <iostream>
#include "heap.hpp"

int main (int argc, char *argv[]) {
    std::vector<int> buf{ 11, 4, 9, 2, 5, 6, 10, 8, 16 };
    heap<int, std::less<int>> hp(std::move(buf));
    hp.print();
    hp.push(20);
    hp.print();
}