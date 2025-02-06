#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<char> vc;

vector<vc> alph1={{'q','w','e','r','t','y','u','i','o','p','['},{'a','s','d','f','g','h','j','k','l',';'},{'z','x','c','v','b','n','m',','}};
map<ll,ll> wa;
map<char,ii> m;
int main(){
	JET
	string s; cin>>s;
	set<ll> pos={-1,0,1};
	fore(i,0,26){
		bool e=false;
		fore(j,0,3){
			fore(k,0,SZ(alph1[j])){
				if(i+'a'==alph1[j][k]){
					e=true;
					m[i+'a']=ii({j,k});
					break;
				}
			}
			if(e) break;
		}
	}
	m['[']=ii({0,10});
	
	m[';']=ii({1,9});

	m[',']=ii({2,7});
	
	wa[0]=1;
	wa[1]=1;
	wa[2]=1;
	fore(i,0,SZ(s)){
		if(!m.count(s[i])) {pos.clear(); break;}
		fore(r,-2,3){
			if(r+m[s[i]].snd<0||r+m[s[i]].snd>=SZ(alph1[m[s[i]].fst])-wa[m[s[i]].fst]) pos.erase(r);
		}
	}
	auto it=pos.begin();
	cout<<SZ(pos)<<"\n";
	string r[SZ(pos)];
	fore(i,0,SZ(pos)){
		string w="";
		fore(j,0,SZ(s)){
			auto [k,q]=m[s[j]];
			w.pb(alph1[k][q+*it]);
		}
		r[i]=w;
		it++;
	}
	sort(r,r+SZ(pos));
	fore(i,0,SZ(pos))cout<<r[i]<<"\n";
	return 0;
}