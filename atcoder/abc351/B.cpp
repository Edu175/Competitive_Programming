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
	ll n; cin>>n;
	char a[2][n][n];
	fore(h,0,2)fore(i,0,n)fore(j,0,n)cin>>a[h][i][j];
	ll c,v;
	fore(i,0,n)fore(j,0,n)if(a[0][i][j]!=a[1][i][j]){
		c=i,v=j;
	}
	cout<<c+1<<" "<<v+1<<"\n";
	return 0;
}
