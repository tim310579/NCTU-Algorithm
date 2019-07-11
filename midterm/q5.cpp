#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;
int main(){
	long long n, x;
	cin >> n >> x;
	long long se[4][n];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j<n; j++){
			cin >> se[i][j];
		}
	}
	unordered_map<long long, long long> ma;
	long long total = 0;
	for(int j = 1; j < n-2; j++){
		for(int i =0; i < j; i++){
			++ma[x - (se[0][i] + se[1][j])];
		}
		for(int k = j+2; k < n; k++){
			total += ma[se[2][j+1] + se[3][k]];
		}
	}
	cout << total;
}
