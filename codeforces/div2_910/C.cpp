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
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		if(k<n+m-2||k%2!=(n+m-2)%2){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		ll a[n][m-1]={},b[n-1][m]={};
		//a[0][0]=0,a[0][1]=0;
		b[0][0]=1;b[0][1]=1;
		fore(i,2,m-1)a[0][i]=a[0][i-1]^1;
		fore(i,1,n-1)b[i][0]=b[i-1][0]^1;
		b[0][m-1]=a[0][m-2]^1;
		fore(i,1,n-1)b[i][m-1]=b[i-1][m-1]^1;
		a[n-1][0]=b[n-2][0]^1;
		fore(i,1,m-1)a[n-1][i]=a[n-1][i-1]^1;
		fore(i,0,n){
			for(auto c:a[i]){
				if(!c)cout<<"B ";
				else cout<<"R ";
			}
			cout<<"\n";
		}
		fore(i,0,n-1){
			for(auto c:b[i]){
				if(!c)cout<<"B ";
				else cout<<"R ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
