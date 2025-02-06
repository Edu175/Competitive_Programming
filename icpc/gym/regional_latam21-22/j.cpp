#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ull R1=0xac2fa8f7a4b36573;
const ull R2=0xcc132ed981f0d3f1;
const ull R3=0xa31b3920dc4052f7;

ull falopa(ull x){
	x+=R1;
	x=(x^(x>>30))*R2;
	x=(x^(x>>27))*R3;
	return x^(x>>31);
}
ll w,h;
ii cuad(ii a){
	if(a.snd==0)return {0,a.fst};
	if(a.fst==w)return {1,a.snd};
	if(a.snd==h)return {2,-a.fst};
	if(a.fst==0)return {3,-a.snd};
	return {-1,-1};
}

int main(){
	ET
	cin>>w>>h;
	ll n; cin>>n;
	vector<pair<ii,ll>>b;
	fore(i,0,n){
		ii x,y; cin>>x.fst>>x.snd>>y.fst>>y.snd;
		if(cuad(x).fst!=-1&&cuad(y).fst!=-1){
			b.pb({cuad(x),i});
			b.pb({cuad(y),i});
		}
	}
	sort(ALL(b));
	vv vis(n);
	ll flag=1;
	ll m=SZ(b);
	vector<ull> hsh(n);
	ull ha=0;
	fore(i,0,2*m){
		ll c=b[i%m].snd;
		if(vis[c])flag&=ha==hsh[c];
		vis[c]=1;
		ha^=falopa(c);
		hsh[c]=ha;
	}
	if(flag)cout<<"Y\n";
	else cout<<"N\n";
}