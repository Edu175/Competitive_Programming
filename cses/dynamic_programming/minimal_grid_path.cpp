#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n; cin>>n;
	vector<string> a(n,string(n,'.'));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	string ans={a[0][0]};
	vector<ii> pos={{0,0}};
	vector<vv> vis(n,vv(n));
	while(1){
		vector<vector<ii>> nxt(26);
		auto agr=[&](ll i, ll j){
			if(vis[i][j])return;
			vis[i][j]=1;
			nxt[a[i][j]-'A'].pb({i,j});
		};
		for(auto [i,j]:pos){
			if(i+1<n)agr(i+1,j);
			if(j+1<n)agr(i,j+1);
		}
		ll did=0;
		fore(i,0,26)if(SZ(nxt[i])){
			pos=nxt[i];
			ans.pb('A'+i);
			did=1;
			break;
		}
		if(!did)break;
	}
	cout<<ans<<"\n";
	return 0;
}