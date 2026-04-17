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
typedef vector<vector<ll>> mat;

void check(mat b){
	ll n=SZ(b);
	mat sp(n,vv(n));
	fore(i,0,n)fore(j,0,n){
		auto &cur=sp[i][j];
		cur=b[i][j];
		if(i)cur+=sp[i-1][j];
		if(j)cur+=sp[i][j-1];
		if(i&&j)cur-=sp[i-1][j-1];
		ll c=cur-b[i][j];
		if(c&1){
			cout<<"failed check\n";
			for(auto r:b)imp(r)
			assert(0);
		}
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		mat a(n,vv(n)),b=a;
		auto calc=[&](ll i, ll j){
			auto &res=a[i][j];
			res=b[i][j];
			if(i)res+=a[i-1][j];
			if(j)res+=a[i][j-1];
			if(i&&j)res-=a[i-1][j-1];
			return res;
		};
		fore(d,0,n-1){
			fore(bo,0,2){
				ll i=d,j=n-1;
				ll cur=0,tot=0;
				b[i][j]=bo;
				cur+=b[i][j],tot++;
				calc(i,j);
				while(i+1<n){
					i++,j--;
					b[i][j]=0;
					calc(i,j);
					b[i][j]=calc(i,j+1)&1;
					cur+=b[i][j],tot++;
					// cerr<<i<<","<<j<<": "<<a[i][j]<<": "<<a[i][j+1]<<": ";
					calc(i,j);
					// cout<<a[i][j]<<"\n";
				}
				if(cur>=tot-cur)break;
			}
		}
		b[n-1][n-1]=1; // last one is always on
		ll c=0; fore(i,0,n)fore(j,0,n)c+=b[i][j];
		ll bound=n*n/10*3;
		cerr<<"cant  "<<c<<"\n";
		cerr<<"bound "<<bound<<"\n";
		for(auto r:b)imp(r)
	}
	return 0;
}
