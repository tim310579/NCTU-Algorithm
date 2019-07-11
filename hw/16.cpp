#include <iostream>
using namespace std;
int main (){
	int n , m;
	cin >> n >> m;
	char maze[n][m];
	for(int i =0 ;i<n ;i++){
		for(int j=0 ;j<m ;j++){
			cin >> maze[i][j];
		}
	} 
	int x = 0;
	int ans = 0;
	int temp = 0;
	/*for(int j= 0; j <m ; j++){
			if(maze[x][j] == 'x'){
				temp = j;
			}
		}
		
		ans += temp;*/
	int tt = 0;		//tt is the times to go down
	for(int i =0 ;i<n ;i++){
		for(int j = 0 ;j< m-1 ;j++){
			if(maze[i][j] == 'x'){
				tt = i;
				//temp = j;
			}
		}
		
	}
	
	int temp1[n] ={0},temp2[n] ={0};
	//cout << temp;
	for(int x = 0 ; x <n ; x++){
		for(int j = m-2 ;j>0 ;j--){	//->->->| go right,down and left 
			if(maze[x][j] == 'x'){	//<-<-<-£¾ 
				temp2[x] = m-1-j;
				
			}
		}
	//	cout <<temp1 <<" ";
		for(int j = 1 ;j < m-1 ;j++){	//another
			if(maze[x][j] == 'x'){
				temp1[x] = j;
			}
		}
	}
	for(int x = 0 ; x <n ; x++){
		cout <<temp1[x] <<" "<<temp2[x]<<endl;
	}
	int l =0 ,r =0;
	
			l = temp1[tt];
			r = temp2[tt];
		
	for(int x = tt-1 ; x >= 0; --x){
		int templ = l;
		int tempr = r;
		l = min(templ + temp1[x]* 2 , tempr + m-1);		//(go left ,up,right to the last x ,back to left) or  (go right ,up left ,goto left)
		r = min(tempr + temp2[x]* 2 , templ + m-1);
			/*if(temp+temp2[x] > m-1-temp+m-1-temp1[x]){	
				ans += m-1-temp+m-1-temp1[x] ;
				temp = temp1[x];		//temp is the location of the upper row
			
			}
			else {
				ans += temp+temp2[x];
				temp = temp2[x];
			
			}*/
	
		
		//ans += temp ;
	}
	cout << l + tt;
	//cout <<" "<<tt;
}
