#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;

/*vector<ll> comp[MAXN]; ll id[MAXN];
void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i;}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b;
	comp[a].clear();
	return 1;
}*/
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("red.in", ios::in);
	cout.open("red.out", ios::out);
	char c; cin>>c;
	uf_init();
	while(c!='F'){
		ll a,b; cin>>a>>b; a--,b--;
		if(c=='P'){
			if(uf_find(a)==uf_find(b))cout<<"S\n";
			else cout<<"N\n";
			//cout<<id[a]<<" "<<id[b]<<" "<<uf_query(a,b)<<"\n";
		}
		else uf_join(a,b);
		cin>>c;
	}
	return 0;
}
