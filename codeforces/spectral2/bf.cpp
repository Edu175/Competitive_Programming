#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

set<vv> st;
void dfs(vv a){
	if(st.count(a))return;
	st.insert(a);
	ll n=SZ(a);
	fore(l,0,n)fore(r,l+1,n+1){
		if(accumulate(a.begin()+l,a.begin()+r,0ll)%2==0){
			auto b=a;
			b.erase(b.begin()+l,b.begin()+r);
			dfs(b);
		}
	}
}
vv a;
ll n;
string s;

void f(ll i){
	if(i==n){
		dfs(a);
		return;
	}
	ll l=0,r=1;
	if(s[i]!='?')l=r=s[i]-'0';
	fore(b,l,r+1){
		a.pb(b);
		f(i+1);
		a.pop_back();
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		st.clear();
		f(0);
		cout<<SZ(st)<<"\n";
		for(auto a:st){
			cerr<<"{";
			fore(i,0,SZ(a))cerr<<a[i];
			cerr<<"}\n";
		}
	}
	return 0;
}
