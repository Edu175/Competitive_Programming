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
const ll n=1ll<<8,INF=1e10;

ll g[n][n];

/*void floyd(){//O(n^3)
	//setear g[i][i]=0 y INF a aristas no existentes
	//se pisan los valores en la matriz de adyacencia
	fore(k,0,n)fore(i,0,n)if(g[i][k]!=INF)fore(j,0,n)if(g[k][j]!=INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);//or if(d==f||newPath<d)for flag value
		//g[j][i]=g[i][j];//not directed
}
ll g[MAXN][MAXN];int n;*/
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

ll pren(ll a, ll i){
	if(a&(1ll<<i))return 1;
	return 0;
}

ll op(ll mk, ll a, ll b, ll oper){
	ll res=0;
	ll e=0;
	if(a!=0&&b!=0)e=0;
	if(a!=1&&b!=1)e=1;
	if(a!=2&&b!=2)e=2;
	//cout<<"op "<<a<<" "<<b<<": "<<e<<"\n";
	//cout<<"op "
	assert(a!=b&&b!=e&&e!=a);
	fore(i,0,8){
		if(!pren(mk,i))continue;
		ll p=pren(i,a);
		ll q=pren(i,b);
		ll r=0;
		if(oper==0)r=p&q;
		if(oper==1)r=p|q;
		if(oper==2)r=p^q;
		p=r;
		ll _i=(p<<a)|(q<<b)|(pren(i,e)<<e);
		res|=1ll<<_i;
	}
	return res;
}
vector<vector<ll>>dir={{0,1,0},{0,1,1},{1,0,2},{1,2,2}};
ll B=35;
int main(){FIN;
	fore(i,0,n)fore(j,0,n)g[i][j]=INF;
	fore(i,0,n){
		for(auto d:dir){
			ll j=op(i,d[0],d[1],d[2]);
			g[i][j]=1;
		}
	}
	fore(i,0,n)g[i][i]=0;
	floyd();
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d,m; cin>>a>>b>>c>>d>>m;
		ll mka=0,mkb=0;
		ll gra[B]={};
		vector<ll> oc[8];
		ll grb[B]={};
		fore(i,0,B){
			ll pos=(pren(a,i)<<0)|(pren(b,i)<<1)|(pren(m,i)<<2);
			mka|=(1ll<<pos);
			gra[i]=pos;
			oc[pos].pb(i);
		}
		fore(i,0,B){
			ll pos=(pren(c,i)<<0)|(pren(d,i)<<1)|(pren(m,i)<<2);
			mkb|=(1ll<<pos);
			grb[i]=pos;
		}
		ll flag=1;
		//fore(i,0,B)fore(j,0,B)if((gra[i]==gra[j])&&(grb[i]!=grb[j]))flag=0;
		fore(i,0,8){
			fore(j,0,SZ(oc[i])-1)if(grb[oc[i][j]]!=grb[oc[i][j+1]])flag=0;
		}
		if(flag==0){
			cout<<"-1\n";
			continue;
		}
		ll res=g[mka][mkb];
		/*cout<<mka<<" "<<mkb<<":\n";
		fore(i,0,n)if(g[mka][i]==1)cout<<i<<" ";
		cout<<"\n";*/
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}
