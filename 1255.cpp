#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define MAX 10000005
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
vector<int> primes;
ll sumprime[MAX];
bool is_prime[MAX];
void sieve(){
	is_prime[0]=is_prime[1]=true;
	for(int i=4;i<MAX;i+=2){
		is_prime[i]=true;
	}
	for(int i=3;i*i<MAX;i+=2){
		if(!is_prime[i]){
			for(int j=i*i;j<MAX;j+=i){
				is_prime[j]=true;
			}
		}
	}
	for(int i=0;i<MAX;i++){
		if(!is_prime[i]){
			sumprime[i]=sumprime[i-1]+i;
		}else{
			sumprime[i]=sumprime[i-1];
		}
	}
}
*/

int optimal_game(int arr[],int s,int e,vector<vector<int>> &dp){
	if(s>e){
		return 0;
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	int op1=arr[s]+min(optimal_game(arr,s+2,e,dp),optimal_game(arr,s+1,e-1,dp));
	int op2=arr[e]+min(optimal_game(arr,s,e-2,dp),optimal_game(arr,s+1,e-1,dp));
	return dp[s][e]=max(op1,op2);
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//double	pi=3.14159265358979323846;
	//sieve();
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<vector<int>> dp(n,vector<int>(n,-1));
	int ans=optimal_game(a,0,n-1,dp);
	cout<<ans<<endl;
	

	return 0;
	
}
