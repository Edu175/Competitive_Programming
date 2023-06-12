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
		ll n,m; cin>>n>>m;
		ll g[n+1];
		for(ll i=n;i>=1;i--){
			g[i]=(n/i)*(n/i-1)/2;
			for(ll j=2;j*i<=n;j++)g[i]-=g[j*i];
		}
		fore(i,0,n)g[i]=g[i+1];
		ll sum=0,op=0;
		ll c[n];
		fore(i,1,n)c[i]=g[i]/i;
		for(ll i=n-1;i>=1;i--){
			ll add=c[i]*i;
			ll opi=c[i];
			if(sum+add>m)opi=(m-sum)/i,add=opi*i;
			sum+=add;
			op+=opi;
			//cout<<i<<": "<<opi<<" "<<add<<": "<<sum<<"\n";
		}
		if(sum==m)cout<<m+op<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
