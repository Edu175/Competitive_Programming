#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	char a[n][m];
	vector<ll>b(n);
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='o')b[i]|=1ll<<j;
		}
	}
	ll res=n+5;
	fore(mk,0,1ll<<n){
		ll vis=0,c=0;
		fore(i,0,n)if(mk>>i&1)vis|=b[i],c++;
		if(vis==(1ll<<m)-1)res=min(res,c);
	}
	cout<<res<<"\n";
	return 0;
}
