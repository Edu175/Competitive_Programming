#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
vector<string> s={"GGGgGGG","gggggGG","gGGGGGg","ggGGGGG","GggGgGG","GgGGGgG","GGGGGgG","ggGggGG","GGGGGGG","GgGGGGG"};
bool comp(ll i, string &w){
	fore(j,0,7){
		assert(( SZ(w)==7 && SZ(s[i])==7));
		if(w[j]=='G'||w[j]=='g'){
			if(w[j]!=s[i][j]) return false;
		}
	}
	return true;
}
int main(){
	JET
	ll n; cin>>n;
	string r="";
	//cout<<int('*')<<" "<<int('9')<<"\n";
	fore(i,0,n){
		string w; cin>>w;
		char t=80;
		fore(j,0,10){
			if(comp(j,w)) {
				if(t<='9') t='*';
				else t='0'+j;
			}
		}
		if(t>'9') t='*';
		r.pb(t);	
	}
	cout<<r<<"\n";
	return 0;
}