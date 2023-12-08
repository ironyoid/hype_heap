#include <functional>
#include <iostream>
#include <utility>
#include "heap.hpp"
#include "dijkstra.hpp"

int main (int argc, char *argv[]) {
    Algorithms::Graph graph(9);
    graph.Add(0, 1, 4);
    graph.Add(0, 7, 8);
    graph.Add(1, 2, 8);
    graph.Add(1, 7, 11);
    graph.Add(2, 3, 7);
    graph.Add(2, 8, 2);
    graph.Add(2, 5, 4);
    graph.Add(3, 4, 9);
    graph.Add(3, 5, 14);
    graph.Add(4, 5, 10);
    graph.Add(5, 6, 2);
    graph.Add(6, 7, 1);
    graph.Add(6, 8, 6);
    graph.Add(7, 8, 7);

    auto pathes = graph.FindPathes(0);

    for(int i = 0; i < pathes.size(); ++i) {
        std::cout << i << "    " << pathes[i] << std::endl;
    }
}