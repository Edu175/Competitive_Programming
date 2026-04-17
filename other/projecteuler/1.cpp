#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll fn(ll n){return n*(n+1)/2;}

int main(){FIN;
	ll res=0,n=999;
	vector<ll>d={3,5,15};
	for(auto i:d){
		ll nd=n/i;	
		res+=(i==15?-1:1)*fn(nd)*i;
	}
	cout<<res<<"\n";
	return 0;
}
