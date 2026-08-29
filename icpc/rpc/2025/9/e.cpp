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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e15;
typedef ll tc;
struct Line{tc m,h;};
struct CHT{
	vector<Line> c;
	int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x/y+(x%y?!((x>0)^(y>0)):0);
	}
	void add(tc m, tc h){
		Line l=(Line){m,h};
		if(SZ(c)&&m==c.back().m){
			l.h=min(h,c.back().h);c.pop_back();if(pos)pos--;
		}
		while(SZ(c)>1&&in(c.back(),l)<=in(c[SZ(c)-2],c.back())){
			c.pop_back();if(pos)pos--;
		}
		c.pb(l);
	}
	inline bool fbin(tc x, int m){return in(c[m],c[m+1])>x;}
	tc eval(tc x){
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<SZ(c)-1&&!fbin(x,pos))pos++;
		if(pos>=SZ(c))return INF;
		return c[pos].m*x+c[pos].h;
	}
};
struct STree{
	vector<CHT> t; ll n;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, tc m, tc h){
		for(p+=n;p>0;p>>=1)t[p].add(m,h);
	}
	tc query(ll l, ll r, tc x){
		tc res=INF;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=min(res,t[l++].eval(x));
			if(r&1)res=min(res,t[--r].eval(x));
		}
		return res;
	}
};
const ll MAXV=1e6+5;
int main(){FIN;
	ll n; cin>>n;
	vv a(n+1,0);
	fore(i,1,n+1)cin>>a[i];
	a.pb(MAXV-1);
	n=SZ(a);
	STree st(MAXV);
	auto agr=[&](ll j, ll dp){st.upd(a[j],-2*j,j*j+dp);};
	agr(0,0);
	ll ult=-1;
	fore(i,1,n){
		ll cur=st.query(0,a[i]+1,i-1)+(i-1)*(i-1);
		ult=cur;
		agr(i,cur);
		// cerr<<i<<": "<<cur<<"\n";
	}
	cout<<ult<<"\n";
	return 0;
}
