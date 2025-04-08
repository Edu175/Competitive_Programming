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
vector<vector<ii>> stL;
vector<vector<ii>> laL;
struct STree{
	vector<tn> st; vector<tl> lazy; int n;
	vector<bool> visS,visL;
	STree(int n):st(4*n+5,0),lazy(4*n+5,CLEAR),n(n),visS(4*n+5),visL(4*n+5){}
	void push(int k, int s, int e){
		// if(lazy[k]==CLEAR)return;
		if(!visS[k])stL.back().pb({k,st[k]}),visS[k]=1;
		st[k] = calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			if(!visL[2*k])laL.back().pb({2*k,lazy[2*k]}),visL[2*k]=1;
			if(!visL[2*k+1])laL.back().pb({2*k+1,lazy[2*k+1]}),visL[2*k+1]=1;
			
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		// laL.back().pb({k,lazy[k]});
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){
		push(k,s,e);
		if(e<=a||b<=s) return ;
		if(a<=s&&e<=b){
			// laL.back().pb({k,lazy[k]});
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m = (s+e)/2;
		upd(2*k,s,m,a,b,v), upd(2*k+1,m,e,a,b,v);
		// stL.back().pb({k,st[k]});
		st[k] = oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s) return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b) return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void rollback(){
		for(auto [whe,wha]:stL.back())st[whe]=wha;
		for(auto [whe,wha]:laL.back())lazy[whe]=wha;
		stL.pop_back();
		laL.pop_back();
	}
	void upd(int a, int b, tl v){
		laL.back().pb({1,lazy[1]});
		visL[1]=1;
		upd(1,0,n,a,b,v);}
	tn query(int a, int b){
		visL[1]=1;
		laL.back().pb({1,lazy[1]});
		return query(1,0,n,a,b);}
	void desvis(){
		for(auto [k,ksdfj]:stL.back())visS[k]=0;
		for(auto [k,ksdfj]:laL.back())visL[k]=0;
	}
};

enum {ADD,DEL,QUERY};
struct Query {int type,x,y,h;};
struct DynCon {
	vector<Query> q;
	STree dsu;
	vector<int> mt;
	vv last;
	DynCon(int n, int m):dsu(n),last(m){}
	void add(int x, int y, int h, int i){
		q.pb((Query){ADD,x,y,h});mt.pb(-1);last[i]=q.size()-1;
	}
	void remove(int x, int y, int h, int i){
		q.pb((Query){DEL,x,y,h});
		int pr = last[i]; mt[pr] = SZ(q)-1;mt.pb(pr);
	}
	void query(ll a, ll b){
		q.pb((Query){QUERY,a,b,-1});
		mt.pb(-1);
	}
	void process(){
		if(!SZ(q)) return;
		fore(i,0,SZ(q)) if(q[i].type==ADD&&mt[i]<0)mt[i]=SZ(q);
		go(0,SZ(q));
	}
	void go(int s, int e){
		stL.pb({}); laL.pb({});
		if(s+1==e){
			if(q[s].type==QUERY){
				ll res=dsu.query(q[s].x,q[s].y);
				cout<<res<<"\n";
			}
			dsu.desvis();
			dsu.rollback();
			return;
		}
		int m = (s+e)/2;
		for(int i=e-1;i>=m;i--)if(mt[i]>=0&&mt[i]<s)dsu.upd(q[i].x,q[i].y,q[i].h);
		dsu.desvis();
		go(s,m); dsu.rollback();
		stL.pb({}); laL.pb({});
		for(int i=m-1;i>=s;i--)if(mt[i]>=e)dsu.upd(q[i].x,q[i].y,q[i].h);
		dsu.desvis();
		go(m,e);dsu.rollback();
	}
};


int main(){
	JET
	ll q; cin>>q;
	vector<array<ll,3>> rec; 
	vv vals;
	vector<array<ll,5>> all; 
	while(q--){
		char c; cin>>c;
		if(c=='+'){
			ll a,b,h; cin>>a>>b>>h;
			all.pb({0,a,b,h,SZ(rec)});
			rec.pb({a,b,h});
			vals.pb(a); vals.pb(a-1); vals.pb(a+1);
			vals.pb(b); vals.pb(b-1); vals.pb(b+1);
		}
		if(c=='-'){
			ll i; cin>>i; i--;
			auto [a,b,h]=rec[i];
			all.pb({1,a,b,h,i});
		}
		if(c=='?'){
			ll l,r; cin>>l>>r;
			vals.pb(l);
			vals.pb(r);
			all.pb({2,l,r,-1,-1});
		}
	}
	sort(ALL(vals));
	vals.resize(unique(ALL(vals))-vals.begin());
	// cout<<"vals: ";for(auto i:vals)cout<<i<<" ";;cout<<"\n";
	ll n=SZ(vals);
	DynCon dc(n,SZ(rec)); rec.clear();
	// dont use rec after this
	for(auto& [t,a,b,h,i]:all){
		a=lower_bound(ALL(vals),a)-vals.begin();
		b=lower_bound(ALL(vals),b)-vals.begin();
	}
	vals.clear();
	reverse(ALL(all));
	while(SZ(all)){
		auto& [t,a,b,h,i]=all.back(); all.pop_back();
		if(t==0)dc.add(a,b,h,i);
		if(t==1)dc.remove(a,b,h,i);
		if(t==2)dc.query(a,b);
	}
	dc.process();
	return 0;
}