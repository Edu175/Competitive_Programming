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
const ld EPS=1e-14;
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
};

struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	// bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	ld get_alp(ln l){ // alp of intersection w.r.t segment l
		// if(*this/l)return -1; // chequear
		ld alp=((p-l.p)%pq/(l.pq%pq));
		return alp;
	}
	// bool has(pt r){return dist(r)<=EPS;}
	// bool operator==(ln l){return *this/l&&has(l.p);}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	ld dist(pt r){return (r-proj(r)).norm();}
};
int main(){FIN;
	ll n; cin>>n;
	vector<pt> a(4);
	cin>>a[0].x>>a[0].y>>a[2].x>>a[2].y;
	a[1]=pt(a[2].x,a[0].y);
	a[3]=pt(a[0].x,a[2].y);
	vector<ln> ls(n);
	fore(i,0,n){
		pt p,pq;
		cin>>p.x>>p.y>>pq.x>>pq.y;
		pt q=p+pq;
		ls[i]=ln(p,q);
	}
	vector<pair<ld,ll>> ev;
	ll ex=0;
	fore(i,0,n){
		ln l=ls[i];
		vector<ld> all;
		ll bad=0;
		if(!l.pq.x&&!l.pq.y){
			ll good=1;
			fore(j,0,4){
				good&=l.p.left(a[j],a[(j+1)%4]);
			}
			ex+=good;
			continue;
		}
		fore(j,0,4){
			ln sid(a[j],a[(j+1)%4]);
			if(!l.pq.x&&!sid.pq.x){
				bad|=l.p.x==sid.p.x;
				continue;
			}
			if(!l.pq.y&&!sid.pq.y){
				bad|=l.p.y==sid.p.y;
				continue;
			}
			ld alp=l.get_alp(sid);
			ld len=sid.pq.norm();
			if(alp*len<-EPS)continue;
			if(alp*len>len+EPS)continue;
			// seg has it
			alp=sid.get_alp(l);
			alp=max(alp,0.0l);
			all.pb(alp);
		}
		sort(ALL(all));
		vector<ld> u;
		for(auto i:all)if(!SZ(u)||abs(u.back()-i)>EPS)u.pb(i);
		bad|=SZ(u)<2;
		if(bad)continue;
		assert(SZ(u)==2);
		ld s=u[0],e=u[1];
		ev.pb({s,1});
		ev.pb({e,-1});
		// cout<<i<<": "<<s<<","<<e<<"\n";
	}
	sort(ALL(ev));
	ll cnt=0;
	ld res=-1;
	fore(i,0,SZ(ev)){
		cnt+=ev[i].snd;
		if(i==SZ(ev)-1||ev[i+1].fst-ev[i].fst>EPS){
			if(cnt+ex==n){
				res=ev[i].fst;
				break;
			}
		}
	}
	if(ex==n)res=0;
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
