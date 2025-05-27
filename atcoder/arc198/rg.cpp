#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-1)+2; cout<<n<<"\n";
	vv a(n),b(n); ll sum=0;
	fore(i,0,n)a[i]=rng()%V+1,sum+=a[i];
	fore(i,0,n-1)b[i]=rng()%V+1,sum-=b[i];
	b.back()=sum;
	imp(a)
	imp(b)
	return 0;
}
