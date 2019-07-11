#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int getmid(int s, int e){
	return  s + (e - s) / 2;
}
void buildTree(int *tree,int *a,int index,int s,int e)
{
	int m = getmid(s,e);
	

	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	
	tree[index] =max(tree[2*index],tree[2*index+1]);
	
	return;
}
int get_count(int *tree,int *a,int index,int s,int e,int l,int r,int cnt){

	if(s ==e &&a[s]<=r &&a[s] >=l){
		cnt++;
	}
		int m = getmid(s,e);
		int left = get_count(tree,a,2*index,s,m,l,r,cnt);
		int right = get_count(tree,a,2*index+1,m+1,e,l,r,cnt);
		cnt = cnt+left+right;
	return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
                                    
   
    
	int N,M;
	int l,r;
	
	//cin >> N >> M;
	scanf("%d %d",&N,&M);
	int treeindex = 1;											
    int s =0,e=N-1;
	
    int max_size = 4*N+1;
	int a[N];
	int cnt;
	for(int i=0 ;i<N ;i++){
		//cin >> a[i];
		scanf("%d",&a[i]);
	}
		int *tree = new int[max_size]; 
	 buildTree(tree,a,treeindex,s,e);
	 for(int i=0;i<max_size;i++){
	 	cout <<tree[i]<<" ";
	 }
	for(int i=0 ;i< M ;i++){
		//cin >>l >>r;
		scanf("%d %d",&l,&r);
		
		cout<<get_count(tree,a,treeindex,s,e,l,r,0)<<endl;
		//cout <<cnt <<'\n';
	}
	
	return 0;
}
