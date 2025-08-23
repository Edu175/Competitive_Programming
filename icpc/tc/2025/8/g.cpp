#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<vector<ii>> d={
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,1},{1,0},{1,1}}
};

int main(){
	JET
	string s,s1;
	cin>>s>>s1;
	ll n = SZ(s);
	vector<vv> a(n+1,vv(2));
	// ll a[n+1][2];
	fore(i,0,n){
		a[i][0] = (s[i]!='X');
		a[i][1] = (s1[i]!='X');
	}
	a[n][0] = 0;
	a[n][1] = 0;
	ll cnt = 0;
	bool b = false;
	fore(i,0,n){
		// cout<<"asdnoasbd  "<<i<<" "<<n<<endl;
		if(i == 1 && b) break;
		if(i== 1) b =true;
		for(auto trio:d){
			auto x = trio[0];
			auto y = trio[1];
			auto z = trio[2];
			if(a[i+x.fst][x.snd] && a[i+y.fst][y.snd] && a[i+z.fst][z.snd]){
				cnt++;
				a[i+x.fst][x.snd] = 0;
				a[i+y.fst][y.snd] = 0;
				a[i+z.fst][z.snd] = 0;
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
}