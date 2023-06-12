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
		ll a[m];
		vector<ll>gap;
		fore(i,0,m)cin>>a[i];
		sort(a,a+m);
		fore(i,0,m){
			if(i)gap.pb(a[i]-a[i-1]-1);
		}
		gap.pb(n-a[m-1]+a[0]-1);
		sort(ALL(gap));
		reverse(ALL(gap));
		ll res=0;
		fore(i,0,m){
			if(gap[i]){
				ll sv=4*i+1;
				if(sv<gap[i])res+=sv;
				else res+=gap[i];
				if(gap[i]==sv)res--;
			}
		}
		res+=m;
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
