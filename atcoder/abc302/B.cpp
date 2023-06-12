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

int main(){FIN;
	ll n,m; cin>>n>>m;
	char a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	string s="snuke";
	vector<pair<ll,ll>>res;
	vector<pair<ll,ll>>dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
	fore(i,0,n)fore(j,0,m){
		//cout<<i<<" "<<j<<":\n";
		vector<pair<ll,ll>>resi;
		fore(h,0,SZ(dir)){
			//cout<<h<<":\n";
			ll r=i,c=j;
			for(ll k=0;k<SZ(s)&&r>=0&&r<n&&c>=0&&c<m&& a[r][c]==s[k]; k++ ,r+=dir[h].fst, c+=dir[h].snd)resi.pb({r,c});//,cout<<r<<","<<c<<" ";
			//cout<<"\n";
			if(SZ(resi)==SZ(s))res=resi;
			resi.clear();
		}
	}
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
