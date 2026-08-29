#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define debug(x) {cerr<<#x<<": ";for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define debugp(x) {cerr<<#x<<": ";for(auto y:x)cout<<cv(y)<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef __int128 xl;
const ll INF=1e18;
struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	xl operator%(pt p){return xl(x)*p.y-xl(y)*p.x;}
	xl operator*(pt p){return xl(x)*p.x+xl(y)*p.y;}
	bool operator<(pt p)const {
		return x<p.x||(x==p.x&&y<p.y);
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
};
#define str to_string
string cv(pt p){return str(p.x)+","+str(p.y);}
vector<pt> chull(vector<pt> p, bool dosort){ // only upper
	// if(SZ(p)<3)return p;
	vector<pt> r;
	if(1)sort(ALL(p));
	reverse(ALL(p));
	fore(i,0,SZ(p)){ // now doesnt include collinear
		while(SZ(r)>1&&r.back().leftOrAt(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	return r;
}
void reorder(vector<pt> &p){
	if(!p[2].left(p[0],p[1]))reverse(ALL(p));
	int pos=0;
	fore(i,1,SZ(p))if(pt(p[i].y,p[i].x)<pt(p[pos].y,p[pos].x))pos=i;
	rotate(p.begin(),p.begin()+pos,p.end());
}
vector<pt> minkowski_sum(vector<pt> p, vector<pt> q){
	if(min(SZ(p),SZ(q))<3){
		vector<pt> v;
		for(pt pp:p)for(pt qq:q)v.pb(pp+qq);
		return chull(v,1);
	}
	reorder(p); reorder(q);
	fore(i,0,2)p.pb(p[i]),q.pb(q[i]);
	vector<pt> r;
	int i=0,j=0;
	while(i+2<SZ(p)||j+2<SZ(q)){
		r.pb(p[i]+q[j]);
		auto cross=(p[i+1]-p[i])%(q[j+1]-q[j]);
		i+=cross>=0;
		j+=cross<=0;
	}
	return r;
}
// pt farthest(pt v, vector<pt> &p){
// 	int n=SZ(p);
// 	if(n<10){
// 		int k=0; fore(i,1,n)if(v*(p[i]-p[k])>0)k=i;
// 		return p[k];
// 	}
// 	if(n==SZ())
// }

vector<ll> best; // for each len k
void cand(vector<pt> &c){
	for(auto p:c)best[p.x]=max(best[p.x],p.y);
}
vector<ll> a;
void rec(ll l, ll r){ // they dont have 0,0
	ll m=(l+r)/2;
	vector<pt> pre,suf;
	pt p(0,0);
	fore(i,m,r)p.x++,p.y+=a[i],pre.pb(p);

	p=pt(0,0);
	for(ll i=m-1;i>=l;i--)p.x++,p.y+=a[i],suf.pb(p);
	
	pre=chull(pre,0);
	suf=chull(suf,0);
	auto got=minkowski_sum(suf,pre);

	// cerr<<"\n\nrec "<<l<<","<<r<<" "<<m<<":\n";
	// debugp(pre)
	// debugp(suf)
	// debugp(got)
	
	cand(got);
	// bc 0 is not there, I should do these here
	cand(pre);
	cand(suf);
	if(r-l>1){
		rec(l,m);
		rec(m,r);
	}
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		best=vv(n+1,-INF);
		rec(0,n);
		vector<pt> c;
		fore(i,1,n+1)if(best[i]>-INF)c.pb(pt(i,best[i]));
		// show(best)
		// debugp(c)
		c=chull(c,0);
		// debugp(c)
		vector<pair<pt,ll>> qs(q);
		fore(i,0,q){
			ll x; cin>>x;
			qs[i]={{x,1},i};
		}
		sort(ALL(qs));
		sort(ALL(c)); // cw
		// cerr<<"qs: "; for(auto i:qs)cerr<<cv(i.fst)<<" "<<i.snd<<" ";;cerr<<"\n";
		// reverse(ALL(c)); // clockwise now
		ll m=SZ(c);
		ll po=0,val=-INF;
		fore(i,0,m){
			ll cur=qs[0].fst*c[i];
			// cerr<<i<<": "<<cur<<"\n";
			if(cur>val)po=i,val=cur;
		}
		vector<ll> ans(q);
		ans[qs[0].snd]=val;
		// cerr<<po<<"\n";
		fore(i,1,q){
			pt di=qs[i].fst;
			while(1){
				ll nxt=(po+1)%m;
				if(di*c[nxt]>di*c[po])po=nxt;
				else break;
			}
			ll val=di*c[po];
			ans[qs[i].snd]=val;
			// ll dbg=-INF;
			// for(auto p:c)dbg=max(dbg,ll(p*di));
			// assert(dbg==val);
		}
		show(ans)
	}
	return 0;
}