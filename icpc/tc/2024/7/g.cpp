#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld EPS=1e-7;
ld sq(ld x){return x*x;}

int main(){
	JET
	ll n,R; cin>>n>>R;
	vector<ll>xs(n);
	fore(i,0,n)cin>>xs[i];
	// for(auto i:xs)cout<<i<<" ";;cout<<"\n";
	vector<ld> ys(n);
	auto can=[&](ll i, ld y)->bool{
		// cout<<"can "<<i<<" "<<y<<"\n";
		fore(j,0,i){
			if(sq(xs[j]-xs[i])+sq(ys[j]-y)<=4*R*R)return 0;
			if(abs(xs[i]-xs[j])<=2*R&&y<ys[j])return 0;
		}
		// cout<<"yes\n";
		return 1;
	};
	fore(i,0,n){
		ld l=R,r=1e7;
		while(r-l>EPS){
			ld m=(l+r)/2;
			if(can(i,m))r=m;
			else l=m;
		}
		ys[i]=l;
	}
	cout<<fixed<<setprecision(15);
	for(auto i:ys)cout<<i<<" ";
	cout<<"\n";
	return 0;
}