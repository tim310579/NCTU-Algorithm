#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <set>
#include <utility>
#define LL 1000000000
using namespace std;

struct node{
	int length = 0;
	int h = 0;

};
void bellman(node *vertex[],vector <pair<int,int>> nod[],int n){
	for(int i=1 ;i<=n ;i++){
		vertex[i]->h = LL;
	}
	vertex[0] = new node;
	vertex[0]->h = 0;
	for(int i = 1 ;i<=n ;i++){
		nod[0].push_back(make_pair(i,0));
	}
	//for(int k= 0 ;k <=n ;k++){
	
		for(int i = 1 ;i <= n ;i++){
			for(auto it = nod[i].begin() ;it != nod[i].end() ;it++){
				//if( vertex[i]->h + it->second < vertex[it->first]->h){
				vertex[it->first]->h = min(vertex[i]->h + it->second,vertex[it->first]->h);
				
			}
		}
	//}
	
}
void modify(node *vertex[],vector <pair<int,int>> nod[],int n){
	
	for(int i = 1; i<= n ;i++){
		vertex[i] = new node;
		vertex[i]->h = 0;
		vertex[i]->length = LL;
	}
	bellman(vertex, nod ,n);
	for(int i=1 ;i<=n ;i++){
		for(auto it = nod[i].begin(); it != nod[i].end() ;it ++){
			it->second = it->second + vertex[i]->h - vertex[it->first]->h;
		}
	}
	
}
void Dijk(vector <int> ans[], node *vertex[],vector <pair<int,int>> nod[],int s ,int n){
	for(int i = 1; i<=n ;i++){
		//vertex[i] = new node;
		vertex[i]->length = LL;
	}
	vertex[s]->length = 0;
	priority_queue <pair<int ,int>, vector<pair<int, int>>, greater<pair<int,int>>> qu;
	qu.emplace(vertex[s]->length,s);
	while(!qu.empty()){
		int d = qu.top().first;
		int u = qu.top().second;
		qu.pop();
		for(auto it = nod[u].begin() ;it != nod[u].end() ;it++){
			if(it->second + d < vertex[it->first]->length){
				//qu.erase(make_pair(vertex[it->first]->length,it->first));
				vertex[it->first]->length = it->second + d ;
				qu.emplace(vertex[it->first]->length,it->first);
			}
		}
	}
	for(int i=1 ;i <= n ;i++){
		if(vertex[i]->length == LL){
			vertex[i]->length = LL;
		}
		else vertex[i]->length = vertex[i]->length -vertex[s]->h +vertex[i]->h;
		//cout << vertex[i]->length <<" ";
		ans[s].push_back(vertex[i]->length);
	}
	//cout <<endl;
}
int main(){
	int n , m, q;
	cin >> n >> m >> q;
	node *vertex[n+1];
	int u , v , w;
	vector <pair<int,int>> nod[n+1];
	vector <int> ans[n+1];
	for(int i=0 ;i< m; i++){
		cin >> u >> v >> w;
		nod[u].push_back({v,w});
	}
	modify(vertex ,nod ,n);
	for(int i =1 ;i <= n ;i++){
		Dijk(ans ,vertex,nod,i,n);
	}
	//int x[q+1] ={0},y[q+1]={0};
	int x[q] ,y[q];
	for(int i = 0 ; i< q ;i++){
		//cin >> x[i] >> y[i];
		cin >> x[i] >> y[i];
		
		//cout <<length[x][y]<<endl;
	}
	for(int i=0 ; i< q ;i++){
		auto it = ans[x[i]].begin() + y[i]-1;
		if(*it == LL) cout <<"no path" <<endl;
		else cout << *it << endl;
	}
}
