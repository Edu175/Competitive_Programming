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
	ll N; srand((ll)&N); cin>>N;
	ll a=rand()%int(1e9-5)+1,b=rand()%int(1e9-5)+1;
	if(a>b)swap(a,b);
	if(a==b)b++;
	ll n=rand()%(N-1)+2;
	ll s=rand()%(n-1),e=rand()%(n-1);
	if(e>=s)e++;
	cout<<n<<" "<<n-1<<" "<<a<<" "<<b<<" "<<s<<" "<<e<<"\n";
	vector<ii>ed;
	fore(i,1,n)ed.pb({rand()%i,i});
	for(auto i:ed)cout<<i.fst<<" "<<i.snd<<"\n";
	return 0;
}
