#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

map<tuple<ll,vv,ll>,ll> dp;

ll f(ll p, vv a, ll x){ // w/l position
	if(!SZ(a))return (p==0)==(x==0);
	tuple<ll,vv,ll> state={p,a,x};
	if(dp.count(state))return dp[state];
	auto &res=dp[state];
	res=1;
	fore(i,0,SZ(a)){
		vv ai=a; ll xi=x^(a[i]*(p==0));
		ai.erase(ai.begin()+i);
		ll cur=f(p^1,ai,xi);
		res=min(res,cur);
	}
	res^=1;
	// cout<<p<<" { ";
	// for(auto i:a)cout<<i<<" ";
	// cout<<"} "<<x<<": "<<res<<"\n";
	return res;
}

vector<vv> all;

vv a;
ll n,m;
void back(){
	if(SZ(a)==n){
		if(f(0,a,0))all.pb(a);
		return;
	}
	ll s=0;
	if(SZ(a))s=a.back();
	fore(c,s,m+1){
		a.pb(c);
		back();
		a.pop_back();
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		// dp.clear();
		ll n; cin>>n; n<<=1;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll win=f(0,a,0);
		if(win)cout<<"Menji\n";
		else cout<<"Bot\n";
	}
	return 0;
}
