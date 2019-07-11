#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,x;
	vector <long long> a,b,c,d;
	vector <long long> AA;
	vector <long long> BB;
	//int cnt =0;
	long long u;
	cin >>n >> x;
	//int a[n], b[n], c[n], d[n];
	for(int i=0 ;i<n ;i++){
		cin >> u;
		a.push_back(u); 
	}
	for(int i=0 ;i<n ;i++){
		cin >> u;
		b.push_back(u); 
	}
	for(int i=0 ;i<n ;i++){
		cin >> u;
		c.push_back(u); 
	}
	for(int i=0 ;i<n ;i++){
		cin >> u;
		d.push_back(u); 
	}
	//int tem[n*n];
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<n ;j++){
			AA.push_back(a[i]+b[j]);
			BB.push_back(c[i]+d[j]);
		}
	}
	sort(AA.begin(),AA.end());
	sort(BB.begin(),BB.end());
	for(int i =0 ;i<n*n ;i++){
		cout <<AA[i]<<" ";
	}
	cout <<endl;
	for(int i =0 ;i<n*n ;i++){
		cout <<BB[i]<<" ";
	}
	cout <<endl;
	

	

	long long ct=0;
	for(int i=0 ;i<n*n ;i++){
		pair<vector<long long>::iterator,vector<long long>::iterator> range = equal_range(BB.begin(),BB.end(),x-AA[i]);
		//ct +=count(BB.begin(),BB.end(),x-AA[i]);
		//cout << range.first <<" "<< range.second <<" ";
		//int u = range.second - range.first;
		ct += range.second - range.first;
		//cout <<u <<" ";
		auto bounds = equal_range(BB.begin(),BB.end(),x-AA[i]);
		cout << bounds.first-BB.begin()<< " "<<bounds.second-BB.begin() <<" ";
	}
	//cout <<endl;
	
	cout <<ct;
	
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,x;
	vector <long long> a,b,c,d;
	vector <long long> AA;
	vector <long long> BB;
	//int cnt =0;
	long long u;
	cin >>n >> x;
	//int a[n], b[n], c[n], d[n];
	for(int i=0 ;i<n ;i++){
		cin >> u;
		a.push_back(u); 
	}
	for(int i=0 ;i<n ;i++){
		cin >> u;
		b.push_back(u); 
	}
	for(int i=0 ;i<n ;i++){
		cin >> u;
		c.push_back(u); 
	}
	for(int i=0 ;i<n ;i++){
		cin >> u;
		d.push_back(u); 
	}
	//int tem[n*n];
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<n ;j++){
			AA.push_back(a[i]+b[j]);
			BB.push_back(c[i]+d[j]);
		}
	}
	//sort(AA.begin(),AA.end());
	sort(BB.begin(),BB.end());
	/*for(int i =0 ;i<n*n ;i++){
		cout <<AA[i]<<" ";
	}
	cout <<endl;
	for(int i =0 ;i<n*n ;i++){
		cout <<BB[i]<<" ";
	}
	cout <<endl;*/
	

	

	long long ct=0;
	for(int i=0 ;i<n*n ;i++){
		pair<vector<long long>::iterator,vector<long long>::iterator> range = equal_range(BB.begin(),BB.end(),x-AA[i]);
		//ct +=count(BB.begin(),BB.end(),x-AA[i]);
		//cout << range.first <<" "<< range.second <<" ";
		//int u = range.second - range.first;
		ct += range.second - range.first;
		//cout <<u <<" ";
	}
	//cout <<endl;
	cout <<ct;
	
}
