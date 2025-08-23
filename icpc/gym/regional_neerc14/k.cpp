#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll mod(ll a, ll m){
	return ((a%m+m)%m);
}
int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("knockout.in","r",stdin);     freopen("knockout.out","w",stdout);
	#endif

	JET
	ll n,m; cin>>n>>m;
	ll a[n],b[n];
	fore(i,0,n) cin>>a[i]>>b[i];
	while(m--){
		ll l,r,t; cin>>l>>r>>t;
		ll c=0;
		fore(i,0,n){
			ll p=min(a[i],b[i])+((t/abs(b[i]-a[i]))&1?abs(b[i]-a[i])-t%abs(b[i]-a[i]):t%abs(b[i]-a[i]));
			if(l<=p&&p<=r) c++;
		}
		cout<<c<<"\n";
	}
	return 0;
	
}