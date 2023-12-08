#include "dijkstra.hpp"
#include "heap.hpp"
#include <climits>
#include <utility>

namespace Algorithms {

    bool Vertex::operator<(const Vertex &val) const {
        return this->u < val.u;
    }
    bool Vertex::operator>(const Vertex &val) const {
        return this->u > val.u;
    }

    Graph::Graph(int list_size) : _list_size(list_size) {
        _adj_list = new std::list<Vertex>[_list_size];
    }

    bool Graph::Add(int x, int y, int w) {
        bool ret = false;
        if(x < _list_size && y < _list_size) {
            _adj_list[x].push_back(Vertex{ y, w });
            _adj_list[y].push_back(Vertex{ x, w });
            ret = true;
        }
        return ret;
    }

    std::vector<int> Graph::FindPathes(int start) {
        heap<Vertex> hp;
        std::vector<int> dists(_list_size, INT_MAX / 2);
        dists[start] = 0;
        hp.push(Vertex{ start, 0 });

        while(hp.size() != 0) {
            auto vert = hp.pop();
            auto adj = _adj_list[vert.u];

            for(const auto &n : adj) {
                auto res_dist = vert.w + n.w;
                if(res_dist < dists[n.u]) {
                    dists[n.u] = res_dist;
                    hp.push(Vertex{ n.u, dists[n.u] });
                }
            }
        }
        return dists;
    }

} // namespace Algorithms
