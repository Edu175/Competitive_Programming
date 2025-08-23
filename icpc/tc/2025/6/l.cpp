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
		// separo los puntos que no estan en el hull
		set<pt> c;
		fore(i,0,SZ(c1)) c.insert(c1[i]);
		poly p2;fore(i,0,n) if(!c.count(p[i])) p2.pb(p[i]);
		auto c2=chull(p2);
		ll rta=area(c1);
		ll po=0;
		ll m=SZ(c2); ld M=LLONG_MAX;
		ll k=SZ(c1);
		auto adm=[=](ll x, ll sz){x++; return x<sz?x:0;};
		fore(i,0,m)if(M>tr(c1[0],c1[1],c2[i])) {M=tr(c1[0],c1[1],c2[i]);po=i;}
		// cout<<po<<"\n";
		pt X;
		fore(i,0,k){
			while( tr(c1[i],c1[adm(i,k)],c2[po]) > tr(c1[i],c1[adm(i,k)],c2[adm(po,m)]) ){ 
				po=adm(po,m);
			}
			// cout<<c1[i].x<<" "<<c1[i].y<<"hull"<<i<<"\n";
			// cout<<c2[po].x<<" "<<c2[po].y<<"inn"<<po<<"\n";
			// fore(j,0,m){
			// 	cout<<tr(c1[i],c1[adm(i,k)],c2[j])<<"Area "<<c2[j].x<<" "<<c2[j].y<<"c2"<<j<<"\n";
			// }
			if(M>tr(c1[i],c1[adm(i,k)],c2[po])){
				M=tr(c1[i],c1[adm(i,k)],c2[po]);
				X=c2[po];
			}
		}
		// cout<<X.x<<" "<<X.y<<"\n";
		cout<<ll(rta-M)<<"\n";
	}
	return 0;
}
// -44 45 //yo
// 20895
// ///
// 5 -31 // bruta
// 21408
// ////
// 1
// 7
// 5 -31
// -61 72
// 46 66
// -10 9
// -44 45
// -74 -36
// 10 -60


// 2
// -74 -36hull0
// -10 9inn2
// 7524Area -44 45c20
// 2316Area 5 -31c21
// 5316Area -10 9c22
// 10 -60hull1
// -10 9inn2
// 10584Area -44 45c20
// 1674Area 5 -31c21
// 5004Area -10 9c22
// 46 66hull2
// -44 45inn0
// 2787Area -44 45c20
// 10625Area 5 -31c21
// 6435Area -10 9c22
// -61 72hull3
// -44 45inn0
// 2187Area -44 45c20
// 8467Area 5 -31c21
// 6327Area -10 9c22
// -44 45
// 20895