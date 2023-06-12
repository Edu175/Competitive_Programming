#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long ll;

ll n,m;
vector<ll>dir={-1,1};
char a[55][55];
bool allowed(ll f, ll i){
	bool res=1;
	if(f%m==m-1&&i==1)res=0;
	else if(f%m==0&&i==-1)res=0;
	else if(f/m==0&&i==-m)res=0;
	else if(f/m==n-1&&i==m)res=0;
	else if(a[(f+i)/m][(f+i)%m]=='.')res=0;
	return res;
}
ll cant=0;
bool vis[2505][2505];
bool bfs(ll v){
	queue<ll>q;
	vis[v][v]=1;
	ll cti=cant;
	cti--;
	for(auto i:dir){
		if(allowed(v,i)&&!vis[v][v+i]){
			q.push(v+i);
			vis[v][v+i]=1;
			cti--;
			break;
		}
	}
	while(SZ(q)){
		ll f=q.front();
		//cout<<f<<" ";
		q.pop();
		for(auto i:dir){
			ll fi=f+i;
			if(allowed(f,i)&&!vis[v][fi]){
				q.push(fi);
				vis[v][fi]=1;
				cti--;
			}
		}
	}
	if(cti)return 1;
	else return 0;
}

int main(){FIN;
	cin>>n>>m;
	dir.pb(-m);
	dir.pb(m);
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				cant++;
			}
		}
	}
	if(cant<3){
		cout<<-1;
		return 0;
	}
	ll res=2;
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]=='#'){
				//cout<<m*i+j<<": ";
				if(bfs(m*i+j))res=1;//,cout<<"YES\n";
				//else cout<<"NO\n";
			}
		}
	}
	pres;
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
