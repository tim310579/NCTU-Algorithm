#include <iostream>
#include <algorithm>
using namespace std;

int findmax(int* a,int size,int low,int high);


int main(){
	int N;
	cin >>N;
	if(N<1 || N>1000000) return 0;
	int a[N];
	for(int i=0; i<N; i++){
		cin >>a[i];
	
	}
	//int low,mid,high;
	int x = findmax(a,N,0,N-1);
	if (x<0) x =0;
	cout << x;
	return 0;
}
int crossmax(int* a, int size, int low, int mid, int high);
int findmax(int* a,int size,int low,int high){
		if(low == high) return a[low];
		int mid = (low + high)/2;
		int leftmax = findmax(a,size,low,mid);
		int rightmax = findmax(a,size,mid+1,high);
		int cross = crossmax(a, size, low, mid, high);
		return max(max(leftmax, rightmax), cross);
	}
	
int crossmax(int* a, int size, int low, int mid, int high){
	int leftmax = a[mid],leftsum =0;
	int rightmax = a[mid+1],rightsum =0;
	for(int i= mid; i >= low; --i){
		leftsum += a[i];
        leftmax = max(leftmax, leftsum);
	}
	for (int i = mid + 1; i <= high; ++i)
    {
        rightsum += a[i];
        rightmax = max(rightmax, rightsum);
    }
    return max(max(leftmax, rightmax), leftmax + rightmax);
} 
