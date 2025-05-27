#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		ll c=__builtin_popcountll(x);
		ll r=n-c;
		ll res=-1;
		if(r<=0)res=x;
		else if(r%2==0)res=x+r;
		else if(c==0){
			if(n==1)res=-1;
			else res=n+3;
		}
		else if(c>1||x>1)res=x+r+1;
		else res=n+3;
		cout<<res<<"\n";
	}
	return 0;
}
