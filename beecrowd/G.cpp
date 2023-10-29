#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	char a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	ll r=n,c=m;
	fore(i,0,n){
		ll q=1;
		fore(j,1,m){
			if(a[i][j]!=a[i][j-1])c=min(c,q),q=1;
			else q++;
		}
		c=min(c,q);
	}
	fore(j,0,m){
		ll q=1;
		fore(i,1,n){
			if(a[i][j]!=a[i-1][j])r=min(r,q),q=1;
			else q++;
		}
		r=min(r,q);
	}
	
	ll n1=0,n2=0;
	fore(i,1,r+1)n1+=(r%i==0);
	fore(i,1,c+1)n2+=(c%i==0);
	cout<<n1*n2<<"\n";
	return 0;
}

