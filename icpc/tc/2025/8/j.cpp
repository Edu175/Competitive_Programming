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
typedef ll ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p) const {return pt(x-p.x,y-p.y);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>0;}
};
struct Cmp {
	pt r;
	Cmp(){}
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1, const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<pt> a(n+1);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		vector<Cmp> cmps(n);
		vector<vv> rad(n),pos(n);
		fore(i,0,n){
			auto &r=rad[i];
			fore(j,0,n)if(i!=j)r.pb(j);
			auto &p=pos[i]; p.resize(n);
			auto &cmp=cmps[i];
			cmp=Cmp(a[i]);
			sort(ALL(r),[&](ll i, ll j){return cmp(a[i],a[j]);});
			fore(j,0,SZ(r))p[r[j]]=j;
		}
		ll m=n-1;
		auto opu=[&](ll i, ll j){
			pt p=a[j]-(a[i]-a[j]);
			auto &vec=rad[j];
			auto &cmp=cmps[j];
			a[n]=p;
			ll ans=lower_bound(ALL(vec),n,
				[&](ll i, ll j){return cmp(a[i],a[j]);}
			)-vec.begin();
			return ans;
		};
		auto dis=[&](ll s, ll e){if(e<s)e+=m;return e-s;};
		auto afu=[&](ll i, ll j, ll k){ // returns cant
			ll e=opu(i,j);
			ll s=opu(k,j);
			return dis(s,e);
		};
		
		auto query=[&](ll i, ll j, ll k){
			ll big=dis(pos[k][i],pos[k][j]);
			ll semi=dis(pos[j][i],opu(i,j));
			ll t1=afu(i,j,k);
			ll t2=afu(k,i,j);
			return big-semi+t1+t2;
		};
		
		while(q--){
			ll i,j,k; cin>>i>>j>>k; i--,j--,k--;
			if(!a[k].left(a[i],a[j]))swap(i,j);
			if(!query(i,j,k))cout<<"YES\n";
			else cout<<"NO\n";
		}
		
	}
	return 0;
}