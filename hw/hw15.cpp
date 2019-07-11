#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int w,n;
	cin >> w >> n;
  
    pair<int,int> c[n];
    int x[n] , r[n];
    for(int i=0;i<n;i++){
        cin >> x[i] >>r[i];
        c[i].first = x[i] - r[i];
        c[i].second = x[i] + r[i];
    }
    sort(c,c+n);
    for(int i=0 ;i<n ;i++){
		cout << c[i].first <<" "<<c[i].second <<endl;
	}
    int temp=0,ans=0,i=0;
    while(temp<w && i<n)
    {
        ans++;
        int t = temp;
        if(c[i].first>temp){
            break;
        }
        while(c[i].first <= temp &&i<n)
        {
            t = max(t,c[i].second);		//取可以涵蓋到前範圍，且包到最後的點 
            i++;
        }
        temp = t;
    }
    if(temp<w) cout <<-1;
        
    else cout << ans;
}

