#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	// int n; cin>>n;
	string s; cin>>s;
	int n=SZ(s);//; cin>>n;
	vector<string> bolitas;
	vector<string> palitos;
	string aux="";
	int i=0;
	int acc=0;
	while(i<n){
		if(i>0 && s[i]==s[i-1])acc++;
		else acc=1;
		if(i>=n-2) aux.pb(s[i]);
		else if(s[i]==s[i+2]){
			if(s[i]=='X' && s[i+1]=='I'){
				if(acc%3==1){
					bolitas.pb(aux);
					i+=2;
					palitos.pb("XIX");
					aux.clear();
					acc=1;					
				}
				else{
					int j=i+2;
					while(j<n-2 && s[j+1]=='I' && s[j+2]=='X') j+=2;
					j-=2;
					while(i<j){
						aux.pb(s[i]);
						i++;
					}
					bolitas.pb(aux);
					i+=2;
					palitos.pb("XIX");
					aux.clear();
					acc=1;
				}
			}
			else if(s[i]=='C' && s[i+1]=='X'){
				if(acc%3==1){
					bolitas.pb(aux);
					i+=2;
					palitos.pb("CXC");
					aux.clear();	
					acc=1;				
				}
				else{
					int j=i+2;
					while(j<n-2 && s[j+1]=='X' && s[j+2]=='C') j+=2;
					j-=2;
					while(i<j){
						aux.pb(s[i]);
						i++;
					}
					bolitas.pb(aux);
					i+=2;
					palitos.pb("CXC");
					aux.clear();
					acc=1;
				}
			}
			else if(s[i]=='M' && s[i+1]=='C'){
				if(acc%3==1){
					bolitas.pb(aux);
					i+=2;
					palitos.pb("MCM");
					aux.clear();	
					acc=1;				
				}
				else{
					int j=i+2;
					while(j<n-2 && s[j+1]=='C' && s[j+2]=='M') j+=2;
					j-=2;
					while(i<j){
						aux.pb(s[i]);
						i++;
					}
					bolitas.pb(aux);
					i+=2;
					palitos.pb("MCM");
					aux.clear();
					acc=1;
				}
			}
			else aux.pb(s[i]);
		}
		else aux.pb(s[i]);
		i++;
	}
	vector<string> rta;
	fore(i,0,SZ(palitos)){
		int j=0;
		string a=bolitas[i];
		while(j<SZ(a)){
			string agg="";
			if(a[j]=='V' || a[j]=='D' ||a[j]=='L'){
				agg.pb(a[j]);
				rta.pb(agg);
				j++;	
			}
			else{
				if(j<SZ(a)-2 && a[j+1]==a[j] && a[j+2]==a[j]){
					agg.pb(a[j]);
					agg.pb(a[j]);
					agg.pb(a[j]);
					rta.pb(agg);
					j+=3;
				}
				else if(j<SZ(a)-1 &&a[j+1]==a[j]){
					agg.pb(a[j]);
					agg.pb(a[j]);
					rta.pb(agg);
					j+=2;
				}
				else{
					agg.pb(a[j]);
					rta.pb(agg);
					j++;
				}
			}
		}
		rta.pb(palitos[i]);
	}
	int j=0;
	while(j<SZ(aux)){
		string agg="";
		if(aux[j]=='V' || aux[j]=='D' ||aux[j]=='L'){
			agg.pb(aux[j]);
			rta.pb(agg);
			j++;	
		}
		else{
			if(j<SZ(aux)-2 && aux[j+1]==aux[j] && aux[j+2]==aux[j]){
				agg.pb(aux[j]);
				agg.pb(aux[j]);
				agg.pb(aux[j]);
				rta.pb(agg);
				j+=3;
			}
			else if(j<SZ(aux)-1 &&aux[j+1]==aux[j]){
				agg.pb(aux[j]);
				agg.pb(aux[j]);
				rta.pb(agg);
				j+=2;
			}
			else{
				agg.pb(aux[j]);
				rta.pb(agg);
				j++;
			}
		}
	}
	set<string> se;
	se.insert("I");
	se.insert("II");
	se.insert("III");
	se.insert("V");
	se.insert("X");
	se.insert("XX");
	se.insert("XXX");
	se.insert("XIX");
	se.insert("L");
	se.insert("C");
	se.insert("CC");
	se.insert("CCC");
	se.insert("CXC");
	se.insert("D");
	se.insert("M");
	se.insert("MM");
	se.insert("MMM");
	se.insert("MCM");
	int aaa=0;
	string rec;
	for(auto x:rta){
		assert(se.count(x));
		aaa+=SZ(x);
		rec+=x;
	}
	assert(aaa==n);
	assert(rec==s);
	cout<<SZ(rta)<<"\n";
	for(auto x:rta) cout<<x<<"\n";
}