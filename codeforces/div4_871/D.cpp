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

ll flag=0,m;
//set<ll>st;
void f(ll x){
	/*if(st.count(x))return;
	st.insert(x);*/
	if(x==0)return;
	if(x==m)flag=1;
	if(x%3==0)f(x/3),f(x/3*2);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		flag=0;
		ll n; cin>>n>>m;
		f(n);
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
