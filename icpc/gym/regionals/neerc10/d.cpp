#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld EPS=1e-6,DINF=1e15;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>-EPS;
	}
};
vector<pt> chull(vector<pt>p){
	//if(SZ(p)<3)return p;
	vector<pt> r;
	sort(ALL(p));
	// fore(i,0,SZ(p)){
	// 	while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
	// 	r.pb(p[i]);
	// }
	// r.pop_back();
	// ll L=SZ(r);
	// int k=SZ(r);
	for(ll i=SZ(p)-1;i>=0;i--){
		while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],p[i])){
		r.pop_back();
		}
		r.pb(p[i]);
	}
	ld mx=-5;
	fore(i,0,SZ(r))mx=max(mx,r[i].y);
	vector<pt>res;
	fore(i,0,SZ(r)){
		res.pb(r[i]);
		if(abs(mx-r[i].y)<=EPS)return res;
	}
	assert(0);
}
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
ln Xaxis(pt(1,0),pt(0,0));
ln Yaxis(pt(0,1),pt(0,0));
ld getH(ld r, pt p){
	ln l(pt(r,0),p);
	return (l^Yaxis).y;
}

pair<ld,ld> myn(pair<ld,ld> a, pair<ld,ld> b){ // r,h
	if(a.fst*a.fst*a.snd<=b.fst*b.fst*b.snd)return a;
	return b;
}

int main(){
	#ifdef ONLINE_JUDGE
	freopen("dome.in","r",stdin);     freopen("dome.out","w",stdout);
	#endif
	JET
	ll n; cin>>n;
	vector<pt>a;
	fore(i,0,n){
		ld x,y,z; cin>>x>>y>>z;
		pt p=pt(pt(x,y).norm(),z);
		a.pb(p);
	}
	auto c=chull(a);
	pair<ld,ld> best={-1,-1}; ll did=0;
	// for(auto i:c)cout<<i.x<<","<<i.y<<" ";;cout<<"\n";
	fore(i,0,SZ(c)){
		ld L=0,R=DINF;
		if(i){
			pt p=ln(c[i-1],c[i])^Xaxis;
			L=max(L,p.x);
		}
		if(i<SZ(c)-1){
			pt p=ln(c[i],c[i+1])^Xaxis;
			R=min(R,p.x);
		}
		ld m=3*c[i].x/2;
		auto proba=[&](ld r){
			// cout<<"proba "<<r<<"\n";
			pair<ld,ld> cand={r,getH(r,c[i])};
			if(!did)did=1,best=cand;
			else best=myn(best,cand);
			// cout<<best.fst<<" "<<best.snd<<"\n";
		};
		// cout<<L<<" "<<m<<" "<<R<<"\n";
		if(L<=m&&m<=R){
			proba(m);
		}
		if(L>0)proba(L);
		if(R<DINF)proba(R);
	}
	assert(did);
	cout<<fixed<<setprecision(3);
	cout<<best.snd<<" "<<best.fst<<"\n";
	return 0;
}

/*

2
1.00 0.00 1.00
0.00 1.50 0.50
1,1 1.5,0.5 
0 1.5 2
proba 1.5
1.5 3
proba 2
1.5 3
2 2.25 1e+10
proba 2.25
1.5 3
proba 2
1.5 3
3.000 1.500




*/