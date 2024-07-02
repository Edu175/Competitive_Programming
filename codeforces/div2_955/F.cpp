#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll INF=1e10;
#define oper min
#define NEUT INF
struct STree{
	vector<ll>st;int n; vector<int>ss,es,pos;
	STree(int n): st(4*n+5,NEUT), n(n), ss(4*n+5),es(4*n+5), pos(n+5) {}
	void init(int k, int s, int e, vector<ll> &a){
		ss[k]=s,es[k]=e;
		if(s+1==e){st[k]=a[s];pos[s]=k;return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	ll find(ll k, ll s, ll e, ll x){
		if(s+1==e){
			if(st[k]<=x)return s;
			return -1; //o s-1?
		}
		ll m=(s+e)/2;
		if(st[2*k+1]<=x)return find(2*k+1,m,e,x);
		return find(2*k,s,m,x);
	}
	ll find(ll p){
		ll k=pos[p],x=st[k];
		while(k>1){
			if((k&1)&&st[k^1]<=x)return find(k^1,ss[k^1],es[k^1],x);
			k/=2;
		}
		return -1;
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
};

struct node{
	ll vl,vr,did; ii mn,res;
	node(ll v, ll i):vl(v),vr(v),did(0),mn({v,i}),res({INF,-1}){}
};
node operc(node a, node b){
	if(a.mn.snd==-1)return b;
	if(b.mn.snd==-1)return a;
	if(a.vr>b.vl)a.did=1;
	if(a.did)a.res=min(a.res,b.mn);
	a.vr=b.vr;
	a.did|=b.did;
	a.mn=min(a.mn,b.mn);
	a.res=min(a.res,b.res);
	return a;
}
node NEUTc(0,-1);
struct STcustom{
	int n; vector<node>t;
	STcustom(int n):n(n),t(2*n+5,NEUTc){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=operc(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUTc,der=NEUTc;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=operc(izq,t[l++]);
			if(r&1)der=operc(t[--r],der);
		}
		return operc(izq,der);
	}
};


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<STree> st(2,STree(n));
		st[0].init(a);
		vector<STcustom> cu(2,STcustom(n));
		fore(i,0,n)cu[0].upd(i,{a[i],i});
		fore(i,0,n)a[i]=-a[i];
		reverse(ALL(a));
		st[1].init(a);
		fore(i,0,n)cu[1].upd(i,{a[i],i});
		fore(i,0,n)a[i]=-a[i];
		reverse(ALL(a));
		
		auto get=[&](){
			vector<ll>res(2);
			fore(h,0,2){
				ll p=cu[h].query(0,n).res.snd;
				if(p==-1) {
					cout<<"-1 -1\n";
					return;
				}
				ll b=st[h].find(p)+1;
				res[h]=b;
				// cout<<"get "<<h<<": "<<p<<" "<<b<<"\n";
			}
			res[1]=n-1-res[1];
			cout<<res[0]+1<<" "<<res[1]+1<<"\n";
			// return ii({res[0],res[1]});
		};
		auto upd=[&](ll p, ll v){
			a[p]=v;
			cu[0].upd(p,{v,p});
			st[0].upd(p,v);
			p=n-1-p;
			v=-v;
			cu[1].upd(p,{v,p});
			st[1].upd(p,v);
		};
		get();
		ll q; cin>>q;
		while(q--){
			ll p,v; cin>>p>>v; p--;
			upd(p,v);
			get();
		}
	}
	return 0;
}
