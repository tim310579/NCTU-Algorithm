#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	cin.tie(NULL); 
	int n,m;

	cin >> n>> m;
	bool ma[n+1][m+1];	
	for(int i =0;i<= n;i++){
		for(int j=0 ;j<=m ;j++){
			ma[i][j] = false;
		}
	}
	char a[n+1][m+1];
	ma[0][1] = true;
	
	for(int i=1 ;i<= n ; i++){
		
		for (int j=1 ;j<= m ; j++){
			cin >> a[i][j];
			ma[i][j] = ( a[i][j] == '.') && (ma[i-1][j] || ma[i][j-1] );	//一位置的左或上可到，該位就可到 
				
		}
	}

	if(ma[n][m] == true) cout << "Yes";
	else if(ma[n][m] == false) cout << "No";
}
