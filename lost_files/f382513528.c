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
	ll n; cin>>n;
	string s; cin>>s;
	ll res=-1,t=0,a=0;
	for(auto i:s){
		if(i=='T')t++;
		else a++;
		//cout<<a<<" "<<t<<"\n";
		if(res==-1){
			if(a==(n+1)/2)res=0;//,cout<<"a\n";
			if(t==(n+1)/2)res=1;//,cout<<"a\n";
		}
	}
	if(res)cout<<"T\n";
	else cout<<"A\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
