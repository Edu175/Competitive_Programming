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

ii operator+(ii p,ii q){return {p.fst+q.fst,p.snd+q.snd};}
ii operator+=(ii &p,ii q){return p=p+q;}
ii operator-(ii p,ii q){return {p.fst-q.fst,p.snd-q.snd};}

int main(){FIN;
	ll n,m; cin>>n>>m;
	char g[n][m];
	fore(i,0,n)fore(j,0,m)cin>>g[i][j];
	ii s={0,0};
	ll q; cin>>q;
	fore(t,0,q-(q&1)){
		ll a,b; cin>>a>>b; a--,b--;
		ii p[4]; p[0]={a,b},p[1]={a,b+m},p[2]={a+n,b},p[3]={a+n,b+m};
		if(s.fst<=a&&s.snd<=b)s=p[0]-s;
		if(s.fst<=a&&s.snd>b)s=p[1]-s;
		if(s.fst>a&&s.snd<=b)s=p[2]-s;
		if(s.fst>a&&s.snd>b)s=p[3]-s;
	}
	char res[n][m];
	//cout<<s.fst<<","<<s.snd<<"\n";
	assert(0<=s.fst&&s.fst<n&&0<=s.snd&&s.snd<m);
	fore(i,0,n)fore(j,0,m)res[i][j]=g[(i-s.fst+n)%n][(j-s.snd+m)%m];
	/*fore(i,0,n){
		fore(j,0,m)cout<<res[i][j];
		cout<<"\n";
	}*/
	if(q&1){
		ll a,b; cin>>a>>b;
		fore(i,0,n)reverse(res[i],res[i]+b),reverse(res[i]+b,res[i]+m);
		fore(j,0,m){
			fore(i,0,a/2)swap(res[i][j],res[a-1-i][j]);
			fore(i,a,a+(n-a)/2)swap(res[i][j],res[n-1-(i-a)][j]);
		}
	}
	fore(i,0,n){
		fore(j,0,m)cout<<res[i][j];
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
