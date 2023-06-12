#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		char a[4];
		map<char,ll>oc;
		ll maxi=0;
		fore(i,0,4){
			cin>>a[i];
			oc[a[i]]++;
			maxi=max(maxi,oc[a[i]]);
		}
		ll flag=1;
		for(auto i:oc){
			if(i.snd!=2)flag=0;
		}
		ll res=0;
		if(flag)res=1;
		else res=4-maxi;
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
