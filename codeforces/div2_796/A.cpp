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
		vector<ll> v;
		fore(i,0,31)if((1ll<<i)&n)v.pb(i);
		ll res=(1ll<<v[0]);
		if(SZ(v)==1){
			if(res==1)res+=2;
			else res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
