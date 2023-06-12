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
	ll n,x; cin>>n>>x;
	map<ll,ll>pos;
	ll r1=0,r2;
	fore(i,0,n){
		ll ai; cin>>ai;
		if(pos[x-ai])r1=i+1,r2=pos[x-ai];
		pos[ai]=i+1;
	}
	if(r1)cout<<r1<<" "<<r2;
	else cout<<"IMPOSSIBLE";
	return 0;
}
