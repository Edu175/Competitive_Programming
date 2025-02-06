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
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vv a(m),q(k);
		fore(i,0,m)cin>>a[i],a[i]--;
		set<ll>st;
		fore(i,0,n)st.insert(i);
		fore(i,0,k)cin>>q[i],q[i]--,st.erase(q[i]);
		if(SZ(st)>=2){
			cout<<string(m,'0')<<"\n";
		}
		else if(SZ(st)==0){
			cout<<string(m,'1')<<"\n";
		}
		else {
			string res(m,'0');
			fore(i,0,m)res[i]='0'+(a[i]==*st.begin());
			cout<<res<<"\n";
		}
	}
	return 0;
}
