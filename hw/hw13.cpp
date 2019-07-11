#include <iostream>
#include <algorithm>
using namespace std;
long long c[3001];
void fd(pair<int,int> a[],int n){
	//long long c[n+1];
	c[0] = 0;
	
	
	for(int i=1 ;i<= n ;i++){
		c[i] = 1000000000;
	}
	for (int i = 0; i < n; ++i){
		for (int j = n-1; j > 0; --j){
			if(a[i].second + c[j-1] <= a[i].first){		//若累積到前一個的重量加現在要放的比現在這個地可負重少 
				c[j] = min(c[j],c[j-1] + a[i].second);	//就能放，放的情況分兩種，一個是之前有算過的c[j],或是c[j-1]加上第i個的重量 
			}											//從n-1倒回來是因為有前面的數據，可以直接進行比較 
		}												//可以直接帶數值進去試試看 
		
	}
	
	for(int i=0 ;i<=n ;i++){
		cout << c[i] <<" ";		//c[i] 指的是累積到第i個的重量，若無法再累積上去，則無法將1000000000更新成新的值 
		
	}
	cout << endl;
	for(int i=0 ;i<=n ;i++){
		
		if(c[i] == 1000000000){
			cout << i-1;
			break;
		}
	}
	
}
int main(){
	int n;
	int temw = 0;
	int cnt = 0;
	cin >> n;

	pair <int,int> p[n];
	for(int i=0 ;i < n ;i ++){
		cin >> p[i].second >> p[i].first;	//first->d[i] ,second->w[i] 
	}
	sort(p,p+n);	//根據可負載的重量排序 
	//cout <<endl;
	for(int i=0 ;i < n ;i ++){
		//cout << p[i].second <<" "<<p[i].first<<endl;
	}
	
	fd(p,n);
	

	return 0;
} 
