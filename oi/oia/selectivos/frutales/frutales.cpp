#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e3+5;

ll sp[2][MAXN][MAXN],a[2][MAXN][MAXN];
ll get(ll w, ll s0, ll s1, ll e0, ll e1){
	return sp[w][e0][e1]-sp[w][s0][e1]-sp[w][e0][s1]+sp[w][s0][s1];
}
int main(){
	ifstream cin;cin.open("frutales.in", ios::in);
	ofstream cout; cout.open("frutales.out", ios::out);
	ll n,m,p,f; cin>>n>>m>>p>>f;
	fore(i,0,p){
		ll x,y; cin>>x>>y; x--,y--;
		a[0][x][y]=1;
	}
	fore(i,0,f){
		ll x,y; cin>>x>>y; x--,y--;
		a[1][x][y]=1;
	}
	fore(h,0,2){
		fore(i,1,n+1)fore(j,1,m+1)sp[h][i][j]=sp[h][i][j-1]+a[h][i-1][j-1];
		fore(i,1,n+1)fore(j,1,m+1)sp[h][i][j]+=sp[h][i-1][j];
	}
	/*fore(h,0,2){
		cout<<h<<":\n";
		fore(i,0,n+1){
			fore(j,0,m+1)cout<<sp[h][i][j]<<" ";
			cout<<"\n";
		}
	}*/
	vector<ll>res={0,0,0,0}; // -frutales, tamaño, i, j
	fore(i,0,n)fore(j,0,m){
		//cout<<i<<" "<<j<<": ";
		ll l=0,r=min(n-i,m-j);
		while(l<=r){
			ll mid=(l+r)/2;
			if(get(0,i,j,i+mid,j+mid)==0)l=mid+1;
			else r=mid-1;
		}
		ll c=get(1,i,j,i+r,j+r);
		//cout<<r<<" "<<c<<": ";
		l=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if(get(1,i,j,i+mid,j+mid)==c)r=mid-1;
			else l=mid+1;
		}
		//cout<<l<<"\n";
		vector<ll>resi={-c,l,i,j};
		res=min(res,resi);
		//imp(resi);
	}
	cout<<res[2]<<" "<<res[3]<<"\n"<<res[1]<<"\n"<<-res[0]<<"\n";
	return 0;
}
