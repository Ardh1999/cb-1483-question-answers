#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define Pii pair<int,int>
#define SS second 
#define F first
#define mod 1000000007
#define ld long double
#define sp fixed<<setprecision(12)
using namespace std;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

unordered_map<string,bool> mp;

bool wpm(string s,string t,int i,int j){
	string temp=to_string(i)+to_string(j);
	if(mp.count(temp)){
		return mp[temp];
	} 
    if(j==t.length()){
        return mp[temp]=(i==s.length());
    }
    if(i==s.length()){
        for(int k=j;k<t.length();k++){
            if(t[k]!='*'){
                return mp[temp]=false;
            }
        }
        return mp[temp]=true;
    }
    if(t[j]==s[i] or t[j]=='?'){
        return mp[temp]=wpm(s,t,i+1,j+1);
    }
    if(t[j]=='*'){
        return mp[temp]=(wpm(s,t,i+1,j) or wpm(s,t,i,j+1));
    }
    return mp[temp]=false;

}

void solve(){
    string s,t;
    cin>>s>>t;
    cout<<wpm(s,t,0,0);
    


}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //double    pi=3.14159265358979323846;
    //sieve();
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
    
}//Ardhendu Reja , JGEC