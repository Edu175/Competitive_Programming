#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n";
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==1){
			cout<<"1\n";
			continue;
		}
		if(n&1){
			cout<<"-1\n";
			continue;
		}
		vector<ll>res(n);
		res[0]=n;
		fore(i,1,n){
			if(i&1)res[i]=n-i;
			else res[i]=i;
		}
		imp(res);
	}
	return 0;
}
