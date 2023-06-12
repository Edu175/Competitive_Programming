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
		if(SZ(a)<SZ(b))swap(a,b);
		string w="$$";
		fore(d,-SZ(a)-3,SZ(b)+3){
			fore(i,0,SZ(a)-1){
				if(i+d<0||i+d+1>=SZ(b))continue;
				if(a[i]==b[i+d]&&a[i+1]==b[i+d+1]){
					w=a[i],w+=a[i+1];//,cout<<w<<" w\n";
				}
			}
		}
		if(w!="$$")cout<<"YES\n*"<<w<<"*\n";
		else if(a[0]==b[0])cout<<"YES\n"<<a[0]<<"*\n";
		else if(a.back()==b.back())cout<<"YES\n*"<<a.back()<<"\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
