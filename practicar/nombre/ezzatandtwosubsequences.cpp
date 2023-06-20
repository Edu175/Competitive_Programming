#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef double ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		long long n; cin>>n; 
		ll a[n];
		ll maxi=-1000000005;
		ll sum=0;
		fore(i,0,n){
			cin>>a[i];
			maxi=max(maxi,a[i]);
			sum+=a[i];
		}
		ll res= maxi + (sum-maxi) / (n-1);
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	 return 0;
}
