#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n];
	vector<ll>b;
	fore(i,0,n)cin>>a[i];
	fore(i,0,m){
		ll x; cin>>x;
		if(!SZ(b)||b.back()>x)b.pb(x);
	}
	m=SZ(b);
	fore(i,0,n){
		//cout<<i<<"\n";
		while(a[i]>=b.back()){
			//cout<<"  "<<a[i]<<endl;
			ll l=0,r=m-1;
			while(l<=r){
				ll mid=(l+r)/2;
				if(b[mid]>a[i])l=mid+1;
				else r=mid-1;
			}
			a[i]%=b[l];
			//cout<<"  "<<l<<endl<<endl;
		}
	}
	imp(a);
	return 0;
}
