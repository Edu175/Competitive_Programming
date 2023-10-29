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
		ll a[n];
		ll flag=1;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]>i)flag=0,cout<<i<<"\n";
			if(a[i]==0)a[i]=i;
			else if(a[i]>0)a[i]--;
		}
		ll j,p=n-1, v=n;
		ll res[n];
		while(p>=0){
			if(a[p]==-1)j=p;
			else j=a[p];
			cout<<p<<" "<<j<<":\n";
			if(a[j]!=-1&&a[j]!=j)flag=0,cout<<p<<" "<<j<<" j\n";
			res[j]=v,v--;
			for(int i=p;i>j;i--){
				if(a[i]!=-1&&a[i]!=j)flag=0,cout<<i<<" "<<j<<"\n";;
				res[i]=v;
				v--;
			}
			p=j-1;
		}
		imp(a);
		imp(res);
		if(flag){
			imp(res);
		}
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
