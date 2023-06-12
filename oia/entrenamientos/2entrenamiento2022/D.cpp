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
		string a,b; cin>>a>>b;
		char da=a[SZ(a)-1],db=b[SZ(b)-1];
		ll res=0;
		if(da!=db){
			if(da=='S')res=2;
			if(da=='L')res=1;
			if(db=='L')res=2;
			if(db=='S')res=1;
		}
		else {
			if(SZ(a)>SZ(b))res=1;
			if(SZ(a)<SZ(b))res=2;
			if(da=='S'){
				if(res==1)res=2;
				else if(res==2)res=1;
			}
		}
		if(res==0)cout<<"=\n";
		else if(res==1)cout<<">\n";
		else cout<<"<\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
