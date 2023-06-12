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
		vector<ll>a(26,0),b(26,0);
		ll qa=1,qb=0;
		fore(i,1,n){
			ll &w=b[s[i]-'a'];
			if(!w)qb++;
			w++;
		}
		a[s[0]-'a']=1;
		ll res=qa+qb;
		fore(i,1,n){
			ll &wa=a[s[i]-'a'],&wb=b[s[i]-'a'];
			if(!wa)qa++;
			if(wb==1)qb--;
			wa++,wb--;
			res=max(res,qa+qb);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
