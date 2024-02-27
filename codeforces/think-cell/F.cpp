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
const ll MAXN=1ll<<25;

ll B;
bool vis[MAXN];
vector<ll>bag;
void dfs(ll x){
	vis[x]=1;
	bag.pb(x);
	fore(i,0,B)if((x>>i)&1){
		ll y=x^(1ll<<i);
		if(!vis[y])dfs(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		B=64-__builtin_clzll(n);
		ll all=(1ll<<(B+1))-1;
		ll resi=0;
		fore(_,0,q){
			ll v; cin>>v; v=(resi+v)%n;
			fore(h,0,2){
				ll x=h<<B;
				if(h)v=(~v)&all;
				for(ll i=B-1;i>=0;i--)if(!((v>>i)&1)){
					if(vis[x^(1ll<<i)])x^=1ll<<i;
				}
				resi=max(resi,x^(h<<B));
				dfs(v);
			}
			cout<<resi<<" ";
		}
		cout<<"\n";
		for(auto i:bag)vis[i]=0;
		bag.clear();
	}
	return 0;
}
