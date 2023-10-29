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
	//cout<<"ttttttttttttt "<<t<<"\n";
	while(t--){
		ll n,k; cin>>n>>k;
		string s(n,'$');
		ll e=0,d=3,flag=1;
		ll p[k],c[k];
		fore(i,0,k)cin>>p[i];
		fore(i,0,k)cin>>c[i];
		fore(i,0,k){
			c[i]-=d;
			d+=c[i];
			//cout<<i<<": "<<e<<" -> "<<p[i]<<" "<<d<<" -> "<<c[i]<<"\n";
			if(c[i]+(i==0)*3>p[i]-e)flag=0;
			if(flag)fore(j,0,c[i])s[e+j]='a'+i;
			e=p[i];
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		string xyz="xyz";
		ll j=0;
		fore(i,0,n)if(s[i]=='$'){
			s[i]=xyz[(j++)%3];
		}
		cout<<s<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
