#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m,d; cin>>n>>m>>d; d++;
	vector<ll> a(n);
	set<ii> st;
	fore(i,0,n)cin>>a[i],st.insert({a[i],i});
	vv res(n,-1);
	ll cnt=0;
	// for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	while(SZ(st)){
		// cout<<"vuelta "<<cnt<<"\n";
		auto [v,i]=*st.begin();
		st.erase(st.begin());
		while(1){
			// cout<<i<<"\n";
			res[i]=cnt;
			v+=d;
			auto it=st.lower_bound({v,-1});
			if(it==st.end())break;
			v=it->fst,i=it->snd;
			st.erase(it);
		}
		cnt++;
	}
	cout<<cnt<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
