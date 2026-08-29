#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vector<string> a(n);
	fore(i,0,n)cin>>a[i];
	string t; cin>>t;
	vv po(n);
	string ans;
	vector<vv> oc(26);
	fore(i,0,n)oc[a[i][po[i]]-'a'].pb(i);
	auto put=[&](char c){
		ans.pb(c);
		ll le=c-'a';
		auto v=oc[le]; oc[le].clear();
		for(auto i:v){
			auto &p=po[i]; p++;
			if(p<SZ(a[i]))oc[a[i][p]-'a'].pb(i);
		}
	};
	fore(i,0,SZ(t)){
		char c=t[i];
		while(1){
			ll w=-1;
			fore(le,0,26)if(le+'a'!=c&&SZ(oc[le]))w=le;
			if(w==-1)break;
			put(w+'a');
		}
		if(i<SZ(t)-1)put(c);
		// cerr<<"ans "<<ans<<"\n";
		// cerr<<"po: ";
		// fore(i,0,n)cout<<po[i]<<"/"<<SZ(a[i])<<" ";;cerr<<"\n";
	}
	ll good=1;
	fore(i,0,n)good&=po[i]==SZ(a[i]);
	if(!good){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	cout<<ans<<"\n";
	return 0;
}