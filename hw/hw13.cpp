#include <iostream>
#include <algorithm>
using namespace std;
long long c[3001];
void fd(pair<int,int> a[],int n){
	//long long c[n+1];
	c[0] = 0;
	
	
	for(int i=1 ;i<= n ;i++){
		c[i] = 1000000000;
	}
	for (int i = 0; i < n; ++i){
		for (int j = n-1; j > 0; --j){
			if(a[i].second + c[j-1] <= a[i].first){		//�Y�ֿn��e�@�Ӫ����q�[�{�b�n�񪺤�{�b�o�Ӧa�i�t���� 
				c[j] = min(c[j],c[j-1] + a[i].second);	//�N���A�񪺱��p����ءA�@�ӬO���e����L��c[j],�άOc[j-1]�[�W��i�Ӫ����q 
			}											//�qn-1�˦^�ӬO�]�����e�����ƾڡA�i�H�����i���� 
		}												//�i�H�����a�ƭȶi�h�ոլ� 
		
	}
	
	for(int i=0 ;i<=n ;i++){
		cout << c[i] <<" ";		//c[i] �����O�ֿn���i�Ӫ����q�A�Y�L�k�A�ֿn�W�h�A�h�L�k�N1000000000��s���s���� 
		
	}
	cout << endl;
	for(int i=0 ;i<=n ;i++){
		
		if(c[i] == 1000000000){
			cout << i-1;
			break;
		}
	}
	
}
int main(){
	int n;
	int temw = 0;
	int cnt = 0;
	cin >> n;

	pair <int,int> p[n];
	for(int i=0 ;i < n ;i ++){
		cin >> p[i].second >> p[i].first;	//first->d[i] ,second->w[i] 
	}
	sort(p,p+n);	//�ھڥi�t�������q�Ƨ� 
	//cout <<endl;
	for(int i=0 ;i < n ;i ++){
		//cout << p[i].second <<" "<<p[i].first<<endl;
	}
	
	fd(p,n);
	

	return 0;
} 
