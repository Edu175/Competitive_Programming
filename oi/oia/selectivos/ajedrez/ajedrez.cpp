#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ii operator+(ii p1,ii p2){return {p1.fst+p2.fst,p1.snd+p2.snd};}
vector<ii>dir[3];
dir[0]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
dir[1]={{-1,-1},{-1,1},{1,-1},{1,1}};
dir[2]={{-1,0},{0,-1},{0,1},{1,0}};
const ll MAXN=1e3+5;
ll n;
ll a[MAXN][MAXN];
int main(){FIN;
	ifstream cin;   cin.open("ajedrez.in", ios::in);
	ofstream cout; cout.open("ajedrez.out", ios::out);
	ll c; cin>>n>>c;
	while(c--){
		ll i,j,k,l; cin>>i>>j>>k>>l; i--,j--,k--,l--;
		for(;i!=k||k!=l;(i<k?i++;i--),(j<l?j++:j--))a[i][j]=1;
	}
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j];
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
