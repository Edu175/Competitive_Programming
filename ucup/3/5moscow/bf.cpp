#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
vector<ii> moves(ii par){
	auto [l,r]=par;
	ll z=r-l;
	vector<ii> ret(2,par);
	ret[0].fst-=z;
	ret[1].snd+=z;
	for(auto &[l,r]:ret)l=max(l,0ll),r=min(r,n);
	return ret;
}
ll bfs(ii s){
	ii dst={0,n};
	if(s==dst)return 0;
	set<ii> st;
	queue<pair<ii,ll>> q;
	st.insert(s); q.push({s,0});
	while(SZ(q)){
		auto [x,d]=q.front(); q.pop();
		for(auto y:moves(x)){
			if(y==dst)return d+1;
			if(!st.count(y)){
				st.insert(y);
				q.push({y,d+1});
			}
		}
	}
	assert(0);
}

ll lgt(ll n){
	ll res=0;
	while(n>1)res++,n=(n+1)/2;
	return res;
}
int main(){
    JET
	ll l,r; cin>>n>>l>>r;
	ll z=r-l;
	ll tot=(l+z-1)/z +1+ (n-r+z-1)/z;
	ll best=lgt(tot);
	cout<<"best: "<<best<<"\n";
	cout<<"actual: "<<bfs({l,r})<<"\n";
	return 0;
}
