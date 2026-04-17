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

typedef struct item *pitem;
struct item{
	int d;
	pitem p,jump;
	ii val;
};
ii oper(ii a, ii b){
	return {min((ll)a.fst,b.fst-a.snd),min(a.snd+b.snd,INF)};
}
pitem makeLeaf(pitem p, ii val){
	pitem x= new item();
	x->d=p->d+1;
	x->p=p;
	if(p->d-p->jump->d==p->jump->d-p->jump->jump->d){
		x->jump=p->jump->jump;
		x->val=oper(val,oper(p->val,p->jump->val));
	}
	else x->jump=p,x->val=val;
}
struct bloque{
	ll pot;
	ll a[MAXN],v[MAXN];
	ii V[MAXN];
	pitem h[MAXN];
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
			V[i]={(pot<s[i]?s[i]:INF),v[i]};
		}
		a[n]=n;
		V[n]={-1,0};
		h[n]=new item();
		h[n]->d=0;
		h[n]->p=h[n]->jump=h[n];
		auto dfs=[&](ll x, auto &&dfs)->void{
			if(x==n)return;
			dfs(a[x],dfs);
			h[x]=makeLeaf(h[a[x]],V[x]);
		}
	}
	void go(ll &x, ll &z){
		while(1){
			auto nod=h[x]->val;
			z<nod.fst&&a[x]<n
		}
		// cout<<"go "<<x<<" "<<z<<endl;
		assert(z<INF);
		for(ll k=K-1;k>=0;k--)fore(j,0,B){
			auto nod=V[k][x];
			if(){
				z+=nod.snd;
				// cout<<"salto "<<k<<"\n";
				// cout<<x<<" -> "<<F[k][x]<<"\n";
				// cout<<nod.fst<<","<<nod.snd<<"\n";
				assert(z<INF);
				x=F[k][x];
			}
			else break;
		}
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
			// assert(pot<s[x]&&z>=s[x]);
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
