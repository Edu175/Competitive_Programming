#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n][m];
		a[0][0]=1;
		ll cn=0,vn=0;
		fore(i,0,n){
			if(i)a[i][0]=vn, cn++;
			if(cn==2)cn=0,vn=vn^1;
			ll c=0,v=a[i][0]^1;
			fore(j,1,m){
				a[i][j]=v;
				c++;
				if(c==2)v=v^1,c=0;
			}
		}
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
