#include <bits/stdc++.h>
#define int long long int
#define pb push_back

#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
const int MAX=10000005;
vector<int> primes;
bitset<MAX> is_prime;
void sieve(){
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(int i=4;i<MAX;i+=2){
        is_prime[i]=0;
    }
    for(int i=3;i*i<MAX;i+=2){
        if(is_prime[i]){
            primes.pb(i);
            for(int j=i*i;j<MAX;j+=i){
                is_prime[j]=0;
            }
        }
    }
}
*/
/*
void lcs(char s1[],char s2[]){
    int n=strlen(s1);
    int m=strlen(s2);
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
    
    int index=dp[n][m];
    //cout<<index<<endl;
    char ans[index+1];
    ans[index]='\0';
    index--;
    int x=n;
    int y=m;
    while(x>0 and y>0){
        if(dp[x-1][y]==dp[x][y-1] and dp[x-1][y]!=dp[x][y]){
            ans[index]=s1[x-1];
            index--;
            x--;
            y--;
        }else if(dp[x-1][y]>dp[x][y-1]){
            x--;
        }else{
            y--;
        }

    }
    //reverse(ans.begin(),ans.end());

    cout<<ans;
    return;
}
*/


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;
    //sieve();
    int t=1;
    
    cin>>t;
    
    for(int tc=1;tc<=t;tc++){
        int n,k;
        cin>>n>>k;
        int ans=INT_MAX;
        for(int i=2;i*i<=k;i++){
            if(k%i==0){
                int cnt=0;
                while(k%i==0){
                    cnt++;
                    k/=i;
                }
                int c=0;
                int p=i;
                while(p<=n){
                    c+=(n/p);
                    p*=i;
                }
                ans=min(ans,(c/cnt));
            }
        }
        if(k>1){
            int cnt=0;
            int p=k;
            while(p<=n){
                cnt+=(n/p);
                p*=k;
            }
            ans=min(ans,cnt);
        }
        if(ans==INT_MAX){
            ans=0;
        }
        cout<<ans<<'\n';
    }
    
    return 0;
    
}