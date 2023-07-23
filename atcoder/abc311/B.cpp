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
	char a[n][m];
	ll b[m]={};
	fore(i,0,n){
		fore(j,0,m)cin>>a[i][j],b[j]|=(a[i][j]=='x');
	}
	ll q=0,res=0;
	//imp(b);
	fore(i,0,m){
		//cout<<i<<": "<<q<<"\n";
		if(b[i])res=max(res,q),q=0;
		else q++;
	}
	res=max(res,q);
	cout<<res<<"\n";
	return 0;
}
