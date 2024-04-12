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
	ll r=0;
	ll n=21;
	char a[n][n];
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	
	fore(i,0,n-3)fore(j,0,n-3){
		ll s=0;
		fore(i1,0,4)fore(j1,0,4)s+=a[i+i1][j+j1]-'0';
		r=max(r,s);
	}
	cout<<r<<"\n";
	return 0;
}
