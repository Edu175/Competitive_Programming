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

// vector<ii>dir={{0,1},{1,0},{0,-1},{-1,0}};

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vv>ans(m,vv(2,n/2));
	ll cnt=2*n-1;
	vector<string>a(cnt);
	fore(i,0,cnt)cin>>a[i];
	vv l(2),r(2,n-1);
	fore(i,1,cnt){
		ll w=(i-1)&1,fg=(i-1)%4>=2;
		fore(j,0,m)if(a[i][j]=='1'){
			// cout<<"pinga "<<i<<" "<<j<<": "<<w<<" "<<fg<<"\n";
			ans[j][w]=(fg^w)?r[w]:l[w];
		}
		(fg^w)?r[w]--:l[w]++;
	}
	fore(i,0,m){
		fore(j,0,2)cout<<ans[i][j]+1<<" ";
		cout<<"\n";
	}
	return 0;
}
