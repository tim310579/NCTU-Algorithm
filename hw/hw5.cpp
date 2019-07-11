#include <iostream>
#include <algorithm>
using namespace std;

int getmid(int s, int e){
	return  s + (e - s) / 2;
}
void buildTree(int *tree,int *a,int index,int s,int e)
{
	int m = getmid(s,e);
	

	if(s==e)
	{
		tree[index]=e;
		return ;
	}
	buildTree(tree,a,2*index,s,m);
	buildTree(tree,a,2*index+1,m+1,e);
	
	if(a[tree[2*index]] >= a[tree[2*index+1]]){
		
		//index = 2*index;
		tree[index] = tree[2*index];
		
	}
	else {
		//index = 2*index + 1;
		tree[index] = tree[2*index+1];
	}
	
	return;
}


int get_index(int *tree,int *a,int index,int s,int e,int l,int r)
{
	if(s>=l && e<=r){
		return tree[index];
	}
	
	else if(l>e || s>r){
		return r;
	}

		int m = getmid(s,e);
		int left = get_index(tree,a,2*index,s,m,l,r);
		int right = get_index(tree,a,2*index+1,m+1,e,l,r);
		if(a[left] >= a[right]){
		
			return left;
		}
		else {
			//index = 2*index + 1;
			return right;
		}

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
                                    
   
    
	int N,M;
	int l,r;
	
	cin >> N >> M;
	int treeindex = 1;											
    int s =0,e=N-1;
	int p[N];
    int max_size = 4*N+1;
	for(int i = 0; i<N; i++){
		
		cin >>p[i];
	}
	int *tree = new int[max_size]; 
	buildTree(tree,p,treeindex,s,e);
	for(int i=1 ;i<=M ;i++){
		
		cin >> l >> r;
   			l--;
			r--;
    cout << get_index(tree,p,treeindex,s,e,l,r) + 1 <<'\n';
  
	}
    return 0;

}
