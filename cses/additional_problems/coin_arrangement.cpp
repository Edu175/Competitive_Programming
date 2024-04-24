#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>c(2);
	vector<vector<ll>>a(n,vector<ll>(2));
	fore(h,0,2){
		fore(i,0,n)cin>>a[i][h],a[i][h]--;
	}
	ll res=0;
	fore(i,0,n){
		fore(h,0,2)c[h]+=a[i][h];
		//cout<<i<<": ";imp(c);
		if((c[0]<0)!=(c[1]<0)){
			ll x=min(abs(c[0]),abs(c[1]));
			//cout<<"distinto "<<x<<"\n";
			ll c0=c[0],c1=c[1];
			c[c1<0]+=x;
			c[c1>=0]-=x;
			res+=x;
		}
		res+=abs(c[0])+abs(c[1]);
	}
	cout<<res<<"\n";
	return 0;
}
