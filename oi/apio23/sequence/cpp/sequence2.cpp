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
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e6;
#define NEUT {INF,-INF}
ii oper(ii a, ii b){return {min(a.fst,b.fst),max(a.snd,b.snd)};}
struct STree{
	vector<ii>t; ll n,C;
	STree(ll n):t(2*n+5,NEUT),n(n),C(n/2){}
	void upd(ll p, ll v){
		p+=C;
		for(p+=n,t[p]=oper(t[p],{v,v});p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ii query(ll l, ll r){
		ii res=NEUT;
		l+=C,r+=C;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(t[l++],res);
			if(r&1)res=oper(t[--r],res);
		}
		return res;
	}
};

int sequence(int N, std::vector<int> A) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i]-1;
	vector<ll>pos[n];
	fore(i,0,n)pos[a[i]].pb(i);
	vector<ll>s(n);
	fore(i,0,n)s[i]=1;
	ll res=0;
	fore(i,0,n)if(SZ(pos[i])){
		//cout<<i<<":\n";
		//imp(s);
		STree st(2*n+5);
		ll sum=0,rew=0;
		fore(j,0,n){
			sum+=s[j],rew+=a[j]==i;
			res=max(res,rew-st.query(-n,sum+1).fst);
			st.upd(sum,rew);
			//cout<<j<<": "<<sum<<" "<<rew<<"\n";
			//cout<<res<<"\n";
		}
		//cout<<res<<"\n";
		for(auto j:pos[i])s[j]=-1;
		st=STree(2*n+5);
		sum=0,rew=0;
		fore(j,0,n){
			sum+=s[j],rew+=a[j]==i;
			res=max(res,rew-st.query(sum,n+1).fst);
			st.upd(sum,rew);
		}
		//cout<<res<<"\n";
	}
	return res;
}
