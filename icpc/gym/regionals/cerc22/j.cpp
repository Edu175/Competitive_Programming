#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef __int128_t xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	xl operator%(pt p){
		xl arg=xl(x)*xl(p.y)-xl(y)*xl(p.x);
		// cerr<<"arg "<<arg<<"\n";
		return arg;
	}
	bool left(pt p, pt q){return xl((q-p)%(*this-p))>xl(0);}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
};
vector<pt> chull(vector<pt> p){
	// if(SZ(p)<3)return p;
	vector<pt> r; int k = 0;
	fore(i,0,SZ(p)){
		while(SZ(r)>1+k && r.back().leftOrAt(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	return r;
}
bool les(pt a, pt b){ // a < b ?
	ll ret=b.left(pt(0,0),a);
	// cout<<"is "<<b.x<<","<<b.y<<" left of (0,0) "<<a.x<<","<<a.y<<"? "<<ret<<"\n";
	return ret;
}
vv sp; // )
struct STree{
	vector<vector<pt>> st; ll n;
	STree(ll n):st(2*n+5),n(n){}
	void agr(ll p, pt e){ // agrega en orden
		for(p+=n;p>0;p>>=1)st[p].pb(e);
	}
	void init(){
		fore(i,0,SZ(st))st[i]=chull(st[i]);
	}
	pt cand(ll sumx, ll sumy, vector<pt> &c){
		// cerr<<"cand ";
		// for(auto p:c)cout<<p.x+sumx<<","<<p.y+sumy<<" ";;cout<<"\n";
		ll l=-1,r=SZ(c)-1;
		while(r-l>1){
			ll m=(l+r)/2;
			pt p=c[m];
			p.x+=sumx; p.y+=sumy;
			pt q=c[m+1];
			q.x+=sumx; q.y+=sumy;
			// cerr<<"can "<<m<<" "<<m+1<<": "<<p.x<<","<<p.y<<" "<<q.x<<","<<q.y<<" = "<<les(q,p)<<"\n";;
			if(les(q,p))l=m;
			else r=m;
		}
		// cout<<"= "<<r<<": "<<c[r].x<<","<<c[r].y<<"\n";
		pt ret=c[r];
		ret.x+=sumx;
		ret.y+=sumy;
		return ret;
	}
	pt query(ll l, ll r){
		ll sumx=-(l-1);
		ll sumy=-sp[l];
		// cerr<<"sum "<<sumx<<" "<<sumy<<"\n";
		vector<ll> indL,indR;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)indL.pb(l++);
			if(r&1)indR.pb(--r);
		}
		vv ind=indL; reverse(ALL(indR));
		for(auto i:indR)ind.pb(i);
		pt res={1,INF};
		for(auto i:ind){
			pt got=cand(sumx,sumy,st[i]);
			if(les(got,res))res=got;
		}
		return res;
	}
};
int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	sp=vv(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	STree st(n);
	fore(i,0,n)st.agr(i,{i,sp[i+1]});
	st.init();
	while(q--){
		ll l,z; cin>>l>>z; l--;
		ll r=l+z;
		auto p=st.query(l,r);
		ll num=p.y;
		if(num<0){
			cout<<"stay with parents\n";
			continue;
		}
		// cerr<<"p "<<p.x<<","<<p.y<<"\n";
		ll res=num/p.x;
		// if(res>INF/10)res=0;
		cout<<res<<"\n";
	}
	return 0;
}
