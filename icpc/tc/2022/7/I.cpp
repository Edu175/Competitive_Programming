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
	ll n,m; cin>>n>>m;
	ll bor=0;
	fore(i,0,n){
		fore(j,0,m){
			ll x;
			cin>>x;
			if(x&&(i==n-1||i==0||j==0||j==m-1))bor++;
		}
	}
	ll res;
	if(bor)res=2;
	else res=4;
	pres;
	return 0;
}
