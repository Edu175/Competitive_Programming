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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ld tc;
struct Line{tc m,h;};
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c; int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x/y;
		// return x/y+(x%y?!((x>0)^(y>0)):0);//==ceil(x/y)
	}
	void add(tc m, tc h){ // m's should be non increasing
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
		// O(log n) query:
		// int s=0,e=SZ(c);
		// while(e-s>1){int m=(s+e)/2;
		// 	if(fbin(x,m-1))e=m;
		// 	else s=m;
		// }
		// return c[s].m*x+c[s].h;
		// O(1) query (for ordered x's):
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<SZ(c)-1&&!fbin(x,pos))pos++;
		return c[pos].m*x+c[pos].h;
	}
};
// a.n-m*a.d > m*b.d-b.n

struct fr{ll n,d;};
// bool operator<(fr a, fr b){return a.n*b.d<b.n+a.d;}

ld med(ld a, ld b){
	if(2*a<b)return sqrt(a*b);
	return (a+b)/2;
}

int main(){FIN;
	ll n; cin>>n;
	vector<fr> a(n),b(n);
	ll s=0;
	fore(i,0,n){
		ll x; cin>>x; s+=x;
		a[i]={s,i+1};
	}
	s=0;
	fore(i,0,n){
		ll x; cin>>x; s+=x;
		b[i]={s,i+1};
	}
	
	vector<ld> ls(n),rs(n);
	fore(i,0,n)ls[i]=1e-7,rs[i]=1e10;
	fore(_,0,25){
		CHT cht;
		for(ll i=n-1;i>=0;i--)cht.add(b[i].d,-b[i].n);
		vector<pair<ld,ll>> ms;
		fore(i,0,n)ms.pb({med(ls[i],rs[i]),i});
		sort(ALL(ms));
		
		for(auto [m,i]:ms){
			auto &l=ls[i],&r=rs[i];
			// cerr<<i<<": "<<l<<","<<r<<"\n";
			if(a[i].n-m*a[i].d>cht.eval(m))l=m;
			else r=m;
		}
	}
	ll mx=0;
	fore(i,0,n)if(rs[i]>rs[mx])mx=i;
	ld m=rs[mx];
	// cerr<<"m "<<m<<"\n";
	ll mn=0; ld val=1e24; // 1e9*(1e9*1e5)
	fore(i,0,n){
		ld cur=m*b[i].d-b[i].n;
		if(cur<val)mn=i,val=cur;
	}
	cout<<mx+1<<" "<<mn+1<<"\n";
	return 0;
}