#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define imp(v) {for(auto skjdf:v)cout<<skjdf<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
ll mul(ll a, ll b){return a*b%MOD;}
ll add(ll a, ll b){
    a+=b;
    if(a>=MOD)a-=MOD;
    return a;
}
ll sub(ll a, ll b){
    a-=b;
    if(a<0)a+=MOD;
    return a;
}
ll fpow(ll b, ll e){
    if(e<0)return 0;
    ll res=1;
    while(e){
        if(e&1)res=mul(res,b);
        b=mul(b,b);
        e>>=1;
    }
    return res;
}
const ll B=20;
struct matrix{
	vector<ll>x;
	matrix(): x(B){}
	bool add(ll v){
		if(v==0)return 0;
		for(ll j=B-1;j>=0;j--)v=min(v,v^x[j]);
		if(v){x[31-__builtin_clz(v)]=v;return 1;}
		return 0;
	}
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n);
        vector<ll>occ(2*n+1);
        fore(i,0,n)cin>>a[i], occ[a[i]]++;
        vector<vector<ll>> div(2*n+1);
        fore(i,1,2*n+1){
            for(int j = 0;j<2*n+1;j+=i){
                div[j].pb(i);
            }
        }
        ll ans=0;
        fore(x,0,2*n+1){
			ll c=0,d=0;
            matrix mt;
            for(auto dv:div[x]){
                c+=occ[dv];
                if(occ[dv])d+=mt.add(dv);
            }
            ll res=fpow(2,c-d);
            if(!mt.add(x))ans=add(ans,res);
            // cout<<"xor "<<x<<": "<<c<<" "<<d<<": "<<res<<"\n";
        }
        cout<<sub(ans,1)<<"\n";

    }
}