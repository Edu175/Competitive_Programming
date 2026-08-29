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
	ll n,m; cin>>n>>m;
	vector<vector<char>> a(n,vector<char>(m));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	vv h(m);
	ll res=0;
	fore(i,0,n){
		fore(j,0,m){
			h[j]++;
			if(a[i][j]=='0')h[j]=0;
		}
		// cout<<i<<": ";;imp(h)
		fore(l,0,m){
			ll mn=h[l];
			fore(r,l,m){
				mn=min(mn,h[r]);
				ll cur=(r-l+1)*mn;
				res=max(res,cur);
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}