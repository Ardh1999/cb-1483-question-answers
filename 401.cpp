#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 100005
#define mod (int)(1e18+7)
#define sp fixed<<setprecision(12)
/*
vector<int> primes;
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
    
}

int power(int a,int n,int p){
    int res=1;
    while(n){
        if(n&1){
            res=(res*a)%p;
            n--;
        }else{
            a=(a*a)%p;
            n/=2;
        }
    }
    return res;
}
*/


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    //double    pi=3.14159265358979323846;

    int t=1;
    //cin>>t;
    //int it=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int type;
            cin>>type;
            if(type==1){
                int x,y;
                cin>>x>>y;
                int ans=(abs(x)*abs(x))+(abs(y)*abs(y));
                if(pq.size()<k){
                    pq.push(ans);
                }else{
                    if(ans<pq.top()){
                        pq.pop();
                        pq.push(ans);
                    }
                }
            }else{
                cout<<pq.top()<<'\n';
            }
        }
        
    }

    return 0;
    
}