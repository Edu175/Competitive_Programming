#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(a) for(auto i:a)cout<<i<<" ";;cout<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

set<vv> st;

vector<ii> mvs;

void dfs(vv a){
	st.insert(a);
	for(auto [l,r]:mvs){
		auto b=a;
		rotate(b.begin()+l,b.begin()+l+1,b.begin()+r);
		if(!st.count(b))dfs(b);
	}
}

ll sig(vv a){
	ll res=0;
	fore(i,0,SZ(a))fore(j,i+1,SZ(a))res+=a[i]>a[j];
	return res&1;
}

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	iota(ALL(a),0);
	ll m; cin>>m;
	fore(i,0,m){
		ll l,r; cin>>l>>r; l--;
		mvs.pb({l,r});
	}
	dfs(a);
	cout<<"size "<<SZ(st)<<"\n";
	ll cnt=0;
	for(auto a:st){
		for(auto i:a)cout<<i<<" ";
		cout<<"| "<<sig(a)<<"\n";
		if(++cnt>20)break;
	}
	return 0;
}