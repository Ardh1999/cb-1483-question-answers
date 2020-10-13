#include<bits/stdc++.h>
using namespace std;
set<vector<int>> st;
int n,a[16];
void siu(int i,int target,vector<int> v){
	if(i==n){
		return;
	}
	if(target==0){
		if(v.size()>0){
			st.insert(v);
		}
		return;
	}
	if(a[i]<=target){
		v.push_back(a[i]);
		siu(i+1,target-a[i],v);
		v.pop_back();
	}
	siu(i+1,target,v);
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int target;
	cin>>target;
	vector<int> v;
	siu(0,target,v);
	for(auto x:st){
		for(auto z:x){
			cout<<z<<' ';
		}
		cout<<'\n';
	}
	return 0;
}