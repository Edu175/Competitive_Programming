#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cerr<<#v<<": ";for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// esto esta mal xd

const ll MAXN=3e5+5;

vv g[MAXN];
ll vis[MAXN];
vv nod;
void dfs(ll x){
	// cerr<<"dfs "<<x<<"\n";
	vis[x]=1; nod.pb(x);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	string s; cin>>s;
	vector<ii> a(m);
	fore(i,0,m){
		ll l,r; cin>>l>>r; l--,r--;
		a[i]={l,r};
	}
	sort(ALL(a),[&](ii a, ii b){return a.fst+a.snd<b.fst+b.snd;});
	vv id(n); iota(ALL(id),0);
	vv cant(n); const ll C=2;
	set<ll> st(ALL(id));
	for(auto [l,r]:a){
		ll sum=l+r;
		for(auto it=st.lower_bound(l);it!=st.end()&&2**it<sum;){
			ll x=*it,y=sum-x; assert(x!=y);
			g[x].pb(y);
			g[y].pb(x);
			// cerr<<x<<" -> "<<y<<"\n";
			if(++cant[x]>=C)it=st.erase(it);
			else it++;
		}
	}
	st=set<ll>(ALL(id));
	cant=vv(n);
	reverse(ALL(a));
	for(auto [l,r]:a){
		ll sum=l+r;
		for(auto it=st.lower_bound(sum/2+1);it!=st.end()&&*it<=r;){
			ll x=*it,y=sum-x; assert(x!=y);
			// cerr<<y<<" <- "<<x<<"\n";
			g[x].pb(y);
			g[y].pb(x);
			if(++cant[x]>=C)it=st.erase(it);
			else it++;
		}
	}
	ll res=1;
	fore(x,0,n)if(!vis[x]){
		dfs(x);
		
		// show(nod);
		ll fg=0;
		for(auto i:nod){
			char c=s[i];
			if(c!='?')fg|=1<<(c-'0');
		}
		if(fg==3)res=0;
		else if(fg==0)res=res*2%ll(1e9+7);
		// cerr<<"fg "<<fg<<"\n";
		
		nod.clear();
	}
	cout<<res<<"\n";
	return 0;
}
