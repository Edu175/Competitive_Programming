#include "sequence.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,apio=b;i<apio;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto slkdh:v)cout<<slkdh<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll INF=5e6;
struct node{
	ll mxp,mnp,mxs,mns,sum;
};
node oper(node a, node b){
	a.mxp=max(a.mxp,a.sum+b.mxp);
	a.mnp=min(a.mnp,a.sum+b.mnp);
	a.mxs=max(a.mxs+b.sum,b.mxs);
	a.mns=min(a.mns+b.sum,b.mns);
	a.sum+=b.sum;
	return a;
}
node NEUT({-INF,INF,-INF,INF,0});
struct STcustom{
	vector<node>t; ll n;
	STcustom(ll n):t(2*n+5,node({0,0,0,0,0})),n(n){}
	void upd(ll p, ll v){
		p+=n;
		t[p].mxp+=v,t[p].mnp+=v,t[p].mxs+=v,t[p].mns+=v,t[p].sum+=v;
		for(;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
const ll C=5e5,MAXN=2*C+5;
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]=min(ft[i],v);
}
int get(int i0){ // get sum of range [0,i0)
	int r=INF;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r=min(r,ft[i]);
	return r;
}
ll l[MAXN],r[MAXN];
bool cmp(ll i, ll j){
	return ii({l[i],i})<ii({l[j],j});
}
ll B=162;
int sequence(int N, std::vector<int> A) {
	ll n=N;
	B=sqrt(double(n)/log2(n))+0.5;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	vector<ll>pos[n];
	fore(i,0,n)pos[a[i]].pb(i);
	STcustom st(n);
	fore(i,0,n)st.upd(i,1);
	ll res=1;
	vector<ll>s(n);
	fore(i,0,n)s[i]=1;
	fore(i,0,n)if(SZ(pos[i])){
		vector<ll>&v=pos[i];
		for(auto j:v)st.upd(j,-1),s[j]--;
		if(SZ(v)<B){
			vector<node> pre(SZ(v)),suf(SZ(v));
			fore(j,0,SZ(v)){
				ll p=v[j];
				pre[j]=st.query(0,p+1);
				suf[j]=st.query(p,n);
			}
			fore(s,0,SZ(v))fore(e,s+1,SZ(v)){
				ll dif=pre[e].sum-pre[s].sum;
				if(dif<=0){
					if(dif+pre[s].mxs+suf[e].mxp+e-s+1>=0)
						res=max(res,e-s+1);
				}
				else {
					if(dif+pre[s].mns+suf[e].mnp-(e-s+1)<=0)
						res=max(res,e-s+1);
				}
			}
		}
		else {
			ll sum=0,rew=0;
			vector<ll>rw(n+1);
			vector<ll>ev{n};
			l[n]=r[n]=rw[n]=0;
			fore(j,0,n){
				sum+=s[j],rew+=a[j]==i;
				rw[j]=rew;
				l[j]=sum-rew,r[j]=sum+rew;
				ev.pb(j);
			}
			sort(ALL(ev),cmp); reverse(ALL(ev));
			fore(i,0,MAXN)ft[i]=INF;
			for(auto i:ev){
				res=max(res,rw[i]-get(r[i]+C+1));
				upd(r[i]+C,rw[i]);
			}
		}
		for(auto j:v)st.upd(j,-1),s[j]--;
	}
	return res;
}
