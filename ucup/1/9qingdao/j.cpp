#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a;
		ll c = 0;
		fore(i,0,n){
			ll x; cin>>x;
			if(x==0) c++;
			else a.pb(x);
		}
		if(n==m){
			cout<<"Richman\n";
			continue;
		}
		if(c>m){
			cout<<"Impossible\n";
			continue;
		}
		m-=c;
		ll sum = 0;
		fore(i,0,m){
			sum+=a[i];
		}
		ll mini = 1e18;
		fore(i,m,SZ(a)){
			mini = min(mini,a[i]);
		}
		cout<<sum+mini-1<<"\n";
		
	}
}