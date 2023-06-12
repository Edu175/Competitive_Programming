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
		if((n&1)==0){
			cout<<n/2<<" "<<n/2<<"\n";
			continue;
		}
		ll a=n/2,b=n/2+1;
		string c=to_string(a),d=to_string(b);
		//cout<<c<<" "<<d<<"\n";
		reverse(ALL(c)); reverse(ALL(d));
		//cout<<c<<" "<<d<<"\n";
		for(ll i=0;c[i]=='9'&&d[i]=='0'&&i<SZ(c);i+=2)c[i]='5',d[i]='4';
		//cout<<c<<" "<<d<<"\n";
		for(ll i=1;c[i]=='9'&&d[i]=='0'&&i<SZ(c);i+=2)c[i]='4',d[i]='5';
		//cout<<c<<" "<<d<<"\n";
		ll sum0=0,sum1=0;
		reverse(ALL(c)); reverse(ALL(d));
		for(auto i:c)sum0+=i-'0';
		for(auto i:d)sum1+=i-'0';
		cout<<c<<" "<<d<<"\n";
		//cout<<sum0<<" "<<sum1<<"\n";
		//assert(sum0==sum1);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
