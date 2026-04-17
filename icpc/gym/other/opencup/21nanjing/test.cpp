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
const ll n=20;
const ll maxl=5e4;
char a[20][20];
random_device rd;
mt19937 rng(rd());
vector<ii> dir={ii({1,0}),ii({0,1}),ii({-1,0}),ii({0,-1})};
ii operator+(ii a, ii b){return ii({a.fst+b.fst,a.snd+b.snd});}
bool check(ii v){
	return (v.fst>=0&&v.fst<n)&&(v.snd>=0&&v.snd<n)&&(a[v.fst][v.snd]=='1');
}
int main(){
	JET
	ll trash; cin>>trash>>trash;
	fore(i,0,n)fore(j,0,n) cin>>a[i][j];
	ll cnt=0;
	fore(_,0,500){
		set<ii> S;
		fore(i,0,n)fore(j,0,n) if(a[i][j]) S.insert((ii){i,j});
		fore(i,0,maxl){
			ii mov=dir[rng()%4];
			set<ii> s;
			for(auto p:S){
				if(check(p+mov)) s.insert(p+mov);
				else s.insert(p);
			}
			swap(s,S);
		}
		cnt+=SZ(S)>1;
		cout<<cnt<<"/"<<(_+1)<<" "<<double(cnt)/double(_+1)<<endl;
	}
	return 0;
}