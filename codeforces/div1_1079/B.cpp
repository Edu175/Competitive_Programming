#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll sq=sqrt(n)+5;
		ll res=0,ig=0;
		fore(v,1,sq){
			fore(i,0,n)if(v<=a[i]){
				ll d=v*a[i];
				fore(way,0,2){
					ll j=i+(way?-d:d);
					if(j<0||j>=n)continue;
					if(a[j]==v){
						res++,ig+=a[i]==a[j];
						// cerr<<"match "<<i<<" "<<j<<"\n";
					}
				}
			}
		}
		// cerr<<res<<" "<<ig<<"\n";
		assert(ig%2==0);
		res-=ig/2;
		cout<<res<<"\n";
	}
	return 0;
}
