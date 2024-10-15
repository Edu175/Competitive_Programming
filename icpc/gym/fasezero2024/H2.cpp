#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
bool is(ll x){
	if(x<=1)return 0;
	for(ll i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll x=n/2,y=n-x;
		while(x>0){
			if(!is(x)&&!is(y))break;
			x--,y++;
		}
		if(x<=0)cout<<"-1\n";
		else cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
