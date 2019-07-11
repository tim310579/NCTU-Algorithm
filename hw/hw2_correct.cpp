#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int N;
	

	cin >> N;
	
	int a[N]={ };

	for(int i=0 ; i<N ;i++){
		cin >> a[i];
	
	}

	long long sum =0;
	long long M =a[0];
	
	for(int i=0 ;i<N ;i++){
		sum += a[i];
		if(sum < 0) sum =0;
		if(sum > M) M = sum;
		else M = M;
		//M = max(sum,M);
	}
	if (M<0) M =0;
	cout << M;
	
	return 0;
}
