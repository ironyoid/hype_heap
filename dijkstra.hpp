#ifndef __DIIJKSTRA_H
#define __DIIJKSTRA_H
#include <iostream>
#include <vector>
#include <list>

namespace Algorithms {
    struct Vertex {
        int u;
        int w;
        bool operator<(const Vertex &val) const;
        bool operator>(const Vertex &val) const;
    };
    class Graph
    {
       public:
        Graph(int list_size);

        bool Add (int x, int y, int w);
        std::vector<int> FindPathes (int start);

       private:
        int _list_size;
        std::list<Vertex> *_adj_list;
    };

} // namespace Algorithms
#endif /* __DIIJKSTRA_H */