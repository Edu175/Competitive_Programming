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
		ll n=8;
		char a[8][8];
		fore(i,0,n){
			fore(j,0,n)cin>>a[i][j];
		}
		char res='n';
		fore(i,0,n){
			if(a[i][0]!='R')continue;
			char d=a[i][0];
			ll flag=1;
			fore(j,0,n)if(a[i][j]!=d)flag=0;
			if(flag)res=d;
		}
		fore(j,0,n){
			if(a[0][j]!='B')continue;
			char d=a[0][j];
			ll flag=1;
			fore(i,0,n)if(a[i][j]!=d)flag=0;
			if(flag)res=d;
		}
		//assert(res!='n');
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
