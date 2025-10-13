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

const ll INF=1e18;

vector<vv> solve(vector<vv> a){
	ll n=SZ(a),m=SZ(a[0]);
	// cout<<"solve\n";
	// fore(i,0,n){
	// 	imp(a[i])
	// }
	assert(n<=m);
	vector<vv> res(n,vv(m,INF));
	fore(s,0,n){
		// cout<<"\n\nS "<<s<<"\n";
		// vector<vv> b(n-s,vv(m));
		// fore(i,s,n)fore(j,0,m)b[i-s][j]=a[i][j]&&a[s][j];
		vv dp(m,INF);
		for(ll i=n-1;i>=s;i--){
			vv pos;
			if(i>s)fore(j,0,m)if(a[i][j]&&a[s][j])pos.pb(j);
			// cout<<"i "<<i<<": ";imp(pos)
			fore(ind,0,SZ(pos)-1){
				ll l=pos[ind],r=pos[ind+1],area=(i-s+1)*(r-l+1);
				fore(j,l,r+1)dp[j]=min(dp[j],area);
				// cout<<s<<","<<i<<" "<<l<<","<<r<<": "<<area<<"\n";
			}
			// cout<<i<<" dp: "; imp(dp)
			fore(j,0,m)res[i][j]=min(res[i][j],dp[j]);
		}
	}
	return res;
}

void tra(vector<vv> &a){
	ll n=SZ(a),m=SZ(a[0]);
	vector<vv> b(m,vv(n));
	fore(i,0,n)fore(j,0,m)b[j][i]=a[i][j];
	a=b;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> a(n,vv(m));
		fore(i,0,n)fore(j,0,m){
			char c; cin>>c;
			a[i][j]=c-'0';
		}
		ll sw=0;
		if(n>m){
			sw=1;
			swap(n,m);
			tra(a);
		}
		auto b=solve(a);
		if(sw){
			swap(n,m);
			tra(b);
		}
		fore(i,0,n){
			for(auto v:b[i]){
				if(v>=INF)v=0;
				cout<<v<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
