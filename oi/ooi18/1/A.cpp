#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,rus=b;i<rus;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdkjg:v)cout<<sdkjg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll task,group; cin>>task>>group;
	assert(task==1);
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<ll>res;
	fore(i,0,n){
		res.pb(i);
		res.pb(n-1-i);
	}
	res.resize(n);
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
