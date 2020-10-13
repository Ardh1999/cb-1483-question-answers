#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MAX 1000005
#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
vector<int> primes;
bool is_prime[MAX];
void sieve(){
	is_prime[0]=is_prime[1]=true;
	for(int i=4;i<=MAX;i+=2){
		is_prime[i]=true;
	}
	for(int i=3;i*i<=MAX;i+=2){
		if(!is_prime[i]){
			for(int j=i*i;j<=MAX;j+=i){
				is_prime[j]=true;
			}
		}
	}
	primes.pb(2);
	for(int i=3;i<=MAX;i+=2){
		if(!is_prime[i]){
			primes.pb(i);
		}
	}
}
*/
map<ll,ll> mp;
ll solve(ll n){
	if(n==0 || n==1) return n;
	if(mp.count(n)) return mp[n];
	ll res=n;
	res=max(res,solve(n/2)+solve(n/3)+solve(n/4));
	mp[n]=res;
	return res;

}
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
	//double	pi=3.14159265358979323846;
	
	ll n;
	cin>>n;
	ll ans=solve(n);
	cout<<ans<<endl;
	
	return 0;
	
}