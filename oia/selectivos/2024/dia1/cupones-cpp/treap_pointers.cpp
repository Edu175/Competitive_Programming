#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=2e5+5;
struct node{
	ll* l,r;
	ll val,tag,sum,sz,rev;
};
node h[MAXN];
void upd(ll t, ll k, ll v){
	if(!t)return;
	if(v){//agrego
		h[t].sz+=h[k].sz;
		h[t].sum+=h[k].sum;
	}
	else {//saco
		h[t].sz-=h[k].sz;
		h[t].sum-=h[k].sum;
	}
}
void prop(ll k){
	if(h[k].rev){
		h[k].sum=-h[k].sum;
		if(h[k].l)h[h[k].l].rev^=1;
		if(h[k].r)h[h[k].r].rev^=1;
		h[k].rev=0;
	}
}
void prop2(ll t){
	prop(t);
	prop(h[t].l);
	prop(h[t].r);
}
void split(ll t, ll &l, ll &r, ll k){ //split treap t with left treap val < k
	prop2(t);
	if(t==0){
		l=0;r=0;
		return;
	}
	if(h[t].val>=k){ //go left
		upd(t,h[t].l,0);
		split(h[t].l,l,h[t].l,k);
		upd(t,h[t].l,1);
		r=t;
	}
	else {//go right
		upd(t,h[t].r,0);
		split(h[t].r,h[t].r,r,k);
		upd(t,h[t].r,1);
		l=t;
	}
}
void merge(ll &t, ll l, ll r){ // l > r priority
	if(h[r].tag>h[l].tag)swap(l,r);
	prop2(l);
	prop(r); //skipeable
	if(r==0){t=l;return;}
	if(h[l].val<h[r].val){
		upd(l,h[l].r,0);
		merge(h[l].r,h[l].r,r);
		upd(l,h[l].r,1);
	}
	else {
		upd(l,h[l].l,0);
		merge(h[l].l,h[l].l,r);
		upd(l,h[l].l,1);
	}
	t=l;
}
void prnt(ll t){
	if(!t)return;
	prnt(h[t].l);
	cout<<"["<<t<<":"<<h[t].l<<","<<h[t].r<<"|" <<h[t].val<<","<<h[t].sum<<","<<h[t].rev<<","<<h[t].sz<<"] ";
	prnt(h[t].r);
}
void dbg(ll t){
	prnt(t);
	cout<<"\n";
}
ll sum=0;
ll* rt=NULL;
ll query(){ //difference
	return h[rt].sum;
}
set<ll>myset;
//ll l,r, val,tag,sum,sz,rev;
ll cnt=1;
ll update(ll x){
	//cout<<"\n";
	if(myset.count(x)){
		//cout<<"saco\n";
		
		ll* l,m,r;
		split(rt,l,r,x);
		split(r,m,r,x+1);
		if(l)h[l].rev^=1;
		//cout<<"l "; dbg(l);
		//cout<<"m "; dbg(m);
		//cout<<"r "; dbg(r);
		merge(rt,l,r);
		
		myset.erase(x);
	}
	else {
		//cout<<"agrego\n";
		ll l,m,r;
		split(rt,l,r,x);
		if(l)h[l].rev^=1;
		h[cnt]={0,0,x,rand(),(h[r].sz&1?-x:x),1,0};
		m=cnt;
		merge(rt,l,m);
		merge(rt,rt,r);
		
		cnt++;
		myset.insert(x);
	}
	ll dif=query();
	//cout<<"update "<<x<<":\n";
	//dbg(rt);
	return (dif+sum)/2;
}
long long agregar(long long x) {
	sum+=x;
	return update(x);
}

long long sacar(long long x) {
	sum-=x;
	return update(x);
}
