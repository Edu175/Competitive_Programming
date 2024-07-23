#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int n;
	cin>>n;
	map<char,string> m[5];
	
	m[0]['A']="***";
	m[0]['B']="***";
	m[0]['C']="***";
	m[0]['D']="***";
	m[0]['E']="***";
	
	m[1]['A']="*.*";
	m[1]['B']="*.*";
	m[1]['C']="*..";
	m[1]['D']="*.*";
	m[1]['E']="*..";
	
	m[2]['A']="***";
	m[2]['B']="***";
	m[2]['C']="*..";
	m[2]['D']="*.*";
	m[2]['E']="***";
	
	m[3]['A']="*.*";
	m[3]['B']="*.*";
	m[3]['C']="*..";
	m[3]['D']="*.*";
	m[3]['E']="*..";
	
	m[4]['A']="*.*";
	m[4]['B']="***";
	m[4]['C']="***";
	m[4]['D']="***";
	m[4]['E']="***";
	
	string s; cin>>s;
	fore(i,0,5){
		fore(j,0,SZ(s)){
			cout<<m[i][s[j]];
		}
		cout<<"\n";
	}
	return 0;
}