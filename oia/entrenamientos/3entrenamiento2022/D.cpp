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
const ll MAXN=30,INF=1e9;

ll g[MAXN][MAXN];

void floyd(){
	fore(k,0,MAXN)fore(i,0,MAXN)if(g[i][k]<INF)fore(j,0,MAXN)if(g[k][j]<INF){
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
}

int main(){FIN;
	string s,t; cin>>s>>t;
	if(SZ(s)!=SZ(t)){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,MAXN){
		fore(j,0,MAXN)g[i][j]=INF;
	}
	fore(i,0,MAXN)g[i][i]=0;
	ll m; cin>>m;
	fore(i,0,m){
		char a,b;ll w; cin>>a>>b>>w;
		g[a-'a'][b-'a']=min(g[a-'a'][b-'a'],w);
	}
	floyd();
	/*fore(i,0,MAXN){
		fore(j,0,MAXN){
			if(g[i][j]!=INF)cout<<g[i][j]<<" ";
			else cout<<"- ";
		}
		cout<<"\n";
	}*/
	ll sum=0,flag=1;;
	string res;
	fore(i,0,SZ(s)){
		ll a=s[i]-'a',b=t[i]-'a';
		ll resi=-1,mini=INF;
		fore(j,0,MAXN){
			if(g[a][j]<INF&&g[b][j]<INF){
				if(g[a][j]+g[b][j]<mini)mini=g[a][j]+g[b][j],resi=j;
			}
		}
		sum+=mini;
		if(resi==-1)flag=0;
		res.pb('a'+resi);
		//cout<<s[i]-'a'<<"->"<<t[i]-'a'<<" = "<<g[s[i]-'a'][t[i]-'a']<<"\n";
	}
	if(flag==0)cout<<"-1\n";
	else {
		cout<<sum<<"\n"<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
