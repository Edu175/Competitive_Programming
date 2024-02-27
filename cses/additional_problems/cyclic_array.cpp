#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll K=19;
int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(2*n+5);
	fore(i,0,n)cin>>a[i],a[i+n]=a[i];
	ll p=-1,sum=0;
	ll F[K][2*n+5];
	fore(i,0,2*n){
		while(p<2*n&&sum<=k)sum+=a[++p];
		F[0][i]=p;
		sum-=a[i];
	}
	F[0][2*n]=2*n;
	//fore(i,0,2*n)cout<<F[0][i]<<" ";;cout<<endl;
	fore(k,1,K)fore(i,0,2*n+1)F[k][i]=F[k-1][F[k-1][i]];
	ll res=n;
	fore(i,0,n){
		ll resi=1,x=i;
		for(ll k=K-1;k>=0;k--)if(F[k][x]<i+n)x=F[k][x],resi+=1ll<<k;
		res=min(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
