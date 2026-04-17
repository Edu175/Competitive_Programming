#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool good(vv a){
	ll fg=1;
	for(auto i:a)fg&=i>=0;
	return fg;
}
ll n;
ll bfs(vv s){
	queue<pair<vv,ll>>q;
	set<vv>st;
	q.push({s,0});
	while(SZ(q)){
		auto [x,d]=q.front(); q.pop();
		fore(i,1,n-1){
			auto y=x;
			y[i-1]+=y[i];
			y[i+1]+=y[i];
			y[i]-=2*y[i];
			if(!st.count(y)){
				st.insert(y);
				if(good(y))return d+1;
				q.push({y,d+1});
			}
		}
	}
	return -1;
}

// void fail(){
// 	cout<<"-1\n";
// 	exit(0);
// }

int main(){
    JET
	cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	if(good(a))cout<<"0\n";
	else cout<<bfs(a)<<"\n";
    return 0;
}