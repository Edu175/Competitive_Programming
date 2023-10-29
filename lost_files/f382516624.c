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
	ll n,k; cin>>n>>k;
	char a[n][n];
	fore(j,0,n){
		fore(i,0,n)a[i][j]='.';
	}
	for(ll i=0;i<k*2&&i<n;i+=2)a[i][i]='R';
	if((n+1)/2>=k){
		fore(j,0,n){
			fore(i,0,n)cout<<a[i][j];
			cout<<"\n";
		}
	}else cout<<-1<<"\n";
	}
	 return 0;
}
