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
		ll n; cin>>n;
		ll a[n];
		ll o[100];
		mset(o,0);
		ll x=1;
		fore(i,0,n){
			cin>>a[i];
			o[a[i]]++;
			if(o[a[i]]>=2)x=0;
		}
		if(o[0])cout<<n-o[0]<<"\n";
		else cout<<n+x<<"\n";
	}
	return 0;
}
