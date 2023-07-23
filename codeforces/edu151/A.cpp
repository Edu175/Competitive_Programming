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
		ll n,k,x; cin>>n>>k>>x;
		if(x!=1){
			cout<<"YES\n";
			cout<<n<<"\n";
			fore(i,0,n)cout<<"1 ";
			cout<<"\n";
			continue;
		}
		if(k==x){
			cout<<"NO\n";
			continue;
		}
		if(n%2==0){
			cout<<"YES\n";
			cout<<n/2<<"\n";
			fore(i,0,n/2)cout<<"2 ";
			cout<<"\n";
			continue;
		}
		if(k==2){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		cout<<n/2<<"\n3 ";
		fore(i,0,n/2-1)cout<<"2 ";
		cout<<"\n";
	}
	return 0;
}
