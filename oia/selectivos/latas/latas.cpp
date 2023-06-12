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
const ll MAXN=1005;
ll n;
ll a[MAXN][MAXN],sp[MAXN][MAXN];

int main(){FIN;
	ifstream cin; cin.open("latas.in", ios::in);
	ofstream cout; cout.open("latas.out", ios::out);
	cin>>n;
	fore(i,0,n)fore(j,0,i+1)cin>>a[i][j];
	fore(i,0,n+1)sp[i][0]=0;
	fore(j,0,n+1)sp[0][j]=0;
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]=sp[i][j-1]+a[i-1][j-1];
	fore(i,1,n+1)fore(j,1,n+1)sp[i][j]+=sp[i-1][j];
	/*fore(i,0,n+1){fore(j,0,n+1)cout<<sp[i][j]<<" ";cout<<"\n";}
	cout<<"\n";*/
	ll tr[n+1]; tr[n]=0;
	for(ll h=n-1;h>=0;h--){
		ll sum=0;
		for(ll i=n-1,j=h;i>=0&&j<n;i--,j++)sum+=a[i][j];
		tr[h]=sum+tr[h+1];
	}
	//imp(tr); cout<<"\n";
	ll res=0;
	fore(i,0,n){
		fore(j,0,i+1){
			ll sum=sp[n][n]-sp[i][n]-sp[n][j]+sp[i][j], resi=sum-tr[min(j+i+1,n)];
			//cout<<i<<" "<<j<<": "<<sum<<" "<<min(j+i+1,n)<<": "<<resi<<"\n";
			res=max(resi,res);
		}
	}
	cout<<sp[n][n]-res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

