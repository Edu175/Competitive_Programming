#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii,
null_type,
less<ii>
,rb_tree_tag,
tree_order_statistics_node_update> 
indexed_set;

ll cnt=0;
vv rel;
vector<string> cod;
map<string,ll> id;
indexed_set st;

void issue(string s){
	if(!id.count(s)||id[s]==-1){ // no existe
		ll idx=cnt++;
		id[s]=idx;
		rel.pb(0);
		cod.pb(s);
		st.insert({0,idx});
		cout<<"CREATED "<<idx<<" 0\n";
	}
	else {
		ll idx=id[s];
		cout<<"EXISTS "<<idx<<" "<<rel[idx]<<"\n";
	}
}
void delet(string s){
	if(!id.count(s)||id[s]==-1){ // no existe
		cout<<"BAD REQUEST\n";
	}
	else {
		ll idx=id[s];
		id[s]=-1;
		st.erase({-rel[idx],idx});
		cout<<"OK "<<idx<<" "<<rel[idx]<<"\n";
	}
}
void increase(string s, ll m){
	if(!id.count(s)||id[s]==-1){ // no existe
		cout<<"BAD REQUEST\n";
	}
	else {
		ll idx=id[s];
		st.erase({-rel[idx],idx});
		rel[idx]+=m;
		st.insert({-rel[idx],idx});
		cout<<"OK "<<idx<<" "<<rel[idx]<<"\n";
	}
}
void find(ll k){
	if(!SZ(st))cout<<"EMPTY\n";
	else {
		k=min(k,SZ(st)-1);
		ll idx=st.find_by_order(k)->snd;
		cout<<"OK "<<cod[idx]<<" "<<idx<<" "<<rel[idx]<<"\n";
	}
}

int main(){
	JET
	ll q; cin>>q;
	while(q--){
		string ty; cin>>ty;
		if(ty=="ISSUE"){
			string s; cin>>s;
			issue(s);
		}
		else if(ty=="DELETE"){
			string s; cin>>s;
			delet(s);
		}
		else if(ty=="RELIABILITY"){
			string s; cin>>s;
			ll m; cin>>m;
			increase(s,m);
		}
		else if(ty=="FIND"){
			ll k; cin>>k;
			find(k);
		}
	}
	return 0;
}
