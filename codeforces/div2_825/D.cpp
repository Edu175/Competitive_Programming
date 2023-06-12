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
		string s;cin>>s;
		ll v[2*n]; fore(i,0,2*n)v[i]=s[i];
		ll c[2];
		fore(i,0,2*n)c[v[i]]++;
		if(c[0]&1){
			cout<<"-1\n";
			continue;
		}
		vector<ll>a,b;
		ll l=0;
		vector<ll>res;
		fore(i,0,2*n){
			if(l!=SZ(a)&&v[i]==v[a[l]])b.pb(i),l++;
			else a.pb(i);
		}
		imp(a);
		imp(b);
		if(SZ(a)==SZ(b)){
			imp(a);
			continue;
		}
		swap(v[b.back()],v[a[SZ(a)-2]]);
		cout<<2<<" "<<b.back()<<" "<<a[SZ(a)-2]<<"\n";
		a.clear();
		b.clear();
		fore(i,0,2*n){
			if(l!=SZ(a)&&v[i]==v[a[l]])b.pb(i),l++;
			else a.pb(i);
		}
		imp(a);
		imp(b);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
