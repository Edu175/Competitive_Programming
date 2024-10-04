#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fjhg:v)cout<<fjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct node{
	ll pre,suf,res,sum,p;
	node(ll i, ll v):p(i){pre=suf=sum=res=v;}
};
node NEUT(-1,0);
node oper(node a, node b){
	auto c=a;
	c.res=max({a.res,b.res,a.suf+b.pre});
	c.pre=max(a.pre,a.sum+b.pre);
	if(c.pre==a.pre)c.p=a.p;
	else c.p=b.p;
	c.suf=max(b.suf,a.suf+b.sum);
	c.sum=a.sum+b.sum;
	return c;
}
struct STree{
	vector<node>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
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

vector<STree> st(2,0);
ll n,q;
ll ci;
pair<bool,bool> can(ll p){
	auto res0=st[0].query(p,q).res;
	auto res1=st[1].query(p,q).res;
	// cout<<"can "<<p<<": "<<res0<<" "<<res1<<"\n";;
	return {res0>ci,res1>ci};
}
void upd(ll p, ll v){
	st[0].upd(p,{p,v});
	st[1].upd(p,{p,-v});
}
vector<int> distribute_candies(vector<int> c, vector<int> l,
                                    vector<int> r, vector<int> v){
	l.insert(l.begin(),0); r.insert(r.begin(),0);
	v.insert(v.begin(),0);
	n=SZ(c),q=SZ(l);
	st[0]=st[1]=STree(q);
	vector<vector<ii>>upds(n+1);
	fore(i,0,q){
		r[i]++;
		upds[l[i]].pb({i,v[i]});
		upds[r[i]].pb({i,0});	
	}
	vector<int>res(n);
	fore(i,0,n){
		for(auto [p,v]:upds[i])upd(p,v);
		ci=c[i];
		ll l=0,r=q-1;
		while(l<=r){
			ll m=(l+r)/2;
			auto rq=can(m);
			if(rq.fst||rq.snd)l=m+1;
			else r=m-1;
		}
		// cerr<<i<<": "<<l<<" --> ";
		if(r<0)r=0;
		// if(r>=0){
			auto rq=can(r);
			if(rq.fst)res[i]=c[i];
			else res[i]=0;
			ll w=res[i]==0;
			// cout<<"("<<w<<") ";
			l=st[w].query(r,q).p+1;
			// cout<<r<<" r "<<rq.fst<<","<<rq.snd<<"\n";
		// }
		// cerr<<l<<": "<<res[i]<<"\n";
		// fore(h,0,2){
		// 	fore(i,0,q)cout<<st[h].query(i,i+1).sum<<" ";
		// 	cout<<"\n";
		// }
		// cout<<"\n";
		res[i]+=st[0].query(l,q).sum;
		res[i]=min(res[i],c[i]);
		res[i]=max(res[i],0);
	}
	return res;
}
									
