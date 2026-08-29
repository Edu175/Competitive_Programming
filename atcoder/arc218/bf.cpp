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

void solve(vv a){
	ll n=SZ(a);
	ii bst={-1,0};
	fore(mk,1,1ll<<n){
		ll prev=1e9,inc=0,sz=0;
		fore(i,0,n)if(mk>>i&1){
			inc+=prev<a[i];
			prev=a[i];
			sz++;
		}
		ii cur={inc,-sz};
		bst=max(bst,cur);
	}
	cout<<-bst.snd<<"\n";
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	while(q--){
		ll l,r; cin>>l>>r; l--;
		vv b;
		fore(i,l,r)b.pb(a[i]);
		solve(b);
	}
	return 0;
}
