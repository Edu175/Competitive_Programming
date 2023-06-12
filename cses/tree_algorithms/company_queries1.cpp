#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b; i<edu; i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5,K=20;

ll n;
ll F[K][MAXN];

void fathers(){
	F[0][0]=-2;
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-2;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll x=i+1;
		ll e; cin>>e; e--;
		F[0][x]=e;
	}
	fathers();
	while(q--){
		ll x,k; cin>>x>>k; x--;
		fore(i,0,K)if(k&(1ll<<i)){
			x=F[i][x];
			if(x<0)break;
		}
		cout<<x+1<<"\n";
	}
	return 0;
}
