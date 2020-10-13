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
int lcs3(string s1,string s2,string s3){
	int n=s1.length();
	int m=s2.length();
	int o=s3.length();
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(o+1,0)));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=o;k++){
				if(s1[i-1]==s2[j-1] and s1[i-1]==s3[k-1]){
					dp[i][j][k]=1+dp[i-1][j-1][k-1];
				}else{
					dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	return dp[n][m][o];
}
/*
string printlcs(string s1,string s2){
	int n=s1.length();
	int m=s2.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int sum=0;
			if(s1[i-1]==s2[j-1]){
				sum=1+dp[i-1][j-1];
			}
			else{
				sum=max(dp[i-1][j],dp[i][j-1]);
			}
			dp[i][j]=sum;
		}
	}
	//return dp[n][m];

	string ans;
	
	int x=n;
	int y=m;
	while(x>0 and y>0){
		if(dp[x-1][y]==dp[x][y-1] and dp[x-1][y]!=dp[x][y]){
			ans+=s1[x-1];
			x--;
			y--;
		}else if(dp[x-1][y]>dp[x][y-1]){
			x--;
		}else{
			y--;
		}

	}
	reverse(ans.begin(),ans.end());

	return ans;
	
}
*/
int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	//double	pi=3.14159265358979323846;
	//sieve();
	
	string s1,s2,s3;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	int ans=lcs3(s1,s2,s3);
	
	cout<<ans<<endl;
	
	
	
	return 0;
	
}