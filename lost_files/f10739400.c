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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n], b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		ll c[n/2+1];
		ll j=0;
		fore(i,n/2,n){
			c[j]=a[i]+b[n-1-j];
			j++;
		}
		//imp(c);
		sort(c,c+(n/2+1));
		//imp(c);
		cout<<c[0]<<"\n";
	}
	return 0;
}
