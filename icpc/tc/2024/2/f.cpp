#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t;
	cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n){
			cin>>a[i];
		}
		sort(a,a+n);
		ll rta=0;
		int i=0;
		while(i<n && a[i]<0){
			rta+=(-2*a[i]);
			i+=k;
		}
		i=n-1;
		while(i>=0 && a[i]>0){
			rta+=(2*a[i]);
			i-=k;
		}
		rta-=max(a[n-1],-a[0]);
		cout<<rta<<"\n";
	}	
}