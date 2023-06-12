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
		ll n;cin>>n;
		vector<ll>v(n);
		ll res=0;
		fore(i,0,n)cin>>v[i];
		ll a=v[0],b=v[n-1];
		ll i=0, j=0;
		while(i+j+2<=n){
			//cout<<a<<" "<<" "<<b<<" s="<<i+j+2<<" | ";
			if(a==b){
				res=i+j+2;
				i++,a+=v[i];
				j++,b+=v[n-1-j];
			}
			if(a<b)i++,a+=v[i];
			if(b<a)j++,b+=v[n-1-j];
			
		}
		cout<</*"\n"<<*/res<<"\n";
	}
	return 0;
}
