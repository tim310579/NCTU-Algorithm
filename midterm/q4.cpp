#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, m, s;
	cin >> n >> m >> s;
	int a[n+1];
	int tot = 0;
	for(int i =1; i<=n; i++){
		cin >> a[i];
		tot += a[i];
	}
	int dp[n+1][m+1];

	for(int j = 0; j<=m; j++){
		dp[0][j] = 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j <= m; j++){
			if(j < a[i]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + a[i]); 
			}
		}
	}
	cout << tot - dp[n][m-s];
}
