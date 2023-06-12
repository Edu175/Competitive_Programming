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
		//cout<<"\n";
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		if(n==1||n==2){
			imp(a);
			continue;
		}
		if(n%2==0){
			if(a[n/2]==a[n/2-1]){
				cout<<"-1\n";
				continue;
			}
		}
		vector<ll>r1,r2;
		ll l=0,r=n-1;
		if(n%2==0||a[n/2]!=a[n/2+1]){
			while(l<=r){
				r1.pb(a[l]);
				l++;
				if(l<=r)r1.pb(a[r]);
				r--;
			}
			ll flag=1;
			fore(i,1,n){
				if(r1[i]==r1[i-1])flag=0;
			}
			if(flag){
				imp(r1);
				continue;
			}
		}
		l=0,r=n-1;
		if(n%2==0||a[n/2]!=a[n/2-1]){
			while(l<=r){
				r2.pb(a[r]);
				r--;
				if(l<=r)r2.pb(a[l]);
				l++;
			}
			ll flag=1;
			fore(i,1,n){
				if(r2[i]==r2[i-1])flag=0;
			}
			if(flag){
				imp(r2);
				continue;
			}
		}
		cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
