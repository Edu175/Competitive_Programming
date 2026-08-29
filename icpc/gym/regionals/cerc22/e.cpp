#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-7;

int main(){
	JET
	ll n; cin>>n;
	vector<ld> a(n);
	fore(i,0,n)cin>>a[i];
	fore(to,1,1e4+1){
		ld r=to/a[0];
		ll bad=0;
		fore(i,0,n){
			ld num=a[i]*r;
			ld diff=abs(num-round(num));
			if(diff/num>EPS){
				bad=1;
				break;
			}
		}
		if(bad)continue;
		fore(i,0,n){
			cout<<round(a[i]*r)<<"\n";
		}
		exit(0);
	}
	assert(0);
	return 0;
}