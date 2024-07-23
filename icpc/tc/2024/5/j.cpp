#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	string s;
	cin>>s;
	int i=SZ(s)-1;
	int cnt=0;
	ll res=0;
	ll aux=0;
	ll vs=0;
	bool y=false;
	while(i>=0){
		if(s[i]=='v'){
			cnt++;
			y=true;
		}
		else{
			if(y){y=false;
			res+=(cnt-1)*aux;
			vs+=max(cnt-1,0);
			cnt=0;
			}
			aux+=vs;
		}
		i--;
	}
	if(s[0]=='v'){
		res+=(cnt-1)*aux;
	}
	cout<<res<<"\n";
	
}