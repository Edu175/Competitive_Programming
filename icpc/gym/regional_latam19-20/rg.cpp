#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
typedef long double ld;
random_device rd;
mt19937 rng(rd());
vector<char>v={'A','H'};
string gen(ll n){
	string s;
	ll bef=0;
	fore(i,0,n){
		bef^=(rng()%10==0);
		s.pb(v[bef]);
		
	}
	return s;
}
int main(){ET
	ll N; cin>>N;
	ll n=rng()%N+1;
	while(1){
		auto s=gen(n);
		ld sum=1;
		fore(i,1,n){
			if(s[i]!=s[i-1]){
				sum*=2*i+1;
			}
		}
		// cout<<s<<" "<<sum<<endl;
		if(sum<ld(1ull<<63)){
			cout<<s<<"\n";
			break;
		}
	}
	
	// cout<<"\n";
}