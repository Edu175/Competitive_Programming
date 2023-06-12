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

ll ask(ll i, ll j){
	i++,j++;
	cout<<"? "<<i<<" "<<j<<endl;
	ll ret; cin>>ret;
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll x=ask(0,0);
		if(n==1||m==1){
			if(n==1)cout<<"! 1 "<<x+1<<endl;
			else if(m==1)cout<<"! "<<x+1<<" 1"<<endl;
			continue;
		}
		ll q=ask(1,0);
		ll i=0,j=0;
		if(q==x){
			j=x;
			i=ask(i,j);
		}
		else{
			i=x;
			j=ask(i,j);
		}
		cout<<"! "<<i+1<<" "<<j+1<<endl;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
