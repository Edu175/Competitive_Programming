#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	cout<<"1\n";
	ll n=1000;
	vector<vector<char>>a(n,vector<char>(n,'.'));
	a[0][0]='V';
	cout<<n<<" "<<n<<"\n";
	fore(i,0,n){
		imp(a[i]);
	}
	return 0;
}
