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


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//double	pi=3.14159265358979323846;
	//sieve();
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int dp[n+1]={0};
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<=n;i++){
			int ct=0;
			if(i>m){
				dp[i]=(dp[i-1]+dp[i-m])%mod;
			}
			else if(i<m){
				dp[i]=1;
			}else{
				dp[i]=2;
			}
		}
		cout<<(dp[n]%mod)<<"\n";
	}


	return 0;
	
}
