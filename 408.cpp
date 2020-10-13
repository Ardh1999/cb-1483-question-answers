#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> ans;
		for(int i=0;i<n;i++){
			int c,r;
			cin>>c>>r;
			ans.push_back({r,c});
		}
		sort(ans.begin(),ans.end());
		int res=1,last=ans[0].first;
		for(int i=1;i<n;i++){
			if(ans[i].second>=last){
				res++;
				last=ans[i].first;
			}
		}
		cout<<res<<'\n';
	}
    
    return 0;
}