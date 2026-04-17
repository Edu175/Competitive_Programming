#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<string> S(20);
int main(){
	JET
	cout<<"20 20\n";
	fore(i,0,20){
		S[i]=string(20,(i&1?'1':'0'));
	}
	fore(i,0,10){
		S[2*i][(i&1)?0:19]='1';
	}
	S[0]="01010101010101010101";
	fore(i,0,20)cout<<S[i]<<"\n";
	return 0;
}