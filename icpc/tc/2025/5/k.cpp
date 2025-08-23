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

int main(){
	JET
	ll r,x1,x2,y1,y2;
	cin>>r>>x1>>y1>>x2>>y2;
	ll tot = (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
	ll aux = sqrt(tot);
	if(aux*aux<tot) aux++;
	else assert(aux*aux == tot);
	r*=2;
	cout<<(aux+r-1)/r<<"\n";
	return 0;
}