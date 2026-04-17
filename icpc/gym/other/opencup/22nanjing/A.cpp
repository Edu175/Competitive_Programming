#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

string go(ii st, ii d){
	string r = "";
	while(st.fst > d.fst) r.pb('U'), st.fst--;
	while(st.fst < d.fst) r.pb('D'), st.fst++;
	while(st.snd > d.snd) r.pb('L'), st.snd--;
	while(st.snd < d.snd) r.pb('R'), st.snd++;
	return r;
}



int main(){
	JET 
	ll n; cin>>n;
	ii fin; cin>>fin.fst>>fin.snd;
	vector<string> res;
	res.pb(go({1,1},{n,n}) + go({n,n},fin));
	res.pb(go({1,n},{n,1}) + go({n,1},fin));
	res.pb(go({n,1},{1,n}) + go({1,n},fin));
	res.pb(go({n,n},{1,1}) + go({1,1},fin));
	sort(ALL(res),[&](string a, string b){return SZ(a)<SZ(b);});
	cout<<res[0]<<"\n";
	return 0;
}