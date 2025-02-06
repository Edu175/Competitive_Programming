#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


int main(){
	JET
	ll n; cin>>n;
	vector<string> a(n,string(n,'.'));
	fore(i,0,n)cin>>a[i];
	auto rot=[&](){
		auto b=a;
		fore(i,0,n)fore(j,0,n)a[i][j]=b[n-1-j][i];
	};
	string s; cin>>s;
	vector<vv>vis(n,vv(n,0));
	vector<string> b(n,string(n,'.'));
	ll flag=1,cnt=0;
	fore(i,0,4){
		// fore(i,0,n){
		// 	cout<<a[i]<<"\n";
		// }
		fore(i,0,n)fore(j,0,n)if(a[i][j]=='.'){
			if(!flag||vis[i][j]){flag=0;continue;}
			vis[i][j]=1;
			b[i][j]=s[cnt++];
		}
		rot();
	}
	flag&=cnt==SZ(s);
	if(!flag)cout<<"invalid grille\n";
	else {
		fore(i,0,n)fore(j,0,n)cout<<b[i][j];
		cout<<"\n";
	}
	return 0;
}