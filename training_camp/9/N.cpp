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

int main(){FIN;
	ll n,m; cin>>n>>m;
	char a[n][m];
	ll gr=1e9,cant=0;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				cant++;
			}
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]=='#'){
				ll gri=0;
				if(i){
					if(a[i-1][j]=='#')gri++;
				}
				if(j){
					if(a[i][j-1]=='#')gri++;
				}
				if(i<n-1){
					if(a[i+1][j]=='#')gri++;
				}
				if(j<m-1){
					if(a[i][j+1]=='#')gri++;
				}
				gr=min(gr,gri);
			}
			//cout<<gri;
		}
		//cout<<"\n";
	}
	//cout<<cant<<" "<<gr<<" ";
	assert((cant-gr<=1)==(cant<3));
	if(cant-gr<=1)cout<<-1;
	//if(cant<3)cout<<-1;
	
	else cout<<gr;
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
