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
const ll MAXN=2e2+5;

ll dp[MAXN][MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,x; cin>>n>>m>>x;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		ll h[n][m];
		fore(i,0,n)fore(j,0,m)cin>>h[i][j];
		if(n==1){
			cout<<h[0][a[0]]<<"\n";
			continue;
		}
		fore(i,0,m+3)st.insert(x*i%m);
		vector<ll>p;
		for(auto i:st)p.pb(i);
		vector<ll>id(n,-1);
		fore(i,0,n){
			if(id[i]!=-1)continue;
			for(auto j:p)id[(i+j)%m]=i;
		}
		
		ll res=0;
		fore(i,0,n){
			ll mx=h[i][a[i]];
			for(auto s:p)mx=max(mx,h[i][(a[i]+s)%m]);
			res+=mx;
		}
		cout<<res<<"\n";
	}
	return 0;
}
