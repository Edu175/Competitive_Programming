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

vector<ii> get(vv a, ll fg){
	ll n=SZ(a);
	vv id(n); iota(ALL(id),0);
	vector<ii> res;
	fore(i,0,n){
		ll p=-1;
		fore(j,0,n)if(a[j]==i)p=j;
		res.pb({i,(fg?p:i)});
		a.erase(a.begin()+p);
		a.insert(a.begin()+i,i);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv p(n),q(n);
		fore(i,0,n)cin>>p[i],p[i]--;
		fore(i,0,n)cin>>q[i],q[i]--;
		auto a=get(p,0);
		auto b=get(q,1); reverse(ALL(b));
		for(auto i:b)a.pb(i);
		cout<<SZ(a)<<"\n";
		for(auto [v,i]:a)cout<<v+1<<" "<<i+1<<"\n";
	}
	return 0;
}