#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> bellman(std::vector<std::vector<std::pair<int, std::size_t>>>& adjlist){
    auto n = adjlist.size();
    // bellman-ford, but initialize distance to 0
    std::vector<int> height(n, 0);
    for(std::size_t k = 1; k < n; ++k){
        for(std::size_t u = 0; u < n; ++u){
            for(const auto& [weight, v]: adjlist[u]){
                height[v] = std::min(height[v], height[u] + weight);
            }
        }
    }
    // modify adjlist with new weight
    for(std::size_t u = 0; u < n; ++u){
        for(auto& [weight, v]: adjlist[u]){
            weight += (height[u] - height[v]);
        }
    }
    return height;
}

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, std::size_t>>>& adjlist, std::size_t i){
    // initialize distance to -1
    // the visited and distance vector are merged, with -1 as an unvisited value
    // since dijkstra deals with positive-weighted edges, using any negative number as an unvisited value is safe
    std::vector<int> distance(adjlist.size(), -1);
    // initialize pqueue with (0 distance, i vertex)
    std::priority_queue<std::pair<int, std::size_t>, std::vector<std::pair<int, std::size_t>>, std::greater<>> sequence;
    sequence.emplace(0, i);
    // iterate through all nodes
    while(!sequence.empty()){
        const auto [weight, u] = sequence.top();
        sequence.pop();
        // if u is unvisited, update distance[u] and visit all adjacent nodes
        if(distance[u] == -1){
            distance[u] = weight;
            for(const auto& [edge_weight, v]: adjlist[u]){
                // prevent putting visited nodes back in
                if(distance[v] == -1){
                    sequence.emplace(weight + edge_weight, v);
                }
            }
        }
    }
    return distance;
}

auto johnson(std::vector<std::vector<std::pair<int, std::size_t>>>& adjlist){
    // modify adjlist and obtain height vector
    auto height = bellman(adjlist);
    // temp[u][v] = min distance from u -> v (-1 means unreachable)
    auto n = adjlist.size();
    std::vector<std::vector<int>> temp(n);
    for(std::size_t i = 0; i < n ; ++i){
        temp[i] = dijkstra(adjlist, i);
    }
    return std::pair(height, temp);
}

int main(){
    std::size_t n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<std::pair<int, std::size_t>>> adjlist(n);
    for(int u, v, w; m--;){
        std::cin >> u >> v >> w;
        adjlist[u - 1].emplace_back(w, v - 1);
    }

    const auto [height, lookup] = johnson(adjlist);
    for(std::size_t u, v; q--;){
        std::cin >> u >> v;
        if(const auto& d = lookup[u - 1][v - 1]; d == -1){
            std::cout << "no path\n";
        }else{
            std::cout << d + height[v - 1] - height[u - 1] << '\n';
        }
    }
}
