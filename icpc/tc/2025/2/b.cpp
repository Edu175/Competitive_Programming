#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	string s; cin>>s;
	ll a=0,b=0;
	vector<ii>ret;
	for(auto i:s){
		ii par;
		if(i=='1'){ // hor
			if(a==2)a--,par={2,2};
			else par={3-a,0},a++;
		}
		else {
			if(b==2)b--,par={2,2};
			else par={0,3-b},b++;
		}
		ret.pb(par);
	}
	for(auto i:ret)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}