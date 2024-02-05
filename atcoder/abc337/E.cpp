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
	ll n; cin>>n;
	ll m=0;
	while((1ll<<m)<n)m++;
	vector<vector<ll>>a(m);
	fore(i,0,n){
		fore(j,0,m)if((i>>j)&1)a[j].pb(i);
	}
	cout<<m<<endl;
	fore(i,0,m){
		cout<<SZ(a[i])<<" ";
		for(auto j:a[i])cout<<j+1<<" ";
		cout<<endl;
	}
	string s; cin>>s;
	ll x=0;
	fore(i,0,m)if(s[i]=='1')x|=1ll<<i;
	cout<<x+1<<endl;
	return 0;
}
