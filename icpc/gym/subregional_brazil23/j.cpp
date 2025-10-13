#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impt(v) {for(auto i:v)cout<<i.x<<","<<i.y<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld EPS=1e-9,INF=1e20;

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
};
pt ccw90(1,0);
pt cw90(-1,0);

// Returns planar graph representing Delaunay's triangulation.
// Edges for each vertex are in ccw order.
// It can work with doubles, but also integers (replace long double in line 51)
typedef struct QuadEdge* Q;
struct QuadEdge {
	int id,used;
	pt o;
	Q rot,nxt;
	QuadEdge(int id=-1, pt o=pt(INF,INF)):id(id),used(0),o(o),rot(0),nxt(0){}
	Q rev(){return rot->rot;}
	Q next(){return nxt;}
	Q prev(){return rot->next()->rot;}
	pt dest(){return rev()->o;}
};

Q edge(pt a, pt b, int ida, int idb){
	Q e1=new QuadEdge(ida,a);
	Q e2=new QuadEdge(idb,b);
	Q e3=new QuadEdge;
	Q e4=new QuadEdge;
	tie(e1->rot,e2->rot,e3->rot,e4->rot)={e3,e4,e2,e1};
	tie(e1->nxt,e2->nxt,e3->nxt,e4->nxt)={e1,e2,e4,e3};
	return e1;
}

void splice(Q a, Q b){
	swap(a->nxt->rot->nxt,b->nxt->rot->nxt);
	swap(a->nxt,b->nxt);
}

void del_edge(Q& e, Q ne){
	splice(e,e->prev()); splice(e->rev(),e->rev()->prev());
	delete e->rev()->rot; delete e->rev();
	delete e->rot; delete e;
	e=ne;
}

Q conn(Q a, Q b){
	Q e=edge(a->dest(),b->o,a->rev()->id,b->id);
	splice(e,a->rev()->prev());
	splice(e->rev(),b);
	return e;
}

auto area(pt p, pt q, pt r){return (q-p)%(r-q);}

// is p in circunference formed by (a,b,c)?
bool in_c(pt a, pt b, pt c, pt p){
	// Warning: this number is O(max_coord^4).
	// Consider using int128 or using an alternative method for this function
	long double p2=p*p,A=a*a-p2,B=b*b-p2,C=c*c-p2;
	return area(p,a,b)*C+area(p,b,c)*A+area(p,c,a)*B>EPS;
}

pair<Q,Q> build_tr(vector<pt>& p, int l, int r){
	if(r-l+1<=3){
		Q a=edge(p[l],p[l+1],l,l+1),b=edge(p[l+1],p[r],l+1,r);
		if(r-l+1==2) return {a,a->rev()};
		splice(a->rev(),b);
		auto ar=area(p[l],p[l+1],p[r]);
		Q c=abs(ar)>EPS?conn(b,a):0;
		if(ar>=-EPS) return {a,b->rev()};
		return {c->rev(),c};
	}
	int m=(l+r)/2;
	auto [la,ra]=build_tr(p,l,m);
	auto [lb,rb]=build_tr(p,m+1,r);
	while(1){
		if(ra->dest().left(lb->o,ra->o)) ra=ra->rev()->prev();
		else if(lb->dest().left(lb->o,ra->o)) lb=lb->rev()->next();
		else break;
	}
	Q b=conn(lb->rev(),ra);
	auto valid=[&](Q e){return b->o.left(e->dest(),b->dest());};
	if(ra->o==la->o) la=b->rev();
	if(lb->o==rb->o) rb=b;
	while(1){
		Q L=b->rev()->next();
		if(valid(L)) while(in_c(b->dest(),b->o,L->dest(),L->next()->dest())) del_edge(L,L->next());
		Q R=b->prev();
		if(valid(R)) while(in_c(b->dest(),b->o,R->dest(),R->prev()->dest())) del_edge(R,R->prev());
		if(!valid(L)&&!valid(R)) break;
		if(!valid(L)||(valid(R)&&in_c(L->dest(),L->o,R->o,R->dest()))) b=conn(R,b->rev());
		else b=conn(b->rev(),L->rev());
	}
	return {la,rb};
}

vector<vector<int>> delaunay(vector<pt> v){
	int n=SZ(v); auto tmp=v;
	vector<int> id(n); iota(ALL(id),0);
	sort(ALL(id),[&](int l, int r){return v[l]<v[r];});
	fore(i,0,n) v[i]=tmp[id[i]];
	assert(unique(ALL(v))==v.end());
	vector<vector<int>> g(n);
	int col=1;
	fore(i,2,n) col&=abs(area(v[i],v[i-1],v[i-2]))<=EPS;
	if(col){
		fore(i,1,n) g[id[i-1]].pb(id[i]),g[id[i]].pb(id[i-1]);
	}
	else{
		Q e=build_tr(v,0,n-1).fst;
		vector<Q> edg={e};
		for(int i=0;i<SZ(edg);e=edg[i++]){
			for(Q at=e;!at->used;at=at->next()){
				at->used=1;
				g[id[at->id]].pb(id[at->rev()->id]);
				edg.pb(at->rev());
			}
		}
	}
	return g;
}
int sgn2(ld x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		// if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	ld angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	ld dist(pt r){return (r-proj(r)).norm();}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(ln l, ln m){ // angle bisector
	pt p=l^m;
	return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}

int main(){
	JET
	vector<pt> box(4);
	fore(i,0,4)cin>>box[i].x>>box[i].y;
	sort(ALL(box));
	swap(box[1],box[2]);
	swap(box[2],box[3]);
	// impt(box)
	auto expand=[&](ll d){
		box[0].x-=d; box[0].y-=d;
		box[1].x+=d; box[1].y-=d;
		box[2].x+=d; box[2].y+=d;
		box[3].x-=d; box[3].y+=d;
	};
	expand(1);
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	// impt(a)
	fore(i,0,n)fore(j,0,4)a.pb(ln(box[j],box[(j+1)%4]).ref(a[i]));
	// impt(a)
	auto g=delaunay(a);
	expand(-1);
	// impt(box)
	ld res=0;
	fore(x,0,n){ // only real points
		vector<ln>ls;
		// cout<<"\n"<<x<<":\n";
		for(auto y:g[x]){
			ln l=bisector(a[x],a[y]);
			// cout<<y<<": "<<a[y].x<<","<<a[y].y<<"\n";
			// cout<<l.p.x<<","<<l.p.y<<"--"<<l.pq.x<<","<<l.pq.y<<"\n";
			ll did=0;
			if(abs(l.pq.x)<=EPS){
				l.p.x=max(l.p.x,box[0].x);
				l.p.x=min(l.p.x,box[2].x);
				did=1;
			}
			if(abs(l.pq.y)<=EPS){
				l.p.y=max(l.p.y,box[0].y);
				l.p.y=min(l.p.y,box[2].y);
				did=1;
			}
			// cout<<l.p.x<<","<<l.p.y<<"--"<<l.pq.x<<","<<l.pq.y<<"\n";
			if(y<n||did)ls.pb(l);
		}
		// cout<<x<<"->"<<y<<"\n";
		fore(i,0,SZ(ls)){
			pt p=ls[i]^ls[(i+1)%SZ(ls)];
			// cout<<x<<": "<<p.x<<","<<p.y<<": "<<(p-a[x]).norm()<<"\n";
			res=max(res,(p-a[x]).norm2());
		}
	}
	res=sqrtl(res);
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}