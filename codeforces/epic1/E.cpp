#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005,INF=MAXN*1e9;

vector<ll>g[MAXN];
ll s[MAXN],D[MAXN];
vector<ll>ord;
void dfs1(ll x){
	for(auto y:g[x]){
		D[y]=D[x]+1;
		dfs1(y);
	}
	ord.pb(x);
}

ll dfs2(ll x){
	if(s[x]>0)return x;
	ll mn=-1;
	for(auto y:g[x]){
		ll r=dfs2(y);
		if(mn==-1||D[r]<D[mn])mn=r;
	}
	return mn;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			
		}
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		ord.clear();
		dfs1(0);
		ll res=0;
		for(auto x:ord){
			// cout<<x<<":"<<endl;
			if(!SZ(g[x])){s[x]=INF;continue;}
			ll sum=0;
			for(auto y:g[x])sum+=a[y];
			s[x]=sum-a[x];
			// cout<<s[x]<<"-->"<<endl;
			while(s[x]<0){
				ll y=dfs2(x);
				ll d=min(s[y],-s[x]);
				res+=(D[y]-D[x])*d;
				s[y]-=d;
				s[x]+=d;
				// cout<<y<<" "<<d<<": "<<s[x]"\n";
			}
			// cout<<s[x]<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
