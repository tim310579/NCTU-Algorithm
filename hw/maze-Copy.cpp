#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<bool>> maze(n + 1, std::vector(m + 1, false)); // extra top and left layer
    maze[0][1] = true; // makes sure (1,1) is reachable

    for(std::size_t i = 1; i <= n; ++i){
        std::cin.get(); // ignore '\n'
        for(std::size_t j = 1; j <= m; ++j){
            maze[i][j] = (std::cin.get() == '.') && (maze[i - 1][j] || maze[i][j - 1]);
        }
    }

    std::cout << (maze[n][m] ? "Yes\n" : "No\n");
}
