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
		ll n,a,b,c=0;
		cin>>n>>a>>b;vector<ll>v(n);
		ll res=0;
		//ll posc=-1;
		fore(i,0,n){
			cin>>v[i];
			res+=b*(v[i]-c);
			if(a*(v[i]-c)<=(v[i]-c)*b*(n-i-1))res+=a*(v[i]-c), c=v[i]/*posc=i,*/;
			//cout<<c<<" ";
		}
		//cout<<"\n";
		/*ll sum=0;
		fore(i,posc+1,n){
			sum+=v[i]-c;
		}
		res+=sum*b;*/
		cout<<res<<" "<<"\n";
	}
	return 0;
}
