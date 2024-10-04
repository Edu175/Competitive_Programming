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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-8;

int main(){FIN;
	ll t; cin>>t;
	fore(caso,0,t){
		cout<<"Case #"<<caso+1<<": ";
		ll n,p; cin>>n>>p;
		ld lhs=log(100)*(n-1),rhs=log(p)*(n-1)+log(100)*n;
		ld l=0,r=110;
		while(r-l>=EPS){
			ld m=(l+r)/2;
			if(log(p+m)*n+lhs>=rhs)r=m;
			else l=m;
		}
		cout<<fixed<<setprecision(15)<<l<<"\n";
	}
	return 0;
}
