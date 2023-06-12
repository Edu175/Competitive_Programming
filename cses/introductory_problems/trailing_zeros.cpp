#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,v,n) for(ll i=v, edu=n; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll pot5[18];
	pot5[0]=1;
	fore(i,1,18)pot5[i]=pot5[i-1]*5;
	ll res=0;
	for(ll i=1; pot5[i]<=n; i++){
		res+=n/pot5[i];
	}
	cout<<res;
	return 0;
}
