#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	int n;
	cin>>n;
	int ax,ay; cin>>ax>>ay;
	int bx,by; cin>>bx>>by;
	int cx,cy; cin>>cx>>cy;
	if(cx==ax || cy==ay || bx==ax || by==ay || abs(ax-cx)==abs(ay-cy) || abs(ax-bx)==abs(ay-by)) {cout<<"NO\n"; return 0;}
	if(cx>ax && bx>ax){
		if((cy>ay && by>ay) || (cy<ay && by<ay)){
			cout<<"YES\n"; return 0;
		}
	}
	if(cx<ax && bx<ax){
		if((cy>ay && by>ay) || (cy<ay && by<ay)){
			cout<<"YES\n"; return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}