#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	cin.tie(NULL); 
	int Data;
	cin >>Data;
while(Data >0){
	Data --;
	string str;
	string temp;
	string tot;
	
	int count[100000] ={0};

	int N;
	//int ph[8]={0};
	cin >>N;
	int u[N];
	for(int k=0; k<N; k++){
		cin >>str;
	
		for(int j =0;j<str.size() ;j++){
			if(str[j] =='-'){
			str.erase(j,1);
			j--;
			}
		}
		
		for(int i=0 ;i<7 ;i++){
			
			if (str[i] <= 'C'&& str[i] >= 'A') str[i] ='2'; //ABC
			else if (str[i] <= 'F'&& str[i] >= 'D') str[i] ='3';//DEF
			else if (str[i] <= 'I'&& str[i] >= 'G') str[i] ='4';//GHI
			else if (str[i] <= 'L'&& str[i] >= 'J') str[i] ='5';//JKL
			else if (str[i] <= 'O'&& str[i] >= 'M') str[i] ='6';//MNO
			else if (str[i] <= 'S'&& str[i] >= 'P') str[i] ='7';//PRS
			else if (str[i] <= 'V'&& str[i] >= 'T') str[i] ='8';//TUV
			else if (str[i] <= 'Y'&& str[i] >= 'W') str[i] ='9';//WXY
			//else str[i] = str[i];
		}
	
		
		stringstream dd;
		dd <<str;
		dd >>u[k];
		
	}

	sort(u,u+N);//排序u 

	
	int cnt =0;
	for(int i=0 ;i<N ;i++){ //計算每個數字出現次數 
		
		if(u[i] == u[i+1]){
			count[cnt]++; 
			u[i] =10000000;
		}
		else if(u[i] != u[i+1]){
			cnt++;
		} 
		
	}
	sort(u,u+N);

	
	if (*max_element(count,count+N) ==0) { //沒重複的情況 
	 cout << "No duplicate."<<'\n'; 

	}
	else{									//有重複的情況 
		for(int i=0; i<=cnt ;i++){			//出現次數都要大於一才印出 
			if(count[i] >= 1){
				cout <<setw(3) << setfill('0') <<u[i]/10000 <<"-" << setw(4) << setfill('0') <<u[i]%10000 << " "<< count[i]+1 << '\n';
		
			}
		
		}
	}
	cout <<'\n';
}
}
