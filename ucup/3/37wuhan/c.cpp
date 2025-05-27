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
const ll B=1000;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]++;
		vv res(m);
		ll len=2*n-1;
		vector<vv> h(B);
		auto add=[&](ll k, ll p){
			// cout<<"add "<<k<<" "<<p<<"\n";
			p/=len;
			p+=k;
			if(p>=m)return;
			// cout<<k<<" "<<p<<"\n";
			if(k>=B){
				for(ll i=p;i<m;i+=k)res[i]++;
			}
			else {
				h[k].pb(p);
			}
		};
		ll gan=0;
		fore(i,0,n){
			// cout<<"\n\n"<<i<<"\n";
			ll l=2*i+1,r=2*(n-1-i);
			// cout<<l<<" "<<r<<"\n";
			if(a[i]<=l&&a[i]<=r&&i<n-1){
				gan++;
				continue;
			}
			ll dir=1,t=i;
			auto simul=[&](){
				ll w=t/len;
				if(w<m)res[w]++;
				// cout<<"simul "<<t<<" "<<t/len<<"\n";
				ll q=a[i]/len,rem=a[i]%len;
				if(i==n-1)t+=len*(q+(rem>0));
				else {
					t+=q*len;
					ll am=dir?r:l;
					if(rem==0);
					else if(rem>am)t+=len;
					else t+=am,dir^=1;
				}
			};
			vv ts;
			ll P=6;
			fore(i,0,P){ // 6
				ts.pb(t);
				simul();
			}
			// continue;
			// imp(ts)
			// cout<<endl;
			ll k=ts[P-1]-ts[P-3];
			assert(k%len==0);
			k/=len;
			add(k,ts[P-2]);
			add(k,ts[P-1]);
		}
		fore(k,1,B){
			auto &v=h[k];
			vv up(m);
			for(auto i:v)up[i]++;
			fore(i,0,m){
				res[i]+=up[i];
				if(i+k<m)up[i+k]+=up[i];
			}
		}
		for(auto &i:res)i+=2*gan;
		imp(res);
	}
	return 0;
}
