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
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll C=5e5,MAXN=2*C+5;
#define NEUT 3*C
#define oper min
struct STree{ //persistent
	vector<int>st,L,R,rts; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),rts(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
	ll upd_2d
};
unordered_map<ll,ll> ft[MAXN+1];
void upd(ll p, ll q, ll v){
	p+=C,q+=C;
	p=MAXN-1-p; v-=C;
	//cout<<"upd "<<p<<","<<q<<" "<<-v<<"\n";
	for(ll i=p+1;i<=MAXN;i+=i&-i)
	for(ll j=q+1;j<=MAXN;j+=j&-j){
		ll &r=ft[i][j];
		r=min(r,v);
	}
}
ll query(ll p, ll q){
	p+=C,q+=C;
	p=MAXN-1-p;
	//cout<<"query "<<p<<","<<q<<"\n";
	ll res=0;
	for(ll i=p+1;i;i-=i&-i)
	for(ll j=q+1;j;j-=j&-j){
		res=min(res,ft[i][j]);
	}
	//cout<<res<<" res\n";
	return res+C;
}

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
		//cout<<"\nin"<<i<<":\n";
		for(auto j:pos[i])s[j]=0;
		//imp(s);
		fore(j,0,MAXN)ft[j].clear();
		upd(0,0,0);
		ll sum=0,rew=0;
		fore(j,0,n){
			sum+=s[j],rew+=a[j]==i;
			ll p=sum-rew,q=sum+rew;
			res=max(res,rew-query(p,q));
			upd(p,q,rew);
			//cout<<j<<": "<<sum<<" "<<rew<<"\n";
			//cout<<"add "<<p<<","<<q<<" "<<rew<<"\n";
			//cout<<res<<"\n\n";
		}
		//cout<<res<<"\n";
		for(auto j:pos[i])s[j]=-1;
	}
	return res;
}
