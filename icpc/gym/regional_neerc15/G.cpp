#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
bool vis[1000];
int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("generators.in","r",stdin);     freopen("generators.out","w",stdout);
	#endif
	ll n,k; cin>>n>>k;
	vv v[n];
	fore(i,0,n){
		ll x,a,b,c; cin>>x>>a>>b>>c;
		mset(vis,0);
		while(!vis[x]){
			vis[x]=1;
			v[i].pb(x);
			x=(a*x+b)%c;
		}
	}
	ll r=0; vector<pair<ll,ii>> del;
	vv idx;
	fore(i,0,n){
		ii mx={-1,-1};
		fore(j,0,SZ(v[i])) mx=max(mx,ii({v[i][j],j}));
		r+=mx.fst;
		idx.pb(mx.snd);
		ii md={-1,-1};
		fore(j,0,SZ(v[i])) if((mx.fst-v[i][j])%k) md=max(md,ii({v[i][j],j}));
		if(md.fst!=-1) del.pb(pair<ll,ii>{md.fst-mx.fst,(ii){i,md.snd}});
	}
	if(r%k) {
		cout<<r<<"\n";
		for(auto i: idx) cout<<i<<" ";;cout<<"\n";
	}
	else if(SZ(del)){
		pair<ll,ii> mx={-1e10,(ii){-1,-1}};
		for(auto d: del) mx=max(d,mx);
		r+=mx.fst;
		idx[mx.snd.fst]=mx.snd.snd;
		cout<<r<<"\n";
		for(auto i: idx) cout<<i<<" ";;cout<<"\n";
	}
	else{
		cout<<"-1\n";
	}
	return 0;
}