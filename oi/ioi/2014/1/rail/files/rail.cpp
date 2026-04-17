#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int getDistance(int x, int y);

const ll MAXN=5005,MAXV=1e6+5;
ll mem[MAXN][MAXN];
ll dis(ll x, ll y){
	ll &res=mem[x][y];
	if(res!=-1)return res;
	return res=getDistance(x,y);
}
ll h[MAXV];
void findLocation(int N, int first, int d[], int t[]){
	mset(mem,-1);
	mset(h,-1);
	auto assign=[&](ll i, ll ds, ll ty){
		// cout<<"assign "<<i<<": "<<ds<<" "<<ty<<"\n";
		d[i]=ds;
		t[i]=ty+1;
		h[d[i]]=ty;
	};
	assign(0,first,0);
	vector<ii>a;
	ll n=N;
	if(n==1)return;
	fore(i,1,n)a.pb({dis(0,i),i});
	sort(ALL(a));
	ll mn=a[0].snd;
	assign(mn,d[0]+dis(0,mn),1);
	ll l=0,r=mn;
	for(auto [w,i]:a)if(i!=mn){
		// cout<<i<<": "<<l<<" "<<r<<"\n";
		ll posd=d[0]+dis(0,i);
		ll posi=d[r]-dis(r,i);
		ll m=posi+posd;
		ii c0,c1;
		if(m%2==0&&h[m/2]==1)c1={posi,0};
		else c1={posd,1};
		
		posi=d[0]-(dis(0,i)-2*(d[mn]-d[0]));
		posd=d[l]+dis(l,i);
		m=posi+posd;
		if(m%2==0&&h[m/2]==0)c0={posd,1};
		else c0={posi,0};
		
		// cout<<c0.fst<<","<<c0.snd<<" "<<c1.fst<<","<<c1.snd<<"\n";
		ii c=dis(r,i)==(d[r]-posi)?c0:c1;
		
		assign(i,c.fst,c.snd);
		if(c.fst<d[l])l=i;
		if(c.fst>d[r])r=i;
		// cout<<"\n";
	}
}
