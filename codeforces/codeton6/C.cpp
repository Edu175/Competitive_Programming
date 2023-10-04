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
		ll n,k; cin>>n>>k;
		ll a[n];
		vector<ll>is(k);
		fore(i,0,n)cin>>a[i],a[i]--,is[a[i]]=1;
		vector<ll>pre(n+1),suf(n+1);
		fore(i,1,n+1)pre[i]=max(pre[i-1],a[i-1]);
		for(ll i=n-1;i>=0;i--)suf[i]=max(suf[i+1],a[i]);
		//imp(pre); imp(suf);
		fore(i,0,k){
			if(!is[i]){
				cout<<"0 ";
				continue;
			}
			ll l=0,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(pre[m+1]>=i)r=m-1;
				else l=m+1;
			}
			ll p=l;
			l=0,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(suf[m]>=i)l=m+1;
				else r=m-1;
			}
			//cout<<"\n"<<i<<": "<<p<<" "<<r<<"\n";
			cout<<2*(r-p+1)<<" ";
		}
		cout<<"\n";//\n\n\n";
	}
	return 0;
}
