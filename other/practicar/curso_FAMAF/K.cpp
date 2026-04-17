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

vector<ll> divs(ll x){
	vector<ll>r;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			r.pb(x/i),r.pb(i);
			if(i*i==x)r.pop_back();
		}
	}
	sort(ALL(r));
	return r;
}

int main(){FIN;
	ll a,b; cin>>a>>b;
	if(a>b)swap(a,b);
	vector<ll> d=divs(b-a);
	ll k=0,mn=a*b;
	for(auto i:d){
		assert(a%i==b%i);
		ll ki=(i-a%i)%i,mni=lcm(a+ki,b+ki);
		//cout<<i<<": "<<ki<<" "<<mni<<"\n";
		if(mni<mn)mn=mni,k=ki;
	}
	cout<<k<<"\n";
	return 0;
}
