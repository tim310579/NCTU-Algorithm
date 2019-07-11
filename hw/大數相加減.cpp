#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

bool compare_to_0(string a){
	if(a[0] =='-') return true;
	else return false;
}
string compare(string a,string b){
	if(a[0]=='-'&&b[0]=='-'){
		if(a.size()>b.size()) return b;
	else if (a.size() <b.size()) return a;
	else for(int i=0;i <(a.size());i++){
		if(a[i] >b[i]) return b;
		else if(a[i] < b[i]) return a;
		else continue;
	}
}
	else if(a[0]=='-'&&b[0]!='-') return b;
	else if(a[0]!='-'&&b[0]=='-') return a;
	
	else if(a.size()>b.size()) return a;
	else if (a.size() <b.size()) return b;
	else for(int i=0;i <(a.size());i++){
		if(a[i] >b[i]) return a;
		else if(a[i] < b[i]) return b;
		else continue;
	}
}

string BigInegerMinus(string s1, string s2, bool negative) 
{
 
	if (s1.size() < s2.size())
	{
		return BigInegerMinus(s2, s1, true);
	}
	if (s1.size() == s2.size())
	{
		int i = 0;
		while(i < s1.size() && s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i])
		{
			return BigInegerMinus(s2, s1, true);
		}
	}
	string res(s1.size(), '0');
	int i = s1.size() -1, j = s2.size() - 1;
	int k = i;
	int borrow = 0;
	while(i >= 0 && j >= 0)
	{
		int sum = s1[i] - '0' - borrow - (s2[j] - '0');
		//cout<<sum<<endl;
		if (sum < 0)
		{
			borrow = 1;
			sum += 10;
			res[k--] = sum + '0';
		}
		else{
			borrow = 0;
			res[k--] = sum + '0';
		}
		i--;j--;
	}
	while(i >= 0)
	{
		int sum = s1[i--] - '0' - borrow;
		if (sum < 0)
		{
			borrow = 1;
			sum += 10;
			res[k--] = sum + '0';
		}
		else{
			borrow = 0;
			res[k--] = sum + '0';
		}
	}
	if (res[0] == '0')
	{
		//ignore the prefix '0's
		int index = 1;
		while(index < res.size() && res[index] == '0')
			index++;
		if (negative)
		{
			return "-" + res.substr(index, res.size() - index);
		}
		else return res.substr(index, res.size() - index);
	}
	else {
		if (negative)
		{
			return "-" + res;
		}
		else return res;
	}
}


string add(string num1,string num2){
	if(num1.size()<num2.size()){//把num1固定?位??大的那??，方便后面?理
		string temp=num1;
		num1=num2;
		num2=temp;
	}
	int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag是?位??
	while(length1>0){//?低位?始把??的位相加
		a=num1[length1-1]-'0';//?取num1?前位的?字
		if(length2>0)//如果num2??加完（注意，num2是位??少的）
			b=num2[length2-1]-'0';//?取num2?前位的?字
		else
			b=0;//如果num2加完了，num2??位上就?有??加了
				//??我?有break，因??然num2?有?字?加了，但可能?有?位需要加
		sum=a+b+flag;//num1与num2??位上的?字相加，再加上?位位
		if(sum>=10){//如果加起?大于于10，那就需要?位了
			num1[length1-1]='0'+sum%10;//?算加完之后，?前位??是多少
			flag=1;//把?位??置1
		}else{
			num1[length1-1]='0'+sum;//?算加完之后，?前位??是多少
			flag=0;//把?位??置0
		}
		length1--;//向高位移?1位
		length2--;//向高位移?1位
	}
	//如果?????位都加完了，?位位是1，?明位?要增加1了
	//比如99+1，加完之后，?成了三位?100，其?就是再在前面加一位1
	if(1==flag)
		num1="1"+num1;
	return num1;
}



/*
int main(){
	
	
	int N;
	
	while(cin >> N){
	
	if (N<1 || N>1000000) return 0;
	int a[N]={0};

	for(int i=0 ; i<N ;i++){
		cin >> a[i];
		if(a[i] >1000000000 ||a[i] <-1000000000) return 0;
	}
	
	string sum = {'0'};
	string M={'0'};
	string T={'0'};
	stringstream ss;
	int k=a[0];
	ss<<k;
	ss>>M;
	
	//int sum =0;
	//int M = a[0];
	
	for(int i=0 ;i<N ;i++){
		string temp;
		stringstream tt;
		tt<<a[i];
		tt>>temp;
		//cout <<temp[0] <<temp[1] <<endl;
		if(compare_to_0(temp) == true) {
			//cout <<"find" <<endl;
			temp.erase(0,1);
			sum = BigInegerMinus(sum, temp,false);
		
			} 
		else if(compare_to_0(temp) == false) {
			sum = add(sum,temp);
			
		}
		sum = compare(T,sum);
		//sum += a[i];
		//if(compare_to_0(sum)) {
		//	sum ={'0'};
		//}
		M = compare(sum ,M);
		//if(sum > M) M = sum;
		//else M = M;
		if(compare_to_0(M)) M={'0'};
	}

	cout << M <<endl;
}
	return 0;
}*/
int main(){
	unsigned int a = 999999937*999999937;
	cout <<a;
	return 0;
}
