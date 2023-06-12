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
	ll _; cin>>_;
	while(_--){
		ll n; cin>>n;
		string s,t; cin>>s>>t;
		map<string,ll>mp;
		fore(i,0,n){
			string e; e+=s[i]; e+=t[n-1-i];
			sort(ALL(e));
			mp[e]++;
		}
		bool imp=0,flag=1;
		for(auto i:mp){
			if(i.snd&1){
				if(i.fst[0]==i.fst[1]){
					if(imp)flag=0;
					else imp=1;
				}
				else flag=0;
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
