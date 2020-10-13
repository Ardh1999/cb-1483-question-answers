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


int n,x,k;
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;

    int t=1;
    cin>>t;
    //int it=1;
    while(t--){
       set<pair<int,int>>st;
        map<int,int>m;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(m.find(x)==m.end()){ // x not occur before
                st.insert({-1,x});
                m[x]++;
            }
            else{
                st.erase({-m[x],x});
                m[x]++;
                st.insert({-m[x],x});
            }

            int count=0;
            vector<int>v;
            while(!st.empty())
            {
                auto p=*st.begin();
                cout<<p.second<<" ";
                st.erase(p);
                v.push_back(p.second);
                count++;
                if(count==k)
                    break;
            }
            for(auto it:v)
                st.insert({-m[it],it});

        }
        cout<<endl;

    }

    return 0;
    
}