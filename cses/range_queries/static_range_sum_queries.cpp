#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n], sump[n+1];
	sump[0]=0;
	fore(i,0,n)cin>>a[i],sump[i+1]=sump[i]+a[i];
	while(q--){
		ll b,c; cin>>b>>c; b--, c--;
		cout<<sump[c+1]-sump[b]<<"\n";
	}
	return 0;
}
