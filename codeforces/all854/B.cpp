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

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],un=0,ig=1;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==1)un=1;
			if(i&&a[i]!=a[i-1])ig=0;
		}
		if(un){
			if(ig)cout<<"0\n";
			else cout<<"-1\n";
			continue;
		}
		vector<pair<ll,ll>>res;
		ll br=1;
		while(br){
			ll x=0,flag=1;
			fore(i,0,n)if(a[i]<a[x])x=i;
			//cout<<x<<": "; imp(a);
			fore(i,0,n){
				if(a[i]!=a[x]){
					flag=0;
					a[i]=(a[i]+a[x]-1)/a[x];
					res.pb({i,x});
				}
			}
			if(flag)break;
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res){
			cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
