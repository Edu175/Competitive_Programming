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

const ll MAXN=30;
ll g[MAXN];
vector<ll> ad[MAXN];
LL res=0;
LL to2(LL n){
	return n*(n-1)/2;
}
LL to3(LL n){
	//cerr<<"to3 "<<n<<" = "<<n*(n-1)*(n-2)/6<<"\n";
	//if(n<0)return
	return n*(n-1)*(n-2)/6;
}
vector<ll>deg={5,1,4,3,3,5,2,7,1,9};
ll ppc(ll n){return __builtin_popcount(n);}
int main(){FIN;
	ll asd; cin>>asd;
	char qwe;
	fore(i,0,asd)fore(j,0,asd)cin>>qwe;
	ll t; cin>>t;
	vector<ll>ns(t),ms(t);
	fore(i,0,t)cin>>ns[i]>>ms[i];
	vector<ii>sdeg;
	fore(i,0,SZ(deg))sdeg.pb({deg[i],i});
	sort(ALL(sdeg));
	fore(_,0,t){
		ll n=ns[_],m=ms[_];
		mset(g,0);
		fore(i,0,n){
			ad[i].clear();
		}
		//imp(g);
		res=0;
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed.pb({u,v});
			g[u]|=1<<v;
			g[v]|=1<<u;
			ad[u].pb(v);
			ad[v].pb(u);
		}
		vector<ll>per(n-10);
		fore(i,0,10)per.pb(1);
		do{
			ll mk=0;
			vector<ll>h;
			fore(i,0,n)if(per[i]){
				mk|=1<<i;
				h.pb(i);
			}
			vector<ll>b;
			for(auto x:h)b.pb(g[x]&mk);
			vector<ii>d;
			fore(i,0,SZ(b))d.pb({ppc(b[i]),h[i]});
			sort(ALL(d));
			ll flag=1;
			fore(i,0,10)flag&=d[i].fst==sdeg[i].fst;
			if(!flag)continue;
			
		}
		while(next_permutation(ALL(per)));
		cout<<res<<"\n";
	}
}

