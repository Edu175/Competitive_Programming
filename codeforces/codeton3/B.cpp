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
		ll n; cin>>n;
		string s; cin>>s;
		ll c[2]={0,0};
		ll seg[2]={0,0};
		ll j=1;
		fore(i,0,n){
			c[s[i]=='1']++;
			if(i){
				if(s[i]==s[i-1])j++;
				else seg[s[i-1]=='1']=max(j,seg[s[i-1]=='1']),j=1;
			}
		}
		seg[s[n-1]=='1']=max(j,seg[s[n-1]=='1']);
		/*imp(seg);
		imp(c);*/
		cout<<max({c[0]*c[1],seg[0]*seg[0],seg[1]*seg[1]})<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
