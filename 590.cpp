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
	
	int n,K;
	cin>>n>>K;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}

    int s=0;
    int e=0;
    int r=-1,l=-1;
    int maxlen=0;
    while(e<n){
        if(A[e]==0) K--;
        if(K<0){
            if(A[s]==0) K++;
            s++;
        }
        if((e-s+1)>maxlen){
        	maxlen=e-s+1;
        	l=s;
        	r=e;
        }
        e++;     
    }
    cout<<maxlen<<endl;
	for(int i=0;i<n;i++){
		if(i>=l and i<=r){
			A[i]=1;
		}
		cout<<A[i]<<" ";
	}


	return 0;
	
}
