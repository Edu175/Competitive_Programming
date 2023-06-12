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
		vector<ll>c(m);
		char a[n][m];
		fore(i,0,n){
			fore(j,0,m)cin>>a[i][j];
		}
		for(ll i=n-1;i>=0;i--){
			fore(j,0,m){
				if(a[i][j]=='o')c[j]=n-i;
				if(a[i][j]=='*'){
					a[i][j]='.';
					a[n-1-c[j]][j]='*';
					c[j]++;
				}
			}
		}
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j];
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
