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
const ll MAXN=2e5+5;
ll a[MAXN],sp[MAXN];


ll ask(ll l, ll r){
	cout<<"? "<<r-l<<" ";
	fore(i,l,r)cout<<i+1<<" ";
	cout<<endl;
	ll x; cin>>x;
	return x;
}
bool can(ll l, ll r){
	return (ask(l,r)!=sp[r]-sp[l]);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		sp[0]=0;
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll l=0,r=n;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m,r))l=m;
			else r=m;
		}
		cout<<"! "<<l+1<<endl;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
