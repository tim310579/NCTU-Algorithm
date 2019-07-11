#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int l=1, r=1;
	int temp = 1;
	cin >> n;
	int a[n];
	for(int i=0 ;i < n ;i++){
		cin >> a[i];
	}
	long long sum = a[0];
	long long M = a[0];
	for(int i = 1; i < n; i++){
		
		if(sum < 0) {
			sum = a[i];
			temp = i+1;
		}
		else{
			sum += a[i];
		} 
		if(sum > M){
			M = sum;
			l = temp;
			r = i+1;
		}
		
	}
	cout << l << " " << r;
}
