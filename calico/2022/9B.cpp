#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),d(n),l(n),r(n);
		fore(i,0,n)r[i]=(i+1)%n,l[i]=(i-1+n)%n;
		vector<ll> is(n,1);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>d[i];
		fore(h,0,2){
			for(ll i=n-1;i>=0;i--){
				if(!is[i])continue;
				if(a[i]+d[i]<=a[r[i]]){
					is[i]=0;
					r[l[i]]=r[i];
					l[r[i]]=l[i];
					d[l[i]]+=d[i];
				}
			}
		}
		ll sum=0;
		fore(i,0,n)if(is[i])sum+=d[i];
		ll res=1e12;
		fore(i,0,n)if(is[i]){
			res=min(res,a[i]+sum-d[l[i]]);
		}
		cout<<res<<"\n";
	}
	return 0;
}
