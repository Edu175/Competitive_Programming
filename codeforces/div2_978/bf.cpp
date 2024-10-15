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

int main(){
	ll n,m,k; cin>>n>>m>>k;
	ll res=0;
	fore(mk,0,1<<(n*m*k)){
		vector<vv> a(n,vv(m));
		fore(i,0,n)fore(j,0,m){
			a[i][j]=mk>>(k*(m*i+j))&((1ll<<k)-1);
		}
		ll flag=1;
		fore(i1,0,n)fore(i2,i1+1,n)fore(j1,0,m)fore(j2,j1+1,m){
			if(a[i1][j1]^a[i1][j2]^a[i2][j1]^a[i2][j2]){
				flag=0;
				goto fail;
			}
		}
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
		res++;
		fail:
		5;
	}
	cout<<"total "<<res<<"\nexpected "<<(1<<(k*(n+m-1)))<<"\n";
	return 0;
}
