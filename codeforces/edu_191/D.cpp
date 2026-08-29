#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
void zip(vv &a){
	vv vals(ALL(a));
	sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
	for(auto &i:a)i=lower_bound(ALL(vals),i)-vals.begin();
}
ll get_bad(vv a){
	ll n=SZ(a);
	vector<vv> pos(n);
	fore(i,0,n)pos[a[i]].pb(i);
	fore(c,0,n){
		auto v=pos[c];
		if(!SZ(v))continue;
		if(v.back()-v[0]+1!=SZ(v))return c;
	}
	return -1;
}
bool good(vv a, ll x, ll p){
	// cerr<<"good "<<a<<" "<<x<<" "<<p<<"\n";
	vv cands;
	fore(i,0,SZ(a)){
		if(a[i]==x){
			if(!SZ(cands))cands.pb(i-1);
		}
		else {
			if(SZ(cands)==1)cands.pb(i);
		}
	}
	for(auto i:cands)if(i>=0){
		vv b=a;
		b[p]=x;
		swap(b[p],b[i]);
		if(get_bad(b)==-1)return 1;
	}
	return 0;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		zip(a);
		ll x=get_bad(a);
		if(x==-1){
			cout<<"YES\n";
			continue;
		}
		vv p;
		fore(i,0,n)if(a[i]==x)p.pb(i);
		ll res=0;
		fore(w,0,2){
			ll i=w?p.back():p[0];
			vv b=a;
			b[i]=-1;
			if(w)reverse(ALL(b)),i=n-1-i;
			res|=good(b,x,i);
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
