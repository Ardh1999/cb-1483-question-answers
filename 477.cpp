#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int mx=INT_MIN;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		mx=max(a,mx);
	}
	cout<<mx<<'\n';
	return 0;
}