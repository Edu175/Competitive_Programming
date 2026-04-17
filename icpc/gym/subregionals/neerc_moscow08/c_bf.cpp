#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e9*4+5;
int main(){
	JET
	ll n,m; cin>>n>>m;
	vv a(n*m);
	fore(i,0,n*m)cin>>a[i];
	sort(ALL(a));
	ll ans=INF;
	vector<vv> best(n,vv(m,-1));
	do{
		ll res=0;
		vector<vv> b(n,vv(m));
		fore(i,0,n)fore(j,0,m)b[i][j]=a[m*i+j];
		fore(i,0,n)fore(j,0,m){
			res+=abs(b[i][j]-(i?b[i-1][j]:0));
			res+=abs(b[i][j]-(j?b[i][j-1]:0));
			if(i==n-1)res+=b[i][j];
			if(j==m-1)res+=b[i][j];
		}
		if(res<ans){
			ans=res,best=b;
			// cout<<"mejoro ";
			// for(auto i:a)cout<<i<<" ";;cout<<"\n";
			// fore(i,0,n){
			// 	fore(j,0,m)cout<<b[i][j]<<" ";
			// 	cout<<"\n";
			// }
		}
	}while(next_permutation(ALL(a)));
	cout<<ans<<"\n";
	fore(i,0,n){
		fore(j,0,m)cout<<best[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
