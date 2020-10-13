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
    
    //cin>>t;
    
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            int c,r;
            cin>>c>>r;
            ans.pb({(c+r),(c-r)});
        }
		sort(ans.begin(),ans.end());
        int res=1,last=ans[0].first;
        for(int i=1;i<n;i++){
            if(ans[i].second>=last){
                res++;
                last=ans[i].first;
            }
        }
        cout<<(n-res)<<'\n';
        
    }
    
    return 0;
    
}