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
    if(a>=MOD)a-=b;
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
vector<ll>b,occ;

ll ele(ll x){
    ll ans=fpow(2,x-1);
    // cout<<"ele "<<x<<": "<<ans<<"\n";
    return ans;
}

ll f(ll l, ll r, ll p, ll j){
    if(l>=r)return 1;
    if(j==-1)return ele(occ[b[l]]);
    ll m=lower_bound(ALL(b),((b[l]>>(j+1))<<(j+1))|(1ll<<j))-b.begin();
    ll res=0;
	if(!p){
        res= mul(f(l,m,0,j-1),f(m,r,2,j-1));
		// cout<<"pingo\n";
    }
    else if(p==1){
        res= mul(f(l,m,1,j-1),f(m,r,2,j-1));
    }
    else {
        res= add(mul(f(l,m,2,j-1),f(m,r,2,j-1)),mul(f(l,m,1,j-1),f(m,r,1,j-1)));
    }
	cout<<"f "<<l<<","<<r<<" ("<<m<<") "<<j<<" "<<p<<": "<<res<<endl;
	return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll t;cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n);
        occ=vector<ll>(2*n+1);
        fore(i,0,n)cin>>a[i], occ[a[i]]++;
        // vector<ll>d;
        // fore(i,0,n+1)if(occ[i])d.pb(i);
        vector<vector<ll>> div(2*n+1);
        fore(i,1,2*n+1){
            for(int j = 0;j<2*n+1;j+=i){
                div[j].pb(i);
            }
        }
		imp(occ);
		imp(div[0]);
        ll ans=0;
        fore(x,0,2*n+1){
            b.clear();
            for(auto d:div[x])if(!x||d<x)b.pb(d);
            sort(ALL(b));
            cout<<"xor "<<x<<":\n";
			imp(b);
			ll res=f(0,SZ(b),0,63-__builtin_clzll(x?x:2*n+5)+5);
            if(x)res=mul(res,ele(occ[x]));
			cout<<res<<"\n\n";
            ans+=res;
        }
        cout<<ans<<"\n";

    }
}