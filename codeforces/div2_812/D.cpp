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

ll ask(ll a, ll b){
	ll ret;
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>ret;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vector<ll>>r(n+1);
		fore(i,0,(1ll<<n))r[0].pb(i+1);
		fore(i,0,n){
			for(ll a=0,b=2; b<(1ll<<(n-i)); a+=4,b+=4){
				ll q=ask(r[i][a],r[i][b]);
				if(q==1){
					r[i+1].pb(r[i][a]);
					r[i+1].pb(r[i][b+1]);
				}
				else if(q==2){
					r[i+1].pb(r[i][b]);
					r[i+1].pb(r[i][a+1]);
				}
				else if(q==0){
					r[i+1].pb(r[i][a+1]);
					r[i+1].pb(r[i][b+1]);
				}
			}
		}
		ll fin=ask(r[n-1][0],r[n-1][1]);
		if(fin==1)cout<<"! "<<r[n-1][0]<<endl;
		else if(fin==2)cout<<"! "<<r[n-1][1]<<endl;
		else assert(0);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
