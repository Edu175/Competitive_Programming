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
		ll l,r,k,ev=0;
		cin>>l>>r>>k;
		if(l%2==0||r%2==0)ev++;
		ev+=(r-l)/2;
		ll res=0;
		if(k>=r-l+1-ev)res=1;
		if(l>1&&l==r)res=1;
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	 return 0;
}
