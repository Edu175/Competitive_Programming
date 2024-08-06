#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ld>b(n);
		fore(i,0,n)b[i]=log2(log(a[i]));
		ll res=0;
		fore(i,1,n){
			if(b[i]<b[i-1]&&b[i]==2*b[i]){res=-1;break;}
			ll l=0,r=log2(b[i-1])+5;
			while(l<=r){
				ll m=(l+r)/2;
				if((b[i]<<m)<b[i-1])l=m+1;
				else r=m-1;
			}
			res+=l;
			b[i]*=pow(2,l);
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
