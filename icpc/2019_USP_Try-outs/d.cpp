#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
random_device rd;
mt19937 rng(rd());

typedef struct item *pitem;
bool les(ii a, ii b){
	return a.fst*b.snd<b.fst*a.snd;
}
bool leq(ii a, ii b){
	return a.fst*b.snd<=b.fst*a.snd;
}
bool eq(ii a, ii b){
	return a.fst*b.snd==b.fst*a.snd;
}
struct item{
	int pr; ii key; ll val,add,mx;
	pitem l,r;
	item(ii key, ll val):pr(rng()),key(key),val(val),l(0),r(0){}
};

void push(pitem it){
	if(it){
		it->val=max(it->val,it->add);
		it->mx=max(it->mx,it->val);
		it->add=0;
	}
}
ll mx(pitem t){return t?push(t),t->mx:0;}
void upd_mx(pitem t){
	if(t){
		t->mx=max({t->val,mx(t->l),mx(t->r)});
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l); push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_mx(t);
}
void split(pitem t, pitem& l, pitem& r, ii key, ll b){ //repetidos?
	if(!t){l=r=0;return;}
	push(t);
	if((!b?leq:les)(key,t->key))split(t->l,l,t->l,key,b),r=t;
	else split(t->r,t->r,r,key,b),l=t;
	upd_mx(t);
}

void output(pitem t){
	if(!t)return;
	push(t);
	output(t->l);
	cout<<(t->key).fst<<"/"<<(t->key).snd<<","<<t->val<<" ";
}

int main(){JET
	ll n; cin>>n;
	ll v=0;
	pitem rt=0;
	fore(_,0,n){
		cout<<"\n"<<_<<": "; output(rt); cout<<"\n";
		char ty; cin>>ty;
		ii s,e; cin>>s.fst>>s.snd>>e.fst>>e.snd;
		s.fst^=v,s.snd^=v,e.fst^=v,e.snd^=v;
		cout<<s.fst<<","<<s.snd<<" "<<e.fst<<","<<e.snd<<" s e\n";
		if(ty=='B'){
			ll h; cin>>h; h^=v;
			pitem lb = new item(s,h);
			pitem rb = new item(e,h);
			pitem l=0,m=0,r=0;
			split(rt,l,m,s,0);
			split(m,m,r,e,1);
			if(m)m->add=max(m->add,h);
			pitem u=0;
			split(m,u,m,s,1);
			if(!u)merge(m,lb,m);
			else merge(m,u,m);
			
			split(m,m,u,e,0);
			if(!u)merge(m,m,rb);
			else merge(m,m,u);
			cout<<"h: "<<h<<"\n";
			cout<<"l: "; output(l);  cout<<"\n";
			cout<<"m: "; output(m);cout<<"\n";
			cout<<"r: "; output(r);cout<<"\n";
			merge(rt,l,m); merge(rt,rt,r);
			
		}
		else {
			pitem l=0,m=0,r=0;
			split(rt,l,m,s,0);
			split(m,m,r,e,1);
			cout<<"l: "; output(l);  cout<<"\n";
			cout<<"m: "; output(m);cout<<"\n";
			cout<<"r: "; output(r);cout<<"\n";
			ll res=mx(m);
			merge(rt,l,m); merge(rt,rt,r);
			v=res;
			cout<<res<<"\n";
		}
	}
	
	return 0;
}


/*
0: 
h: 4
l: 
m: 1/2,4 3/2,4 
r: 

1: 1/2,4 3/2,4 
l: 
m: 1/2,4 
r: 3/2,4 
4

2: 1/2,4 3/2,4 
l: 1/2,4 
m: 3/2,4 
r: 
4

3: 1/2,4 3/2,4 
l: 1/2,4 
m: 
r: 3/2,4 
0

4: 1/2,4 3/2,4 
l: 1/2,4 3/2,4 
m: 
r: 
0

5: 1/2,4 3/2,4 
l: 
m: 
r: 1/2,4 3/2,4 
0

*/