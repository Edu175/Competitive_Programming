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
const ll MAXN=1e7+5;

ll divs[MAXN];
void div_cri(){
	fore(i,2,MAXN)for(ll j=i;j<MAXN;j+=i)if(!divs[j])divs[j]=i;
}

int main(){FIN;
	div_cri();
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ll d=abs(a-b);
		if(gcd(a,b)!=1){
			cout<<"0\n";
			continue;
		}
		if(d==1){
			cout<<"-1\n";
			continue;
		}
		ll m=divs[d];
		assert(a%m==b%m);
		ll res=m-(a%m);
		//cout<<m<<": "<<resi<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
