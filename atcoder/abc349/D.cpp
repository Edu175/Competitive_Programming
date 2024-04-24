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
const ll K=62;
int main(){FIN;
	ll l,r; cin>>l>>r;
	ll x=l;
	vector<ll>res;
	while(x!=r){
		for(ll i=(x?__builtin_ctzll(x):K);i>=0;i--){
			if(x+(1ll<<i)<=r){
				x+=1ll<<i;
				break;
			}
		}
		res.pb(x);
	}
	res.pop_back();
	cout<<SZ(res)+1<<"\n";
	cout<<l<<" ";
	for(auto i:res){
		cout<<i<<"\n"<<i<<" ";
	}
	cout<<r<<"\n";
	return 0;
}
