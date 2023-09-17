#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MOD=1000000009;

vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>>v;
	if(x==1)v.pb({1,0}); 
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v.pb({i,count});
	}
	if(x>1)v.pb({x,1});
	return v;
}

int main(){FIN;
	ll x; cin>>x;
	for(auto i:fact(x)){
		cout<<i.fst<<"**"<<i.snd<<" * ";
	}
	cout<<"\n";
	return 0;
}
