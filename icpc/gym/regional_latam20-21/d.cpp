#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ET
	ll n; cin>>n;
	if(n==1){
		cout<<"N\n";
		return 0;
	}
	priority_queue<ll>pq;
	fore(i,0,n){
		ll x; cin>>x;
		pq.push(-x);
	}
	vv sin;
	while(SZ(pq)){
		auto x=pq.top(); pq.pop();
		if(SZ(pq)&&pq.top()==x)pq.pop(),pq.push(x-1);
		else sin.pb(x);
	}
	if(SZ(sin)<=2)cout<<"Y\n";
	else cout<<"N\n";
}