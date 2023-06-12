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
		fore(i,0,n)cin>>a[i];
		map<ll,ll>oc;
		ll rep=0;
		ll mini=10e9+5;
		fore(i,0,n){
			oc[a[i]]++;
			if(oc[a[i]]>2)rep++;
			mini=min(mini,a[i]);
		}
		n-=rep;
		ll res=n/2;
		if(n%2==1)res++;
		cout<<res<<"\n";
	}
	return 0;
}
