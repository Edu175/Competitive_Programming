#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto p:v)cout<<p<<" ";;cout<<"\n";}
#define impp(v) {for(auto p:v)cout<<cv(p)<<" ";;cout<<endl;}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;

struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	ll norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	ll operator*(pt p){return x*p.x+y*p.y;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
	bool operator<(pt p) const {
		if(x==p.x)return y<p.y;
		return x<p.x;
	}
};
#define str to_string
string cv(pt p){return str(p.x)+","+str(p.y);}

vector<pt> chull(vector<pt> p){// CCW order
	if(SZ(p)<3) return p;//incl collinear
	vector<pt> r; sort(ALL(p)); int k=0;
	fore(_,0,2){//first lower hull, then upper hull
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
			r.pb(p[i]);
		}
        r.pop_back(),k=SZ(r),reverse(ALL(p));
	}
	return r;
}
bool acute(pt p, pt q, pt r){return r.left(p,q);}
bool obtuse(pt p, pt q, pt r){return !acute(p,q,r);}
bool proper(vector<pt> a){
	ll n=SZ(a);
	if(n<3)return 0;
	fore(i,0,n){
		ll j=(i+1)%n,k=(i+2)%n;
		if(!acute(a[i],a[j],a[k]))return 0;
	}
	return 1;
}
ld len(pt p, pt q){return (q-p).norm();}
ld perimeter(vector<pt> a){
	ll n=SZ(a);
	ld res=0;
	fore(i,0,n){
		ll j=(i+1)%n;
		res+=len(a[i],a[j]);
	}
	return res;
}
ll cuad(pt p){
	if(p.x>0&&p.y>=0)return 0;
	if(p.x<=0&&p.y>0)return 1;
	if(p.x<0&&p.y<=0)return 2;
	if(p.x>=0&&p.y<0)return 3;
	assert(!p.x&&!p.y);
	return -1;
}
bool cmp(pt p, pt q){
	ll c1=cuad(p),c2=cuad(q);
	if(c1==c2)return p%q>0;
	return c1<c2;
}
pt o(0,0);
struct poly{ // its a queue
	ld perim=0;
	ll bads=0;
	deque<pt> a;
	bool good(){
		ll n=SZ(a);
		if(n<=1||bads)return 0;
		// I think these two can be asserted
		// NO, because of collinears, they dont guarantee
		// a good triangle even if they are on the same semiplane 
		if(obtuse(o,a[0],a[1]))return 0;
		if(obtuse(a[n-2],a[n-1],o))return 0;
		return 1;
	}
	ld get(){
		if(!good())return -INF;
		return perim+len(o,a.front())+len(o,a.back());
	}
	
	void pop(){
		if(SZ(a)>=3)bads-=obtuse(a[0],a[1],a[2]);
		if(SZ(a)>=2)perim-=len(a[0],a[1]);
		a.pop_front();
	}
	void push(pt p){
		a.push_back(p);
		ll n=SZ(a);
		if(n>=3)bads+=obtuse(a[n-3],a[n-2],a[n-1]);
		if(n>=2)perim+=len(a[n-2],a[n-1]);
	}
};

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pt> a(n);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		sort(ALL(a),cmp);
		// impp(a)
		ld res=0;
		do{
			auto b=a; b.pb(o);
			auto CH=chull(b);
			if(!proper(CH))continue;
			set<pt> sCH(ALL(CH));
			auto _b=b; b.clear();
			for(auto i:_b)if(!sCH.count(i))b.pb(i);
			b.pb(o);
			auto ch=chull(b);
			if(SZ(ch)<SZ(b)||!proper(ch))continue;
			res=perimeter(CH)+perimeter(ch);
		}while(0);
		// cerr<<res<<" inside\n";
		poly me,otr;
		ll po=0;
		auto same=[&](ll s, ll i){return s==i||a[i].left(a[s],o);};
		
		// build initial
		fore(i,1,n){
			if(same(0,i)){
				if(po==0)po=i;
				me.push(a[i]);
			}
			else otr.push(a[i]);
		}
		me.push(a[0]);
		// done
		
		auto cand=[&](ll s){
			assert(SZ(me.a)+SZ(otr.a)==n);
			// cout<<s<<": "<<po<<":\n";
			// cout<<"me: ";impp(me.a)
			// cout<<"otr: ";impp(otr.a)
						
			if(s+1<n&&!cmp(a[s],a[s+1]))return;
			
			ld cur=me.get()+otr.get();
			// cout<<"= "<<cur<<"\n\n";

			res=max(res,cur);
		};
		
		cand(0);
		
		fore(s,1,n){
			ll pri=1;
			while((pri&&s==po)||!same(s,po)){
				pri=0;
				me.pop();
				otr.push(a[po++]);
				po%=n;
			}
			me.push(a[s]);
			otr.pop();
			
			cand(s);
		}
		cout<<fixed<<setprecision(15);
		cout<<res<<"\n";
	}
	return 0;
}