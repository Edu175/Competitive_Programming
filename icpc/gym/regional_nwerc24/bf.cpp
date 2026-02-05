#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MX=60;

int a[3][3],rs[3],cs[3],ds1[2],ds2[2];
// int cnt[MX];
vector<array<array<ll,3>,3>> all[MX];
ll tle=0; int ant=0,got=0;
void f(int i, int j){
	// cout<<i<<" "<<j<<"\n";
	tle++;
	if(clock()-ant>CLOCKS_PER_SEC*5){
		ant=clock();
		cerr<<tle<<": "<<got<<"\n";
		cerr<<i<<" "<<j<<"\n";
		fore(i,0,3){
			fore(j,0,3)cerr<<a[i][j]<<" ";
			cerr<<"\n";
		}
		cerr<<endl;
	}
	if(i==2&&j&&cs[j-1]!=rs[0])return;
	if(j==3){
		if(i&&rs[i]!=rs[0])return;
		f(i+1,0);
		return;
	}
	if(i==3){
		if(ds1[1]!=rs[0])return;
		// cnt[rs[0]]++;
		got++;
		array<array<ll,3>,3> cur;
		fore(i,0,3)fore(j,0,3)cur[i][j]=a[i][j];
		all[rs[0]].pb(cur);
		return;
	}
	if(i==2&&j==1&&ds2[1]!=rs[0])return;
	fore(v,0,MX-max(rs[i],cs[j])){
		a[i][j]=v;
		rs[i]+=v; cs[j]+=v;
		int w1=(i==j);
		int w2=(i+j==2);
		ds1[w1]+=v; ds2[w2]+=v;
		if((w1&&ds1[w1]>=MX)||(w2&&ds2[w2]>=MX)){
			rs[i]-=v; cs[j]-=v;
			ds1[w1]-=v; ds2[w2]-=v;
			break;
		}
		f(i,j+1);
		rs[i]-=v; cs[j]-=v;
		ds1[w1]-=v; ds2[w2]-=v;
	}
}

int main(){
	JET
	f(0,0);
	fore(s,0,MX){
		auto v=all[s];
		cout<<"sum "<<s<<": "<<SZ(v)<<"\n";
		for(auto &a:v){
			fore(i,0,3)fore(j,0,3)cout<<a[i][j]<<" \n"[j==2];
			cout<<"\n";
		}
		cout<<"\n\n";
	}
	return 0;
}