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
		ll n,m; cin>>n>>m;
		string a[n];
		ll res=10e5;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			fore(j,0,n-i-1){
				ll mini=0;
				fore(h,0,m)mini+=abs(a[i][h]-a[1+j+i][h]);
				res=min(res,mini);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
