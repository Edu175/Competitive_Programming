#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,q;
	cin>>n>>q;
	ll best[3*n+1];
	ll a[n+1];
	fore(i,1,n+1) cin>>a[i];
	best[0]=0;
	fore(i,1,3*n+1){
		best[i]=1e16;
		// cout<<" i "<<i;
		if(i<n+1) best[i]=a[i];
		fore(j,1,i){
			best[i]=min(best[i],best[j]+best[i-j]);
		}
		// cout<<" best de i "<<best[i]<<"\n";
	}
	ll pete[250];
	fore(i,0,250) pete[i]=1e16;
	fore(i,1,n+1){
		fore(j,1,n+1){
			pete[i+j]=min(pete[i+j],a[i]+a[j]);
		}
	}
	fore(i,0,q){
		ll k;
		cin>>k;
		ll rta=1e16;
		if(k<=n) cout<<a[k]<<"\n";
		else{
			fore(j,n+1,2*n+1){
				ll aux=0;
				if(j>k) continue;
				aux=pete[j];
				ll val=k;
				val-=j;
				// cout<<"en linea i "<<i<<" con k "<<k<<" me queda por calcular val "<<val<<"\n";
				// cout<<"3n es "<<3*n<<" y su best "<<best[3*n]<<"\n";
				aux+=(best[3*n]*(val/(3*n)));
				aux+=best[val%(3*n)];
				rta=min(rta,aux);
			}	
			assert(rta<1e15+1e14);
			cout<<rta<<"\n";
		}
		
		
	}
	
}