#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;



int main(){
	JET
	map<int,int> M;
	int _; cin>>_; while(_--){
		int n,m; cin>>n>>m;
		fore(i,0,n+m){
			int a; cin>>a;
			M[a]=(i<n?M[a]+1:0);
		}
		ll mx=0;
		ll act=0;
		for(auto [k,f]: M){
			if(f){
				act+=f;
				mx=max(mx,act);
			}
			else act=0;
		}
		M.clear();
		if(mx){ cout<<mx<<"\n";}
		else{cout<<"Impossible\n";}
	}
	return 0;
}