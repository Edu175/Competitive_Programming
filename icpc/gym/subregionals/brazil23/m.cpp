#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int MAXN=105;
const int INF=1e9;

ll d[MAXN][MAXN]; int n;
ll g[MAXN][MAXN];
void floyd(){
	fore(k,0,n)fore(i,0,n) if(d[i][k]<INF)fore(j,0,n)if(d[k][j]<INF)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
	JET
	cin>>n; 
	fore(i,0,n){
		fore(j,0,n){
			cin>>g[i][j];
			d[i][j]=g[i][j];
		}
	}
	ll rta=0;
	bool f=false;
	floyd();
	fore(i,0,n){
		fore(j,i+1,n){
			if(d[i][j]<g[i][j])f=true;
			ll flag=0;
			fore(k,0,n){
				if(k==i || k==j) continue;
				if(d[i][k]+d[k][j]==d[i][j])flag=1;
			}
			rta+=flag;
		}
	}
	if(f){
		cout<<-1<<"\n";
		return 0;
	}
	cout<<rta<<"\n";
	return 0;
}