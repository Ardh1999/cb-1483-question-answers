#include <bits/stdc++.h>
#define ll long long int
#define MAX 100007
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
	double	pi=3.14159265358979323846;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int a=2;
		long long int b=3;
		if(n==1){
			cout<<a<<endl;
		}
		else if(n==2){
			cout<<b<<endl;
		}
		else{
			long long int c;
			for(int i=3;i<=n;i++){
				c=a+b;
				a=b;
				b=c;
			}
			cout<<c<<endl;
		}
	}

	
	return 0;
	
}
