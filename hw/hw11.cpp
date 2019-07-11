#include <iostream>
using namespace std;
long long c[3001][3001];
int knapsack(long long t[] ,long long v[], int n, int T)
{
	//long long c[n+1][n+1];
    for (int i = 0; i < n; ++i){ 
	    for (int j = 0; j <= T; ++j){
            if(j < t[i]){
                c[i+1][j] = c[i][j];
            }
            else{
                c[i+1][j] = max( c[i][j],c[i][j - t[i]] + v[i]);
            }
 		}
	}
	for(int i=0 ;i <n ;i++){
		//cout << c[i][T]<<" ";
	}
    return c[n][T];
}

int main(){
	int n,T;
	cin >> n >> T;
	long long t[n];
	long long v[n];
	for(int i =0 ;i<n ;i++){
		cin >> t[i] >>v[i];
	}
	cout << knapsack(t,v,n,T);		
	return 0;
}
