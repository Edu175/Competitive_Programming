#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>s(n),a(n);
	ll c=0,d=0;
	while(q--){
		ll x; cin>>x; x--;
		if(s[x])a[x]+=d,c--;
		else a[x]-=d,c++;
		s[x]^=1;
		d+=c;
	}
	fore(x,0,n){
		if(s[x])a[x]+=d;
	}
	imp(a);
	return 0;
}
