#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szkopul=b;i<szkopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n=100;
	vector<ii>ed;
	fore(i,0,n)ed.pb({i,(i+1)%n});
	cout<<n<<" "<<n<<" 4\n";
	for(auto i:ed)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}