#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	int f,a,b,c,n,m;
	cin>>f>>a>>b>>c>>n>>m;
	int tab[n][m];
	map<int,int> oc;
	fore(i,0,n) fore(j,0,m) cin>>tab[i][j];
	fore(i,0,n) fore(j,0,m) oc[tab[i][j]]++;
	vector<ii> func(SZ(oc));
	func[0]={f,0};
	fore(i,1,SZ(oc)){
		int val=((a*func[i-1].fst+b)%c)+1;
		func[i]={val,i};
	}
	sort(ALL(func));
	vector<ii> val;
	for(auto x:oc){
		val.pb({x.snd,x.fst});
	}
	sort(ALL(val));
	cout<<SZ(oc)<<"\n";
	vv rta(SZ(oc));
	fore(i,0,SZ(oc)){
		rta[func[i].snd]=val[i].snd;
	}
	for(auto x:rta) cout<<x<<" ";
	cout<<"\n";
	return 0;
}
