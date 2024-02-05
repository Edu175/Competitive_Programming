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
const ll MOD=998244353,MAXN=3e5+5;

set<vector<ll>>st;

void f(vector<ll>a){
	if(st.count(a))return;
	st.insert(a);
	//imp(a);
	fore(i,0,SZ(a)){
		for(ll l=i;l>=0&&a[l]>=a[i];l--)for(ll r=i;r<SZ(a)&&a[r]>=a[i];r++){
			vector<ll>ai;
			fore(j,0,l)ai.pb(a[j]);
			ai.pb(a[i]);
			fore(j,r+1,SZ(a))ai.pb(a[j]);
			f(ai);
		}
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		st.clear();
		f(a);
		cout<<SZ(st)<<"\n";
	}
	return 0;
}
