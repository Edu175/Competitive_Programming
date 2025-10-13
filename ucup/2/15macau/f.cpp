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
void tle(bool b){
	if(!b){
		auto start=clock();
		while(clock()-start<=27*CLOCKS_PER_SEC);
	}
}
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-6;
struct pt {
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
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// is it to the left of directed line pq?,   leftoigual
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>-EPS;}
};

int sgn2(ld x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq%l.pq)<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		// tle(!(*this/l));
		// if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
int sgn(ld x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	// bool operator==(const pol& rhs){
	// 	ll fg=SZ(p)==SZ(rhs.p);
	// 	if(!fg)return 0;
	// 	fore(i,0,SZ(p))fg&=p[i]==rhs.p[i];
	// 	return fg;
	// }
	bool left(ln l){
		pt a=l.p,b=a+l.pq;
		for(auto i:p)if(!i.left(a,b))return 0;
		return 1;
	}
	ld area(){
		ld r=0.;
		fore(i,0,n){
			ll sig=i==n-1?0:i+1;
			r+=p[i]%p[sig];
		}
		return abs(r)/2; // negative if CW, positive if CCW
	}
	pol cut(ln l){   // cut CONVEX polygon by line l
		vector<pt> q;  // returns part at left of l.pq
		fore(i,0,n){
			ll sig=i+1; if(sig>=n)sig-=n;
			int d0=sgn(l.pq%(p[i]-l.p)),d1=sgn(l.pq%(p[sig]-l.p));
			if(d0>=0)q.pb(p[i]);
			ln m(p[i],p[sig]);
			if(d0*d1<0&&!(l/m))q.pb(l^m);
		}
		return pol(q);
	}
};
ln get(ll a, ll b, ll c){
	tle(a||b);
	pt p,q;
	if(b){
		auto f=[&](ll x){
			return -(c+a*x)/ld(b);
		};
		p=pt(0,f(0)),q=pt(1,f(1));
		if(b<0)swap(p,q);
	}
	else {
		p=pt(-c/ld(a),1);
		q=pt(-c/ld(a),0);
		if(a<0)swap(p,q);
	}
	return ln(p,q);
}

const ll MAXN=10005,MAXR=305*305/2;

ll L[MAXN],R[MAXN];
char op[MAXN];
vector<ln> all;
typedef bitset<MAXR> mask;
ll id[MAXN];
ll cnt=0;
string s;
ll p;
ll f(){
	// cout<<"f: "<<p<<": "<<s.substr(0,p)<<" "<<s.substr(p)<<endl;
	ll x=cnt++;
	if(s[p]=='('){
		p++;
		if(s[p]=='!')op[x]=s[p++],L[x]=f();
		else {
			L[x]=f();
			op[x]=s[p++];
			R[x]=f();
		}
		tle(s[p++]==')');
	}
	else { // atomic
		tle(s[p++]=='[');
		string tmp;
		vv a;
		do{
			if(s[p]==','||s[p]==']')a.pb(stoll(tmp)),tmp.clear();
			else tmp.pb(s[p]);
			p++;
		}while(s[p-1]!=']');
		// cout<<p<<": ";
		// imp(a) cout<<endl;
		tle(SZ(a)==3);
		ln l=get(a[0],a[1],a[2]);
		id[x]=SZ(all);
		all.pb(l);
	}
	return x;
}

vector<pol> reg;

mask dfs(ll x){
	if(L[x]==-1&&R[x]==-1){
		mask res;
		fore(j,0,SZ(reg))res[j]=reg[j].left(all[id[x]]);
		return res;
	}
	if(R[x]==-1){
		tle(op[x]=='!');
		auto res=dfs(L[x]);
		res=~res;
		return res;
	}
	auto lhs=dfs(L[x]);
	auto rhs=dfs(R[x]);
	if(op[x]=='&')lhs&=rhs;
	if(op[x]=='|')lhs|=rhs;
	if(op[x]=='^')lhs^=rhs;
	return lhs;
}

int main(){FIN;
	pt p,q; cin>>p.x>>q.x>>p.y>>q.y;
	mset(L,-1); mset(R,-1);
	cin>>s;
	ll rt=f();
	reg.pb(pol({p, pt(q.x,p.y), q, pt(p.x,q.y)}));
	for(auto l:all){
		vector<pol>prox;
		for(auto p:reg){
			ln lrev=l;
			lrev.pq=lrev.pq*-1;
			if(!p.left(lrev)){
				auto pn=p.cut(l);
				if(pn.area()*MAXR>EPS)prox.pb(pn);
			}
			if(!p.left(l)){
				auto pn=p.cut(lrev);
				if(pn.area()*MAXR>EPS)prox.pb(pn);
			}
		}
		swap(reg,prox);
	}
	assert(SZ(reg)<MAXR);
	auto bits=dfs(rt);
	ld ans=0;
	fore(i,0,SZ(reg))ans+=bits[i]*reg[i].area();
	cout<<fixed<<setprecision(15)<<ans<<"\n";
	return 0;
}
