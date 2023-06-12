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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[k];
		vector<ll>sp;
		fore(i,0,k){
			cin>>a[i];
		}
		fore(i,1,k)sp.pb(a[i]-a[i-1]);
		ll flag=1;
		fore(i,1,k-1){
			if(sp[i]<sp[i-1])flag=0;
		}
		if(k>1&&a[0]>sp[0]*(n-k+1))flag=0;
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
		
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
