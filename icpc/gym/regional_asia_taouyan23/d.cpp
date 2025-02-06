#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
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

vector<ii> hor={{1,0},{0,1},{-1,0},{0,-1}},
diag={{1,1},{-1,1},{-1,-1},{1,-1}};

int main(){
	JET
	ll t; cin>>t;
	fore(_,0,t){
		ll n,m,d1,d2; cin>>n>>m>>d1>>d2;
		vector<string>a(n,string(m,'0'));
		fore(i,0,n)fore(j,0,m){
			char c; cin>>c;
			if(c=='V')a[i][j]='V';
		}
		auto doit=[&](ll x, ll y, ll val){
			if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='V')
					a[x][y]=max(a[x][y],char('0'+val));
		};
		fore(i,0,n)fore(j,0,m)if(a[i][j]=='V'){
			for(auto [r,c]:hor){
				doit(i+r,j+c,d1);
			}
			for(auto [r,c]:diag){
				doit(i+r,j+c,d2);
			}
		}
		cout<<"Airplane #"<<_+1<<":\n";
		fore(i,0,n)cout<<a[i]<<"\n";
	}
	return 0;
}