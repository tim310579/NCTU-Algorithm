#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define LL 1000000000
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int u, v, w;
	vector <pair<int,int>> p[n];
	for(int i=0 ;i < m ;i++){
		cin >> u >> v >> w;
		p[u].push_back(make_pair(w,v));
		p[v].push_back(make_pair(w,u));
	}
//	sort(p,p+n);
	int d[n];
	for(int i=0 ;i<n ;i++){
		d[i] = -1;
	}
	priority_queue <pair<int,int>> q;
	q.emplace(LL, 0);

	while(q.top().second != n-1){
		auto wv = q.top();
		
		q.pop();
		if(d[wv.second] == -1){
			d[wv.second] = wv.first;
			//cout <<wv.first <<" "<<wv.second<<endl;
			for(auto it = p[wv.second].begin();it != p[wv.second].end() ;it++){
				if(d[it->second] == -1){
					q.emplace(min(wv.first,it->first),it->second);
					//cout << wv.first<<" ";
				}
			}
		}
	}
	cout << q.top().first;
} 
