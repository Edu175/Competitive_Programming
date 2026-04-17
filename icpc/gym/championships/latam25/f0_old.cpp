#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=2e9;
typedef ll tn;
typedef ll tl;
#define NEUT INF
#define CLEAR 0

tn oper(tn a, tn b){
	return min(a,b);
}

void acum(tl &a, tl v){
	a=max(a,v);
}

tn calc(int s, int e, tn a, tl v){
	assert(s|e|1);
	a=max(a,v);
	return a;
}
struct pu{bool whi; ll whe,wha;};
vector<pu>c; // which, where, what
void put(bool whi, ll whe, ll old, ll now){
	if(old!=now)c.pb({whi,whe,old});
}
struct STree{
	vector<tn> st; vector<tl> lazy; int n;
	STree(int n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n){}
	void push(int k, int s, int e, ll doit=1){
		if(lazy[k]==CLEAR)return;
		ll old=st[k];
		// c.pb({1,k,st[k]});
		st[k] = calc(s,e,st[k],lazy[k]);
		put(1,k,old,st[k]);
		if(e-s!=1){
			// c.pb({0,2*k,lazy[2*k]});
			// c.pb({0,2*k+1,lazy[2*k+1]});
			ll old=lazy[2*k];
			acum(lazy[2*k],lazy[k]);
			put(0,2*k,old,lazy[2*k]);
			
			old=lazy[2*k+1];
			acum(lazy[2*k+1],lazy[k]);
			put(0,2*k+1,old,lazy[2*k+1]);
		}
		old=lazy[k];
		c.pb({0,k,lazy[k]});
		lazy[k]=CLEAR;
		put(0,k,old,st[k]);
	}
	void upd(int k, int s, int e, int a, int b, tl v){
		push(k,s,e);
		if(e<=a||b<=s) return ;
		if(a<=s&&e<=b){
			ll old=lazy[k];
			c.pb({0,k,lazy[k]});
			acum(lazy[k],v);
			put(0,k,old,lazy[k]);
			push(k,s,e,0);
			return;
		}
		int m = (s+e)/2;
		upd(2*k,s,m,a,b,v), upd(2*k+1,m,e,a,b,v);
		ll old=st[k];
		// c.pb({1,k,st[k]});
		st[k] = oper(st[2*k],st[2*k+1]);
		put(1,k,old,st[k]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s) return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b) return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	ll snap(){return c.size();}
	void rollback(int snap){
		// cout<<"rollback\n";
		while(SZ(c)>snap){
			auto i=c.back(); c.pop_back();
			(i.whi?st:lazy)[i.whe]=i.wha;
			// cout<<whi<<": "<<whe<<" "<<wha<<"\n";
		}
	}
	void upd(int a, int b, tl v){
		// cout<<"upd "<<a<<" "<<b<<": "<<v<<"\n";
		ll old=lazy[1];
		upd(1,0,n,a,b,v);
		put(0,1,old,lazy[1]);
	}
	tn query(int a, int b){
		ll old=lazy[1];
		ll res=query(1,0,n,a,b);
		put(0,1,old,lazy[1]);
		return res;
	}
};

enum {ADD,DEL,QUERY};
struct Query {int type,x,y,h;};
struct DynCon {
	vector<Query> q;
	STree dsu;
	vector<int> mt;
	map<pair<ii,int>,int> last;
	DynCon(int n):dsu(n){}
	void add(int x, int y, int h){
		// cout<<"add "<<x<<","<<y<<" "<<h<<"\n";
		q.pb((Query){ADD,x,y,h});mt.pb(-1);last[{{x,y},h}]=q.size()-1;
	}
	void remove(int x, int y, int h){
		// cout<<"remove "<<x<<","<<y<<" "<<h<<"\n";
		q.pb((Query){DEL,x,y,h});
		int pr = last[{{x,y},h}]; mt[pr] = SZ(q)-1;mt.pb(pr);
	}
	void query(ll a, ll b){
		// cout<<"query "<<a<<","<<b<<"\n";
		q.pb((Query){QUERY,a,b,-1});
		mt.pb(-1);
	}
	void process(){
		if(!SZ(q)) return;
		fore(i,0,SZ(q)) if(q[i].type==ADD&&mt[i]<0)mt[i]=SZ(q);
		go(0,SZ(q));
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY){
				ll res=dsu.query(q[s].x,q[s].y);
				cout<<res<<"\n";
			}
			return;
		}
		int k=dsu.snap(), m = (s+e)/2;
		for(int i=e-1;i>=m;i--)if(mt[i]>=0&&mt[i]<s)dsu.upd(q[i].x,q[i].y,q[i].h);
		go(s,m);dsu.rollback(k);
		for(int i=m-1;i>=s;i--)if(mt[i]>=e)dsu.upd(q[i].x,q[i].y,q[i].h);
		go(m,e);dsu.rollback(k);
	}
};


int main(){
	JET
	ll q; cin>>q;
	vector<array<ll,3>> rec; 
	vv vals;
	vector<array<ll,4>> all; 
	while(q--){
		char c; cin>>c;
		if(c=='+'){
			ll a,b,h; cin>>a>>b>>h;
			rec.pb({a,b,h});
			all.pb({0,a,b,h});
			vals.pb(a); vals.pb(a-1); vals.pb(a+1);
			vals.pb(b); vals.pb(b-1); vals.pb(b+1);
		}
		if(c=='-'){
			ll i; cin>>i; i--;
			auto [a,b,h]=rec[i];
			all.pb({1,a,b,h});
		}
		if(c=='?'){
			ll l,r; cin>>l>>r;
			vals.pb(l);
			vals.pb(r);
			all.pb({2,l,r,-1});
		}
	}
	sort(ALL(vals));
	vals.resize(unique(ALL(vals))-vals.begin());
	// cout<<"vals: ";for(auto i:vals)cout<<i<<" ";;cout<<"\n";
	// dont use rec after this
	ll n=SZ(vals);
	DynCon dc(n);
	for(auto [t,a,b,h]:all){
		a=lower_bound(ALL(vals),a)-vals.begin();
		b=lower_bound(ALL(vals),b)-vals.begin();
		if(t==0)dc.add(a,b,h);
		if(t==1)dc.remove(a,b,h);
		if(t==2)dc.query(a,b);
	}
	dc.process();
	return 0;
}

// 4
// + 1 2 1
// + 3 4 1
// ? 1 2
// ? 1 4
// vals: -1 0 1 2 3 4 5 
// add 1,3 1
// add 3,5 1
// query 1,3
// query 1,5
// rollback
// upd 1 3: 1
// rollback
// rollback
// upd 3 5: 1
// upd 1 3: 1
// 1
// rollback
// 1
// rollback
// rollback
