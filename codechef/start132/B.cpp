#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll fn(ll n){return n*(n+1)/2;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b;
		ll p=-1;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]%2==0){
				b.pb(i-p-1);
				p=i;
			}
		}
		b.pb(n-1-p);
		sort(ALL(b));
		reverse(ALL(b));
		if(!SZ(b)||b[0]==0){
			cout<<fn(n)<<"\n";
			continue;
		}
		//imp(b);
		ll x=b[0]-1;
		b.pb(x/2);
		b.pb((x+1)/2);
		ll res=0;
		//imp(b);
		fore(i,1,SZ(b))res+=fn(b[i]);
		res=fn(n)-res;
		cout<<res<<"\n";
	}
	return 0;
}
