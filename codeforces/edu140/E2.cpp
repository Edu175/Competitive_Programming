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
const ll INF=1e10,MAXM=45;

ll g[MAXM][MAXM];
ll m,mid;
ll gru(pair<ll,ll> a){//[0,mid) [mid,m)
	if(a.fst<mid&&a.snd<mid)return 0;
	if(a.fst>=mid&&a.snd>=mid)return 1;
	return 2;
}
ll gru(ll a){
	return a>=mid;
}

int main(){FIN;
	ll n; cin>>n>>m;
	mid=(m+1)/2;
	ll a[n],w[m];
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,m)cin>>w[i];
	fore(i,1,n)g[min(a[i-1],a[i])][max(a[i-1],a[i])]=1;
	g[a[0]][a[0]]=1;
	g[a[n-1]][a[n-1]]=1;
	ll res[2][1ll<<(m/2)];
	fore(i,0,2)fore(j,0,1ll<<(m/2))res[i][j]=INF;
	fore(bm,0,1ll<<(mid)){
		ll flag=1,des=0,sum=0;
		fore(i,0,mid)if((bm>>i)&1)sum+=w[i];
		fore(i,0,mid){
			if(bm&(1ll<<i))continue;
			fore(j,0,mid)if(g[i][j]&&(bm&(1ll<<j))==0)flag=0;
			fore(j,mid,m)if(g[i][j])des|=1ll<<(j-mid);
		}
		if(flag)res[0][des]=min(res[0][des],sum);
	}
	fore(bm,0,1ll<<(m/2)){
		ll flag=1,sum=0;
		fore(i,0,m/2)if((bm>>i)&1)sum+=w[i+mid];
		//cout<<bm<<": ";
		fore(i,mid,m){
			if(bm&(1ll<<(i-mid)))continue;
			fore(j,mid,m){
				if(g[i][j]&&(bm&(1ll<<(j-mid)))==0)flag=0;//,cout<<i<<","<<j<<" ";
			}
		}
		//cout<<"| "<<flag;
		if(flag)res[1][bm]=min(res[1][bm],sum);//,cout<<": "<<bm<<" "<<sum;
		//cout<<"\n";
	}
	//cout<<"\n";
	/*fore(j,0,1ll<<(m/2)){
		cout<<j<<":"<<res[0][j]<<" ";
	}
	cout<<"\n\n";*/
	fore(bm,0,1ll<<(m/2)){
		fore(i,0,m/2){
			if(bm&(1ll<<i))res[0][bm]=min(res[0][bm],res[0][bm-(1ll<<i)]);
		}
	}
	/*fore(i,0,2){
		fore(j,0,1ll<<(m/2)){
			cout<<j<<":"<<res[i][j]<<" ";
		}
		cout<<"\n\n";
	}*/
	ll mini=INF;
	fore(bm,0,1ll<<(m/2)){
		mini=min(res[1][bm]+res[0][bm],mini);
		//cout<<bm<<": "<<res[0][bm]<<" "<<res[1][bm]<<"\n";
	}
	cout<<mini<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
