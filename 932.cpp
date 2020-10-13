#include<bits/stdc++.h>
using namespace std;
int32_t main() {
	int n;
	cin>>n;
 	vector<int> v;
	 //v.push_back(0);
	while(n--){
		int x;
		cin>>x;
		if(x==0){
			int a;
			cin>>a;
			v.push_back(a);
		}else{
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			int y=0;
			for(int i=l;i<=r;i++){
				y=max(y,(v[i]^x));
			}
			cout<<(y^x)<<'\n';
		}

	}
	return 0;
}