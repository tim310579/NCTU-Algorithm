#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;


struct matrix{
	long long a[2][2];
	//int a[2][2] = {{1,2},{1,0}};
};
matrix ans,ini;
matrix matmulti(matrix x, matrix y){
	matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	 for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            for(int k=0;k<2;k++) {
            	
                temp.a[i][j]= ((temp.a[i][j]%999999937)+((x.a[i][k]%999999937)*(y.a[k][j]))%999999937)%999999937;
                }
            }
       }
       return temp;
}
int main(){
	

	int T;
	int N;
	long long last[2] = {0};
	cin >> T;

	for(int i=0 ;i<T ;i++){
		
		cin >> N;
		
		//if(N ==1 || N ==2) goto A;
		N = N-1;
		ini.a[0][0] =1;
		ini.a[0][1] =2;
		ini.a[1][0] =1;
		ini.a[1][1] =0;

		ans.a[0][0] =1;
		ans.a[0][1] =0;
		ans.a[1][0] =0;
		ans.a[1][1] =1;
		while(N>0){
			if(N&1==1){
				cout << ans.a[0][0] <<" "<<ans.a[0][1]<<"jsa"<<endl;
				cout << ans.a[1][0]<<" "<<ans.a[1][1]<<endl;
				ans = matmulti(ans,ini);
				cout << ans.a[0][0] <<" "<<ans.a[0][1]<<endl;
				cout << ans.a[1][0]<<" "<<ans.a[1][1]<<endl;
			}
			N>>=1;
				ini = matmulti(ini,ini);
				cout << N <<" "<<endl;
				cout << ini.a[0][0]<<" "<<ini.a[0][1]<<"jk"<<endl;
				cout << ini.a[1][0]<<" "<<ini.a[1][1]<<endl;
		}
	
		
		last[0] = (ans.a[0][0]%999999937 + ans.a[0][1])%999999937 ;
		last[1] = (ans.a[1][0]%999999937 + ans.a[1][1])%999999937 ;
		
	//	cout << ans.a[0][0] <<" "<<ans.a[0][1] <<endl;
	//	cout << ans.a[1][0] <<" "<<ans.a[1][1] <<endl;
		cout << last[1] << endl;
	}
	return 0;
}
