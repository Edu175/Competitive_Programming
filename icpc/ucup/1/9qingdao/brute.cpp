#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
vector<vv> mats;

ll n,k;

vector<vv> a;
vector<vv>b;
void cand(){
	//cout<<"cand\n";
	if(!SZ(b)||a<b)b=a;
}
bool good(){
	/*cout<<"good?\n";
	fore(i,0,k){
		fore(j,0,n){
			if(j)cout<<" ";
			cout<<a[i][j];
		}
		cout<<"\n";
	}*/
	fore(i,0,n){
		set<ll>st;
		fore(j,0,k)st.insert(a[j][i]);
		if(SZ(st)!=k){/*cout<<"arista repe\n";*/return 0;}
	}
	fore(i,0,k)fore(j,i+1,k){
		fore(x,0,n){
			ll y=a[j][x];
			ll X=a[i][x],Y=a[i][y];
			if(a[j][X]!=Y){/*cout<<"condicion rara\n";*/return 0;}
		}
	}
	return 1;
}
void f(ll i){ // -1 is first
	if(SZ(a)==k){
		if(good())cand();
		return;
	}
	fore(j,i+1,SZ(mats)){
		a.pb(mats[j]);
		f(j);
		a.pop_back();
	}
}

int main(){
	JET
	ll t; cin>>t;
	cin>>n>>k;
	vv per(n); iota(ALL(per),0);
	do{
		ll fg=1;
		fore(i,0,n)fg&=(per[i]!=i&&per[per[i]]==i);
		if(fg)mats.pb(per);
	}while(next_permutation(ALL(per)));
	/*for(auto v:mats){
		for(auto i:v)cout<<i<<" ";;cout<<"\n";
	}*/
	f(-1);
	if(!SZ(b)){
		cout<<"Impossible\n";
	}
	else {
		fore(i,0,k){
			fore(j,0,n){
				if(j)cout<<" ";
				cout<<b[i][j]+1;
			}
			cout<<"\n";
		}
	}
	return 0;
}