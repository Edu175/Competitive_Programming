#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MAXN=1e2;
int n,m;
vector<int> g[MAXN];
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(){
	queue<int>q;
	mset(ds,-1);
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=1;
		}
	}
	return r;
}
bool dfs(int x){
	for(auto y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
		mt[y]=x;mt2[x]=y;
		return 1;
	}
	ds[x]=1<<30;
	return 0;
}
ll mm(){
	ll r=0;
	mset(mt,-1); mset(mt2,-1);
	while(bfs()){
		fore(i,0,n)if(mt2[i]<0)r+=dfs(i);
	}
	return r;
}
 
 int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	vector <ii> bus;
	int b[n];
	int t[m];
	vector <ii> tro;
	fore(i,0,n) {int a;
		cin>>a;
		b[i]=a;
		int aux=0;
		fore(i,0,3){
			aux+=(a%10);
			a/=10;
		}
		ii res;res.snd=aux; aux=0;
		fore(i,0,3){
			aux+=(a%10);
			a/=10;
		}
		res.fst=aux;
		bus.pb(res);
	}
	fore(i,0,m) {int a;
		cin>>a;
		t[i]=a;
		int aux=0;
		fore(i,0,3){
			aux+=(a%10);
			a/=10;
		}
		ii res;res.snd=aux; aux=0;
		fore(i,0,3){
			aux+=(a%10);
			a/=10;
		}
		res.fst=aux;
		tro.pb(res);
	}
	//fore(i,0,n) cout<<bus[i].fst<<" "<<bus[i].snd<<"\n";
//	fore(i,0,m) cout<<tro[i].fst<<" "<<tro[i].snd<<"\n";
	fore(i,0,n) fore(j,0,m){
		if(bus[i].fst==tro[j].snd || bus[i].snd==tro[j].fst) g[i].pb(j);
	}
	cout<<mm()<<"\n";
	fore(i,0,n){
		if(mt2[i]!=-1){
			if(bus[i].fst==tro[mt2[i]].snd) {cout<<"AT ";
				int aux=1;
				fore(j,0,5) if((aux*=10)>b[i])cout<<"0";
				cout<<b[i]<<" "; aux=1;
				fore(j,0,5) if((aux*=10)>t[mt2[i]])cout<<"0";
				cout<<t[mt2[i]]<<" \n";
			}
			else {cout<<"TA ";
				int aux=1;
				fore(j,0,5) if((aux*=10)>t[mt2[i]])cout<<"0";
				cout<<t[mt2[i]]<<" "; aux=1;
				fore(j,0,5) if((aux*=10)>b[i])cout<<"0";
				cout<<b[i]<<" \n";
			}
			
		}
	}
	return 0;
 }