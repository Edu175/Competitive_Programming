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

int main(){FIN;
	ll n,m,l; cin>>n>>m>>l;
	vector<ll> a(n),b(m);
	fore(i,0,n)cin>>a[i];
	vector<ii>p;
	fore(i,0,m)cin>>b[i],p.pb({b[i],i});
	sort(ALL(p));
	set<ll> st[n];
	fore(i,0,l){
		ll u,v; cin>>u>>v; u--,v--;
		st[u].insert(v);
		//sb[v].insert(u);
	}
	ll res=0;
	fore(u,0,n){
		for(ll j=m-1;j>=0;j--){
			ll v=p[j].snd;
			if(!st[u].count(v)){
				res=max(res,a[u]+b[v]);
				break;
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
