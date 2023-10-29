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

int main(){
	//random_device rd;
	//mt19937 rng(rd());
	//uniform_int_distribution<int>dis(0,1000000000);
	//cout<<dis(rng)<<"\n";
	ll n;
	mt19937 rng((ll)&n);
	vector<int>p={0,1,2,3,4};
	shuffle(ALL(p),rng);
	imp(p);
	cout<<rng()<<"\n";
	return 0;
}
