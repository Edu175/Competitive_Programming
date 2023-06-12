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
typedef long double ld;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll a[n],b[m],sa=0,sb=0;
		fore(i,0,n)cin>>a[i],sa+=a[i];
		fore(i,0,m)cin>>b[i],sb+=b[i];
		ll res=0;
		while(sa*m-sb*n<=0){
			ld opa=ld((sa+k)*m-sb*(n+1))/ld((n+1)*m);
			ld opb=ld(sa*(m+1)-(sb+1)*n)/ld(n*(m+1));
			ld cur=ld(sa*m-sb*n)/ld(n*m);
			//cout<<n<<" "<<sa<<" , "<<m<<" "<<sb<<": "<<cur<<" "<<opa<<" "<<opb<<"\n";
			if(opa==cur&&opb==cur){
				res=-1;
				break;
			}
			if(opa>opb)sa+=k,n++;
			else sb+=1,m++;
			res++;
		}
		//cout<<n<<" "<<sa<<" , "<<m<<" "<<sb<<": "<<sa*m-sb*n<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
