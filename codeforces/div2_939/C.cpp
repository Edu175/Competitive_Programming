#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll get(vector<vector<ll>>r, ll n){
	ll a[n][n]={};
	for(auto v:r){
		ll i=v[1];
		vector<ll>p;
		fore(j,2,SZ(v))p.pb(v[j]);
		if(v[0]==0){
			fore(j,0,n)a[i][j]=p[j];
		}
		else {
			fore(j,0,n)a[j][i]=p[j];
		}
	}
	ll s=0;
	fore(i,0,n)fore(j,0,n)s+=(++a[i][j]);
	/*fore(i,0,n){
		imp(a[i]);
	}*/
	return s;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vector<ll>>res;
		ll s=0;
		fore(i,0,n){
			vector<ll>r={0,i};
			fore(j,0,n)r.pb(j);
			res.pb(r);
			r[0]=1;
			res.pb(r);
		}
		reverse(ALL(res));
		cout<<get(res,n)<<" "<<SZ(res)<<"\n";
		for(auto v:res){
			for(auto i:v)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}
