#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
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
vector<string> pingo(3,"...");

vector<string> f(ll k){
	if(k==0)return {"*"};
	auto pete=f(k-1);
	ll sz=SZ(pete);
	vector<string>ans(sz*3,string(sz*3,'.'));
	fore(i,0,3)fore(j,0,3)if(pingo[i][j]=='*'){
		fore(k,0,sz)fore(l,0,sz)ans[sz*i+k][sz*j+l]=pete[k][l];
	}
	return ans;
}

int main(){FIN;
	ll k; cin>>k;
	fore(i,0,3)fore(j,0,3)cin>>pingo[i][j];
	auto ans=f(k);
	fore(i,0,SZ(ans)){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
