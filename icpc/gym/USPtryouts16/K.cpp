#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll).x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ld p=1;
	ll res=0;
	fore(i,0,n+1){
		p*=ld(n-i)/ld(n);
		//cout<<i<<" "<<p<<"\n";
		if(p<0.5){
			res=i+1;
			break;
		}
	}
	cout<<res<<"\n";
	return 0;
}
