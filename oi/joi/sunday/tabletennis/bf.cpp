#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll res=-1;
		fore(mk,0,1ll<<(n*(n-1)/2)){
			ll a[n][n]; mset(a,0);
			ll c=0;
			fore(i,0,n)fore(j,0,n){
				if(i>j)a[i][j]=(mk>>c++)&1;
			}
			fore(i,0,n)fore(j,i+1,n)a[i][j]=!a[j][i];
			ll q=0;
			fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
				if(a[i][j]==a[j][k]&&a[j][k]==a[k][i])q++;
			}
			if(q==m){res=mk;break;}
		}
		if(res==-1)cout<<"No\n";
		else {
			cout<<"Yes\n";
			ll a[n][n]; mset(a,0);
			ll c=0;
			fore(i,0,n)fore(j,0,n){
				if(i>j)a[i][j]=(res>>c++)&1;
			}
			fore(i,0,n){
				fore(j,0,i)cout<<a[i][j];
				if(i)cout<<"\n";
			}
		}
	}
	return 0;
}
