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

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		ll a[n];
		fore(i,0,n)a[i]=s[i]-'0';
		ll oc[10];
		mset(oc,0);
		vector<ll>v;
		fore(i,0,n){
			oc[a[i]]++;
			v.resize(upper_bound(ALL(v),a[i])-v.begin());
			v.pb(a[i]);
		}
		string res;
		for(auto i:v){
			res.pb('0'+i);
			oc[i]--;
		}
		fore(i,0,10){
			while((oc[i]--))res.pb('0'+min(i+1,9));
		}
		sort(ALL(res));
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
