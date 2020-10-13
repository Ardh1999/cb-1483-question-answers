#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin>>q;
	while(q--){
	    int n;
	    cin>>n;
	    int a[n];
	    int dp1[n],dp2[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        dp1[i]=1;
	        dp2[i]=1;
	    }
	    for(int i=0;i<n;i++){
	        int j=0;
	        while(j<i){
	            if(a[j]<a[i]){
	                dp1[i]=max(dp1[i],dp1[j]+1);
	            }
	            j++;
	        }
	    }
	    //reverse(a,a+n);
	    for(int i=n-1;i>=0;i--){
	        int j=n-1;
	        while(j>i){
	            if(a[j]<a[i]){
	                dp2[i]=max(dp2[i],dp2[j]+1);
	            }
	            j--;
	        }
	    }
	    int mx=1;
	    for(int i=0;i<n;i++){
	        int ans=dp1[i]+dp2[i]-1;
	        mx=max(mx,ans);
	    }
	    cout<<mx<<endl;
	}
	return 0;
}
