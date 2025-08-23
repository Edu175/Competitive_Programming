#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
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

ll a[10][10];
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		ll d,l,r,c; cin>>d>>l>>r>>c;
		r--,c--;
		if(d){
			fore(i,0,l){
				if(i+r >= 10 || a[i+r][c]){
					cout<<"N\n";
					return 0;
				}
				a[i+r][c] = 1;
			}	
		}
		else{
			fore(i,0,l){
				if(i+c >= 10 || a[r][i+c]){
					cout<<"N\n";
					return 0;
				}
				a[r][i+c] = 1;
			}
		}
	}
	cout<<"Y\n";
	return 0;
}