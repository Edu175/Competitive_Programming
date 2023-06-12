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
typedef int ll;

const ll MAXN=200005;
const ll bits=log2(MAXN)+1;
ll sump[MAXN][bits];

int main(){FIN;
	ll t; cin>>t;
	fore(j,0,bits){
		sump[0][j]=0;
		fore(i,1,MAXN){
			sump[i][j]=sump[i-1][j];
			if((i&(1ll<<j))!=(1ll<<j))sump[i][j]++;
		}
	}
	while(t--){
		ll l,r; cin>>l>>r;
		ll bits=log2(r)+1;
		ll mini=200005;
		fore(i,0,bits)mini=min(mini,sump[r][i]-sump[l-1][i]);
		cout<<mini<<"\n";
	}
	return 0;
}
