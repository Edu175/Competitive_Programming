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

const ll INF=1e12;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll c[n][4],d[4]={};
		fore(j,0,4)d[j]=-INF;
		fore(i,0,n)fore(j,0,4){
			ll &res=c[i][j];
			res=-abs(a[i]-b[i]);
			if(j&2)res-=a[i];
			else res+=a[i];
			if(j&1)res-=b[i];
			else res+=b[i];
			d[j]=max(d[j],res);
		}
		ll sum=0;
		fore(i,0,n)sum+=abs(a[i]-b[i]);
		ll res=sum;
		fore(j,0,4){
			ll j2=(~j)&3;
			ll resi=sum+d[j]+d[j2];
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
