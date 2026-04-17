#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;

int main(){FIN;
	ll N,Q; srand((ll)&N); cin>>N>>Q;
	ll n=rand()%(N-1)+2,q=rand()%(Q+1);
	ll g[n][n]={};
	vector<ii>ed;
	fore(i,1,n){
		ll p=rand()%i;
		g[p][i]=g[i][p]=1;
	}
	fore(i,0,n)fore(j,0,i)if(!g[i][j])ed.pb({i,j});
	ll m=SZ(ed)?rand()%SZ(ed):0;
	random_shuffle(ALL(ed));
	ed.resize(m);
	fore(i,0,n)fore(j,0,i)if(g[i][j])ed.pb({i,j});
	cout<<n<<" "<<SZ(ed)<<"\n";
	for(auto [u,v]:ed)cout<<u+1<<" "<<v+1<<"\n";
	fore(i,0,n)cout<<rand()%2<<" ";;cout<<"\n";
	ll K=m>60?1e18:((1ll<<m)+5);
	cout<<rand()%K+1<<"\n";
	cout<<q<<"\n";
	while(q--){
		ll ty=rand()%3;
		if(ty==0){
			cout<<"M "<<rand()%n+1<<"\n";
		}
		else if(ty==1){
			cout<<"K "<<rand()%K+1<<"\n";
		}
		else {
			cout<<"D "<<(SZ(ed)?rand()%SZ(ed)+1:1)<<"\n";
		}
	}
	return 0;
}
