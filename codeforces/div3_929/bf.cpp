#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(mk,0,1ll<<(n*m)){
		ll a[n][m];
		fore(i,0,n)fore(j,0,m)a[i][j]=mk>>(m*i+j)&1;
		ll flag=1;
		fore(i,0,n)fore(j,0,m){
			if(j+2<m&&a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])flag=0;
			if(i+2<n&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j])flag=0;
			if(i+2<n&&j+2<m&&a[i][j]==a[i+1][j+1]&&a[i][j]==a[i+2][j+2])flag=0;
			if(i+2<n&&j+2<m&&a[i][j+2]==a[i+1][j+1]&&a[i][j+2]==a[i+2][j])flag=0;
		}
		if(flag){
			fore(i,0,n){imp(a[i]);}
			cout<<"\n";
		}
	}
	return 0;
}
