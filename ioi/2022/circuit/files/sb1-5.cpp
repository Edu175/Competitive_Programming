#include "circuit.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define dfore(i,a,b) for(ll i=b-1,ioi=a;i>=ioi;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto djfhg:v)cout<<djfhg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MOD=1000002022;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll n,m;
vector<ll>g[MAXN];
ll a[MAXN],tot[MAXN],dp[MAXN];
vector<ll> pre[MAXN], suf[MAXN];
struct tn{
	ll r0,r1;
};
/*string cv(tn a){
	return "["+to_string(a.r0)+","+to_string(a.r1)+"]";
}*/
tn unit(ll v){
	if(!v)return tn({1,0});
	return tn({0,1});
}
typedef ll tl;
tl CLEAR=0;
tn NEUT({0,0});
tn oper(tn a, tn b, ll k){
	tn c=NEUT;
	ll xa=2*k-1,xb=2*k;
	c.r0=add(mul(a.r0,tot[xb]),mul(b.r0,tot[xa]));
	c.r1=add(mul(a.r1,tot[xb]),mul(b.r1,tot[xa]));
	return c;
}
void acum(tl &a, ll v){
	a^=v;
};
void calc(tn &a, ll v){
	if(v)swap(a.r0,a.r1);
}
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n): st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		calc(st[k],lazy[k]);
		if(e-s>1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void init(ll k, ll s, ll e, vector<int>&a){
		if(e-s==1)st[k]=unit(a[s]);
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1],k);
		}
		//cout<<"init "<<k<<" "<<s<<","<<e<<" = "<<cv(st[k])<<"\n";
	}
	void upd(ll k, ll s, ll e, ll a, ll b){
		push(k,s,e);
		if(e<=a||b<=s);
		else if(a<=s&&e<=b){
			acum(lazy[k],1);
			push(k,s,e);
		}
		else {
			ll m=(s+e)/2;
			upd(2*k,s,m,a,b); upd(2*k+1,m,e,a,b);
			st[k]=oper(st[2*k],st[2*k+1],k);
		}
		//cout<<"upd "<<k<<" "<<s<<","<<e<<" "<<a<<","<<b<<" = "<<cv(st[k])<<"\n";
	}
	void init(vector<int>&a){init(1,0,n,a);}
	void upd(ll a, ll b){upd(1,0,n,a,b);}
	ll get(){
		push(1,0,n);
		return st[1].r1;
	}
};
STree st(0);
bool segtree=1;
void init(int N, int M, std::vector<int> P, std::vector<int> A){
	n=N,m=M;
	segtree=__builtin_popcountll(m)==1&&m==n+1;
	fore(i,0,SZ(P)){
		if(P[i]!=-1)g[P[i]].pb(i);
		if(i)segtree&=P[i]==(i-1)/2;
	}
	fore(i,0,m)a[i+n]=A[i];
	fore(i,0,m)tot[n+i]=1;
	dfore(x,0,n){
		ll k=SZ(g[x]);
		tot[x]=k;
		for(auto y:g[x])tot[x]=mul(tot[x],tot[y]);
		pre[x].resize(k+1,1),suf[x].resize(k+1,1);
		fore(i,1,k+1)pre[x][i]=mul(pre[x][i-1],tot[g[x][i-1]]);
		dfore(i,0,k)suf[x][i]=mul(suf[x][i+1],tot[g[x][i]]);
	}
	st=STree(m);
	st.init(A);
	//cout<<segtree<<" seg\n";
}

int count_ways(int L, int R){
	if(segtree){
		ll l=L-n,r=R-n+1;
		//cout<<"cw "<<l<<","<<r<<":\n";
		//fore(i,1,n+m)cout<<i<<": "<<cv(st.st[i])<<"\n";
		st.upd(l,r);
		return st.get();
	}
	else {
		fore(i,L,R+1)a[i]^=1;
		//fore(i,n,n+m)cout<<a[i];;cout<<"\n";
		dfore(x,0,n+m){
			dp[x]=0;
			if(x>=n)dp[x]=a[x];
			else {
				fore(i,0,SZ(g[x])){
					auto y=g[x][i];
					dp[x]=add(dp[x],mul(dp[y],mul(pre[x][i],suf[x][i+1])));
				}
			}
			//cout<<x<<": "<<dp[x]<<"\n";
		}
	return dp[0];
	}
}
