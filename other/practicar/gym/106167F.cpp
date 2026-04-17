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
#define impp(v) {cout<<#v<<": ";for(auto i:v)cout<<cv(i)<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct pt {
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	ll norm2(){return *this**this;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	pt operator/(ll t){return pt(x/t,y/t);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (q-p)%(*this-p)>0;}
};
#define str to_string
string cv(pt p){return str(p.x)+","+str(p.y);}
pt s;
bool operator<(pt p, pt q){ // RADIAL
	return q.left(s,p);
}
bool operator>(pt p, pt q){return q<p;}
int main(){FIN;
	pt fin; cin>>s.x>>s.y>>fin.x>>fin.y;
	ll n; cin>>n;
	vector<pt> a(n),b(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y>>b[i].y,b[i].x=a[i].x;
	a.pb(fin); b.pb(fin); n++;

	deque<pt> p,q;
	// p is upper hull of a
	// q is lower hull of b
	vector<pt> res={s};
	ll r=0;
	while(r<n){
		// cout<<cv(s)<<" "<<r<<":\n";
		// impp(p)
		// impp(q)
		// cout<<endl;
		ll pone=0;
		if(!SZ(p)){
			assert(!SZ(q));
			pone=1;
		}
		else if(b[r]<p.front()){ // se degenera con b[r]
			s=p.front(); p.pop_front(); res.pb(s);
			while((SZ(q)&&q[0].x<=s.x) || (SZ(q)>=2&&!(q[0]<q[1])))q.pop_front();
		}
		else if(a[r]>q.front()){ // se degenera con a[r]
			s=q.front(); q.pop_front(); res.pb(s);
			while((SZ(p)&&p[0].x<=s.x) || (SZ(p)>=2&&!(p[0]>p[1])))p.pop_front();
		}
		else pone=1;
		if(pone){
			while(SZ(p)){
				pt cur=p.back();
				pt ant=SZ(p)>1?p[SZ(p)-2]:s;
				if(cur.left(ant,a[r]))break;
				p.pop_back();
			}
			p.pb(a[r]);

			while(SZ(q)){
				pt cur=q.back();
				pt ant=SZ(q)>1?q[SZ(q)-2]:s;
				if(cur.left(b[r],ant))break;
				q.pop_back();
			}
			q.pb(b[r]);
			
			r++;
		}
	}
	assert(s.x<fin.x);
	res.pb(fin);
	for(auto p:res)cout<<p.x<<" "<<p.y<<"\n";
	// long double len=0;
	// fore(i,0,SZ(res)-1){
	// 	auto cur2=(res[i]-res[i+1]).norm2();
	// 	long double cur=sqrtl(cur2);
	// 	// cerr<<i<<": "<<cur2<<" "<<cur<<"\n";
	// 	len+=cur;
	// }
	// cout<<fixed<<setprecision(10)<<len<<"\n";
	return 0;
}