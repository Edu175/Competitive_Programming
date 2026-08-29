#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	cout<<"1\n";
	ll N; cin>>N; ll n=rng()%N+1;
	cout<<n<<"\n";
	vv a(n),b(n);
	fore(i,0,n)a[i]=rng()&1,b[i]=rng()&1;
	a[0]=1,a.back()=0;
	b[0]=0,b.back()=1;
	for(auto i:a)cout<<i;;cout<<"\n";
	for(auto i:b)cout<<i;;cout<<"\n";
	return 0;
}
