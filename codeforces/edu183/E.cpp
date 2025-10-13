#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng;
const ll INF=1e9;
// example that supports range reverse and addition updates, and range sum query
// (commented parts are specific to this  problem)
typedef struct item *pitem;
struct item {
	ll pr,cnt,val,ori;
	ll mn; // (paramters for range query)
	ll add; // (parameters for lazy prop)
	pitem l,r;
	item(ll val, ll ori): pr(rng()%INF),cnt(1),val(val),ori(ori),l(0),r(0),mn(val),add(0) {}
};
void push(pitem it){
	if(it){
		/*if(it->rev){
			swap(it->l,it->r);
			if(it->l)it->l->rev^=true;
			if(it->r)it->r->rev^=true;
			it->rev=false;
		}*/
		it->val+=it->add;
		it->mn+=it->add;
		if(it->l)it->l->add+=it->add;
		if(it->r)it->r->add+=it->add;
		it->add=0;
	}
}
ll cnt(pitem t){return t?t->cnt:0;}
ll mn(pitem t){return t?push(t),t->mn:INF;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		t->mn=min({t->val,mn(t->l),mn(t->r)});
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, ll sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}
// void rec(pitem t){ // useful for debugging
// 	if(!t)return;
// 	push(t);
// 	rec(t->l);cout<<t->ori<<" ";rec(t->r);
// }
// void rec2(pitem t){ // useful for debugging
// 	if(!t)return;
// 	push(t);
// 	rec2(t->l);cout<<t->val<<" ";rec2(t->r);
// }
// #define output(t) cout<<#t<<":\n";rec(t); cout<<"\n";rec2(t); cout<<"\n";
// use merge and split for range updates and queries

ll query(pitem t){ // first pos with dif<0
	if(!t)return 0;
	push(t);
	// push(t->l); push(t->r);
	if(mn(t->l)<0)return query(t->l);
	ll sz=cnt(t->l);
	if(t->val<0)return sz;
	sz++;
	return sz+query(t->r);
}

ll lwb(pitem t, ll x){
	if(!t)return 0;
	push(t);
	push(t->l); push(t->r);
	if(t->l && t->l->ori>=x)return lwb(t->l,x);
	ll sz=cnt(t->l);
	if(t->ori>=x)return sz;
	sz++;
	return sz+lwb(t->r,x);
}

int main(){FIN;
	ll ac,dr; cin>>ac>>dr;
	ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst;
	fore(i,0,n)cin>>a[i].snd;
	auto val=[&](ll i){
		return max(a[i].fst-ac,0ll)+max(a[i].snd-dr,0ll);
	};
	vector<ll> vs(n),sov;
	fore(i,0,n)vs[i]=val(i);
	sov=vs;
	sort(ALL(sov));
	pitem rt=0;
	fore(i,0,n){
		pitem cur=new item(i-sov[i],sov[i]);
		merge(rt,rt,cur);
	}
	// imp(sov)
	// output(rt);
	ll q; cin>>q;
	while(q--){
		ll i,na,nd; cin>>i>>na>>nd; i--;
		ll p=lwb(rt,vs[i]);
		pitem l,r,sol;
		
		// saco
		split(rt,l,r,p);
		split(r,sol,r,1); // lo aislo
		if(r)r->add--;
		merge(rt,l,r);
		// cout<<"sacado\n";
		// output(rt);
		
		// pongo
		a[i]={na,nd};
		vs[i]=val(i);
		
		p=lwb(rt,vs[i]);
		split(rt,l,r,p);
		if(r)r->add++;
		
		// cout<<"SACO a "<<sol->ori<<","<<sol->val<<"\n";
		free(sol);
		sol=new item(cnt(l)-vs[i],vs[i]);
		// cout<<"PONGO a "<<sol->ori<<","<<sol->val<<"\n";
		
		// l sol r
		// output(l);
		// output(r);
		merge(rt,l,sol);
		merge(rt,rt,r);
		
		//rt
		ll res=query(rt);
		// cout<<"vs: "; imp(vs)
		// output(rt);
		cout<<res<<"\n";
		// cout<<endl<<endl;
	}
	return 0;
}
