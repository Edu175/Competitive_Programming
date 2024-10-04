#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b; i<ioi; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfhg:v)cout<<kdfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll VK=25,MAXN=4e5+5,INF=1e18,B=6;
ll n;
ll s[MAXN],p[MAXN],w[MAXN],l[MAXN];

ii oper(ii a, ii b){
	return {min((ll)a.fst,b.fst-a.snd),min(a.snd+b.snd,INF)};
}

struct bloque{
	ll pot;
	ll a[MAXN],v[MAXN];
	ll D[MAXN],F[MAXN],jump[MAXN];
	ii V[MAXN],val[MAXN]; // V = Father value, val = jump value
	void makeLeaf(ll x, ll p, ii _val){
		F[x]=p;
		V[x]=_val;
		D[x]=D[p]+1;
		if(D[p]-D[jump[p]]==D[jump[p]]-D[jump[jump[p]]]){
			jump[x]=jump[jump[p]];
			val[x]=oper(V[x],oper(val[p],val[jump[p]]));
		}
		else jump[x]=p,val[x]=V[x];
	}
	void init(ll _pot){
		pot=_pot;
		fore(i,0,n){
			if(pot<s[i]){
				a[i]=l[i];
				v[i]=p[i];
			}
			else {
				a[i]=w[i];
				v[i]=s[i];
			}
		}
		fore(i,0,n){
			F[i]=a[i];
			V[i]={(pot<s[i]?s[i]:INF),v[i]};
		}
		D[n]=0;
		F[n]=-1; jump[n]=n;
		val[n]=V[n]={-1,0};
		vector<ll>vis(n+1); vis[n]=1;
		auto dfs=[&](ll x, auto &&dfs)->void{
			if(vis[x])return;
			vis[x]=1;
			dfs(a[x],dfs);
			makeLeaf(x,a[x],V[x]);
		};
		fore(i,0,n)dfs(i,dfs);
		// vector<ll>dbg(n+1);
		// ll mx=0;
		// fill(ALL(vis),0);
		// auto dfs2=[&](ll x, auto &&dfs2)->void{
		// 	if(vis[x])return;
		// 	vis[x]=1;
		// 	dfs2(a[x],dfs2);
		// 	dbg[x]=dbg[a[x]]+1;
		// 	mx=max(mx,dbg[x]);
		// };
		// fore(i,0,n)dfs2(i,dfs2);
		// cout<<"bloque "<<pot<<": "<<mx<<"\n";
	}
	void go(ll &x, ll &z){
		// cout<<"go "<<x<<" "<<z<<endl;
		
		auto can=[&](ll* to, ii* v)->bool{
			if(z<v[x].fst&&to[x]<n){
				z+=v[x].snd;
				x=to[x];
				return 1;
			}
			return 0;
		};
		while(can(jump,val)||can(F,V));
		
		// nod=oper(nod,V[0][x]);
		// cout<<"salto final"<<"\n";
		// cout<<x<<" -> "<<F[0][x]<<"\n";
		// cout<<nod.fst<<","<<nod.snd<<"\n";
		// x=F[0][x];
		// z+=nod.snd;
		// cout<<"ended in "<<x<<","<<z<<endl;
		// assert((pot<s[x]&&z>=s[x]));
		if((pot>=s[x]||z<s[x])&&a[x]==n){
			z+=v[x]; x=a[x];
			assert(x==n);
		}
		else {
			assert(pot<s[x]&&z>=s[x]);
			z+=s[x]; x=w[x];
		}
		// cout<<x<<" "<<z<<"\n\n";
	}
};
bloque dat[VK];
void init(int N, vector<int> S, vector<int> P, vector<int> W, vector<int> L){
	n=N;
	fore(i,0,n){
		s[i]=S[i];
		p[i]=P[i];
		w[i]=W[i];
		l[i]=L[i];
	}
	fore(i,0,VK)dat[i].init(1ll<<i);
}
long long simulate(int X, int Z){
	ll x=X,z=Z;
	while(x<n){
		ll bl=min(VK-1,ll(63-__builtin_clzll(z)));
		dat[bl].go(x,z);
	}
	return z;
}
