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
		ll l,r,x,a,b; cin>>l>>r>>x>>a>>b;
		if(a==b){
			cout<<"0\n";
			continue;
		}
		if(abs(a-b)>=x){
			cout<<"1\n";
			continue;
		}
		vector<ll> n={0,0},m={0,0};
		if(a-x>=l)n[0]++;
		if(a+x<=r)n[1]++;
		if(b-x>=l)m[0]++;
		if(b+x<=r)m[1]++;
		vector<ll>z={0,0};
		if(n==z||m==z){
			cout<<"-1\n";
			continue;
		}
		if((n[0]==1&&m[0]==1)||(n[1]==1&&m[1]==1)){
			cout<<"2\n";
			continue;
		}
		cout<<"3\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
