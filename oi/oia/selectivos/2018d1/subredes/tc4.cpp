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

const ll MAXN=6000;
bool g[MAXN][MAXN];
LL res=0;
LL to2(LL n){
	return n*(n-1)/2;
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
		//fore(i,0,n)imp(g[i]);
		res=0;
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed.pb({u,v});
			g[u][v]=g[v][u]=1;
		}
		fore(i,0,m)fore(j,i+1,m){
			vector<ll> a={ed[i].fst,ed[i].snd,ed[j].fst,ed[j].snd};
			ll resi=0,flag=1;
//			imp(a);
			fore(i,2,4)resi+=g[a[0]][a[i]]&&g[a[1]][a[i^1]];
//			,cout<<"+="<<a[0]<<","<<a[i]<<" "<<a[1]<<","<<a[i^1]<<"\n";
			fore(i,0,2)fore(j,2,4)flag&=a[i]!=a[j];
//			cout<<flag<<"\n";
			if(flag)res+=resi;
		}
		cout<<res/2<<"\n";
	}
}

