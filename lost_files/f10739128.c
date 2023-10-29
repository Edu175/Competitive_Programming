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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<ll>oc(30);
		string w;
		for(auto i:s){
			if(!oc[i-'a'])w.pb(i);
			oc[i-'a']++;
		}
		sort(ALL(w));
		string res;
		ll flag=1;
		ll x=SZ(w)-1;
		ll a=w[0]-'a';
		vector<ll> c(30,0);
		//cout<<w<<"\n";
		ll _=n;
		while(_--){
			if(SZ(res)>=n)break;
			if(c[x]>=oc[x])x--;
			if(c[w[x]-'a']-c[a]<k)res.pb(w[x]),c[w[x]-'a']++;//,cout<<x<<"\n";
			else {
				for(ll j=x-1;j>=0;j--){
					if(c[w[j]-'a']>=oc[w[j]-'a']){
						flag=0;
						_=0;
						break;
					}
					res.pb(w[j]);
					c[w[j]-'a']++;
					//cout<<j<<" ";
				}
				//cout<<"\n";
			}
		}
		reverse(ALL(res));
		if(flag)cout<<res<<"\n";
		else cout<<"-1\n";
		//cout<<res<<" "<<x<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
