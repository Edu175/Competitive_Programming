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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; k--;
		if(k<n-1||k>n*n-n){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		vector<vv> a(n,vv(n,-1));
		vector<ii> pos(n*n);
		ll cnt=0;
		fore(i,0,n)fore(j,0,n)if(i!=j){
			a[i][j]=cnt;
			pos[cnt]={i,j};
			cnt++;
		}
		ll val=cnt;
		fore(i,0,n){
			a[i][i]=cnt;
			pos[cnt]={i,i};
			cnt++;
		}
		auto [i,j]=pos[k];
		swap(a[0][0],a[i][j]);
		fore(i,0,n){
			fore(j,0,n)cout<<a[i][j]+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
