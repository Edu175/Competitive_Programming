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
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n;cin>>n;ll a[n];
		ll l=0,r=0;
		ll p=-1;
		ll res=0;
		ll mini;
		fore(i,0,n)cin>>a[i];
		while(l+r<=n-2){
			if(a[l]<=a[n-1-r])mini=a[l],l++;
			else mini=a[n-1-r],r++;
			if(p<=mini)res++,p=mini;
		}
		cout<<res+1<<"\n";
	}
	return 0;
}
