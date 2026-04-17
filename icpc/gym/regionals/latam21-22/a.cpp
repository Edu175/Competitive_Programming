#include <bits/stdc++.h>
#define  fore(i,a,b) for(int i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=2e18;
// #pragma GCC optimize("Ofast")
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p)const{return x*p.y-y*p.x;}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	bool operator!=(pt p){return !(*this==p);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>0;}
	string cv(){return to_string(x)+","+to_string(y);}
};
int cuad(const pt &a) {
	if(a.x>0&&a.y>=0)return 0;
	if(a.x<=0&&a.y>0)return 1;
	if(a.x<0&&a.y<=0)return 2;
	if(a.x>=0&&a.y<0)return 3;
	assert(a.x==0&&a.y==0);
	return -1;
}
const int MAXN=405;
typedef int node;
#define oper(a,b) (a+b)
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
	void init(vector<node>a){
		fore(i,0,n)t[n+i]=a[i];
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
};
pt a[MAXN];
int n;
ll s;
int concavo(pt &p, pt &q, vector<pt> &a){
	vector<pt>l,r;
	int pos=-1; fore(i,0,SZ(a))if(a[i]==p)pos=i;
	rotate(a.begin(),a.begin()+pos,a.end());
	auto area=[&](pt r){
		ll res=abs(p%q+q%r+r%p);
		return res;
	};
	vector<pair<ll,int>>so;
	fore(i,1,SZ(a)){
		if(a[i].left(p,q))l.pb(a[i]),so.pb({s-area(a[i]),SZ(l)-1});
		else r.pb(a[i]),so.pb({area(a[i]),MAXN+SZ(r)-1});
	}
	sort(ALL(so));
	int n=SZ(l),m=SZ(r);
	vector<int> idl(n),idr(m);
	int cnt=-1;
	ll prev=-INF-6465434343646;
	for(auto [key,snd]:so){
		ll ty=snd>=MAXN,idx=ty?snd-MAXN:snd;
		if(!ty)idl[idx]=cnt+(prev!=key);
		else cnt+=prev!=key,prev=key,idr[idx]=cnt;
	}
	++cnt; vector<int> ini(cnt);
	fore(i,0,m)ini[idr[i]]++;
	STree st(cnt);
	st.init(ini);
	int po=0;
	int res=0;
	fore(i,0,n){
		while(po<m&&l[i].left(r[po],q))st.upd(idr[po++],-1);
		int resi=st.query(idl[i],st.n);
		res+=resi;
	}
	// cout<<"concavo "<<p.cv()<<" "<<q.cv()<<": "<<res<<"\n";
	return res;
}

int todos(pt p, pt q){ // counts convex twice
	vv ra,la;
	auto area=[&](pt r){
		ll res=abs(p%q+q%r+r%p);
		return res;
	};
	fore(i,0,n)if(a[i]!=p&&a[i]!=q){ // no collinear with p,q
		if(a[i].left(p,q))la.pb(area(a[i]));
		else ra.pb(area(a[i]));
	}
	sort(ALL(la));
	sort(ALL(ra)); reverse(ALL(ra));
	int n=SZ(la),m=SZ(ra);
	int res=0,po=0;
	for(auto i:la){
		while(po<m&&i+ra[po]>=s)po++;
		res+=po;
	}
	// cout<<"todos "<<p.cv()<<" "<<q.cv()<<": "<<res<<"\n";
	return res;
}
signed main(){
	ET
	cin>>s>>n; s*=2;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ll all=0,conc=0;
	fore(i,0,n){
		vector<pair<int,pt>>bm;
		fore(j,0,n)if(i!=j){
			pt p=a[j]-a[i];
			bm.pb({cuad(p),p});
		}
		sort(ALL(bm),[](const pair<int,pt> &a, const pair<int,pt> &b){
			if(a.fst==b.fst)return a.snd%b.snd>0;
			return a.fst<b.fst;
		});
		vector<pt>b;
		for(auto j:bm)b.pb(j.snd+a[i]);
		fore(j,0,n)if(i!=j){
			if(i<j)all+=todos(a[i],a[j]);
			conc+=concavo(a[j],a[i],b);
		}
	}
	// cout<<all<<" all\n";
	// cout<<conc<<" conc\n";
	ll res=(all+conc)/2;
	cout<<res<<"\n";
}