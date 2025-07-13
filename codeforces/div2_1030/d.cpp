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
const ll MAXN=2e5+5;

ll dp[MAXN][2];

ll p[MAXN],d[MAXN];
ll n,k;
// map<ll,vv>mp[2];
// vector<ll> ks[2]; // keys
// vector<vv> vs[2]; // values
vector<ii>all[2];
ll get_idx(ll x){
	return lower_bound(p,p+n,x)-p;
}
ll get(ll x, ll t, ll w, ll start=0){
	ll r=(t+(w?-x:x)%k+k)%k;
	// auto &v=mp[w][r];
	auto &a=all[w];
	// cout<<x<<" "<<t<<" "<<w<<": "<<r<<": "; imp(v)
	auto p=lower_bound(ALL(a),ii(r,x))-a.begin();
	auto out=[&](ll p){
		if(p<0||p>=SZ(a))return 1;
		if(a[p].fst!=r)return 1;
		return 0;
	};
	if(start){
		if(out(p))return -1;
		// cout<<" da vuelta start "<<idx[v[p]]<<"\n";
		return get_idx(a[p].snd);
	}
	if(w)p++;
	else p--;
	if(out(p))return -1;
	// cout<<" da vuelta "<<idx[v[p]]<<"\n";
	return get_idx(a[p].snd);
}
ll dfs(ll i, ll w){
	auto &res=dp[i][w];
	if(res!=-1)return res;
	res=0;
	ll prox=get(p[i],d[i],w);
	if(prox==-1)return res=1;
	return res=dfs(prox,w^1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n+3)fore(l,0,2)dp[i][l]=-1;
		fore(i,0,2)all[i].clear();
		fore(i,0,n)cin>>p[i];
		fore(i,0,n)cin>>d[i];
		fore(w,0,2)fore(i,0,n){
			ll r=d[i]+(w?-p[i]:p[i]);
			r=(r%k+k)%k;
			all[w].pb({r,p[i]});
		}
		fore(w,0,2)sort(ALL(all[w]));
		ll q; cin>>q;
		while(q--){
			ll x; cin>>x;
			ll j=get(x,0,1,1);
			if(j==-1){cout<<"YES\n";continue;}
			if(dfs(j,0))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
