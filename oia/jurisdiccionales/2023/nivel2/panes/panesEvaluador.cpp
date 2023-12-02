#include <vector>
#include <iostream>
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

int panes(vector<int> ciudades, vector<int> peajes);

int main(){FIN;
	ll n; cin>>n;
	vector<int>x(n),c(n-1);
	fore(i,0,n)cin>>x[i];
	fore(i,0,n-1)cin>>c[i];
	cout<<panes(x,c)<<"\n";
	return 0;
}
