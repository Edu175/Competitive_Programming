#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll L,R,V; srand((ll)&V); cin>>L>>R>>V;
	//R=1ll<<R,L=1ll<<L;
	ll n=1ll<<(rand()%(R-L+1)+L);
	//ll n=1ll<<(rand()%()+1);
	vector<ll>a={0};
	vector<ll>vis(n);
	vis[0]=1;
	vector<ii>ed;
	fore(i,0,n-1){
		ll p=rand()%(n-1-i);
		fore(j,0,n){
			if(vis[j])continue;
			if(!p){
				ed.pb({a[rand()%SZ(a)],j});
				vis[j]=1;
				a.pb(j);
			}
			p--;
		}
	}
	cout<<n<<"\n";
	for(auto i:ed)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	fore(i,0,n)cout<<rand()%V+1<<" ";
	cout<<"\n";
	return 0;
}

