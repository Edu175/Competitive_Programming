#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfjg:v)cout<<kdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=40000;

vector<ll> g[MAXN];
ll res=0;
ll to3(ll n){
	return n*(n-1)*(n-2)/6;
}
int main(){FIN;
	ll asd; cin>>asd;
	char qwe;
	fore(i,0,asd)fore(j,0,asd)cin>>qwe;
	ll t; cin>>t;
	vector<ll>ns(t),ms(t);
	fore(i,0,t)cin>>ns[i]>>ms[i];
	fore(_,0,t){
		ll n=ns[_],m=ms[_];
		fore(i,0,n){
			g[i].clear();
		}
		res=0;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(i,0,n)res+=to3(SZ(g[i]));
		cout<<res<<"\n";
	}
}

