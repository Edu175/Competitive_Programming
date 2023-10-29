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
const ll MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

int main(){FIN;
	ll n,a,b,d,e; cin>>n>>a>>b>>d>>e; a--,b--;
	ll p[n+5][n+5]; mset(p,0);
	ll q[n+5][n+5]; mset(q,0);
	p[0][a]=1;
	q[0][b]=1;
	/*fore(i,0,n+1)cout<<p[i][n-1]<<" ";
	cout<<"\n";
	fore(i,0,n+1)cout<<q[i][n-1]<<" ";
	cout<<"\n";*/
	fore(j,0,n-1)fore(i,0,n){
		fore(x,1,d+1){
			ll go=min(j+x,n-1);
			p[i+1][go]=(p[i+1][go]+p[i][j]*fpow(d,MOD-2))%MOD;
			//cout<<i<<" "<<j<<" --> "<<i+1<<" "<<go<<" += "<<p[i][j]*fpow(d,MOD-2)%MOD<<"\n";
		}
		fore(x,1,e+1){
			ll go=min(j+x,n-1);
			q[i+1][go]=(q[i+1][go]+q[i][j]*fpow(e,MOD-2))%MOD;
			//cout<<i<<" "<<j<<" --> "<<i+1<<" "<<go<<" += "<<p[i][j]*fpow(e,MOD-2)%MOD<<"\n";
		}
	}
	//cout<<p[0][n-1]<<" "<<n-1<<"\n";
	/*fore(i,0,n+1)cout<<p[i][n-1]<<" ";
	cout<<"\n";
	fore(i,0,n+1)cout<<q[i][n-1]<<" ";
	cout<<"\n";*/
	ll res=0;
	fore(i,0,n)fore(j,i,n)res=(res+p[i][n-1]*q[j][n-1])%MOD;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
