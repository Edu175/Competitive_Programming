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
const ll MOD=998244353,MAXN=105;

vector<ll> comp[MAXN];
ll id[MAXN];

void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
bool uf_join(ll a, ll b){
	if(id[a]==id[b])return 0;
	ll c=id[a], d=id[b]; // c --> d
	if(SZ(comp[c])>SZ(comp[d]))swap(c,d);
	for(auto &i:comp[c]){
		comp[d].pb(i);
		id[i]=d;
	}
	comp[c].clear();
	return 1;
}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll a[MAXN][MAXN];
vector<pair<ll,ll>>dos,b;
set<ll>st;
int main(){//FIN;
	ll n; cin>>n;
	uf_init(n);
	ll flag=1,_=0;
	fore(i,0,n){
		ll d=0;
		fore(j,i,n){
			cin>>a[i][j];
			if(d==1&&a[i][j]==1)flag=0;
			if(a[i][j]==2){
				if(i==j)flag=0;
				d=1;
			}
		}
		a[i][i]=1;
	}
	//if(n==100&&a[0][0]==1&&a[0][1]==1&&a[0][2]==2)_=1;
	fore(i,0,n){
		ll u=i,d=-1;
		fore(j,i,n){
			if(a[i][j]==1)u=j;
			if(a[i][j]==2&&d==-1)d=j;
		}
		if(d!=-1)dos.pb({i,d});
		fore(j,i,u+1)uf_join(j,i);
	}
	/*if(_){
		fore(i,0,n)cout<<id[i]<<" ";
		cout<<"\n";
	}*/
	fore(c,0,n){
		if(!SZ(comp[c]))continue;
		ll l=comp[c][0],r=comp[c][0];
		for(auto &j:comp[c])l=min(l,j),r=max(r,j);
		for(auto &j:dos)if(l<=j.fst&&j.snd<=r)flag=0;
		b.pb({l,r});
	}
	sort(ALL(b));
	/*if(_){
		for(auto i:b)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";
		for(auto i:dos)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";
	}*/
	ll c=1;
	fore(i,0,SZ(dos)){
		if(i<SZ(dos)-1&&dos[i].snd>=dos[i+1].snd)continue;
		ll l=-1,r=-1;
		fore(j,0,SZ(b)){
			if(b[j].fst<=dos[i].fst&&dos[i].fst<=b[j].fst)l=j;
			if(b[j].fst<=dos[i].snd&&dos[i].snd<=b[j].fst)r=j;
		}
		//if(_)cout<<"["<<dos[i].fst<<","<<dos[i].snd<<"]: "<<l<<" "<<r<<"\n";
		set<ll>ids;
		fore(j,l,r+1)ids.insert(id[b[j].fst]);
		ll m=SZ(ids);
		/*if(_&&(m==0||m==1)){
			cout<<"zzz "<<i<<" "<<m<<":\n"<<l<<" "<<r<<": ";
			fore(j,l,r+1)cout<<b[j].fst<<","<<id[b[j].fst]<<" ";
			cout<<"\n";
		}*/
		c=(c*(m*(m-1))/2)%MOD;
		fore(j,l,r+1)uf_join(b[l].fst,b[j].fst);
	}
	/*if(_){
		for(auto i:b)cout<<"("<<i.fst<<","<<i.snd<<": "<<id[i.fst]<<") ";
		cout<<"\n";
	}*/
	for(auto &i:b)st.insert(id[i.fst]);
	ll res=0;
	if(flag)res=(fpow(2,SZ(st))*max(c,ll(1)))%MOD;
	if(_)cout<<SZ(st)<<" "<<c<<": ";
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
