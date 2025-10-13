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
const ll ITER=65;
int main(){FIN;
	ll n; cin>>n;
	vector<array<ll,4>>h(n);
	fore(i,0,n){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		h[i]={b,a,d,c};
	}
	
	auto can=[&](ld m){
		ld sum=0;
		fore(i,0,n){
			ld t0=h[i][0]-m*h[i][1];
			ld t1=h[i][2]-m*h[i][3];
			sum+=max(t0,t1);
		}
		return sum>=0;
	};
	
	ld l=1e-10,r=1e15;
	fore(_,0,ITER){
		ld m=(2*l<r?sqrt(l*r):(l+r)/2); // santo truco
		if(can(m))l=m;
		else r=m;
	}
	
	cout<<fixed<<setprecision(15)<<l<<"\n";
	
	return 0;
}
