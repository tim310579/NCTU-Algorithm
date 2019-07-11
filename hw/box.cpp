#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::vector<std::pair<unsigned int, unsigned int>> boxes = []{
        std::size_t n;
        std::cin >> n;
        std::vector<std::pair<unsigned int, unsigned int>> mboxes(n);
        for(std::size_t i = 0; i < n;){
            std::cin >> mboxes[i].second >> mboxes[i].first;
            if(mboxes[i].second > mboxes[i].first){
                --n; // bad box
            }else{
                ++i; // good box
            }
        }
        mboxes.resize(n);
        std::sort(mboxes.begin(), mboxes.end());
        return mboxes;
    }();

    std::vector<unsigned int> weights(boxes.size() + 1, std::numeric_limits<unsigned int>::max());
    
    weights[0] = 0;
    for(const auto& box: boxes){
        for(std::size_t i = weights.size() - 1; i > 0; --i){
            if(weights[i - 1] <= box.first - box.second){
                weights[i] = std::min(weights[i], weights[i - 1] + box.second);
            }
        }
    }
	for(int i=0 ;i<weights.size();i++ ){
		std::cout << weights[i]<<" ";
	}
    std::cout << std::find(weights.begin(), weights.end(), std::numeric_limits<unsigned int>::max()) - weights.begin() - 1;
}
