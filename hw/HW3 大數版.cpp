#include <iostream>
#include <string>
#include <sstream>
#include<algorithm>
using namespace std;

int n=10;
string dezero(string a)//用?去掉正?前面的0，也就是?可以?入000001?似??的?字
{
	long int i;
	for(i=0;i<a.length();i++)
	{
		if(a.at(i)>48) break;
	}
	if(i==a.length()) return "0";
	a.erase(0,i);
	return a;
}
int judge(string a,string b)//判???正?的大小
{
	if(a.length()>b.length()) return 1;
	if(a.length()<b.length()) return -1;
	long int i;
	for(i=0;i<a.length();i++)
	{
		if(a.at(i)>b.at(i)) return 1;
		if(a.at(i)<b.at(i)) return -1;
	}
	return 0;
}
string Minus(string a,string b)//自然??法（在之前博客中?到?，?里直接挪???用了）
{
	a=dezero(a);
	b=dezero(b);
	long int i,j=0;
	string c="0";
	string c1,c2;
	string d="-";
	if(judge(a,b)==0) return c;
	if(judge(a,b)==1)
	{
		c1=a;
		c2=b;
	}
	if(judge(a,b)==-1)
	{
		c1=b;
		c2=a;
		j=-1;
	}
	reverse(c1.begin(),c1.end());
	reverse(c2.begin(),c2.end());
	for(i=0;i<c2.length();i++)
	{
		if(c2.at(i)>=48&&c2.at(i)<=57) c2.at(i)-=48;
		if(c2.at(i)>=97&&c2.at(i)<=122) c2.at(i)-=87;
	}
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=48&&c1.at(i)<=57) c1.at(i)-=48;
		if(c1.at(i)>=97&&c1.at(i)<=122) c1.at(i)-=87;
	}
	for(i=0;i<c2.length();i++)
	{
		c1.at(i)=c1.at(i)-c2.at(i);
	}
	for(i=0;i<c1.length()-1;i++)
	{
		if(c1.at(i)<0)
		{
			c1.at(i)+=n;
			c1.at(i+1)--;
		}
	}
	for(i=c1.length()-1;i>=0;i--)
	{
		if(c1.at(i)>0) break;
	}
	c1.erase(i+1,c1.length());
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=10) c1.at(i)+=87;
		if(c1.at(i)<10) c1.at(i)+=48;
	}
	reverse(c1.begin(),c1.end());
	if(j==-1) c1.insert(0,d);
	return c1;
}
string mod(string a,string b)//取模?算
{
	long int i,j=0;
	string c1,c2,c3,d;
	if(a.at(0)=='-') j=1;
	if(judge(a,b)==0) return "0";
	if(judge(a,b)==-1)
	{
		return a;
	}
	c1=dezero(a);
	c2=dezero(b);
	d="";
	for(i=0;i<c1.length();i++)
	{
		d=d+c1.at(i);
		while(judge(d,b)>=0)
		{
			d=Minus(d,b);
			d=dezero(d);
		}
	}
	if(j==1) d=Minus(b,d);
	return d;
}
int dp[50001][10000] ;

int main()
{

	dp[1][0] = 1;
	int i, j;
	for( i = 2 ; i <= 50000 ; i++ )
	{
		for( j = 0 ; j < 10000 ; j++ )
		{
			dp[i][j] += dp[i-1][j] + dp[i-2][j] +dp[i-2][j];
			dp[i][j+1] += dp[i][j]/10;
			dp[i][j] %= 10;
			
		}
	}
	
	int T;
	int n;
	cin >>T;
	if(T>100 ||T<=0) return 0;
	while(T>0)
	{
		T--;
		
		cin >> n;
		if(n>1000000000||n<=0) return 0;
		string str;
		
		//cout << "The Fibonacci number for " << n <<" is " ;
		//printf( "The Fibonacci number for %d is ", n );
		for( i = 9999 ; i >= 0 ; i-- )
		{
			if( dp[n][i] != 0 )
				break;
		}
	//	int tt[2000];
		int t=0;
			for( ; i >= 0 ; i-- ){
			stringstream ss;
			string k;
			ss<<dp[n][i];
			ss>>k;
			//cout <<k <<" ";
			//tt[i] = dp[n][i];
				str += k;
			//	printf( "%d", dp[n][i] );
		}
		str =mod(str,"999999937");
		cout <<str;
		//cout <<str;
		
		//	int a = sizeof(tt)/sizeof(tt[0]);
		//	for(int i=0; i<a;i++){
		//		cout <<tt[i];
		//	}
			cout <<endl;
	}
	return 0;
}
