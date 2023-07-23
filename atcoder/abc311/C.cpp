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
const ll MAXN=2e5+5,K=20;

ll to[MAXN],vis[MAXN];
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>to[i],to[i]--;//,F[0][i]=to[i];
	//fore(k,1,K)fore(i,0,n)F[k][i]=F[k-1][F[k-1][i]];
	vector<ll>s,res;
	ll x=0;
	while(1){
		ll y=to[x];
		if(vis[y]){
			s.pb(y);
			do{
				res.pb(s.back()),s.pop_back();
			}
			while(s.back()!=y);
			break;
		}
		vis[y]=1;
		s.pb(y);
		x=y;
	}
	reverse(ALL(res));
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
