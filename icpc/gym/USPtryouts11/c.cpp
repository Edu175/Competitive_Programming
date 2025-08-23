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

pair<vv,vv> polydiv(vv p, vv q){
	ll n=SZ(p)-SZ(q)+1;
	vv b(n);
	for(ll k=n-1;k>=0;--k){
		b[k]=p.back()/q.back(); // assert
		fore(i,0,SZ(q))p[i+k]-=b[k]*q[i];
		p.pop_back();
	}
	return {b,p};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x0; cin>>n>>x0;
		vv a(n+1);
		fore(i,0,SZ(a))cin>>a[i];
		vv q={-x0,1};
		auto [d,r]=polydiv(a,q);
		cout<<r[0]<<"\n";
		imp(d)
	}
	return 0;
}
