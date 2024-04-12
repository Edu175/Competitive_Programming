#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,K=17;

int main(){FIN;
	ll n,t; cin>>n>>t;
	vector<vector<ii>>a(n);
	fore(i,0,n-1){
		ll m; cin>>m;
		fore(_,0,m){
			ll l,r; cin>>l>>r;
			a[i].pb({l,-r});
		}
		sort(ALL(a[i]));
		vector<ii>b;
		for(auto [l,r]:a[i]){
			r=-r;
			while(SZ(b)&&b.back().snd>=r)b.pop_back();
			b.pb({l,r});
		}
		a[i]=b;
	}
	vector<vector<ii>>c(n);
	fore(i,0,n-2){
		c[i].resize(SZ(a[i]));
		fore(j,0,SZ(a[i])){
			auto [l,r]=a[i][j];
			ll k=lower_bound(ALL(a[i+1]),ii({r,-1}))-a[i+1].begin();
			k%=SZ(a[i+1]);
			c[i][j]={r-l+(a[i+1][k].fst-r+t)%t,k};
		}
	}
	ll q; cin>>q;
	while(q--){
		ll s,e; cin>>s>>e; s--,e--;
		ll res=0,k=0;
		fore(i,s,e){
			if(i<e-1)res+=c[i][k].fst,k=c[i][k].snd;
			else res+=a[i][k].snd-a[i][k].fst;
		}
		cout<<res<<"\n";
	}
	return 0;
}
