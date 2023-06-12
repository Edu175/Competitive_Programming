#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) for(auto messi:a)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

int main(){
	ll n; cin>>n;
	set<vector<ll>>gr;
	fore(mk,0,1ll<<(n*(n-1)/2)){
		//cout<<mk<<"\n";
		ll a[n][n],c=0; mset(a,0);
		fore(i,0,n)fore(j,i+1,n){
			a[i][j]=a[j][i]=((mk&(1ll<<c))!=0);
			c++;
		}
		vector<ll>p;
		fore(i,0,n)p.pb(i);
		vector<ll>res;
		do{
			ll b[n][n]; mset(b,0);
			fore(i,0,n)fore(j,0,n)if(i!=j){
				b[p[i]][p[j]]=!a[i][j];
			}
			ll flag=1;
			fore(i,0,n)fore(j,0,n)if(a[i][j]!=b[i][j])flag=0;
			if(flag)res=p;
		}
		while(next_permutation(ALL(p)));
		if(SZ(res)){
			vector<ll>g;
			fore(i,0,n){
				ll sum=0;
				fore(j,0,n)cout<<a[i][j],sum+=a[i][j];
				g.pb(sum);
				cout<<"\n";
			}
			sort(ALL(g));
			gr.insert(g);
			imp(res);
			cout<<"\n";
		}
	}
	for(auto i:gr){
		imp(i);
	}
	return 0;
}
