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
	ll n; cin>>n;
	set<ll>st;
	fore(i,0,n)st.insert(i+1);
	auto p=st.begin();
	vector<ll>res;
	while(SZ(st)){
		p++; if(p==st.end())p=st.begin();
		res.pb(*p);
		auto q=p;
		p++; if(p==st.end())p=st.begin();
		st.erase(q);
	}
	imp(res);
	return 0;
}
