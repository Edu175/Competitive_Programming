#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool ask(ll i, ll j){
	// if(i==j)return 0;
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	string ret; cin>>ret;
	return (ret=="YES");
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n); iota(ALL(a),0);
	stable_sort(ALL(a),ask);
	vv res(n);
	fore(i,0,n)res[a[i]]=i+1;
	cout<<"! ";
	imp(res)
	return 0;
}