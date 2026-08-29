#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	pt operator-(pt p)const {return pt(x-p.x,y-p.y);}
	pt unit(){
		ll g=gcd(x,y);
		assert(g);
		return *this/g;
	}
	pt operator/(ll t){
		assert(x%t==0&&y%t==0);
		return pt(x/t,y/t);
	}
	ll operator*(pt p){return x*p.x+y*p.y;}
	bool operator<(pt p)const {return x<p.x||(x==p.x&&y<p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (q-p)%(*this-p)>0;}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
	bool leftw(pt p, pt q, ll is_strict){
		if(is_strict)return left(p,q);
		return leftOrAt(p,q);
	}
	pt rotcw(){return pt(y,-x);}
};

vector<pt> chull(vector<pt> p, ll incl){
	if(SZ(p)<3)return p;
	vector<pt> r; sort(ALL(p)); int k=0;
	fore(_,0,2){
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k &&
			      r.back().leftw(r[SZ(r)-2],p[i],incl))
				r.pop_back();
			r.pb(p[i]);
		}
		r.pop_back(); k=SZ(r); reverse(ALL(p));
	}
	return r;
}
ll cuad(pt a){
	if(a.x>0&&a.y>=0)return 0;
	if(a.x<=0&&a.y>0)return 1;
	if(a.x<0&&a.y<=0)return 2;
	if(a.x>=0&&a.y<0)return 3;
	assert(a.x==0&&a.y==0);
	assert(0);
}
int main(){
    JET
	ll n,m; cin>>n>>m;
	vector<pt> a(n);
	map<pt,ll> idx;
	fore(i,0,n){
		cin>>a[i].x>>a[i].y;
		idx[a[i]]=i;
	}
	vector<pt> b(m);
	fore(i,0,m)cin>>b[i].x>>b[i].y;
	auto ch_col=chull(a,1);
	// for(auto p:ch_col){cout<<p.x<<" ";}cout<<" ch_col\n";
	map<pt,ll> bu;
	ll z=SZ(ch_col);
	auto cand=[&](pt dir, ll id){
		if(!bu.count(dir)||id<bu[dir])bu[dir]=id;
	};
	if(z>2){
		fore(i,0,z){
			pt me=ch_col[i];
			pt pre=ch_col[(i-1+z)%z];
			pt nxt=ch_col[(i+1)%z];
			if(pre==nxt)continue;
			if(me.leftOrAt(pre,nxt)&&me.leftOrAt(nxt,pre)){
				pt dir=(nxt-pre).rotcw().unit();
				cand(dir,idx[me]);
			}
		}
	}
	auto ch=chull(a,0); // no collinear
	z=SZ(ch);
	
	fore(i,0,z){
		pt me=ch[i];
		pt nxt=ch[(i+1)%z];
		pt dir=(nxt-me).rotcw().unit();
		cand(dir,idx[me]);
		cand(dir,idx[nxt]);
	}
	
	ll _m=m;
	fore(x,-1,2)fore(y,-1,2)if(x||y)b.pb(pt(x,y));
	m=SZ(b);
	
	
	vv per(m); iota(ALL(per),0);
	for(auto &p:b)p=p.unit();
	sort(ALL(per),[&](ll i, ll j){ // cambiado por radial sort
		pt &p1=b[i];
		pt &p2=b[j];
		ll c1=cuad(p1);
		ll c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	});
	vv ans(m);
	
	ll po=0;
	fore(i,0,z)if(ch[i]*b[per[0]]>ch[po]*b[per[0]])po=i;
	for(auto i:per){
		pt v=b[i];
		auto &res=ans[i];
		while(1){
			ll nxt=(po+1)%z;
			if(v*ch[nxt]>v*ch[po])po=nxt; // strict
			else break;
		}
		res=idx[ch[po]];
		if(bu.count(v))res=bu[v];
	}
	fore(i,0,_m)cout<<ans[i]+1<<"\n";
    return 0;
}
