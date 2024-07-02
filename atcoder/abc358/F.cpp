#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	if(k%2!=n%2||k<n){cout<<"No\n";return 0;}
	cout<<"Yes\n";
	char a[2*n+1][2*m+1];
	fore(i,0,2*n+1)fore(j,0,2*m+1){
		char &c=a[i][j];
		c='.';
		if(!i||!j||i==2*n||j==2*m||(i%2==0&&j%2==0))c='+';
		else if(i%2&&j%2)c='o';
	}
	a[0][2*m-1]='S';
	a[2*n][2*m-1]='G';
	
	fore(i,1,n/2*2)fore(j,0,m){
		a[2*i][2*j+1]='-';
		if(2*j+1==2*m-1&&i%2==0)a[2*i][2*j+1]='.';
	}
	
	k=(k-n)/2;
	
	fore(i,0,n-1)if(i%2==0){
		if(k>=m-1)a[2*i+2][1]='.',k-=m-1;
		else {
			ll p=(m-1-k)*2;
			a[2*i+2][p+1]='.';
			a[2*i+1][p]=
			a[2*i+3][p]='|';
			k=0;
		}
	}
	
	fore(i,0,2*n+1){
		fore(j,0,2*m+1)cout<<a[i][j];
		cout<<"\n";
	}
	return 0;
}
