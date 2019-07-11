#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int sum,m;
	cin >> sum >> m;
	long long a[m];
	for(int i=0 ;i< m ; i++){
		cin >> a[i];
	}
	long long ans[sum+1] ={0};
	ans[0] = 1;
	//ans[1] = 1;
	for(int i=1 ;i <= sum ;i++){		//similar to climb stairs
		for(int j =0 ;j < m ;j++){
			if(i-a[j] >= 0){
				ans[i] += ans[i-a[j]]%(1000000000+7);
			}
		}
		//ans[i+1] = ans[i] +ans[i-1];
	}
	cout <<ans[sum] %(1000000000+7);
}

