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
		ll n,c; cin>>n>>c;
		ll a[n];
		fore(i,0,n){
			cin>>a[i];
		}
		ll s=1;
		fore(i,1,n){
			if(a[0]+a[i]>=1*(i+1)*c){
				fore(j,s,i+1)a[0]+=a[j];
				s=i+1;
			}
		}
		if(s==n)cout<<"Yes\n";
		else cout<<"No\n";
		//cout<<endl;
	}
	return 0;
}
