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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll n=1ll<<8,INF=1e10;

ll g[n][n];

void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

ll pren(ll a, ll i){
	if(a&(1ll<<i))return 1;
	return 0;
}

ll encode(vector<ll>a, ll bt=8){
	ll res=0;
	fore(i,0,bt){
		ll pos=0;
		fore(j,0,3)pos|=pren(a[j],i)<<j;
		res|=(1ll<<pos);
	}
	//cout<<"en "<<a<<" "<<bt<<": "<<res<<endl;
	return res;
}
vector<ll> decode(ll mk){
	vector<ll> res(3);
	fore(i,0,8){
		if(!pren(mk,i))continue;
		fore(j,0,3)res[j]|=pren(i,j)<<i;
	}
	//cout<<"en "<<mk<<": "<<res<<endl;
	return res;
}

vector<vector<ll>>dir={{0,1,0},{0,1,1},{1,0,2},{1,2,2}};
ll B=35;

int main(){FIN;
	fore(i,0,n)fore(j,0,n)g[i][j]=INF;
	fore(i,0,n){
		vector<ll>a=decode(i);
		for(auto d:dir){
			vector<ll>ai=a;
			if(d[2]==0)ai[d[0]]&=ai[d[1]];
			if(d[2]==1)ai[d[0]]|=ai[d[1]];
			if(d[2]==2)ai[d[0]]^=ai[d[1]];
			g[i][encode(ai)]=1;
			if(i==159&&encode(ai)==157){
				cout<<a<<" "<<d<<": "<<ai<<" 157\n";
			}
		}
	}
	fore(i,0,n)g[i][i]=0;
	floyd();
	ll t,db=0; cin>>t;
	while(t--){
		ll a,b,c,d,m; cin>>a>>b>>c>>d>>m;
		ll mka=encode({a,b,m},B),mkb=encode({c,d,m},B);
		if(++db==87){
			cout<<a<<"_"<<b<<"_"<<c<<"_"<<d<<"_"<<m<<"\n";
		}
		ll gra[B]={};
		vector<ll> oc[n];
		ll grb[B]={};
		fore(i,0,B){
			ll pos=(pren(a,i)<<0)|(pren(b,i)<<1)|(pren(m,i)<<2);
			gra[i]=pos;
			oc[pos].pb(i);
		}
		fore(i,0,B){
			ll pos=(pren(c,i)<<0)|(pren(d,i)<<1)|(pren(m,i)<<2);
			grb[i]=pos;
		}
		ll flag=1;
		//fore(i,0,B)fore(j,0,B)if((gra[i]==gra[j])&&(grb[i]!=grb[j]))flag=0;
		fore(i,0,n){
			fore(j,0,SZ(oc[i])-1)if(grb[oc[i][j]]!=grb[oc[i][j+1]])flag=0;
		}
		if(flag==0){
			cout<<"-1\n";
			continue;
		}
		ll res=g[mka][mkb];
		cout<<mka<<" "<<mkb<<":\n";
		fore(i,0,n)if(g[mka][i]==1)cout<<i<<" ";
		cout<<"\n";
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}
