#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		if(gcd(n,m)!=1)cout<<"No\n"; // ????
		else {
			cout<<"Yes\n";
			ll mod=n*m;
			// cout<<n<<" "<<m<<"\n";
			vv a,b;
			fore(i,1,n+1){
				ll num=-1;
				// cout<<i<<": ";
				ll prim=1;
				for(ll v=i%mod;prim||v!=i;v=(v+n)%mod){
					prim=0;
					// cout<<v<<" ";
					if(gcd(v,m)==1){
						num=v;
						break;
					}
				}
				// cout<<endl;
				assert(num!=-1);
				a.pb(num);
			}
			// fore(i,0,n)a.pb(i+1);
			// a={1,5,3};
			fore(i,0,m)b.pb(i*n+1);
			auto check=[&](){
				cout<<"check\n";
				vv vis(n*m);
				ll good=1;
				fore(i,0,n){
					fore(j,0,m){
						ll p=a[i]*b[j]%(n*m);
						cout<<p<<" ";
						good&=!vis[p];
						// if(vis[p])return 0;
						vis[p]=1;
					}
					cout<<"\n";
				}
				cout<<endl;
				return good;
			};
			for(auto i:a)cout<<i%mod<<" ";;cout<<"\n";
			for(auto i:b)cout<<i%mod<<" ";;cout<<"\n";
			// assert(check());
		}
	}
	return 0;
}