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

int sequence(int N, std::vector<int> A) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	vector<ll>pos[n];
	fore(i,0,n)pos[a[i]].pb(i);
	STcustom st(n);
	fore(i,0,n)st.upd(i,1);
	ll res=1;
	fore(i,0,n)if(SZ(pos[i])){
		for(auto j:pos[i])st.upd(j,-1);
		/*cout<<i<<":\n";
		cout<<"{" ; fore(j,0,n)cout<<st.query(j,j+1).sum<<" ";cout<<"}\n";
		cout<<"{" ; fore(j,0,n)cout<<st.query(j,j+1).mns<<" ";cout<<"}\n";*/
		fore(s,0,SZ(pos[i]))fore(e,s+1,SZ(pos[i])){
			ll l=pos[i][s],r=pos[i][e];
			ll dif=st.query(l,r+1).sum;
			node pre=st.query(0,l+1),suf=st.query(r,n);
			//cout<<s<<","<<e<<" ("<<l<<","<<r<<"): "<<dif<<" ";
			if(dif<=0){
				if(dif+pre.mxs+suf.mxp+e-s+1>=0)res=max(res,e-s+1);
				//cout<<e-s+1<<" "<<pre.mxs<<" "<<suf.mxp<<" = "<<dif+pre.mxs+suf.mxp+e-s+1<<"\n";
			}
			else {
				if(dif+pre.mns+suf.mnp-(e-s+1)<=0)res=max(res,e-s+1);
				//cout<<-(e-s+1)<<" "<<pre.mns<<" "<<suf.mnp<<" = "<<dif+pre.mns+suf.mnp-(e-s+1)<<"\n";
			}
			//cout<<res<<"\n";
		}
		for(auto j:pos[i])st.upd(j,-1);
		//cout<<"\n";
	}
	return res;
}
