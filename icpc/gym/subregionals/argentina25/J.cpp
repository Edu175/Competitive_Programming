#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ba(vv &a){return SZ(a)?a.back():1e18;}
vector<vv> tra(vector<vv> a){
	if(SZ(a)>=3)return {};
	if(SZ(a)==1)return a;
	ll ult=min(ba(a[0]),ba(a[1]));
	fore(w,0,2)while(SZ(a[w])&&a[w].back()==ult)a[w].pop_back();
	return a;
}

int main(){
	JET
	ll n; cin>>n;
	vector<vv> a(n),b(n);
	multiset<ll> sa,sb;
	fore(w,0,2){
		auto &v=(w?b:a);
		fore(i,0,n){
			ll m; cin>>m;
			v[i].resize(m);
			fore(j,0,m)cin>>v[i][j],(w?sb:sa).insert(v[i][j]);
		}
	}
	
	if(sa==sb&&tra(a)==tra(b))cout<<"S\n";
	else cout<<"N\n";
	return 0;
}