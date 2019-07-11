#include <iostream>
#include <algorithm>
//#include <stdio.h>
#include <math.h>
#define LL 1000001   //LL不能太大 
using namespace std;
int getMid(int s, int e) { 
	return s + (e -s)/2; 
} 
//qs->l
//qe->r
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) 
{ 
   
    if (qs <= ss && qe >= se) 
        return st[si]; 
  
    if (se < qs || ss > qe) 
        return 0; 
  
    int mid = getMid(ss, se); 
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 

int getSum(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        //printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 
  
int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
{ 
   
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 
    int mid = getMid(ss, se); 
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) + 
              constructSTUtil(arr, mid+1, se, st, si*2+2); 
    return st[si]; 
} 
  
int *constructST(int arr[], int n) 
{ 
    int x = (int)(ceil(log2(n)));  
  
    int max_size = 2*(int)pow(2, x) - 1;  
    int *st = new int[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0); 
    return st; 
} 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N,M;
	int l,r;
	
	cin >> N >> M;

	int a[N];
	int cnt;
	int u[LL]={0};

	for(int i=0 ;i<N ;i++){
		cin >> a[i];
		
	}
	for(int i=0 ;i<N ;i++){
		u[a[i]]++;
	}
	int *st = constructST(u,LL);
	
	for(int i =0; i<M; i++){
		//int cnt =0;
		cin >> l >> r;
		cout << getSum(st,LL,l,r)<<'\n';
		//for(int j =l ;j<=r ;j++){
		//	cnt+= u[j];
		//}
		//cout <<cnt<<'\n';
	}

	
	return 0;
}
