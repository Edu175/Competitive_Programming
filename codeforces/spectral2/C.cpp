#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll p=-1,dif=0,val=0;
		fore(i,0,n){
			if(a[i]>0){
				ll cur=dif-2*a[i];
				if(cur>val)p=i,val=cur;
			}
			else dif-=2*a[i];
		}
		vv ops;
		if(p!=-1){
			ll sig=1;
			for(ll i=p-1;i>=0;i--){
				if(a[i]*sig>0){
					sig*=-1;
					ops.pb(i);
				}
			}
			ops.pb(p);
		}
		cout<<SZ(ops)<<"\n";
		for(auto i:ops)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
