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
	ll n,m; cin>>n>>m;
	vector<ll>a(n),b(m);
	set<ll>st;
	set<ll>res;
	fore(i,0,n)cin>>a[i],st.insert(a[i]);
	fore(i,0,m){
		cin>>b[i];
		if(st.count(b[i]))res.insert(b[i]);
	}
	if(SZ(res)){
		imp(res);
	}
	else {
		cout<<"-1\n";
	}
	return 0;
}
