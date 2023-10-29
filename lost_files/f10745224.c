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
const ll MOD=1e9+7,MAXN=2e6+5;

int main(){FIN;
	ll pot2[MAXN];
	pot2[0]=1;
	fore(i,1,MAXN)pot2[i]=(2*pot2[i-1])%MOD;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string a; cin>>a;
		ll ch[2]={-1,3*n};
		ll c=0;
		fore(i,1,n){
			if(c>1)break;
			if(a[i]!=a[i-1])ch[c]=i,c++;
		}
		if(ch[0]==-1){
			cout<<"0\n";
			continue;
		}
		ll l=max(ll(0),ch[0]-(ch[1]-ch[0]));
		ll res=0;
		fore(i,0,n-ch[0]){
			if(a[ch[0]+i]^a[l+i]){
				res=(res+pot2[(n-ch[0])-i-1])%MOD;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
