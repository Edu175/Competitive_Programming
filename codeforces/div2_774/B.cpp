#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n;cin>>n;vector<ll>v(n);
		fore(i,0,n)cin>>v[i];
		sort(ALL(v));
		ll b=v[0]+v[1];
		ll r=v[n-1];
		ll flag=0;
		if(r>b)flag=1;
		fore(i,1,(n-3)/2+1){
			//cout<<"for\n";
			b+=v[1+i];
			r+=v[n-1-i];
			if(r>b){
				flag=1;
				break;
			}
			//cout<<b<<" "<<r<<"\n";
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	 return 0;
}
