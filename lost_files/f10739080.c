#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll ocr[n][35]={},occ[m][35]={};
		ll tot[35]={};
		ll a[n][m];
		fore(i,0,n)fore(j,0,m){
			cin>>a[i][j];
			fore(h,0,35){
				if(a[i][j]&(1ll<<h))ocr[i][h]++,occ[j][h]++,tot[h]++;
			}
		}
		ll res=0,q=n*m-n-m+1;
		//cout<<"q "<<q<<"\n";
		fore(i,0,n)fore(j,0,m){
			ll oc[35]={};
			fore(h,0,35)oc[h]=tot[h]-ocr[i][h]-occ[j][h]+((a[i][j]&(1ll<<h))!=0);
			//cout<<i<<" "<<j<<": "; imp(oc);
			ll resi=0;
			fore(h,0,35){
				if(a[i][j]&(1ll<<h))resi+=(1ll<<h)*(q-oc[h]);
				else resi+=(1ll<<h)*oc[h];
			}
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
