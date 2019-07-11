#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iterator>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	int n;
	cin >>  n;
	long long a;
	priority_queue <long long, vector<long long>, greater<long long>> pq; 
	//vector<long long> s; 
	for(int i = 0 ;i <n ;i++){
		cin >> a;
		pq.push(a);
	}
	//sort(s.begin(),s.end());
	
	

	while(1){
		long long t1 = pq.top();
		pq.pop();
		long long t2 = pq.top();
		pq.pop();
		long long temp = (t1+t2) * 2;
		
		
		if(pq.empty()){
			cout << temp;
			break;
		}
		pq.push(temp);
	}
}
		
