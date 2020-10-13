#include <bits/stdc++.h>
//#define ll long long int
#define pb push_back
//#define MAX 1000005
//#define mod 1000000007
//#define sp fixed<<setprecision(12)
using namespace std;



int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//double	pi=3.14159265358979323846;
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int v[n];
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    sort(v,v+n);
	    long int ans1=0,ans2=0;
	    for(int i=0;i<(n/2);i++){
	        ans1+=abs(v[i]-v[n-i-1]);
	    }
	    for(int i=0;i<n;i++){
			if(i%2==1){
				ans2+=abs(v[i]-v[i-1]);
			}
	        
	    }
	    cout<<ans2<<" "<<ans1<<endl;
	}
	
	return 0;
	
}
