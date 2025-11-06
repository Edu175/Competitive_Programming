#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<string> a(n,string(m,'.'));
		fore(i,0,n)cin>>a[i];
		vector<vv> col(n,vv(m,-1));
		ll fg=1;
		auto assign=[&](ll i, ll j, ll c, char bu){
			if(bu!='U')swap(i,j);
			col[i][j]=c;
		};
		auto doit=[&](vector<string> a, char bu){ // n m
			ll n=SZ(a);
			ll m=SZ(a[0]);
			fore(i,0,n){
				ll c=0;
				fore(j,0,m)if(a[i][j]==bu){
					assign(i,j,c,bu);
					assign(i+1,j,c^1,bu);
					c^=1;
				}
				fg&=c==0;
			}
		};
		doit(a,'U');
		vector<string> b(m,string(n,'.'));
		fore(i,0,n)fore(j,0,m)b[j][i]=a[i][j];
		doit(b,'L');
		if(!fg)cout<<"-1\n";
		else {
			fore(i,0,n){
				fore(j,0,m){
					char c='.';
					if(col[i][j]!=-1)c="WB"[col[i][j]];
					cout<<c;
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}
