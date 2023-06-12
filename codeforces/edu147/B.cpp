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
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		if(a==b){
			ll l=0,s=0,e=0;
			fore(i,1,n){
				if(a[i]!=a[i-1]){
					if(i-l>=s-e+1)s=l,e=i-1;
					l=i;
				}
			}
			if(n-l>=s-e+1)s=l,e=n-1;
			cout<<s+1<<" "<<e+1<<"\n";
			continue;
		}
		ll l=-1,r=-1;
		fore(i,0,n){
			if(l==-1&&a[i]!=b[i])l=i;
			if(a[i]!=b[i])r=i;
		}
		while(l>0&&b[l-1]<=b[l])l--;
		while(r<n-1&&b[r+1]>=b[r])r++;
		cout<<l+1<<" "<<r+1<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
