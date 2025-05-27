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

ll cant(vv a){
	auto vals=a;
	sort(ALL(vals));
	for(auto &i:a)i=lower_bound(ALL(vals),i)-vals.begin();
	ll n=SZ(a);
	vv vis(n);
	ll z=0;
	fore(x,0,n)if(!vis[x]){
		z++;
		for(ll y=x;!vis[y];y=a[y])vis[y]=1;
	}
	return n-z;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv b,c;
		fore(i,0,n){
			cin>>a[i];
			a[i]--;
			if(i&1)c.pb(a[i]);
			else b.pb(a[i]);
		}
		ll good=cant(b)%2==cant(c)%2;
		sort(ALL(b));
		sort(ALL(c));
		if(!good){
			auto &d=(n%2==0?c:b);
			swap(d[SZ(d)-2],d[SZ(d)-1]);
		}
		fore(i,0,n)a[i]=((i&1?c:b)[i/2])+1;
		imp(a)
	}
	return 0;
}
