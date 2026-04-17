#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<vv> strat={
//	 a,b,c,d
	{0,1,0,1},
	{2,0,1,0},
	{0,2,0,1},
	{2,0,2,0}
};
vector<string> colors={"red", "green", "blue"};
ll trad(string s){return find(ALL(colors),s)-colors.begin();}
void first(ll t){
	while(t--){
		vv a(4);
		fore(i,0,4){
			string s; cin>>s;
			a[i]=trad(s);
		}
		ll wh=-1;
		fore(i,0,4){
			ll s=0;
			fore(j,0,4)s+=strat[i][j]*a[j];
			s%=3;
			if(s==a[i])wh=i;
		}
		assert(wh!=-1);
		cout<<wh+1<<endl;
	}
}
void second(ll t){
	while(t--){
		ll p; string sl,sr; cin>>p>>sl>>sr; p--;
		ll l=trad(sl),r=trad(sr);
		vv a(4);
		a[(p-1+4)%4]=l;
		a[(p+1)%4]=r;
		ll c=0;
		fore(i,0,4)c+=strat[p][i]*a[i];
		c%=3;
		cout<<colors[c]<<endl;
	}
}

int main(){
	// JET
	ll t,s; cin>>t>>s;
	if(s==1)first(t);
	else second(t);
	return 0;
}