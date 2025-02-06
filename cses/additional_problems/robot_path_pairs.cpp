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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e13;

// eslachota
// nada es una verga que clasheen las lineas una dsp de la otra
// pq si las considero [,)
// entonces tengo que considerar clashes de paralelas:
// (voy a tener q hacerlo) (y sacar lo del clash con (0,0)
//          |
// 	        |
//  ... ----L----- ...
//

ll trad(char d){
	string s="RULD";
	fore(i,0,4)if(d==s[i])return i;
	assert(0);
}
struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	pt operator/(ll t){return pt(x/t,y/t);}
	
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt p){return x*p.y-y*p.x;}
	ll manh(){return abs(x+y);}
	string cv(){return to_string(x)+","+to_string(y);}
};
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	bool operator/(ln l){return pq%l.pq==0;}
	pt operator^(ln l){ // intersection
		pt r=l.p+l.pq*((p-l.p)%pq)/(l.pq%pq);
		return r;
	}
	bool has(pt r){return *this/ln(p,r);}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=0;}
	ll dist(pt r){
		// cout<<"dist "<<r.cv()<<"\n";
		if(seghas(r))return (r-p).manh();
		return -1;
	}
	ll dist(ln l){
		if(*this/l){ // useless
			return INF;
			assert(0);
			ll d0=dist(p);
			ll d1=dist(p+pq);
			if(d0==-1)return d1;
			if(d1==-1)return d0;
			return min(d0,d1);
		}
		return dist(*this^l);
	}
	string cv(){return p.cv()+"->"+pq.cv();}
};
struct event{
	ll x,l,r,y,qu;
};
bool operator<(event a, event b){return ii(a.x,a.qu)<ii(b.x,b.qu);}
vector<ln>a; 
bool hay(ll m){ // assuming no parallel intersection
	vector<event>ev;
	fore(i,0,m){
		auto p=a[i].p,pq=a[i].pq;
		pt q=p+pq;
		if(pq.y==0){
			if(p.x>q.x)swap(p,q),p.x++,q.x++;
			ev.pb({p.x,0,0,p.y,0});
			ev.pb({q.x,0,0,p.y,0});
		}
		else {
			if(p.y>q.y)swap(p,q),p.y++,q.y++; // [,)
			ev.pb({p.x,p.y,q.y,0,1});
		}
	}
	sort(ALL(ev));
	set<ll>st;
	
	// cout<<"hay "<<m<<"\n";
	for(auto [x,l,r,y,qu]:ev){
		if(qu){
			auto s=st.lower_bound(l);
			auto e=st.lower_bound(r);
			if(s!=e)return 1;
		}
		else {
			if(st.count(y))st.erase(y);
			else st.insert(y);
		}
	}
	// cout<<"no\n";
	return 0;
}
vector<pt> dirs={pt(1,0),pt(0,1),pt(-1,0),pt(0,-1)};
int main(){FIN;
	ll n; cin>>n;
	vector<ii>mov;
	ll acum=0;
	fore(i,0,n){
		char c; ll d; cin>>c>>d;
		auto w=trad(c);
		if(SZ(mov)&&mov.back().fst==(w^2)){cout<<acum<<"\n";exit(0);}
		if(SZ(mov)&&mov.back().fst==w)mov.back().snd+=d;
		else mov.pb({w,d});
		acum+=d;
	}
	// parsed
	n=SZ(mov);
	pt p(0,0);
	acum=0;
	map<ll,set<ii>>ver,hor;
	fore(i,0,n){
		pt pq=dirs[mov[i].fst]*mov[i].snd;
		pt q=p+pq;
		ln l(p,q);
		a.pb(l);
		// cout<<l.cv()<<"\n";
		auto halt=[&](set<ii> &st, ll l, ll r){ // now [,]
			
			// no estoy considerando cuando yo contengo otros rangos
			
			
			auto it=st.upper_bound({l,INF});
			if(it!=st.begin()&&prev(it)->snd>=l){
				cout<<acum<<"\n";exit(0);
				// cout<<acum<<" halts fst point\n";exit(0);
			}
			it=st.upper_bound({r,INF});
			if(it!=st.begin()&&(--it)->snd>=r){
				ll d=min(abs(it->fst-l),abs(it->snd-l));
				cout<<acum+d<<"\n";exit(0);
				// cout<<acum+d<<" halts snd point\n";exit(0);
			}
			if(l>r)swap(l,r);
			st.insert({l,r});
		};
		if(pq.y==0)halt(hor[p.y],p.x,q.x);
		else halt(ver[p.x],p.y,q.y);
		p=q;
		acum+=mov[i].snd;
	}
	ll l=0,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(hay(m))r=m-1;
		else l=m+1;
	}
	if(l==n+1){cout<<acum<<"\n";exit(0);}
	// cout<<r<<" r\n";
	acum=0;
	ll dist=INF;
	fore(i,0,r){
		acum+=a[i].pq.manh();
		ll d=a[r].dist(a[i]);
		if(d>=0&&i<r-1)dist=min(dist,d);
		// cout<<i<<":";
		// cout<<" +=acum "<<a[i].pq.manh();
		// cout<<" d "<<d<<"\n";
	}
	cout<<acum+dist<<"\n";
	return 0;
}