#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353;

int main(){
	JET
	ll n; cin>>n;
	map<ll,ll>a,b;
	set<ll>st;
	vv ps(n),es(n);
	fore(i,0,n)cin>>ps[i];
	fore(i,0,n)cin>>es[i];
	fore(i,0,n)a[ps[i]]=es[i],st.insert(ps[i]);
	ll m; cin>>m;
	ps=es=vv(m);
	fore(i,0,m)cin>>ps[i];
	fore(i,0,m)cin>>es[i];
	fore(i,0,m)b[ps[i]]=es[i],st.insert(ps[i]);
	ll res=1,flag=1;
	for(auto p:st){
		flag&=a[p]>=b[p];
		if(a[p]!=b[p])res=res*2%MOD;
	}
	res*=flag;
	cout<<res<<"\n";
	return 0;
}