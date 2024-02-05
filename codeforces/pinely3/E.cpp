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

vector<ll> good[20];


int main(){FIN;
	fore(n,5,20){
		fore(mk,0,1ll<<n){
			ll s=0;
			fore(i,0,n)if((1ll<<i)&mk){
				for(ll j=i;j<n;j+=i+1)s^=(1ll<<j);
			}
			if(__builtin_popcountll(s)<=n/5)good[n].pb(mk);
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ii>a(m);
		ll g[n][n]={};
		fore(i,0,m)cin>>a[i].fst>>a[i].snd,g[a[i].fst][a[i].snd]=1;
		if(n<5){
			cout<<"-1\n";
			continue;
		}
		if(n>=20){
			cout<<n<<"\n";
			fore(i,1,n+1)cout<<i<<" ";;cout<<"\n";
			continue;
		}
		ll res=-1;
		for(auto mk:good[n]){
			ll flag=1;
			fore(i,0,n)fore(j,0,n)if(g[i][j]&&((1ll<<i)&mk)&&!((1ll<<j)&mk))
				flag=0;
			if(flag)res=mk;
		}
		if(res==-1)cout<<"-1\n";
		else {
			vector<ll>s;
			fore(i,0,n)if(res&(1ll<<i))s.pb(i+1);
			cout<<SZ(s)<<"\n"; imp(s);
		}
	}
	return 0;
}
