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
const ll MAXN=3e5+5;

ll a[MAXN],sp[MAXN],on[MAXN];

ll query(ll l, ll r, ll sum){
	//cout<<"query "<<l<<","<<r<<" "<<sum<<": "<<on[r]-on[l+1]<<" "<<sp[r]-sp[l]<<"\n";
	if(on[r]-on[l+1]==0)return 0;
	return (sp[r]-sp[l]>sum);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1],on[i]=on[i-1]+(!(i-1)||a[i-2]!=a[i-1]);
		vector<ll>res(n,n+5);
		fore(i,0,n){
			//cout<<"doing "<<i<<"\n";
			if(i&&a[i-1]>a[i]){res[i]=1;continue;}
			if(i<n-1&&a[i+1]>a[i]){res[i]=1;continue;}
			if(i){
				ll l=0,r=i-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(query(m,i,a[i]))l=m+1;
					else r=m-1;
				}
				if(r>=0)res[i]=i-r;
			}
			if(i<n-1){
				ll l=i+1,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(query(i+1,m+1,a[i]))r=m-1;
					else l=m+1;
				}
				if(l<n)res[i]=min(res[i],l-i);
			}
			if(res[i]==n+5)res[i]=-1;
		}
		imp(res);
	}
	return 0;
}
