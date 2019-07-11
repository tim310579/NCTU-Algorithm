#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <array>

int main(){
    std::size_t n;
    long long x;
    std::cin >> n >> x;

    std::array<std::vector<long long>, 4> sequences;
    for(auto& seq: sequences){
        seq.resize(n);
        for(auto& e: seq){
            std::cin >> e;
        }
    }

    std::vector<std::pair<long long, std::size_t>> lookup;
    lookup.reserve(n * n / 2);
    for(std::size_t i = 0; i < n; ++i){
        for(std::size_t j = i + 1; j < n; ++j){
            lookup.emplace_back(sequences[0][i] + sequences[1][j], j);
        }
    }
    std::sort(begin(lookup), end(lookup));

    long long total = 0;
    for(std::size_t i = 2; i < n; ++i){
        for(std::size_t j = i + 1; j < n; ++j){
            auto tx = x - sequences[2][i] - sequences[3][j];
            auto lower = std::lower_bound(begin(lookup), end(lookup), std::pair{tx, static_cast<std::size_t>(0)});
            auto upper = std::upper_bound(begin(lookup), end(lookup), std::pair{tx, i - 1});
            total += (upper - lower);
        }
    }
    std::cout << total;
}
