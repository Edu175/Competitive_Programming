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
		string a; cin>>a;
		ll n=SZ(a);
		ll s=-1;
		fore(i,0,n){
			if(a[i]=='?'&&s==-1)s=i;
			if(a[i]!='?'&&s!=-1){
				char x=a[i];
				//if(l==a[i]||l==2)x=a[i];
				fore(j,s,i)a[j]=x;
				s=-1;
			}
		}
		if(s!=-1){
			char x='0';
			if(s)x=a[s-1];
			fore(j,s,n)a[j]=x;
		}
		cout<<a<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
