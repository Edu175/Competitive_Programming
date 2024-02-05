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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		ll C=sqrt(n);
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>ds[C],sp[C];
		fore(d,1,C){
			ds[d].resize(n);
			sp[d].resize(n);
			fore(i,0,n){
				ds[d][i]=(i/d+1)*a[i];
				sp[d][i]=a[i];
				if(i/d)ds[d][i]+=ds[d][i-d],sp[d][i]+=sp[d][i-d];
			}
		}
		while(q--){
			ll s,d,k; cin>>s>>d>>k; s--;
			if(d>=C){
				ll res=0;
				for(ll i=s,c=0;c<k;i+=d,c++)res+=a[i]*(c+1);
				cout<<res<<" ";
			}
			else {
				ll res=ds[d][s+d*(k-1)],sum=sp[d][s+d*(k-1)];
				if(s/d)res-=ds[d][s-d],sum-=sp[d][s-d];
				res-=sum*(s/d);
				cout<<res<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}
