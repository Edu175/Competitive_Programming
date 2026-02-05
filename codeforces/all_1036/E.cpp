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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll sum=0,mx=0;
		fore(i,0,n)cin>>a[i],sum+=a[i],mx=max(mx,a[i]);
		if(mx>sum-mx||sum%2){
			cout<<"-1\n";
			continue;
		}
		ll m=-1,sl=0,sr=sum;
		fore(i,0,n){
			sl+=a[i]; sr-=a[i];
			if(sl>=sr){m=i;break;}
		}
		assert(m!=-1);
		vector<vv> ops;
		auto rang=[&](ll l, ll r, ll c, vv &b){
			fore(i,l,r){
				ll q=min(c,a[i]);
				b[i]=q;
				c-=q; a[i]-=q;
			}
			assert(!c);
		};
		auto op=[&](ll l, ll r, ll s, ll e, ll c){
			// cout<<"op "<<l<<","<<r<<" "<<s<<","<<e<<""
			if(!c)return;
			sum-=2*c;
			vv b(n);
			rang(l,r,c,b);
			rang(s,e,c,b);
			ops.pb(b);
		};
		// cout<<m<<" "<<sl<<" "<<sr<<"\n";
		ll d=(sl-sr)/2;
		op(0,m,m,m+1,d);
		op(0,m+1,m+1,n,sum/2);
		assert(sum==0&&a==vv(n));
		cout<<SZ(ops)<<"\n";
		for(auto v:ops)imp(v)
	}
	return 0;
}
