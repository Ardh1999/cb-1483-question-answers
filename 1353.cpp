#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005;
int dp[N][N][5];
int lcs(int arr1[], int n, int arr2[], int m, int k) 
{ 
  
    // If any of two array is over. 
    if (n <= 0 || m <= 0) 
        return 0; 
  
    // Making a reference variable to dp[n][m][k] 
    int& ans = dp[n][m][k]; 
  
    // If value is already calculated, return 
    // that value. 
    if (ans != -1) 
        return ans; 
  
    // calculating LCS with no changes made. 
    ans = max(lcs(arr1, n - 1, arr2, m, k),  
              lcs(arr1, n, arr2, m - 1, k)); 
  
    // calculating LCS when array element are same. 
    if (arr1[n-1] == arr2[m-1]) 
        ans = max(ans, 1 + lcs(arr1, n - 1,  
                                arr2, m - 1, k)); 
  
    // calculating LCS with changes made. 
	if(k>0)
    	ans = max(ans, 1 + lcs(arr1, n - 1,  
                          arr2, m - 1, k - 1)); 
  
    return ans; 
} 
int32_t main() {
	int n,m,k;
	cin>>n>>m>>k;
	int a1[n],a2[m];
	for(int i=0;i<n;i++){
		cin>>a1[i];
	}
	for(int i=0;i<m;i++){
		cin>>a2[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<lcs(a1,n,a2,m,k)<<'\n';
	return 0;
}
