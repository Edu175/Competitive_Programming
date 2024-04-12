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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; k--;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll p=n;
		fore(i,0,n)if(a[i]>a[k]){p=i;break;}
		if(p==n){
			cout<<n-1<<"\n";
			continue;
		}
		ll res=p-1;
		ll v=a[k];
		swap(a[k],a[p]);
		swap(p,k);
		fore(i,0,n){
			//if(a[i]==v)k=i;
			if(a[i]>v){p=i;break;}
		}
		ll resi=p-k-1+(k>0);
		res=max(res,resi);
		cout<<res<<"\n";
	}
	return 0;
}
