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
const ll K=25,VK=25,MAXN=5e4+5,INF=1e18;
const ll MAXN2=4e5+5;
ll sub=1;
ll n;
ll s[MAXN2],p[MAXN2],w[MAXN2],l[MAXN2];

ii oper(ii a, ii b){
	return {max(min((ll)a.fst,b.fst-a.snd),-1ll),min(a.snd+b.snd,INF)};
}
struct bloque{
	ll pot;
	ll a[MAXN],v[MAXN];
	int F[K][MAXN];
	ii V[K][MAXN];
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
			F[0][i]=a[i];
			V[0][i]={(pot<s[i]?s[i]:INF),v[i]};
			// if(a[i]==n)V[0][i].fst=-1;
		}
		F[0][n]=n;
		V[0][n]={-1,0};
		fore(k,1,K)fore(x,0,n+1){
			F[k][x]=F[k-1][F[k-1][x]];
			V[k][x]=oper(V[k-1][x],V[k-1][F[k-1][x]]);
		}
		// cout<<"bloque "<<pot<<":\n";
		// fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
		// fore(i,0,n)cout<<v[i]<<" ";;cout<<"\n";
		// fore(i,0,n)cout<<V[0][i].fst<<","<<V[0][i].snd<<" ";;cout<<"\n";
	}
	void go(ll &x, ll &z){
		// cout<<"go "<<x<<" "<<z<<endl;
		assert(z<INF);
		ii nod={INF,0};
		for(ll k=K-1;k>=0;k--){
			auto nodi=oper(nod,V[k][x]);
			if(z<nodi.fst&&F[k][x]<n){
				// nod=nodi;
				z+=nodi.snd;
				// cout<<"salto "<<k<<"\n";
				// cout<<x<<" -> "<<F[k][x]<<"\n";
				// cout<<nod.fst<<","<<nod.snd<<"\n";
				assert(z<INF);
				x=F[k][x];
			}
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
			assert(pot<s[x]&&z>=s[x]);
			z+=s[x]; x=w[x];
		}
		// cout<<x<<" "<<z<<"\n\n";
	}
};
bloque dat[VK];
ll F[K][MAXN2];
ii V[K][MAXN2];
ii oper2(ii a, ii b){
	return {max((ll)a.fst,b.fst-a.snd),min(a.snd+b.snd,INF)};
}
void init(int N, vector<int> S, vector<int> P, vector<int> W, vector<int> L){
	n=N;
	fore(i,0,n){
		s[i]=S[i];
		p[i]=P[i];
		w[i]=W[i];
		l[i]=L[i];
	}
	fore(i,0,n)sub&=s[i]==p[i];
	if(!sub){
		// assert(0);
		fore(i,0,VK)dat[i].init(1ll<<i);
		return;
	}
	// D.resize(n+1);
	// for(ll i=n-1;i>=0;i--){
	// 	D[i]=D[w[i]]+s[i];
	// 	sub&=s[i]==p[i];
	// }
	fore(i,0,n){
		F[0][i]=w[i];
		V[0][i]={s[i],s[i]};
		// if(a[i]==n)V[0][i].fst=-1;
	}
	F[0][n]=n;
	V[0][n]={INF,0};
	fore(k,1,K)fore(x,0,n+1){
		F[k][x]=F[k-1][F[k-1][x]];
		V[k][x]=oper2(V[k-1][x],V[k-1][F[k-1][x]]);
	}
	// while(!sub);
}
void go(ll &x, ll &z){
	for(ll k=K-1;k>=0;k--){
		auto nod=V[k][x];
		if(z>=nod.fst&&F[k][x]<n){
			z+=nod.snd;
			x=F[k][x];
		}
	}
	if(z>=s[x]){
		z+=s[x]; x=w[x];
		while(w[x]!=n);
	}
	else {
		z+=p[x]; x=l[x];
	}
}
long long simulate(int X, int Z){
	ll x=X,z=Z;
	
	if(sub){
		while(x<n)go(x,z);
		return z;
	}
	
	while(x<n){
		ll bl=min(VK-1,ll(63-__builtin_clzll(z)));
		dat[bl].go(x,z);
	}
	return z;
}
