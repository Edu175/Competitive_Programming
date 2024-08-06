#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),pos(n);
		fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]]=i;
		vector<ll>res,bad(n);
		ll mx=-1;
		fore(i,0,n){
			mx=max(mx,a[i]);
			if(a[i]==mx)bad[i]=1;
		}
		auto solve=[&](ll r, ll mn, auto &&solve){
			if(r==0)return;
			while(pos[mn]>=r)mn++;
			ll l=pos[mn],p=l;
			fore(i,l,r){
				if(!bad[i])p=i;
				else break;
			}
			fore(i,p,r)res.pb(i);
			for(ll i=p-1;i>=l;i--)res.pb(i);
			solve(l,mn,solve);
		};
		solve(n,0,solve);
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
