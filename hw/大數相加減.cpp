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
	if(num1.size()<num2.size()){//��num1�T�w?��??�j����??�A��K�Z��?�z
		string temp=num1;
		num1=num2;
		num2=temp;
	}
	int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;//flag�O?��??
	while(length1>0){//?�C��?�l��??����ۥ[
		a=num1[length1-1]-'0';//?��num1?�e�쪺?�r
		if(length2>0)//�p�Gnum2??�[���]�`�N�Anum2�O��??�֪��^
			b=num2[length2-1]-'0';//?��num2?�e�쪺?�r
		else
			b=0;//�p�Gnum2�[���F�Anum2??��W�N?��??�[�F
				//??��?��break�A�]??�Mnum2?��?�r?�[�F�A���i��?��?��ݭn�[
		sum=a+b+flag;//num1�Onum2??��W��?�r�ۥ[�A�A�[�W?���
		if(sum>=10){//�p�G�[�_?�j�_�_10�A���N�ݭn?��F
			num1[length1-1]='0'+sum%10;//?��[�����Z�A?�e��??�O�h��
			flag=1;//��?��??�m1
		}else{
			num1[length1-1]='0'+sum;//?��[�����Z�A?�e��??�O�h��
			flag=0;//��?��??�m0
		}
		length1--;//�V���첾?1��
		length2--;//�V���첾?1��
	}
	//�p�G?????�쳣�[���F�A?���O1�A?����?�n�W�[1�F
	//��p99+1�A�[�����Z�A?���F�T��?100�A��?�N�O�A�b�e���[�@��1
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
