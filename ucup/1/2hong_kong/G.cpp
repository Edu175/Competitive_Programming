#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld pi=acosl(-1.0L);
int main(){
	JET
	ll _; cin>>_; while(_--){
		ld l1,l2,a,b; cin>>l1>>l2>>a>>b;
		a*=pi/180.L;
		b*=pi/180.L;
		cout<<(2*a*(l1+l2))+(2*b*l2)<<"\n";
	}
	return 0;
}