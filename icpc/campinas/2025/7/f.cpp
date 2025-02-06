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

int g[3][3][3][3];
int g1[3][3];

int f(int x, int y, int t){
	int a[3][3];
	if(t){
		fore(i,0,3) fore(j,0,3) a[i][j] = g[x][y][i][j];
	}
	else fore(i,0,3)fore(j,0,3) a[i][j] = g1[i][j];
	
	fore(i,0,3){
		if(a[i][0]==a[i][1] && a[i][0]==a[i][2] && a[i][0] <= 1) return a[i][0];
		if(a[0][i]==a[1][i] && a[0][i]==a[2][i] && a[0][i] <= 1) return a[0][i];
	}
	if(a[2][2] == a[1][1] && a[0][0] == a[1][1] && a[1][1] <= 1) return a[1][1];
	if(a[0][2] == a[1][1] && a[2][0] == a[1][1] && a[1][1] <= 1) return a[1][1];
	fore(i,0,3) fore(j,0,3) if(a[i][j]==2) return 2;
	return 3;
}

int main(){
	JET
	fore(i,0,9)fore(j,0,9){
		char c; cin>>c;
		if(c=='O') g[i/3][j/3][i%3][j%3]=0;
		else if(c=='X') g[i/3][j/3][i%3][j%3]=1;
		else g[i/3][j/3][i%3][j%3]=2;
	}
	fore(i,0,3) fore(j,0,3) g1[i][j] = f(i,j,1); 
	int x = f(-1,-1,0);
	if(x==0) cout<<"OLGA";
	if(x==1) cout<<"XENIYA";
	if(x==2) cout<<"UNFINISHED";
	if(x==3) cout<<"DRAW";
	cout<<"\n";
	return 0;
}