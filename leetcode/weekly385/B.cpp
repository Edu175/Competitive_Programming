#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;
ll tr[MAXN][10];
ll cnt=1;
    
    ll add(ll x, char c){
        ll &res=tr[x][c-'0'];
        if(res!=-1)return res;
        return res=cnt++;
    }
    int longestCommonPrefix(vector<ll>& a, vector<ll>& b) {
        mset(tr,-1);
        //imp(a);imp(b);
        
        for(auto i:a){
            string s=to_string(i);
            ll x=0;
            for(auto j:s)x=add(x,j);
        }
        ll res=0;
        for(auto i:b){
            string s=to_string(i);
            ll x=0;
            fore(j,0,SZ(s)){
                x=tr[x][s[j]-'0'];
                if(x==-1){
                    res=max(res,j);
                    break;
                }
            }
            //cout<<i<<": "<<x<<"\n";
            if(x!=-1)res=max(res,(ll)SZ(s));
        }
        //cout<<res<<"\n\n";
        return res;
    }
int main(){
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		cout<<longestCommonPrefix(a,b)<<"\n";
	}
	return 0;
}
