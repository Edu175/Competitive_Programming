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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;
struct MinQ{
	deque<ii>q; ll dif=0;
	MinQ(){}
	void push(ll x){
		ll cnt=1;
		x-=dif;
		while(SZ(q)&&x<=q.back().fst)cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(!SZ(q))return;
		if(q.front().snd>1)q.front().snd--;
		else q.pop_front();
	}
	ll query(){
		assert(SZ(q));
		// if(!SZ(q))return INF;
		return q.front().fst+dif;
	}
	void add(ll x){dif+=x;}
};

typedef ld tc;
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
	bool bad(iterator y){
		iterator z=next(y);
		if(y==begin()){
			if(z==end())return false;
			return y->m==z->m&&y->b<=z->b;
		}
		iterator x=prev(y);
		if(z==end())return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(tc m, tc b){
		iterator y=insert((Line){m,b});
		y->it=y;y->end=end();
		if(bad(y)){erase(y);return;}
		while(next(y)!=end()&&bad(next(y)))erase(next(y));
		while(y!=begin()&&bad(prev(y)))erase(prev(y));
	}
	tc eval(tc x){
		Line l=*lower_bound((Line){x,is_query});
		return l.m*x+l.b;
	}
};
const ld EPS=1e-12;
int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<array<ll,3>> ev; // t, ty, sum
	ll sum=0; fore(i,0,k-1)sum+=a[i];
	fore(u,k-1,n){
		sum+=a[u];
		ll s=u-k+1;
		ev.pb({s,1,sum});
		ev.pb({s+k,-1,sum});
		sum-=a[s];
	}
	vv mn(n),mx(n); // sum
	MinQ q,qn;
	sort(ALL(ev));
	ll po=0;
	fore(i,0,n){
		while(po<SZ(ev)&&ev[po][0]<=i){
			auto [t,ty,sum]=ev[po++];
			if(ty==-1)q.pop(),qn.pop();
			else q.push(sum),qn.push(-sum);
		}
		mn[i]=q.query();
		mx[i]=-qn.query();
	}
	auto doit=[&](vector<ii> v){ // v: l -> l+z
		sort(ALL(v));
		HullDynamic cht;
		ll po=0;
		vector<ld> ret(m+1,5);
		fore(i,1,m+1){
			ll s=i*k;
			while(po<SZ(v)&&v[po].fst<=s){
				auto [l,z]=v[po++];
				cht.add(-ld(1)/z,ld(l)/z);
			}
			if(SZ(cht)){
				auto rq=cht.eval(s); rq=-rq;
				ret[i]=rq;
			}
		}
		return ret;
	};
	vector<ii> le,ri;
	fore(i,0,n){
		ll me=a[i]*k;
		ll to=mn[i];
		if(to<me)le.pb({me,me-to});
		to=mx[i];
		if(me<to)ri.pb({me,to-me});
	}
	// vector<ld> ans(m+1,5); // min time of reaching sum i*k
	auto ans=doit(ri);
	for(auto &[l,z]:le)l=(m+1)*k-l;
	auto ans2=doit(le);
	reverse(ans2.begin()+1,ans2.end());
	fore(i,0,n)ans[a[i]]=0;
	fore(i,1,m+1){
		ld x=min(ans[i],ans2[i]);
		// cerr<<x<<"\n";
		// assert(x>=0);
		x=abs(x);
		if(x>1+EPS)cout<<"-1\n";
		else cout<<fixed<<setprecision(15)<<x<<"\n";
	}
	// cout<<"\n";
	return 0;
}
