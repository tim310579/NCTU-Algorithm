#include <iostream>
#include <algorithm>
using namespace std;
pair <int,int> max(pair <int,int> p[]){
	int y =0;
	int z =0;
	for(int i=0 ;i<26 ;i++){
		if(y < p[i].first){
			y = p[i].first;
			z =	p[i].second;
		}
	}
	pair <int,int> ans;
	ans.first = y;
	ans.second = z;
	return ans;
}
int main(){
	string s;
	cin >> s;
	pair <int,int> p[26];
	for(int i=0 ;i<26 ;i++){
		p[i].second = i+65;		//acsii
	}
	for(int i=0 ;i< s.size() ;i++){
		//p[i].first = i+65;
		p[s[i]-65].first ++;	//cnt 
	}
	
	int ct =0;
	for(int i=0 ;i <26 ;i++){
		if(p[i].first != 0) ct ++;
	}
	//for(int j=0 ;j < ct ;j++){
		for(int i=0 ;i<ct ;i++){
		
			cout << max(p).second << " "<< max(p).first << endl;
			p[max(p).second-65].first = 0;
		
		}
	//}
	
}
