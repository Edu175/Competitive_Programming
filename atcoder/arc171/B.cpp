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
const ll MOD=998244353;
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	set<ll>st;
	ll res=1;
	fore(i,0,n){
		cin>>a[i]; a[i]--;
		if(a[i]<i)res=0;
	}
	fore(i,0,n){
		st.insert(a[i]);
		if(st.count(i)&&a[i]!=i)res=0;
		if(a[i]==i)res=res*SZ(st)%MOD;
		st.erase(i);
	}
	cout<<res<<"\n";
	return 0;
}
