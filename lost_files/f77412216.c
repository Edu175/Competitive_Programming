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
typedef pair<ll,ll> ii;

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		ll mx=0;
		fore(i,0,n){
			cin>>a[i];
			if(abs(a[i])>abs(a[mx]))mx=i;
		}
		ll rev=(a[mx]<0);
		if(a[mx]==0){
			cout<<"0\n";
			continue;
		}
		if(rev){
			reverse(ALL(a));
			fore(i,0,n)a[i]*=-1;
			mx=n-1-mx;
		}
		vector<ii>p;
		fore(i,0,n){
			if(a[i]<0)p.pb({i,mx}),a[i]+=a[mx];
		}
		fore(i,1,n){
			if(a[i]<a[i-1])p.pb({i,i-1}),a[i]+=a[i-1];
		}
		ll flag=1;
		//check
		/*imp(a);
		fore(i,1,n){
			if(a[i-1]>a[i])flag=0;
		}
		assert(flag);*/
		//
		cout<<SZ(p)<<"\n";
		for(auto i:p){
			ll x=i.fst,y=i.snd;
			if(rev)x=n-1-x,y=n-1-y;
			cout<<x+1<<" "<<y+1<<"\n";
		}
	}
	return 0;
}
