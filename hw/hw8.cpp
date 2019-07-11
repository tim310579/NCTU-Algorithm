#include <iostream>
using namespace std;
struct item{
	string key;
};
item *IT[3001];
int main(){
	for(int i=0 ;i<3001 ;i++){
		IT[i] = new item;
		
	}
	int N,M;
	cin >> N >>M;
	string s;
	for(int i=0 ;i<N ;i++){
		cin >> s;
		IT[i]->key = s;
	}
	for(int i=0 ;i<N ;i++){
		for(int j=0 ;j <i ;j++){
			if(IT[i]->key == IT[j]->key){
				cout <<IT[j]->key;
			}
		}
	}
}
