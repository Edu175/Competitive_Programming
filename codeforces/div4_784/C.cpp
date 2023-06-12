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
		ll n; cin>>n;
		ll a[n];
		ll congp;
		ll congi;
		ll res=1;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			if(i==0)congp=a[i]%2;
			if(i==1)congi=a[i]%2;
			if(i>1&&(i%2==0)){
				if(a[i]%2!=congp){
					res=0;
					break;
				}
			}
			if(i>1&&(i%2==1)){
				if(a[i]%2!=congi){
					res=0;
					break;
				}
			}
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
