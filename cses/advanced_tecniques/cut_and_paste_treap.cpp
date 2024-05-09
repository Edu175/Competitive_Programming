#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
typedef struct item *pitem;
struct item{
	pitem l,r;
	ll tag,sz;//sum,rev;
	char let;
};
ll sz(pitem t){return t?t->sz:0;}
//ll sum(pitem t){return t?t->sum:0;}
void upd(pitem t){
	if(t){
		t->sz=sz(t->l)+sz(t->r);
//		t->sum=sum(t->l)+sum(t->r);
	}
}
void push(pitem k){
	if(k){
		/*if(k->rev){
			//k->sum=-k->sum;
			swap(t->l,t->r);
			if(k->l)k->l->rev^=1;
			if(k->r)k->r->rev^=1;
			k->rev=0;
		}*/
	}
}
void split(pitem t, pitem &l, pitem &r, ll k){ // k = size of left treap
	push(t);
	if(!t){l=r=0;return;}
	if(sz(t->l)>=k)split(t->l,l,t->l,k),r=t;
	else split(t->r,t->r,r,k-sz(t->l)-1),l=t;
	upd(t);
}
void merge(pitem &t, pitem l, pitem r){
	if(!l||!r){t=l?l:r;return;}
	push(l); push(r);
	if(l->tag>r->tag)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd(t);
}
/*void prnt(ll t){
	if(!t)return;
	prnt(t->l);
	//cout<<"["<<t<<":"<<t->l<<","<<t->r<<"|" <<t->val<<","<<t->sum<<","<<t->rev<<","<<t->sz<<"] ";
	prnt(t->r);
}
void dbg(ll t){
	prnt(t);
	cout<<"\n";
}*/
string s;

void ans(pitem t){
	if(!t)return;
	ans(t->l);
	s.pb(t->let);
	ans(t->r);
}

int main(){FIN;
	ll n,q; srand((ll)&n); cin>>n>>q;
	string s; cin>>s;
	pitem rt=0;
	fore(i,0,n){
//		cout<<i<<endl;
		pitem x=new item({0,0,rand(),1,s[i]});
		merge(rt,rt,x);
	}
	while(q--){
		ll s,e; cin>>s>>e; s--;
//		cout<<s<<","<<e<<endl;
		pitem l,m,r;
		split(rt,l,r,s);
		split(r,m,r,e-s);
		merge(rt,l,r);
		merge(rt,rt,m);
	}
	ans(rt);
	cout<<s<<"\n";
	return 0;
}
