#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <array>
#include <unordered_map>

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

    std::unordered_map<long long, unsigned long long> lookup;
    unsigned long long total = 0;
    for(std::size_t j = 1; j < n - 2; ++j){
        for(std::size_t i = 0; i < j; ++i){
            ++lookup[x - (sequences[0][i] + sequences[1][j])];
        }
        for(std::size_t l = j + 2; l < n; ++l){
            total += lookup[sequences[2][j + 1] + sequences[3][l]];
        }
    }
    std::cout << total;
}
