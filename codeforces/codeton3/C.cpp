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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s,w; cin>>s>>w;
		ll a[n],b[n];
		fore(i,0,n)a[i]=s[i]-'0',b[i]=w[i]-'0';
		ll x=a[0]^b[0];
		ll flag=1;
		vector<ll> p0;
		fore(i,0,n){
			if((a[i]^b[i])!=x)flag=0;
			if(a[i]==0)p0.pb(i);
		}
		//imp(p0);
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		ll k=SZ(p0);
		x^=k%2;
		if(x){
			cout<<k+1<<"\n";
			for(auto i:p0){
				cout<<i+1<<" "<<i+1<<"\n";
			}
			cout<<1<<" "<<n<<"\n";
		}
		else {
			cout<<k+2<<"\n";
			for(auto i:p0){
				cout<<i+1<<" "<<i+1<<"\n";
			}
			cout<<1<<" "<<1<<"\n";
			cout<<2<<" "<<n<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
