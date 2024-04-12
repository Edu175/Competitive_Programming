#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

typedef struct item *pitem;
struct item {
	int pr,cnt,val;
	int maxi;
	pitem l,r;
	item(int val): pr(rand()),cnt(1),val(val),l(0),r(0),maxi(val) {}
};
int cnt(pitem t){return t?t->cnt:0;}
int maxi(pitem t){return t?t->maxi:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		 t->maxi=max({t->val,maxi(t->l),maxi(t->r)});
	}
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}
void output(pitem t){ // useful for debugging
	if(!t)return;
	output(t->l);cout<<(t->val)<<" ";;output(t->r);
}
int main(){FIN;
	ll n; cin>>n;
	srand(175);
	pitem t=0;
	vector<ll>p(n);
	fore(i,0,n){
		ll v,c; cin>>v>>c; v--;
		p[v]=i;
		c=min(i,c);
		ll s=i-c,e=i-1;
		while(s<=e){ // could do it inside treap if tles
			ll m=(s+e)/2;
			pitem l,r;
			split(t,l,r,m);
			if(maxi(r)>v)s=m+1;
			else e=m-1;
			merge(t,l,r);
		}
		ll x=s;
		//cout<<i<<" "<<v<<": "<<x<<"\n";
		//output(t); cout<<"\n";
		pitem l,r;
		split(t,l,r,x);
		//cout<<"l "<<l<<": "; output(l); cout<<"\n";
		//cout<<"r "<<r<<": "; output(r); cout<<"\n";
		merge(t,l,new item(v));
		merge(t,t,r);
		
		/*cout<<cnt(t)<<"\n";
		output(t);
		cout<<"\n\n";*/
	}
	vector<ll>res;
	pitem l,r=t;
	//cout<<cnt(r)<<endl;
	fore(i,0,n)split(r,l,r,1),res.pb(p[l->val]+1);
	imp(res);
	return 0;
}
