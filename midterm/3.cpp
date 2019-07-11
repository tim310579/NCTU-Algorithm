#include <iostream>
#include <vector>

int main(){
    std::size_t n;
    std::cin >> n;

    std::vector<long long> sequence(n);
    for(auto& x: sequence){
        std::cin >> x;
    }

    auto cur = sequence[0];
    auto all = sequence[0];
    std::size_t l = 1, r = 1, tl = 1;;
    for(std::size_t i = 1; i < n; ++i){
        if(cur < 0){
            tl = i + 1;
            cur = sequence[i];
        }else{
            cur += sequence[i];
        }
        if(cur > all){
            all = cur;
            l = tl;
            r = i + 1;
        }
    }

    std::cout << l << ' ' << r;
}
