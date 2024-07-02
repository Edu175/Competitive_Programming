#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

string s;
vi barras;
vi puntos;
int c[100009];

bool checkM(int i, int j);
bool checkH(int i, int j);
bool checkP(int i, int j);
bool checkT(int i, int j);


bool checkM (int i, int j){
	if(i>j) return false;
	if(s[i]=='|') return checkM(i+1,j);
	
	
	auto last=upper_bound(ALL(barras),j);
	if(last!=barras.begin()) last--;
	else return checkP(i,j);
	int pos=*last;
	if(pos<=j && pos>=i) return (checkH(i,pos-1) && checkP(pos+1,j));
	return checkP(i,j);	
}

bool checkH(int i, int j){
	if(i>j) return false;
	if(i<j) return checkM(i,j);
	return s[i]=='$' || checkM(i,j);
}

bool checkP (int i, int j){
	if(i>j) return false;
	auto last=upper_bound(ALL(puntos),j);
	if(last!=puntos.begin()) last--;
	else return checkT(i,j);
	int pos=*last;
	if(pos<=j && pos>=i) return (checkP(i,pos-1) && checkT(pos+1,j));
	return checkT(i,j);	
}

bool checkT (int i, int j){
	if(i>j) return false;
	if(s[i]=='{' && s[j]=='}') return checkM(i+1,j-1);
	return (c[i]==j);
}

int main(){
	JET
	string aux;
	mset(c,-1);
	while(cin>>aux){
		s+=aux;
		if(aux[SZ(aux)-1]<='9' && aux[SZ(aux)-1]>='0'){
			s+=".";
		}
		
	}
	bool b=false;
	int auxi=0;
	fore(i,0,SZ(s)){
		if(s[i]=='|') barras.pb(i);
		if(s[i]==':') puntos.pb(i);
		if(s[i]<='9' && s[i]>='0' && !b){
			b=true;
			auxi=i;
		}
		if((s[i]>'9' || s[i]<'0') && b){
			if(s[i]=='.'){
				c[auxi]=i;
				b=false;
			}
			else{
				c[auxi]=i-1;
				b=false;
			}
			
		}
	}
	if(b){
		assert(0);
		// c[auxi]=SZ(aux)-1;
	}
	if(checkM(0,SZ(s)-1)) cout<<"YES\n";
	else cout<<"NO\n";
}