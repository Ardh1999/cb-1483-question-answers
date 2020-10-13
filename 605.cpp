#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAX 1000005
#define mod (int)(1e9+7)
#define sp fixed<<setprecision(12)

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    //double    pi=3.14159265358979323846;

    int t=1;
    cin>>t;
    //int it=1;
    while(t--){
        int n;
        cin>>n;
        set<int> fix,pos;
        pos.insert(1);
        int i=1;
        while(i<=n){
            int x=*pos.begin();
            fix.insert(x);
            pos.erase(x);
            pos.insert(2*x);
            pos.insert(3*x);
            pos.insert(5*x);
            i++;
        }
        cout<<*fix.rbegin()<<'\n';
    }

    return 0;
    
}
