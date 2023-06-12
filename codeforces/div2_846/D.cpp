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

ll ask(ll x){
	cout<<"- "<<x<<endl;
	ll ret; cin>>ret; return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll cnt; cin>>cnt;
		if(cnt==-1)break;
		vector<ll>res(30,0);
		ll i=0;
		fore(_,0,cnt){
			if(i>=30)break;
			ll c=ask(1ll<<i);
			ll p=i+1+c-cnt;
			res[p]=1;
			i=p+1;
			cnt=c;
		}
		ll r=0;
		fore(i,0,SZ(res))r+=res[i]<<i;
		cout<<"! "<<r<<endl;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
