#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int vis[300000];
int n,m;
void arriba(vector<vector<char>>& a){
	fore(j,0,m){
		int aux=0;
		fore(i,0,n){
			if(a[i][j]!='.'){
				char r = a[i][j];
				a[i][j]='.';
				a[aux][j]=r;
				aux++;
			}
		}
	}
}

void abajo(vector<vector<char>>& a){
	fore(j,0,m){
		int aux=n-1;
		for(int i = n-1;i>=0;i--){
			if(a[i][j]!='.'){
				char r = a[i][j];
				a[i][j]='.';
				a[aux][j]=r;
				aux--;
			}
		}
	}
}


void izquierda(vector<vector<char>> &a){
	fore(i,0,n){
		int aux=0;
		fore(j,0,m){
			if(a[i][j]!='.'){
				ll r=a[i][j];
				a[i][j]='.';
				a[i][aux]=r;
				aux++;
			}
		}
	}
}

void derecha(vector<vector<char>> &a){
	fore(i,0,n){
		int aux=m-1;
		for(int j=m-1;j>=0;j--){
			if(a[i][j]!='.'){
				char r=a[i][j];
				a[i][j]='.';
				a[i][aux]=r;
				aux--;
			}
		}
	}
}

void doit(int i, vector<vector<char>>& a){
	if(i==0){
		arriba(a);
	}
	if(i==1) izquierda(a);
	if(i==2) abajo(a);
	if(i==3) derecha(a);
}

int main(){
	cin>>n>>m;
	vector<vector<char>> a(n,vector<char>(m));
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];			
		}
	}
	int k; cin>>k;
	fore(i,0,k){
		char c; cin>>c;
		if(c=='G') doit(0,a);
		if(c=='L') doit(1,a);
		if(c=='D') doit(2,a);
		if(c=='P') doit(3,a);
	}
	// cout<<"a"<<endl;
	fore(i,0,n){
		fore(j,0,m) cout<<a[i][j];
		cout<<"\n";
	}
}