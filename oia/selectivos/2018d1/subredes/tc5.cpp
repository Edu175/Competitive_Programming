#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfjg:v)cout<<kdfjg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

const ll MAXN=5632;
bitset<MAXN> g[MAXN];
LL res=0;
LL to2(LL n){
	return n*(n-1)/2;
}
LL to3(LL n){
	//cerr<<"to3 "<<n<<" = "<<n*(n-1)*(n-2)/6<<"\n";
	//if(n<0)return
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
		mset(g,0);
		//imp(g);
		res=0;
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed.pb({u,v});
			g[u][v]=g[v][u]=1;
		}
		for(auto [x,y]:ed){
			auto b=g[x]&g[y];
			res+=to3(b.count());
		}
		cout<<res<<"\n";
	}
}

