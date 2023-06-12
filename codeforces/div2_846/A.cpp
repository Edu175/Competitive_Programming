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
		ll a[n];
		vector<ll>c[2];
		fore(i,0,n)cin>>a[i],c[(a[i]&1)].pb(i);
		ll flag=1;
		vector<ll>res;
		if(SZ(c[1])>=3)fore(i,0,3)res.pb(c[1][i]);
		else if(SZ(c[1])==0)flag=0;
		else if(SZ(c[0])<2)flag=0;
		else {
			fore(i,0,2)res.pb(c[0][i]);
			res.pb(c[1][0]);
		}
		if(flag){
			cout<<"YES\n";
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
