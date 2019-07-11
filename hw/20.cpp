#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <limits>

using namespace std;

void mean_cycle(vector <pair<int,int>> nod[], int n){
	double LL = numeric_limits<double>::infinity();
	double d[n+2][n];
	for(int i = 0 ;i<= n+1 ;i++){
		for(int j=0 ;j<n ;j++){
			d[i][j] = LL;
		}
	}
	int s = n;
	for(int i=0 ;i<n ;i++){
		nod[s].emplace_back(i,0);
	}
	
	d[0][s] = 0;
	
	for(int i = 1; i <= n+1; i++){
		for(int k = 0; k < n; k++){
			for(auto it = nod[k].begin(); it != nod[k].end(); it++){
				d[i][it->first] = min(d[i][it->first], d[i-1][k] + it->second);
			}
		}
	}
	
	double mean = LL;
	for(int i = 0; i < n; i++){
		
		double maxw = -LL;
		for(int k = 1 ;k<=n ;k++){
			maxw = max(maxw,(d[n+1][i] - d[k][i])/(n+1-k));
		}
		mean = min(mean , maxw);
	}
	
	cout << fixed << setprecision(6) << mean;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n , m ;
	cin >> n >> m;
	int u , v , w;
	vector <pair<int,int>> nod[n+2];
	for(int i=0 ;i< m; i++){
		cin >> u >> v >> w;
		nod[u-1].push_back({v-1,w});
	}
	
	mean_cycle(nod,n);
}
