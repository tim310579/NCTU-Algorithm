#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string a;
	int b[1000];
	int jk=65;
	int c[26]={0};
	int d[26]={0};
	int e[26]={0};
	while(cin >>a){
		int f=0;
		if(a.size()>1000) break;
		for(int i = 0; i<a.size(); i++){
			b[i] = a[i];
		//	cout << b[i] <<" ";	
		}
		sort(b,b+a.size());
		//for(int i = 0; i<a.size(); i++){
		//	cout <<b[i]<<" ";
	//	}
	
		
		for(int i = 0; i<a.size(); i++){
			for(int j =0;j<=25; j++){
				if(j+65 == b[i]){
					c[j]++;
				}
			}
			
		}
			
		for(int i=0;i<26;i++){
			d[i] =c[i];
		}
		for(int i=0;i<26;i++){
			e[i] =c[i];
		}
		for(int i=0;i<26;i++){
			if(e[i] != 0) f++;
		}
		
	for(int i=0;i<f ;i++){
		
			int x=0;
			//sort(c,c+26);
			int max =0;
			max = *max_element(c,c+26);
			for(int i=0 ;i<26 ;i++){
				if(c[i] == max) {
					c[i] =0;goto A;
					
				}
			}
			A:for(int j=0 ;j< 26; j++){
				if(d[j] == max){
					x = j;
					d[j] =0;
					goto B;
				}
			}
			B:cout << x+65 << " " << max <<endl;
			
		}
	}
	

	return 0;
} 
