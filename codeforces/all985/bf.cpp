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

const ll MAXN=50*50+5;
vv g[MAXN];
ll n;
ll cv(ll i, ll j){
	if(i>j)swap(i,j);
	return n*i+j;}
ll an(ll i){return (i-1+n)%n;}
ll de(ll i){return (i+1)%n;}

ll vis[MAXN],q=0;
void dfs(ll x){
	vis[x]=1; q++;
	// cout<<"dfs "<<x<<": "<<x/n<<" "<<x%n<<"\n";
	for(auto y:g[x])if(!vis[y])dfs(y);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		string s; cin>>s;
		fore(i,0,n)fore(j,i,n){
			ll x=cv(i,j);
			vis[x]=0;
			g[x].clear();
		}
		q=0;
		ll tot=n;
		fore(i,0,n)fore(j,i+1,n){
			tot++;
			ll a=s[i],b=s[de(i)],c=s[j],d=s[de(j)];
			vv us;
			if(a==c)us.pb(cv(an(i),an(j)));
			if(a==d)us.pb(cv(an(i),de(j)));
			if(b==c)us.pb(cv(de(i),an(j)));
			if(b==d)us.pb(cv(de(i),de(j)));
			// cout<<i<<","<<j<<": "; imp(us);
			for(auto u:us)g[u].pb(cv(i,j));
		}
		fore(i,0,n)fore(fg,0,2){
			ll x=cv(i,fg?de(i):i);
			if(!vis[x])dfs(x);
		}
		// cout<<q<<" "<<tot<<"\n";
		if(q==tot)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
