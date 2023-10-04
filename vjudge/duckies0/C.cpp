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
const ll MOD=1e9+7;

ll fpow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD; e/=2;
	}
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ii,ll>> a(n);
		fore(i,0,n)cin>>a[i].fst.fst,a[i].fst.fst--;
		fore(i,0,n)cin>>a[i].fst.snd,a[i].fst.snd--;
		fore(i,0,n)cin>>a[i].snd,a[i].snd--;
		sort(ALL(a));
		vector<ll> p(n),c(n);
		fore(i,0,n)p[i]=a[i].fst.snd,c[i]=a[i].snd;
		vector<ll>vis(n);
		fore(i,0,n){
			if(p[i]==i)vis[i]=1;
			if(vis[i]||c[i]==-1)continue;
			for(ll x=i;!vis[x];x=p[x])vis[x]=1;
		}
		ll q=0;
		fore(i,0,n){
			if(vis[i])continue;
			q++;
			for(ll x=i;!vis[x];x=p[x])vis[x]=1;
		}
		cout<<fpow(2,q)<<"\n";
	}
	return 0;
}
