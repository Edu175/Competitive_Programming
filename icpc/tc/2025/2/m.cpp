#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld pi=acosl(-1.);
int main(){
	JET
	ll n; ld r; cin>>n>>r;
	ld a=-1-cosl(2*pi/n);
	ld b=2*r*(1-cosl(2*pi/n));
	ld c=b*r/2;
	// cout<<a<<" "<<b<<" "<<c<<"\n";
	cout<<fixed<<setprecision(15)<<(-b-sqrt(b*b-4*a*c))/(2*a)<<"\n";
	return 0;
}