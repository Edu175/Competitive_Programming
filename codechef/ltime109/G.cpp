#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n+1]; ll res[n];
		ll totx=0;
		fore(i,0,n+1)cin>>a[i],totx=totx^a[i];
		if(n%2){
			ll flag=0;
			fore(i,0,n+1){
				if(!flag)if(a[i]==totx){
					flag=1;
					continue;
				}
				res[i-flag]=a[i]^totx;
			}
		}
		else{
			totx=a[n];
			fore(i,0,n)res[i]=a[i]^totx;
		}
		imp(res);
	}
	return 0;
}
