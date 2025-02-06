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
const ll B=15;

ll n;
vv ask(string s){
	cout<<"QUERY "<<s<<endl;
	vv ret(n);
	fore(i,0,n)cin>>ret[i];
	return ret;
}

int main(){
	JET
	cin>>n;
	vv deg(n);
	deg=ask(string(n,'1'));
	
	ll h[n][B]; mset(h,0);
	fore(j,0,B){
		string s(n,'0');
		fore(i,0,n)s[i]+=i>>j&1;
		vv r=ask(s);
		fore(i,0,n)h[i][j]=r[i];
	}
	queue<ll>q;
	fore(i,0,n)if(deg[i]==1)q.push(i);
	vector<ii>ed;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(deg[x]==0)continue;
		ll y=0;
		fore(j,0,B)y+=h[x][j]<<j;
		ed.pb({x,y});
		deg[y]--;
		fore(j,0,B)h[y][j]-=x>>j&1;
		if(deg[y]==1)q.push(y);
	}
	cout<<"ANSWER\n";
	for(auto [x,y]:ed)cout<<x+1<<" "<<y+1<<"\n";
	return 0;
}

/*

5
QUERY 11111
1 1 1 3 2
QUERY 01010
1 1 0 1 1
QUERY 00110
1 1 0 0 2
QUERY 00001
0 0 1 1 0
QUERY 00000
0 0 0 0 0 
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
QUERY 00000
0 0 0 0 0
ANSWER
1 4
2 4
3 5
4 5
5 1



*/