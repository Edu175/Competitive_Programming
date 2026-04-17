#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6;
typedef double ld;
const ld EPS=1e-6,DINF=4e9;

struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
	void prnt(){cout<<x<<","<<y;}
};
pt ccw90(1,0);
pt cw90(-1,0);

int sgn2(ld x){return x<0?-1:1;}
struct ln {
	pt p,pq,q;
	ln(pt p, pt q):p(p),pq(q-p),q(q){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	ld angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	ld dist(pt r){return (r-proj(r)).norm();}
//	ld dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
	void prnt(){p.prnt(),cout<<"--";q.prnt();}
};
ln bisector(ln l, ln m){ // angle bisector
	pt p=l^m;
	return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}

ll c,q,t;

vector<pair<pt,ld>> cy;
vector<vector<pt>>a;

ld dis(pt p, ln l){ // distance from p to segment l
	ld res=min((l.p-p).norm(),(l.q-p).norm());
	//pt q=l.proj(p);
	//if(l.p.x-q.x<=EPS&&q.x-l.q.x<=EPS)res=min(res,l.dist(p));
	if(l.seghas(l.proj(p)))res=min(res,l.dist(p));
	//cout<<"dis ";p.prnt();cout<<" ";l.prnt();cout<<": ";q.prnt();cout<<" = "<<res<<"\n";
	return res;
}
ld dis(ln l, ln m){ // distance from segment l to segment m
	//pt p=l^m;
	//if(l.seghas(p)&&m.seghas(p))return 0;
	return min({
		dis(l.p,m),
		dis(l.q,m),
		dis(m.p,l),
		dis(m.q,l),
	});
}
vector<pair<ll,ld>>g[MAXN];

ld dijkstra(){
	vector<ld>d(c+q+t,-1);
	priority_queue<pair<ld,ll>>pq;
	fore(i,0,q)pq.push({0,c+i}),d[c+i]=0;
	while(SZ(pq)){
		auto [di,x]=pq.top(); pq.pop(); di=-di;
		if(x>=c+q)return di;
		if(d[x]<di)continue;
		for(auto [y,w]:g[x]){
			if(d[y]==-1||di+w<d[y])d[y]=di+w,pq.push({-d[y],y});
		}
	}
}

ld pi=acos(-1);

int main(){FIN;
	//cout<<fixed<<setprecision(15)<<acos(-1)<<endl;
	cin>>c>>q>>t;
	fore(i,0,c){
		pt p; ld r; cin>>p.x>>p.y>>r;
		cy.pb({p,r});
	}
	fore(i,0,q){
		pt p,q; cin>>p.x>>p.y>>q.x>>q.y;
		//a.pb({p,pt(q.x,p.y),q,pt(p.x,q.y)}); has to be alligned
		vector<pt>v={p};
		pt o=(p+q)/2;
		ln l=ln(o,p);
		l=l.rot(pi/2);
		v.pb(l.q);
		v.pb(q);
		l=l.rot(pi);
		v.pb(l.q);
		a.pb(v);
	}
	fore(i,0,t){
		pt p,q,r; cin>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y;
		a.pb({p,q,r});
	}
	fore(i,0,c){
		pt p=cy[i].fst; ld r=cy[i].snd;
		fore(j,i+1,c){
			ld w=0;
			w=max(w,(cy[j].fst-p).norm()-r-cy[j].snd);
			g[i].pb({j,w});
			g[j].pb({i,w});
		}
		fore(j,0,q+t){
			vector<pt>v=a[j];
			ld w=DINF;
			//cout<<i<<" "<<j<<":\n";
			//p.prnt(); cout<<"o"<<r<<"\n";
			fore(k,0,SZ(v)){
				ln l=ln(v[k],v[(k+1)%SZ(v)]);
				//cout<<k<<":\n";
				//l.prnt(); cout<<": "<<dis(p,l)-r<<"\n";
				w=min(w,dis(p,l)-r);
			}
			//cout<<"\n";
			w=max(ld(0),w);
			g[i].pb({c+j,w});
			g[c+j].pb({i,w});
		}
	}
	fore(i,0,q)fore(j,q,q+t){
		vector<pt>u=a[i],v=a[j];
		ld w=DINF;
		fore(k,0,SZ(u))fore(h,0,SZ(v)){
			ln l=ln(u[k],u[(k+1)%SZ(u)]);
			ln m=ln(v[h],v[(h+1)%SZ(v)]);
			w=min(w,dis(l,m));
		}
		g[c+i].pb({c+j,w});
		g[c+j].pb({c+i,w});
	}
	/*fore(i,0,c){
		cy[i].fst.prnt(); cout<<" o"<<cy[i].snd<<"\n";
	}
	fore(i,0,q+t){
		for(auto j:a[i])j.prnt(),cout<<" ";
		cout<<"\n";
	}*/
	cout<<fixed<<setprecision(15)<<dijkstra()<<"\n";
	/*fore(i,0,c+q+t){
		cout<<i<<": ";
		for(auto [j,w]:g[i])cout<<j<<","<<w<<" ";
		cout<<"\n";
	}*/
	return 0;
}
