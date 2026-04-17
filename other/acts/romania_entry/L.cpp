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
const ll B=1200,MAXN=1e5+5;
#define BLOCKSZ sqrt(N)
struct BL{ 
	ll r,n,q; vector<ll>val; vector<ll>a;
	//r=block size, q=number of blocks
	BL(ll N):r(BLOCKSZ),n((N+r-1)/r*r),q(n/r),val(q,n),a(n,n){}
	BL(){}
	ll query(ll x){
		return min(a[x],val[x/r]);
	}
	ll upd(ll i0, ll i1, ll v){
		ll res=0;
		#define SINGLE(s,e) fore(i,s,e)a[i]=min(a[i],v)
		SINGLE(i0,min(i1,i0/r*r+r));
		if(i0/r==i1/r)return res;
		fore(i,i0/r+1,i1/r)val[i]=min(val[i],v); //blocks
		SINGLE(i1/r*r,i1);
		return res;
	}
};
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
	BL nxt(n+5);
	ll sz=0;
	F[n]=n;
	vector<ll>is(n);
	auto calc=[&](){
		fore(i,0,n+1)g[i].clear();
		fore(i,0,n)g[F[i]].pb(i);
		idk=sz=0;
		is=vector<ll>(n);
		dfs(n);
		fore(i,0,nxt.n)nxt.a[i]=n;
		fore(i,0,nxt.q)nxt.val[i]=n;
	};
	ll q,k; cin>>q>>k;
	auto upd=[&](ll x){
//		cout<<"upd "<<x<<": "<<F[x]<<" --> ";
		long long v=0;
		ll _x=x;
		while(x<n&&v*10+a[x]<=k)v=v*10+a[x],x++;
		F[_x]=x;
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
			if(F[y]!=fy&&!is[y]){
				sz++,is[y]=1;
				nxt.upd(S[y],E[y],y);
			}
		}
		if(sz>=B)calc();
		x=0;
		ll res=0;
//		fore(i,0,n)cout<<nxt.query(i)<<" ";;cout<<"\n";
//		fore(i,0,n)cout<<F[i]<<" ";;cout<<"\n";
//		cout<<"query "<<x<<": ";
		while(x<n){
			res++,x=F[x];
			auto y=nxt.query(S[x]);
			res+=D[x]-D[y];
//			cout<<x<<" --> "<<y<<"\n";
			x=y;
		}
		cout<<res<<"\n";
	}
	return 0;
}
