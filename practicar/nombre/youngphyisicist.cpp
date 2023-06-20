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
	ll n; cin>>n;
	ll a[n],x[n],y[n],z[n];
	ll xs=0,ys=0,zs=0;
	fore(i,0,n){
		cin>>x[i]>>y[i]>>z[i];
		xs+=x[i];
		ys+=y[i];
		zs+=z[i];	
	}
	if(xs==0&&ys==0&&zs==0)cout<<"YES\n";else cout<<"NO\n";
	
	return 0;
}
