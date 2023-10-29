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
	string a,b; cin>>a>>b;
	ll ca[30]={},cb[30]={};
	ll ar=0,br=0;
	for(auto i:a){
		if(i=='@')ar++;
		else ca[i-'a']++;
	}
	for(auto i:b){
		if(i=='@')br++;
		else cb[i-'a']++;
	}
	set<char>st={'a','t','c','o','d','e','r'};
	ll flag=1;
	fore(i,0,30){
		if(ca[i]<cb[i]){
			if(!st.count('a'+i))flag=0;
			ar-=cb[i]-ca[i];
		}
		if(cb[i]<ca[i]){
			if(!st.count('a'+i))flag=0;
			br-=ca[i]-cb[i];
		}
	}
	if(ar<0||br<0)flag=0;
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
