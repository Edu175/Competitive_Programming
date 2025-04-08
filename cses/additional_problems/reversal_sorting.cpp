#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// example that supports range reverse and addition updates, and range sum query
// (commented parts are specific to this  problem)
random_device rd;
mt19937 rng(rd());
typedef struct item *pitem;
struct item {
	int pr,cnt,val;
//	int sum; // (paramters for range query)
	bool rev; // int add; // (parameters for lazy prop)
	pitem l,r,fat;
	item(int val): pr(rng()),cnt(1),val(val),l(0),r(0),rev(0),fat(0)/*,sum(val),rev(0),add(0)*/ {}
};
void push(pitem it){
	if(it){
		if(it->rev){
			swap(it->l,it->r);
			if(it->l)it->l->rev^=true;
			if(it->r)it->r->rev^=true;
			it->rev=false;
		}
		// it->val+=it->add;it->sum+=it->cnt*it->add;
		// if(it->l)it->l->add+=it->add;
		// if(it->r)it->r->add+=it->add;
		// it->add=0;
	}
}
int cnt(pitem t){return t?t->cnt:0;}
// int sum(pitem t){return t?push(t),t->sum:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		// t->sum=t->val+sum(t->l)+sum(t->r);
		if(t->l)t->l->fat=t;
		if(t->r)t->r->fat=t;
		t->fat=0;
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l); push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}

void down(pitem t){
	if(t->fat)down(t->fat);
	push(t);
}
ll pos(pitem t){
	down(t);
	ll res=cnt(t->l);
	while(t->fat&&t->fat->l==t)t=t->fat;
	return res+(t->fat?1+pos(t->fat):0);
}
void output(pitem t){ // useful for debugging
	if(!t)return;
	push(t);
	output(t->l);cout<<t->val<<" ";;output(t->r);
}
// use merge and split for range updates and queries

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<pitem>t(n);
	fore(i,0,n)t[i]=new item(i);
	pitem rt=0;
	fore(i,0,n)merge(rt,rt,t[a[i]]);
	vector<ii>ans;
	fore(i,0,n){
		// cout<<i<<": ";
		// output(rt);
		ll p=pos(t[i]);
		// cout<<": "<<p<<endl;
		assert(p>=i);
		if(p==i)continue;
		ans.pb({i,p});
		pitem l,m,r;
		split(rt,l,m,i);
		split(m,m,r,p-i+1);
		m->rev^=1;
		merge(rt,l,m);
		merge(rt,rt,r);
	}
	cout<<SZ(ans)<<"\n";
	for(auto [l,r]:ans)cout<<l+1<<" "<<r+1<<"\n";
	return 0;
}