#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int n; cin>>n;
	int rta=0;
	int a=0,b=0;
	fore(i,0,n){
		ll x; cin>>x;
		if(x%2==0 && x>1 ) a++;
		if(x%2==1) b++;
		if(x%2==1 && x>1){
			rta=2;
		}
	}
	if(rta==2){
		cout<<rta<<"\n";
		return 0;
	}
	if(a) rta++;
	if(b) rta++;
	cout<<rta<<"\n";
	return 0;
}