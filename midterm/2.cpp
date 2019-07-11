#include <iostream>
#include <string>

unsigned int get_impl(const std::string& seq, std::size_t i, unsigned int n, unsigned int& total){
    for(std::size_t j = 0; j < 4; ++j){
        if(seq[i] == '2'){
            i = get_impl(seq, i + 1, n / 2, total);
        }else{
            total += (seq[i++] - '0') * (n * n);
        }
    }
    return i;
}

unsigned int get(const std::string& seq, unsigned int n){
    unsigned int total = 0;
    if(seq[0] == '2'){
        get_impl(seq, 1, n / 2, total);
    }else{
        total = (seq[0] - '0') * n * n;
    }
    return total;
}

int main(){
    unsigned int n;
    std::cin >> n;
    std::cin.get();
    std::string buffer;
    std::getline(std::cin, buffer);
    std::cout << get(buffer, n);
}
