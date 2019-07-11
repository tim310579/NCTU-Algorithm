#include <iostream>
#include <string>
using namespace std;
int getsth(string &s, int n, int i, int &tot){
	for(int j =0; j<4; j++){
		if(s[i] == '2'){
			i = getsth(s, n/2, i+1, tot);
		}
		else {
			tot += (s[i++] - '0') * (n * n); 
		}
	}
	//cout <<tot<<" ";
	return i;
}
int getans(string &s, int n){
	int tot = 0;
	if(s[0] == '2'){
		getsth(s, n/2, 1, tot);
	}
	else {
		tot = (s[0] - '0') * n * n;
	}
	return tot;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int n;
	cin >> n;
	cin.get();
	getline(cin,s);
	cout << getans(s, n);
}
