#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll B=1000,MAXN=1e5+5;
ll S[MAXN],E[MAXN],F[MAXN],D[MAXN];
ll idk=0;
vector<ll>g[MAXN];
void dfs(ll x){
	S[x]=idk++;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		dfs(y);
	}
	E[x]=idk;
}
int main(){FIN;
	string a; cin>>a;
	for(auto &i:a)i-='0';
	ll n=SZ(a);
	ll sz=0;
	F[n]=n;
	auto calc=[&](){
//		vector<ll>g[n+1];
		fore(i,0,n+1)g[i].clear();
		fore(i,0,n)g[F[i]].pb(i);
		idk=0;
		sz=0;
		dfs(n);
		/*stack<ll>sk;
		sk.push(n);
		while(SZ(sk)){
			auto x=sk.top(); sk.pop();
			S[x]=idk++;
			for(auto y:g[x]){
				D[y]=D[x]+1;
				sk.push(y);
			}
			E[x]=idk;
		}*/
	};
	bitset<MAXN>is;
	ll q,k; cin>>q>>k;
	auto upd=[&](ll x){
//		cout<<"upd "<<x<<": "<<F[x]<<" --> ";
		long long v=0;
		ll _x=x;
		while(x<n&&v*10+a[x]<=k)v=v*10+a[x],x++;
		F[_x]=x;
		is.reset();
		is[n]=1;
//		cout<<x<<"\n";
	};
	fore(i,0,n)upd(i);
	calc();
	cout<<D[0]<<"\n";
	while(q--){
		ll x,v; cin>>x>>v; x--;
		a[x]=v;
		fore(i,0,10){
			ll y=x-i;
			if(y<0)break;
			ll fy=F[y];
			upd(y);
			if(F[y]!=fy)sz+=!is[y],is[y]=1;
		}
		if(sz>=B)calc();
		x=0;
		ll res=0;
//		fore(i,0,n)cout<<F[i]<<" ";;cout<<"\n";
//		cout<<"query "<<x<<": ";
		while(x<n){
			x=F[x]-1,res++;
			ll y=x;
			do y=is._Find_next(y);
			while(!(S[y]<=S[x]&&S[x]<E[y]));
			res+=D[x]-D[y];
//			cout<<x<<" --> "<<y<<"\n";
			x=y;
		}
		cout<<res<<"\n";
	}
	return 0;
}
