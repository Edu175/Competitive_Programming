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
string s;
string t;
ll n,h;
map<string,vv> mp;
ll f(){
	if(SZ(t)==n){
		ll good=0;
		fore(k,0,h+1){
			auto a1=t.substr(0,h-k);
			auto b1=t.substr(h-k,k);
			auto b2=t.substr(h,k);
			auto a2=t.substr(h+k,h-k);
			ll cur=a1==a2&&b1==b2;
			if(cur)mp[t].pb(k);
			// if(cur)cout<<t<<": "<<k<<"\n";
			good|=cur;
		}
		return good;
	}
	ll i=SZ(t);
	ll res=0;
	for(auto c:{'a','b'})if(s[i]=='?'||s[i]==c){
		t.pb(c);
		res+=f();
		t.pop_back();
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>s; h=n/2;
		cout<<f()<<"\n";
		for(auto [s,v]:mp){
			cout<<s<<": "; imp(v)
		}
	}
	return 0;
}
