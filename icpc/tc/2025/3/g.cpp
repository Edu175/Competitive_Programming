#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,m; cin>>n>>m;
	swap(n,m);
	ll a[n];
	fore(i,0,n)  cin>>a[i];
	vv rta;
	ll tot = 0;
	fore(i,0,n) tot+=a[i];
	ll mc =0 ;
	if(tot<m){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n){
		mc = max(mc,a[i]+i);
		ll vacio = m-mc;
		tot-=a[i];
		if(tot<vacio){
			ll mc_nes = m-tot;
			ll pos = mc_nes - a[i]+1;
			if(pos<= i ){
				cout<<"-1\n";
				return 0;
			}
			mc_nes = pos+a[i]-1;
			rta.pb(pos);
			// cout<<"puse el "<< i <<" llegue a "<<mc_nes<<"\n";
			fore(j,i+1,n){
				pos = mc_nes+1;
				rta.pb(pos);
				mc_nes = pos+a[j]-1;
				// cout<<"puse el "<<j<<" llegue a "<<mc_nes<<"\n";
			}
			// cout<<mc_nes<<" "<<aendl;
			assert(mc_nes == m);
			break;
		}
		rta.pb(i+1);
	}
	if(mc > m){
		cout<<"-1\n";
		return 0;
	}
	
	for(auto x:rta) cout<<x<<" ";
	cout<<"\n";
	return 0;
}