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
	ll n,k; cin>>n>>k;
	vector<ll>a(k),v(n+1);
	fore(i,0,k)cin>>a[i];
	fore(i,1,n+1){
		for(auto j:a)if(i>=j)v[i]|=!v[i-j];
	}
	fore(i,1,n+1){
		if(v[i])cout<<"W";
		else cout<<"L";
	}
	cout<<"\n";
	return 0;
}
