#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;
struct node{
	vector <int> adjlist;
	string color;
	int value;
	int length, pre;
};
node *vertex[100001];
void bfs(int a,int n){
	queue <int> q;
	int i = a;
	//for(int j =0 ;j< n ;j++){
		if(vertex[i]->color == "white"){
			vertex[i]->color = "gray";
			vertex[i]->length = 0;
			vertex[i]->pre = -1;
			q.push(i);
			while(!q.empty()){
				int u = q.front();
				for(auto it = vertex[u]->adjlist.begin();it != vertex[u]->adjlist.end() ; it ++){
					if(vertex[*it]->color =="white"){
						vertex[*it]->color = "gray";
						vertex[*it]->length = vertex[u]->length + 1;
						vertex[*it]->pre = u;
						q.push(*it);
					//q.push(vertex[*it]->value);
					} 
				}
				q.pop();
				vertex[u]->color = "black";
			}
		
			
		//q.pop();
		//vertex[i]->color = "black";
		}
	for(int i=0; i<n; i++){
		cout << vertex[i]->length<<" ";
	}
	cout <<endl;
	
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0 ;i<n ;i++){
		vertex[i] = new node;
		vertex[i]->color = "white";
		vertex[i]->value = 0;
		vertex[i]->length = 200000;
		vertex[i]->pre = -1; 
	}
	pair <int,int> p[n-1];
	for(int i=0 ;i<n-1 ;i++){
		cin >>p[i].first >> p[i].second;
		vertex[p[i].first]->adjlist.push_back(p[i].second);		//build adjacency
		vertex[p[i].second]->adjlist.push_back(p[i].first);
	}
	
	/*for(int i=0 ;i<n ;i++){
		cout <<i<< " : ";
		for(int j=0 ;j <vertex[i]->adjlist.size() ; j++){
			cout << vertex[i]->adjlist[j]<<" ";
		}
		cout <<endl;
	}*/
	bfs(0,n);		//first bfs
	int max =0;
	int loc =0;
	for(int i=0 ;i< n ;i++){
		if(max <= vertex[i]->length){
			max = vertex[i]->length;
			loc = i;
		} 
		//cout <<i <<" : "<< vertex[i]->color<<" "<<vertex[i]->length<<" "<<vertex[i]->pre <<" "<<endl;
	}
	for(int i=0 ;i<n ;i++){
		vertex[i]->color = "white";
		vertex[i]->length = 200000;
		vertex[i]->pre = -1; 
	}

	bfs(loc,n);		//second bfs
	int ans =0;
	for(int i=0 ;i<n ;i++){
		if(ans <= vertex[i]->length){
			ans = vertex[i]->length;
		}
		//cout << vertex[i]->value<<" ";
		//cout <<i <<" : "<< vertex[i]->color<<" "<<vertex[i]->length<<" "<<vertex[i]->pre <<" "<<endl;
	}
	cout <<ans ;
}
