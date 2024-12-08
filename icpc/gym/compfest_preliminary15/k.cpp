#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto i:v)cout<<i<<" ";cout<<"\n";
#define impr(v) for(auto i:v)cout<<i.m<<","<<i.b<<" ";cout<<"\n";
#define impall(v) for(auto it=v.begin();it!=v.end();it++)cout<<it->m<<","<<it->b<<" ";;cout<<"\n";
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef __int128 tc;
const tc is_query=-(1LL<<62); // special value for query
struct Line {
	tc m,b;
	mutable multiset<Line>::iterator it,end;
	const Line* succ(multiset<Line>::iterator it) const {
		return (++it==end? NULL : &*it);}
	bool operator<(const Line& rhs) const {
		if(rhs.b!=is_query)return m<rhs.m;
		const Line *s=succ(it);
		if(!s)return 0;
		return b-s->b<(s->m-m)*rhs.m;
	}
};
struct HullDynamic : public multiset<Line> { // for maximum
	vector<Line> erased;
	bool esbad(iterator y){
		iterator z=next(y);
		if(y==begin()){
			if(z==end())return false;
			return y->m==z->m&&y->b<=z->b;
		}
		iterator x=prev(y);
		if(z==end())return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	bool bad(iterator y){
		auto ret=esbad(y);
		if(ret)erased.pb(*y);
		return ret;
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(tc m, tc b){
		// cout<<"add "<<m<<" "<<b<<"\n";
		iterator y=insert((Line){m,b});
		y->it=y;y->end=end();
		if(bad(y)){erase(y);return;}
		while(next(y)!=end()&&bad(next(y)))erase(next(y));
		while(y!=begin()&&bad(prev(y)))erase(prev(y));
	}
	vector<tc> eval(tc x){
		auto it=lower_bound((Line){x,is_query});
		if(!size())return {};
		vector<tc>v;
		auto pone=[&](auto it){v.pb(it->m*x+it->b);};
		pone(it);
		if(it!=begin())pone(prev(it));
		if(next(it)!=end())pone(next(it));
		// return l.m*x+l.b;
		return v;
	}
};

const ll MAXN=1e5+5,INF=1e15;
vector<ii> g[MAXN];
ii oper(ii a, ll b){
	if(b>a.fst)return {b,a.fst};
	if(b>a.snd)return {a.fst,b};
	return a;
}
// ii operator+(ii a, ll v){return {a.fst+v,a.snd+v};}
ii c[MAXN];
ll ch[MAXN];
ll wf[MAXN],fa[MAXN];
void dfs0(ll x){
	c[x]={0,-INF};
	for(auto [y,w]:g[x])if(y!=fa[x]){
		fa[y]=x; wf[y]=w;
		dfs0(y);
		c[x]=oper(c[x],c[y].fst+w);
	}
}
void dfs1(ll x){
	for(auto [y,w]:g[x])if(y!=fa[x]){
		ch[y]=c[x].fst==c[y].fst+w?c[x].snd:c[x].fst;
		if(fa[x]!=-1)ch[y]=max(ch[y],ch[x]);
		ch[y]+=w;
		dfs1(y);
	}
}

void init(){
	fa[0]=-1;
	dfs0(0);
	dfs1(0);
}

int main(){JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	init();
	// fore(x,0,n){
	// 	cout<<x<<": "<<c[x].fst<<","<<c[x].snd<<" "<<ch[x]<<"\n";
	// }
	vector<HullDynamic> best(n),sec(n);
	ll diam=0;
	fore(x,0,n){
		// cout<<x<<":\n";
		for(auto [y,w]:g[x])if(y!=fa[x]){
			best[x].add(w,c[y].fst);
		}
		if(fa[x]!=-1)best[x].add(wf[x],ch[x]-wf[x]);
		for(auto i:best[x].erased)sec[x].add(i.m,i.b);
		// ,cout<<"added "<<i.m<<","<<i.b<<" ";;cout<<"\n";
		// impall(best[x])
		// impall(sec[x])
		// cout<<"\n";
		diam=max(diam,(ll)best[x].eval(1)[0]);
	}
	// cout<<"diam "<<diam<<"\n";
	ll q; cin>>q;
	while(q--){
		ll x,k; cin>>x>>k; x--;
		auto v=best[x].eval(k);
		auto v2=sec[x].eval(k);
		if(SZ(v2))v.pb(v2[0]);
		sort(ALL(v));
		reverse(ALL(v));
		ll res=v[0]+(SZ(v)>1?v[1]:0);
		// cout<<"\n";
		// cout<<ch[x]<<"\n";
		// imp(v)
		res=max(res,diam);
		cout<<res<<"\n";
	}
	return 0;
}