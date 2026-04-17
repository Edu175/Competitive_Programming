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
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b(n);
		fore(i,0,n)cin>>b[i];
		vv is(k); // periodic
		ll fg=1;
		fore(r,0,k){
			set<ll> sta,stb;
			for(ll i=r;i<n;i+=k)sta.insert(a[i]),stb.insert(b[i]);
			stb.erase(-1);
			if(SZ(sta)>1||SZ(stb)>1){
				for(ll i=r;i<n;i+=k){
					if(b[i]==-1)b[i]=a[i];
					fg&=a[i]==b[i];
				}
			}
			else {
				if(SZ(stb)==1){
					ll v=*stb.begin();
					for(ll i=r;i<n;i+=k)b[i]=v;
				}
			}
		}
		if(!fg){
			cout<<"NO\n";
			continue;
		}
		map<ll,ll> mpa,mpb;
		fore(i,0,k){
			mpa[a[i]]++;
			if(b[i]!=-1)mpb[b[i]]++;
		}
		for(auto [k,c]:mpb)fg&=mpa[k]>=c;
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
