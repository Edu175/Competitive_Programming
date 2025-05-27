#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=30;

vv g[MAXN];

ll id[MAXN];
ll qid=0;
void dfs(ll x){
	id[x]=qid;
	for(auto y:g[x])if(id[y]==-1)dfs(y);
}

void join(ll x, ll y){
	g[x].pb(y);
	g[y].pb(x);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		fore(i,0,26)id[i]=-1,g[i].clear();
		string a,b,c; cin>>a>>b>>c;
		if(SZ(a)!=SZ(b)){
			cout<<"NO\n";
			continue;
		}
		if(SZ(a)!=SZ(c)){
			cout<<"YES\n";
			continue;
		}
		ll n=SZ(a);
		qid=0;
		fore(i,0,n)join(a[i]-'a',b[i]-'a');
		fore(i,0,26)if(id[i]==-1){
			qid++;
			dfs(i);
		}
		ll fg=0;
		fore(i,0,n)fg|=id[a[i]-'a']!=id[c[i]-'a'];
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}