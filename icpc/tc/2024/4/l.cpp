#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int a,b,c; cin>>a>>b>>c;
	int x,y,z; cin>>x>>y>>z;
	int k=a-x,l=b-y,m=c-z;
	int pos=0; int neg=0;
	vv L={k,m,l};
	for(ll i : L){
		if(i>=0) pos+=i/2;
		else neg-=i;
	} 
	if(pos>=neg) cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}