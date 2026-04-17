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
	ll n; cin>>n;
	vector<vector<char>> a(n,vector<char>(n,'.'));
	vector<set<char>> diag(n+n);
	fore(i,0,n)fore(j,0,n)cin>>a[i][j],diag[i+j].insert(a[i][j]);
	ll good=1;
	fore(i,0,SZ(diag)){
		auto &st=diag[i];
		st.erase('?');
		if(SZ(st)>1)good=0;
		if(SZ(st)==0)st.insert('0');
	}
	if(!good){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n){
		fore(j,0,n){
			char c=a[i][j];
			c=*diag[i+j].rbegin();
			cout<<c;
		}
		cout<<"\n";
	}
	return 0;
}
