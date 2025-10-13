#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {cout<<#v<<": ";;for(auto i:v)cout<<str(i)<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=0;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	// ld norm2(){return *this**this;}
	// ld norm(){return sqrt(norm2());}
	pt operator-(pt p){return pt(x-p.x, y-p.y);}
	// pt operator+(pt p){return pt(x+p.x, y+p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// ld operator*(pt p){return x*p.x+y*p.y;}
	bool operator<(pt p) const {
		return x<p.x-EPS || (abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	ld izq(pt p, pt q){ // que tan a la izquierda está
		return (q-p)%(*this-p);
	}
	bool left(pt p, pt q){ // only for chull
		return izq(p,q)>=0;
	}
};
#define str to_string
string str(pt p){return str(p.x)+","+str(p.y);}
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3) return p;
	vector<pt> r;
    sort(ALL(p)); //first x, then y. Remove if alredy sorted
	int k=0;
	fore(_,0,2){
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
			r.pb(p[i]);
		}
        r.pop_back();
        k=SZ(r);
		reverse(ALL(p));
	}
	return r;
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("average.in","r",stdin);
	freopen("average.out","w",stdout);
	#endif
	JET
	ll n; cin>>n;
	vector<pt> a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	auto c=chull(a);
	ll _n=n; auto _a=a; a.clear();
	set<pt> st(ALL(c));
	for(auto i:_a)if(!st.count(i))a.pb(i);
	auto d=chull(a);
	n=SZ(c);
	ll m=SZ(d);
	auto sig=[&](ll i, ll n){return (i+1)%n;};
	auto ant=[&](ll i, ll n){return (i-1+n)%n;};
	auto dis=[&](ll i, ll j){ // a la recta i-1, i+1. NOT commutative
		return d[j].izq(c[sig(i,n)],c[ant(i,n)]);
	}; 
	auto in=[&](ll i, ll j)->bool {
		if(!m)return 0;
		return dis(i,j)>0;
	};
	ll po=0;
	fore(i,0,m)if(dis(0,i)>dis(0,po))po=i;
	ll tot=_n;
	ll res=(tot-n)*n;
	// imp(c)
	// imp(d)
	if(n<5){
		fore(s,0,n){
			vector<pt> ps;
			fore(i,0,n)if(s!=i)ps.pb(c[i]);
			fore(i,0,m)ps.pb(d[i]);
			res+=SZ(chull(ps));
		}
	}
	else {
		fore(i,0,n){
			while(m&&dis(i,sig(po,m))>dis(i,po))po=sig(po,m);
			// cout<<i<<" "<<po<<" i po\n";
			if(!in(i,po)){res+=n-1;continue;}
			ll l=po,r=sig(po,m);
			vector<pt> ps={c[ant(i,n)],c[sig(i,n)],d[po]};
			while(l!=r&&in(i,ant(l,m)))l=ant(l,m),ps.pb(d[l]);
			while(l!=r&&in(i,r))ps.pb(d[r]),r=sig(r,m);
			ll q=SZ(chull(ps));
			ll cur=n-3+q;
			res+=cur;
			// cout<<i<<": "<<str(c[i])<<": ";
			// imp(ps)
		}
	}
	ll g=gcd(tot,res);
	assert(g);
	res/=g;
	tot/=g;
	cout<<res<<"/"<<tot<<"\n";
	return 0;
}