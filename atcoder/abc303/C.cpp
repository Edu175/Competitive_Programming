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
	ll n,m,h,k; cin>>n>>m>>h>>k;
	string s; cin>>s;
	set<pair<ll,ll>>st;
	fore(i,0,m){
		ll a,b; cin>>a>>b;
		st.insert({a,b});
	}
	pair<ll,ll>p={0,0};
	ll flag=1;
	fore(i,0,n){
		if(s[i]=='U')p.snd++;
		if(s[i]=='D')p.snd--;
		if(s[i]=='L')p.fst--;
		if(s[i]=='R')p.fst++;
		h--;
		if(h<0){
			flag=0;
			break;
		}
		if(st.count(p)&&h<k)h=k,st.erase(p);
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
