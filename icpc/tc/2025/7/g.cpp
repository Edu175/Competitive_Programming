#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef ll tc;
struct Line{tc m,h;};
struct CHT{
	vector<Line> c;
	int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x/y+(x%y?!((x>0)^(y>0)):0);
	}
	void __add(tc m, tc h){
		Line l=(Line){m,h};
		if(SZ(c)&&m==c.back().m){
			l.h=min(h,c.back().h);
			c.pop_back();
			if(pos)pos--;
		}
		while(SZ(c)>1&&in(c.back(),l)<=in(c[SZ(c)-2],c.back())){
			c.pop_back(); if(pos)pos--;
		}
		c.pb(l);
	}
	inline bool fbin(tc x, int m){return in(c[m],c[m+1])>x;}
	tc __eval(tc x){
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<SZ(c)-1&&!fbin(x,pos))pos++;
		return c[pos].m*x+c[pos].h;
	}
	void add(tc m, tc h){__add(-m,-h);}
	tc eval(tc x){return -__eval(x);}
};

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv sp(n+1);
	fore(i,0,n)sp[i+1]=sp[i]+a[i];
	CHT cht;
	fore(j,0,n+1)cht.add(j,-sp[j]);
	vector<ii>sa;
	fore(i,0,n)sa.pb({a[i],i});
	sort(ALL(sa));
	ll del=0;
	for(auto [v,i]:sa){
		ll cur=cht.eval(v)+sp[i]-v*i;
		// cout<<v<<" "<<i<<": "<<cur<<"\n";
		del=max(del,cur);
	}
	ll res=0;
	fore(i,0,n)res+=(i+1)*a[i];
	res+=del;
	// cout<<del<<"\n";
	cout<<res<<"\n";
	return 0;
}