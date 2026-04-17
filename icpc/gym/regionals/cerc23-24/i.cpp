#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv ask(vv a){
	cout<<"QUERY ";
	ll n=SZ(a);
	fore(i,0,n)cout<<a[i];
	cout<<endl;
	vv ret(n);
	fore(i,0,n)cin>>ret[i];
	return ret;
}
const ll B=15;
int main(){JET
	ll n; cin>>n;
	vv deg=ask(vv(n,1));
	vector<vv>h(15,vv(n));
	fore(j,0,B){
		vv v(n);
		fore(i,0,n)if(i>>j&1)v[i]=1;
		h[j]=ask(v);
	}
	queue<ll>q;
	fore(i,0,n)if(deg[i]==1)q.push(i);
	vector<ii>ed;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(deg[x]==0)break; // root
		ll y=0; // father
		fore(j,0,B)y|=h[j][x]<<j;
		ed.pb({x,y});
		deg[y]--;
		fore(j,0,B)h[j][y]-=x>>j&1;
		if(deg[y]==1)q.push(y);
	}
	cout<<"ANSWER\n";
	for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<"\n";
    cout<<endl;
	return 0;
}