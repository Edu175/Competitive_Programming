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
		ll n,k; cin>>n>>k;
		string a,b; cin>>a>>b;
		set<char>st;
		for(auto i:a)st.insert(i);
		string c; // SZ<=10
		for(auto i:st)c.pb(i);
		ll res=0;
		fore(bt,0,1ll<<SZ(c)){
			if(__builtin_popcount(bt)>k)continue;
			vector<ll>u(26,0);
			fore(i,0,SZ(c))if(bt&(1ll<<i))u[c[i]-'a']=1;
			ll m=0,resi=0;
			//cout<<bt<<": ";
			fore(i,0,n){
				if(u[a[i]-'a']||a[i]==b[i])m++;
				else /*cout<<m<<" ",*/resi+=m*(m-1)/2+m,m=0;
			}
			resi+=m*(m-1)/2+m;
			//cout<<"= "<<resi<<"\n";
			//imp(u);
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
