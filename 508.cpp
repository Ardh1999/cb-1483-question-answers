#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0;i<=n;i++){
		string s=to_string(i);
		v.push_back(s);
	}
	sort(v.begin(),v.end());
	for(string s:v){
		cout<<s<<' ';
	}
	return 0;
}