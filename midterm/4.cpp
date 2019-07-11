#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){
    std::size_t n;
    unsigned int s, m;
    std::cin >> n >> s >> m;

    unsigned int x, total = 0;
    std::vector<bool> able(s - m + 1, false);
    able[0] = true;
    for(std::size_t i = 0; i < n; ++i){
        std::cin >> x;
        total += x;
        for(std::size_t j = s - m; j >= x; --j){
            able[j] = able[j] || able[j - x];
        }
    }

    std::cout << total - (std::prev(rend(able)) - std::find(rbegin(able), rend(able), true));
}
