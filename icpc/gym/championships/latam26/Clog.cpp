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
typedef int ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ld EPS=1e-8;
typedef complex<ld> pt;
struct Cmp{// for set
	bool operator()(const pt &a, const pt &b)const{
		if(abs(a.real()-b.real())<=EPS)return a.imag()+EPS<b.imag();
		return a.real()<b.real();
	}
};
const ld pi=atan2(0,-1),tau=2*pi;

pt bary(pt A, pt B, pt C, ld a, ld b, ld c) {
    return (A*a+B*b+C*c)/(a+b+c);
}

pt circumcenter(pt A, pt B, pt C) {
    ld a=norm(B-C),b=norm(C-A),c=norm(A-B);
    return bary(A,B,C,a*(b+c-a),b*(c+a-b),c*(a+b-c));
}

struct circle {
	pt o;ld r;
	circle(pt o, ld r):o(o),r(r){}
	circle(){}
	bool in(pt p){return abs(o-p)<r-EPS;} // strictly inside
	vector<pt> operator^(circle c){ // ccw
		vector<pt> s;
		ld d=abs(o-c.o);
		if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
		ld x=(d*d-c.r*c.r+r*r)/(2*d);
		ld y=sqrt(r*r-x*x);
		pt v=(c.o-o)/d;
		s.pb(o+v*x-(v*pt(0,1))*y);
		if(y>EPS)s.pb(o+v*x+(v*pt(0,1))*y);
		return s;
	}
};
ld ang(pt p){
	ld res=arg(p);
	if(abs(pi-res)<EPS)res=-pi;
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	vector<circle> a(n);
	ld res=0;
	fore(i,0,n){
		ld x,y; cin>>x>>y;
		a[i].o=pt(x,y);
		cin>>a[i].r;
		res=max(res,a[i].r);
	}
	vector<pt> b;
	set<pt,Cmp> st;
	fore(i,0,n)fore(j,i+1,n)for(auto p:(a[i]^a[j])){
		ll bad=0;
		for(auto c:a)bad|=c.in(p);
		if(!bad&&!st.count(p)){
			b.pb(p);
			st.insert(p);
		}
	}
	
	ll m=SZ(b);
	ll bound=max(6*n-12,2);
	assert(m<=bound);
	
	fore(i,0,m)fore(j,i+1,m)fore(k,j+1,m){
		pt o=circumcenter(b[i],b[j],b[k]);
		ld r=abs(b[i]-o);
		if(r<=res)continue;
		circle c(o,r);
		vector<pair<ld,ll>> ev;
		ev.pb({-pi,0});
		ll s=0;
		// ll dbg=o==pt(0,0);
		// if(dbg){cout<<"trying "<<o<<" "<<r<<"\n";}
		fore(i,0,n){
			auto v=a[i]^c;
			if(SZ(v)<2)continue;
			auto p=v[0],q=v[1];
			p=p-o; q=q-o;
			ld l=ang(p),r=ang(q);
			if(l>r)swap(l,r);
			ll cross=0;
			if(r-l>pi)cross=1,swap(l,r);
			if(cross)s++;
			ev.pb({l,+1});
			ev.pb({r,-1});
			// if(dbg)cerr<<i<<": "<<l<<","<<r<<": "<<cross<<"\n";
		}
		sort(ALL(ev));
		ll bad=0;
		fore(i,0,SZ(ev)){
			auto [p,d]=ev[i];
			s+=d;
			if(i==SZ(ev)-1||abs(p-ev[i+1].fst)>EPS){
				bad|=s==0;
				assert(s>=0);
			}
			// if(dbg)cerr<<"event "<<p<<" "<<d<<": "<<s<<"\n";
		}
		if(bad)continue;
		res=c.r;
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}