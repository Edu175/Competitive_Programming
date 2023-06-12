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
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[n];
		ll maxseg=0;
		ll sum=0;
		ll maxsegi=0;
		fore(i,0,n){
			cin>>a[i];
			sum+=a[i];
			if(i>=k)maxseg=max(maxseg,maxsegi), maxsegi-=a[i-k];
			maxsegi+=a[i];
		}
		maxseg=max(maxseg,maxsegi);
		ll res=0;
		if(k>=n)res=n*k-(n*(n+1))/2+sum;
		else res=maxseg+((k-1)*k)/2;
		cout<<res<<"\n";
	}
	return 0;
}
