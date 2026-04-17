#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv get(vv a){ // without i
	ll n=SZ(a);
	vv res(n);
	fore(i,0,n){
		ll u=i;
		auto &cur=res[i];
		fore(j,i+1,n){
			if(a[j]>a[u])cur+=(j-u)*a[u],u=j;
		}
		cur-=a[i];
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,h; cin>>n>>h;
		vv a(n+2,h);
		fore(i,1,n+1)cin>>a[i],a[i]--;
		ll tot=(h-1)*n;
		n+=2;
		vv ri=get(a);
		reverse(ALL(a));
		vv le=get(a);
		reverse(ALL(le));
		reverse(ALL(a));
		ll ans=tot;
		fore(i,1,n){
			ll cur=le[i]+a[i];
			vv p={i};
			fore(j,i,n-1){
				while(SZ(p)>1&&a[j]>=a[p.back()]){
					ll u=p.back(); p.pop_back();
					ll au=p.back();
					cur-=(u-au)*a[u];
				}
				if(SZ(p)==1&&a[j]>=a[p[0]]){
					ll mx=p[0];
					cur-=a[mx];
					p.pop_back();
					cur+=(j-mx)*a[mx];
					cur+=a[j];
					p.pb(j);
				}
				else {
					cur+=(j-p.back())*a[j];
					p.pb(j);
				}
				ll cand=cur+ri[j];
				ans=min(ans,cand);
			}
		}
		ll res=tot-ans;
		cout<<res<<"\n";
	}
	return 0;
}
