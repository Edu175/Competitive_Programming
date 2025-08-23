#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long long ld;
const ld eps=0;
struct pt{
	ld x,y;
	pt(ld x, ld y): x(x), y(y){}
	pt() {}
	ld norm2(){return *this**this;}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{
		return ii({x,y}) < ii({p.x,p.y});
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
};
typedef vector<pt> poly;
poly chull(poly p){
	if(SZ(p)<3) return p;
	poly r;
	sort(ALL(p));
	fore(i,0,SZ(p)){
		while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=SZ(r);
	for(int i=SZ(p)-1; i>=0; --i){
		while(SZ(r)>=k+2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}

ld area(poly p){
	ld r=0;
	ll n=SZ(p);
	fore(i,0,n) r+=p[i]%p[((i+1)%n)];
	return abs(r);
}
ld tr(pt p, pt q, pt r){
	return abs((p%q)+(q%r)+(r%p));
}
int main(){
	JET
	ll _;cin>>_; while(_--){
		ll n;cin>>n;
		poly p(n);
		fore(i,0,n) cin>>p[i].x>>p[i].y;
		//primer hull
		auto c1=chull(p);
		if(SZ(c1)==n){//no se puede
			cout<<"-1\n"; continue;
		}
		ll rta=area(c1);
		set<pt> c;
		fore(i,0,SZ(c1)) c.insert(c1[i]);
		poly p2; fore(i,0,n) if(!c.count(p[i])) p2.pb(p[i]);
		ll M=LLONG_MAX;
		pt X;
		fore(i,0,SZ(p2)){
			fore(j,0,SZ(c1)){
				if(M<tr(c1[j],c1[((j+1)%SZ(c1))],p2[i])){
					M=tr(c1[j],c1[((j+1)%SZ(c1))],p2[i]);
					X=p2[i];
				};
			}
		}
		cout<<X.x<<" "<<Y.y<<"\n"
		cout<<ll(rta-M)<<"\n";
	}
	return 0;
}