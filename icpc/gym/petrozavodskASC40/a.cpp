#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef __int128 xl;
struct pt{
ll x,y;
pt(ll x, ll y): x(x), y(y) {}
pt() {}
ll norm2(){return *this**this;}
pt operator+(pt p){return pt(x+p.x,y+p.y);}
pt operator-(pt p){return pt(x-p.x,y-p.y);}
ll operator*(pt p){return x*p.x+y*p.y;}
ll operator%(pt p){return x*p.y-y*p.x;}
bool left(pt p,pt q){return (q-p)%(*this-p)>=0;}
bool operator<(pt p)const{
	return x<p.x ||(x==p.x && y<p.y);
}
};
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3) return p;
	vector<pt> r;
	sort(ALL(p));
	ll k=0;
	fore(_,0,2){
		fore(i,0,SZ(p)){
			while(SZ(r)>=2+k&&r.back().left(r[SZ(r)-2],p[i])){
				r.pop_back();
				cout<<"wchull"<<endl;
			}
			r.pb(p[i]);
		}
		r.pop_back();
		k=SZ(r);
		reverse(ALL(p));
	}
	return r;
}
void newchull(vector<pt> &v, pt p,bool b){ // 1 if ccw for checking, but v in cw, 0 if cw for checking, but v in ccw
	while(SZ(v)>1){
		if(v.back().left(v[SZ(v)-2],p)^b) v.pop_back();
		else break;
	}
}
xl area(vector<pt> v){
	return SZ(v);
	ll n=SZ(v);
	xl r=0;
	fore(i,0,n){
		r+=v[i]%v[(i+1)%n];
	}
	if(r<0) r=-r;
	assert((!(r&(xl(1)))));
	return (r>>1);
}
xl titecede(xl a, xl b){
	if(a>b) swap(a,b);
	if(!a) return b;
	return titecede(a,b%a);
}
string tos(xl a){
	string s = "";
	if(!a) return "0";
	assert(a>0);
	while(a){
		s.pb('0'+a%10);
		a/=10;
	}
	reverse(ALL(s));
	return s;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("average.in","r",stdin);     freopen("average.out","w",stdout);
	#endif
	JET
	ll n; cin>>n;
	vector<pt> p(n);
	fore(i,0,n) cin>>p[i].x>>p[i].y;
	// fore(i,0,n) {
	// 	p[i].x*=2;
	// 	p[i].y*=2;
	// }

	vector<pt> CH=chull(p);
	set<pt> aux; for(auto P:CH)  aux.insert(P);
	vector<pt> p2; fore(i,0,n) if(!aux.count(p[i])) p2.pb(p[i]);
	vector<pt> ch=chull(p2);
	ll sz1=SZ(CH), sz2=SZ(ch);

	xl AREA=area(CH);
	cout<<tos(AREA)<<"AREA\n";
	cout<<"CH:\n";
	for(auto P:CH) cout<<"("<<P.x<<","<<P.y<<") ";;cout<<"\n";
	cout<<"ch:\n";
	for(auto P:ch) cout<<"("<<P.x<<","<<P.y<<") ";;cout<<"\n";

	assert((sz1>2 || (!sz2)));
	bool b[sz2];
	fore(i,0,sz2){
		b[i]=(ch[i].left(CH[2],CH[0]));
	}
	ll l=0,r=sz2;
	fore(i,0,sz2){
		if(b[i]&& !b[(i+1)%sz2]) r=i+1;
		if(!b[i] && b[(i+1)%sz2]) l=(i+1)%sz2;
	}
	if(r<l) r+=sz2;

	#define ant ((i-1)%sz1)
	#define sig ((i+1)%sz1)
	xl tot=0;

	fore(i,1,sz1+1){
		cout<<"\n";
		cout<<(i%sz1)<<":\n";

		while((l==r || r%sz2!=l%sz2 ) && ch[r%sz2].left(CH[sig],CH[ant])) {
			r++;
			cout<<"w1"<<endl;
		}
		while(l<r && !ch[l%sz2].left(CH[sig],CH[ant])) {
			l++;
			cout<<"w2"<<endl;
		}
		cout<<l<<" "<<r<<"\n";
		p2.clear();
		fore(j,l,r){
			p2.pb(ch[j%sz2]);
		}
		cout<<"p2crudo:\n";
		for(auto P:p2) cout<<"("<<P.x<<","<<P.y<<") ";;cout<<"\n";

		p2.pb(CH[sig]);
		reverse(ALL(p2));
		newchull(p2,CH[ant],1);
		p2.pb(CH[ant]);
		reverse(ALL(p2));
		p2.pop_back();

		newchull(p2,CH[sig],0);
		p2.pb(CH[sig]);
		cout<<"p2cocinado:\n";
		// for(auto P:p2) cout<<"("<<P.x<<","<<P.y<<") ";;cout<<"\n";
		// xl ar=abs(CH[ant]%CH[(i%sz1)]+CH[(i%sz1)]%CH[sig]+CH[sig]%CH[ant])/2;
		xl ar=area({CH[ant],CH[(i%sz1)],CH[sig]});
		cout<<tos(ar)<<"areatrig\n";
		ar=AREA-ar;
		cout<<tos(area(p2))<<"areapol\n";
		ar+=area(p2);
		tot+=ar;
	}
	cout<<"tot antes: "<<tos(tot)<<"\n";
	tot+=AREA*(n-SZ(CH));
	cout<<"tot dsps: "<<tos(tot)<<"\n";
	// n<<=2;
	xl g=titecede(tot,n);
	tot/=g, n/=g;
	cout<<tos(tot)<<"/"<<tos(n)<<"\n";
	return 0;
}
// wchull
// wchull
// wchull
// wchull
// CH:
// (0,0) (8,0) (8,8) (0,8)
// ch:
// (6,6)

// 1:
// 0 1
// p2crudo:
// (6,6)
// p2cocinado:
// (0,0) (8,8)

// 2:
// 0 1
// p2crudo:
// (6,6)
// p2cocinado:
// (0,8) (0,8)

// 3:
// 0 1
// p2crudo:
// (6,6)
// p2cocinado:
// (8,0) (6,6) (0,0)

// 0:
// w2
// 1 1
// p2crudo:

// p2cocinado:
// (6,6) (8,0)
// 54/5
