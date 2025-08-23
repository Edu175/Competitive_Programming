#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

map<char, int> cnt;

ll f(string s1, string aton){
	map<char,int> aux;
	for(auto [x,y] : cnt) aux[x] = y;
	map<char, int> ord;
	fore(i,0,SZ(aton)) ord[aton[i]] = i;
	ll r = 0;
	fore(i,0,SZ(s1)){
		ll o = ord[s1[i]];
		for(auto [x,y] : aux){
			if(ord[x] < o) r+=y;
		}
		aux[s1[i]]--;
	}
	return r;
}

int main(){
	JET
	ll te; cin>>te;
	while(te--){
		cnt.clear();
		string s; cin>>s;
		string aton = "ANOT";
		for(auto x:s) cnt[x]++;
		ll m = 0;
		string rta = s;
		do{
			string res = "";
			for(auto c:aton){
				fore(i,0,cnt[c]) res.pb(c);
			}
			ll x = f(s, aton);
			if(x > m){
				m = x;
				rta = res;
			}
		}while(next_permutation(ALL(aton)));
		cout<<rta<<"\n";
	}
	return 0;
}