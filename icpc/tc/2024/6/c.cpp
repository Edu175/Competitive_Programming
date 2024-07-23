#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,m; cin>>n>>m;
	ll a[n+1];
	ll ip[n+1];
	ll pi[n+1];
	fore(i,0,n){
		cin>>a[i];
	}
	a[n]=m;
	ip[n]=0;
	pi[n]=0;
	for(ll i=n-1;i>=0;i--){
		if(i%2==1){
			ip[i]=ip[i+1];
			pi[i]=pi[i+1]+(a[i+1]-a[i]);
		}
		else{
			pi[i]=pi[i+1];
			ip[i]=ip[i+1]+(a[i+1]-a[i]);
		}
	}
	ll rta=0;
	ll acc=0;
	fore(i,0,n+1){
		ll ant;
		if(i==0) ant=0;
		else ant=a[i-1];
		if(i%2==0){
			if(ant==a[i]-1){
				acc+=a[i]-ant;
			}
			else{
				ll loc=acc+ip[i]+((a[i]-1)-ant);
				acc+=a[i]-ant;
				rta=max(rta,loc);
			}
		}
		else{
			if(ant==a[i]-1) continue;
			else{
				ll loc=acc+((a[i]-(ant+1)))+ip[i];
				rta=max(loc,rta);
			}
		}
	}
	ll nada=0;
	fore(i,0,n+1){
		ll ant;
		if(i==0) ant=0;
		else ant=a[i-1];
		if(i%2==0){
			nada+=(a[i]-ant);
		}
	}
	cout<<max(nada,rta)<<"\n";
	return 0;
}