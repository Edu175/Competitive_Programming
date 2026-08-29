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
	ll n,d; cin>>n>>d;
	vector<vv> pos(n);
	fore(i,0,n){
		ll x; cin>>x;
		pos[x].pb(i);
	}
	ll res=n;
	fore(x,0,n){
		ll good=1;
		
		auto v=pos[x];
		ll m=SZ(v);
		ll L=-1,p=0;
		fore(i,0,m){
			if(L==-1)L=v[i];
			if(i==m-1||v[i+1]-v[i]>d){
				good&=v[i]-L<d;
				
				ll s=v[i]-d;
				if(s<p){
					good&=L>=p;
					p+=2*d;
				}
				L=-1;
			}
		}
		
		if(good){res=x;break;}
	}
	cout<<res<<"\n";
	return 0;
}