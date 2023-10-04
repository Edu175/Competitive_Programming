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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;

ll cv(int x, int y){return (x<<8)|y;}
LL cv(LL a, LL b, LL c, LL d, LL e){return (a<<32)|(b<<24)|(c<<16)|(d<<8)|(e);}
ll pren(ll a, ll i){
	if(a&(1ll<<i))return 1;
	return 0;
}
vector<vector<ll>>dir={{0,1,0},{0,1,1},{1,0,2},{1,2,2}};

//map<ll,ll> dis[1ll<<8][1ll<<8][1ll<<8];
unordered_map<LL,ll> dis;

ll bfs(ii s, ii e, ll m, ll k){
	if(s==e)return 0;
	queue<ii>q;
	q.push(s);
	//vector<vector<ll>>d(1ll<<k,vector<ll>(1ll<<k,-1));
	//map<ll,ll> d[1ll<<k];
	//cout<<s.fst<<","<<s.snd<<" "<<m<<endl;
	//cout<<"d"<<endl;
	//cout<<"cv "<<cv(s.fst,s.snd)<<endl;
    //auto d=dis[m][s.fst][s.snd];
	dis[cv(m,s.fst,s.snd,s.fst,s.snd)]=0;
	while(SZ(q)){
		auto [x,y]=q.front(); q.pop();
		vector<ii>vec={{x&y,y},{x|y,y},{x,y^x},{x,y^m}};
		//cout<<m<<" "<<s.fst<<","<<s.snd<<": "<<x<<","<<y<<" ("<<e.fst<<","<<e.snd<<")\n";
		for(auto [xi,yi]:vec)if(!dis.count(cv(m,s.fst,s.snd,xi,yi))){
			q.push({xi,yi});
			dis[cv(m,s.fst,s.snd,xi,yi)]=dis[cv(m,s.fst,s.snd,x,y)]+1;
			//if((ii){xi,yi}==e)return dis[cv(m,s.fst,s.snd,xi,yi)];
		}
	}
	if(!dis.count(cv(m,s.fst,s.snd,e.fst,e.snd)))return -1;
	return dis[cv(m,s.fst,s.snd,e.fst,e.snd)];
}
const ll B=35;
int main(){FIN;
    //mset(dis,-1);
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d,m; cin>>a>>b>>c>>d>>m;
		ll gra[B]={};
		vector<ll> oc[8];
		ll grb[B]={};
		//cout<<"grs"<<endl;
		fore(i,0,B){
			ll pos=(pren(a,i)<<0)|(pren(b,i)<<1)|(pren(m,i)<<2);
			gra[i]=pos;
			oc[pos].pb(i);
		}
		fore(i,0,B){
			ll pos=(pren(c,i)<<0)|(pren(d,i)<<1)|(pren(m,i)<<2);
			grb[i]=pos;
		}
		//cout<<"flag"<<endl;
		ll flag=1;
		fore(i,0,8){
			fore(j,0,SZ(oc[i])-1)if(grb[oc[i][j]]!=grb[oc[i][j+1]])flag=0;
		}
		if(flag==0){
			cout<<"-1\n";
			continue;
		}
		//cout<<"s e"<<endl;
		ii s={0,0},e={0,0};
		ll k=0,mi=0;
		fore(i,0,B){
			ll pos=gra[i];
			if(oc[pos][0]==i){
				s.fst|=(pren(pos,0)<<k);
				s.snd|=(pren(pos,1)<<k);
				mi|=(pren(pos,2)<<k);
				e.fst|=(pren(grb[i],0)<<k);
				e.snd|=(pren(grb[i],1)<<k);
				k++;
			}
		}
		//cout<<"bfs"<<endl;
		//cout<<s.fst<<" "<<s.snd<<"  "<<e.fst<<" "<<e.snd<<"  "<<mi<<" "<<k<<"\n";
		cout<<bfs(s,e,mi,k)<<"\n";
	}
	return 0;
}
