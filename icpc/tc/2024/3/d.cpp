#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,k; cin>>n>>k;
	queue<ll>ps,us;
	fore(i,0,33)if(n>>i&1)ps.push(1ll<<i);
	if(SZ(ps)>k||n<k){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	while(SZ(ps)+SZ(us)<k){
		auto x=ps.front(); ps.pop();
		if(x==1)us.push(x);
		else {
			ps.push(x/2);
			ps.push(x/2);
		}
	}
	while(SZ(ps))cout<<ps.front()<<" ",ps.pop();
	while(SZ(us))cout<<us.front()<<" ",us.pop();
	cout<<"\n";
	return 0;
}