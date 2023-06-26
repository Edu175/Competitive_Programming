#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[3][n];
		ll x=0;
		fore(i,0,3){
			fore(j,0,n)cin>>a[i][j];
		}
		fore(i,0,3){
			fore(j,0,n){
				ll fl=1;
				fore(b,0,35){
					if((a[i][j]&(1ll<<b))&&
						(k&(1ll<<b))==0)fl=0;
				}
				if(!fl)break;
				x|=a[i][j];
			}
		}
		if(x==k)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
