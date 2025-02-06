#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef array<ll,3> node;
ll A,B,C,a,b,c;

vv cap;

node put(ll i, ll j, node a){
	ll q=min(a[i],cap[j]-a[j]);
	a[j]+=q;
	a[i]-=q;
	return a;
}
ll cv(int a, int b){
	return (a<<25)^b;
}
int main(){
	JET
	cin>>A>>B>>C>>a>>b>>c;
	cap={A,B,C};
	queue<pair<node,ll>>q;
	vv ans(C+1,-1);
	ll dif=SZ(ans);
	set<ii>st;
	auto pone=[&](node a, ll d){
		st.insert({a[0],a[1]});
		q.push({a,d});
		fore(i,0,3)if(ans[a[i]]==-1){
			ans[a[i]]=d;
			dif--;
		}
	};
	pone({a,b,c},0);
	while(SZ(q)){
		auto [a,d]=q.front(); q.pop();
		fore(i,0,3)fore(j,0,3)if(i!=j){
			auto b=put(i,j,a);
			if(!st.count({b[0],b[1]}))pone(b,d+1);
		}
	}
	for(auto i:ans)cout<<i<<" ";;cout<<"\n";
	return 0;
}