#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// cache goes brrr (from 13s to 7s)
#pragma GCC optimize("Ofast,O3,unroll-loops")
const ll MAXN=3e5+5,BU=393,INF=2e9; // 550

ll rs[MAXN];
const ll B=531,N=MAXN,q=(N+B-1)/B;
ll a[N],Bsuf[q+3],Csuf[q+3][B+3];
struct SQRTree{ // suffix queries only
	inline ll oper(ll i, ll &j){
		if(a[i]<a[j])return i;
		return j;
	}
	ll n=q*B;
	SQRTree(){}
	SQRTree(ll _n){
		fore(i,0,MAXN)a[i]=INF;
		fore(i,0,q+3){
			Bsuf[i]=_n;
			fore(j,0,B+3)Csuf[i][j]=_n;
		}
	}
	// ll q,n; vv a,Bsuf; vector<vv> Csuf; // Bloque, Casilla
	// SQRTree(ll N):N(N),q(),n(q*B),
		// a(n+5,NEUT),Bsuf(q+5,NEUT),Csuf(q+3,vv(B+3,NEUT)){}
	void upd(ll &p, bool pon){ // O(sqrt(n))
		ll b=p/B; a[p]=pon?rs[p]:INF;
		for(ll i=p%B;i>=0;i--)Csuf[b][i]=oper(b*B+i,Csuf[b][i+1]);
		for(ll i=b;i>=0;i--)Bsuf[i]=oper(Csuf[i][0],Bsuf[i+1]);
	}
	ll query(ll &p){ // [p,n) , // O(1)
		ll b=p/B;
		return oper(Csuf[b][p%B],Bsuf[b+1]);
	}
};
ll n;
ll dis[MAXN],root[MAXN];
ll pos[MAXN],at[MAXN]; // at already to pos
pair<ii,ll> ran[MAXN];
SQRTree dat;
ll prox(ll i){return dat.query(at[i]);};
void add(ll i){dat.upd(i,1);};
void rem(ll i){dat.upd(i,0);};
ii upds[MAXN];
bitset<MAXN>is;
int main(){JET
	ll q; cin>>q;
	ll cnt=0;
	fore(_,0,q){
		ll l,r=-2; cin>>l;
		if(l>=0)cin>>r;
		l=abs(l); r++;
		if(r!=-1){
			upds[_]={cnt,1};
			ran[cnt]={{l,r},cnt};
			cnt++;
		}
		else upds[_]={l-1,0};
	}
	n=cnt; //rs[cnt]=2e9;
	sort(ran,ran+n);
	fore(i,0,n){
		ll x=ran[i].snd;
		pos[x]=i;
		rs[i]=ran[i].fst.snd;
		at[i]=lower_bound(ran,ran+n,pair<ii,ll>({{rs[i],-1},-1}))-ran;
	}
	fore(i,0,q)upds[i].fst=pos[upds[i].fst];
	dat=SQRTree(n); // pos !!
	root[n]=n;
	fore(idx,0,q){
		if(idx%BU==0){
			ll e=min(q,idx+BU);
			fore(i,idx,e){
				ll x=upds[i].fst;
				if(upds[i].snd)add(x);
				is[x]=1;
			}
			for(ll i=n-1;i>=0;i--){
				ll pa=prox(i);
				root[i]=is[i]||is[pa]?i:root[pa];
				dis[i]=dis[pa]+1;
			}
			fore(i,idx,e){
				ll x=upds[i].fst;
				if(upds[i].snd)rem(x);
				is[x]=0;
			}
		}
		ll x=upds[idx].fst;
		if(upds[idx].snd)add(x);
		else rem(x);
		ll s=Bsuf[0],res=0;
		while(s<n){
			ll si=root[s];
			res+=dis[s]-dis[si];
			if(si<n)res++,si=prox(si);
			s=si;
		}
		cout<<res<<"\n";
	}
	
    return 0;
}