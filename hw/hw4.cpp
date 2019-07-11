#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool equiv(string s,string t){
	
	string s1,s2,t1,t2,temp1,temp2,temp3,temp4;
	int a,b;
	a = s.size();
	b = t.size();
	temp1 =s;
	temp2 =s;
	temp3 =t;
	temp4 =t;
	s1 = temp1.erase(a/2,a/2);
	s2 = temp2.erase(0,a/2);
	t1 = temp3.erase(b/2,b/2);
	t2 = temp4.erase(0,b/2);
	if(s == t) {
	return true;
	}
	else if(s1 == t1 &&s2 ==t2) return true;
	else if(s1 == t2 &&s2 ==t1) return true;
	
	else if(s1.size()!=1 && s2.size()!=1&&s1.size()%2==0&&s2.size()%2==0){
		return ((equiv(s1,t1)&&equiv(s2,t2))||(equiv(s1,t2)&&equiv(s2,t1)));
		
	}
	else 

		{
		return false;
	}
	
}
int main(){
	
	
	string s={' '},t={' '};
	cin >> s;
	cin >> t;
	//int a = s.size();
	//int b = t.size();
	if(equiv(s,t) == true) cout <<"YES";
	else cout <<"NO";
	
	return 0;
}
