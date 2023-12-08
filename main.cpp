#include <functional>
#include <iostream>
#include "heap.hpp"

int main (int argc, char *argv[]) {
    std::vector<int> buf{ 11, 4, 9, 2, 5, 6, 10, 1, 8, 16 };
    heap<int, std::greater<int>> hp(buf);
    std::cout << "res: ";
    hp.print();
}