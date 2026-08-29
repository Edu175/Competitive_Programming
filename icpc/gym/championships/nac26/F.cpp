#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v){for(auto x:v)cout<<x<<" "; cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll MAXN=2e5+5;
const ll INF=1e18;
#define NEUT -INF
ld ft[MAXN+1];
void reset(){ // ft
	fill(ft,ft+MAXN,NEUT);
}
void upd(int i0, ld v){
	for(int i=i0+1;i<=MAXN;i+=(i&-i))ft[i]=max(ft[i],v);
}
ld get(int i0){
	ld r=NEUT;
	for(int i=i0;i;i-=(i&-i))r=max(r,ft[i]);
	return r;
}
vector<array<ll,3>> a;
vv pos; // del y
bool can(ld k){
	ll n=SZ(a);
	reset();
	// cerr<<"\n\ncan "<<k<<":\n";
	fore(i,0,n){
		auto &[x,y,v]=a[i];
		ll sum=x+y;
		ld got=get(pos[i]+1);
		// if(got>NEUT+1000){ // hay alguien posta
		ld cur=got-k*v+sum;
		// if(cur<0){
		// 	cerr<<"pudo "<<i<<": "<<cur<<"\n";
		// }
		if(cur>0)return 1;
		upd(pos[i],-sum-k*v);
	}
	// cerr<<"no\n";
	return 0;
}

ld solve(){
	ll n=SZ(a);
	pos=vv(n); 
	vector<ii> ys(n);
	fore(i,0,n)ys[i]={a[i][1],i};
	sort(ALL(ys));
	ll cnt=0;
	fore(i,0,n){
		pos[ys[i].snd]=cnt;
		if(i==n-1||ys[i].fst<ys[i+1].fst)cnt++;
	}
	ld l=1e-7,r=1e8+5;
	fore(_,0,64){
		ld m=(2*l<r?sqrt(l*r):(l+r)/2);
		if(can(m))l=m;
		else r=m;
	}
	return r;
}

int main(){
    JET
    ll n; cin>>n;
	a.resize(n);
	fore(i,0,n)fore(j,0,3)cin>>a[i][j];
	sort(ALL(a));
	ld res1=solve();
	reverse(ALL(a));
	for(auto &i:a)i[0]*=-1;
	ld res2=solve();
	ld res=max(res1,res2);
	// cerr<<res1<<" "<<res2<<"\n";
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
	return 0;
}
