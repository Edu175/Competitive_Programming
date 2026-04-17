#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 1e5+100;

ll n;
string palabras[MAXN];




set<pair<ll,vv>> st;

void puth(ll szx, ll szy, vv & hx, vv & hy){
	vv h(26,0);
	ll mul = szx/szy;
	ll lon = szx - mul * szy;
	fore(i,0,26) h[i] = hx[i] - hy[i] * mul;
	// cout<<"meto en el set uno con longitudd "<<lon<<endl;
	// cout<<"sz de hx "<<szx<<endl;
	// fore(i,0,26) cout<<hx[i]<<" ";
	// cout<<endl;
	// cout<<"sz de hy "<<szy<<endl;
	// fore(i,0,26) cout<<hy[i]<<" ";
	// cout<<endl;
	// cout<<"entonces "<<endl;
	// fore(i,0,26) cout<<h[i]<<" ";
	// cout<<endl;
	st.insert({lon,h});
}


void put(int x, int y){
	vv hx(26,0), hy(26,0), h(26,0); 
	ll szx = SZ(palabras[x]), szy = SZ(palabras[y]);
	for(auto c:palabras[x])hx[c-'a']++;
	for(auto c:palabras[y])hy[c-'a']++;
	if(szx <= szy){
		fore(i,0,szx)h[palabras[x][i]-'a']++;
		st.insert({szx,h});
		// cout<<"meto en el set uno con longitud "<<szx<<endl;
	}
	else puth(szx,szy,hx,hy);
	
	auto it = st.end(); it--;
	while(SZ(st) && (*it).fst > szy){
		vv hx = (*it).snd;
		puth((*it).fst,szy,hx,hy);	
		// cout<<"saco del set uno con longitud "<<(*it).fst<<endl;
		it = st.erase(it);
		it--;
	}
}


bool b;
string create(){
	string s = "";
	ll ten[26]; mset(ten,0);
	for(auto [l,a] : st){
		// cout<<"viendo condicion con len "<<l<<endl;
		fore(i,0,26){
			// cout<<"letra "<<char(i+'a')<<" hay "<<a[i]<<endl;
			a[i] -= ten[i];
			while(a[i] > 0){
				s.pb(i+'a');
				a[i]--;
				ten[i]++;
				// cout<<"aaaaaaaaaaaaaaaa "<<a[i]<<endl;
			}
			// cout<<"con la letra "<<char(i+'a')<<" me queda "<<a[i]<<" y ten en "<<ten[i]<<endl;
			if(a[i] < 0) b = false;
		}
	}	
	return s;
}

bool compare(string &s, int i){
	string s1 = s, s2 = palabras[i];
	sort(ALL(s1)); sort(ALL(s2));
	// cout<<s1<<" "<<s2<<"\n";
	return s1 == s2;
}

string make(string &s, int i){
	if(i >= n) return "";
	string s1 = "";
	fore(j,0,SZ(palabras[i])) s1.pb(s[j%SZ(s)]);
	return s1;
}

void complete(string &s){
	vv h0(26,0), hs(26,0);
	for(auto c:s) hs[c - 'a']++;
	for(auto c:palabras[0]) h0[c-'a']++;
	fore(i,0,26){
		h0[i] -= hs[i];
		while(h0[i]>0){
			s.pb('a'+i);
			h0[i]--;
		}
	}
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		st.clear();
		b = true;
		cin>>n;
		fore(i,0,n) cin>>palabras[i];
		for(ll i = n-1;i>=1;i--){
			put(i,i-1);
			// cout<<"que carajos pasa "<<endl;
		}		
		// cout<<"asdnoasdn"<<endl;
		string s = create();
		complete(s);
		vector<string> res;
		// cout<<"inicial "<<s<<"\n";
		fore(i,0,n){
			b &= compare(s,i);
			// cout<<"toca comparar "<<s<<" con "<<palabras[i]<<" el booleano esta "<<b<<"\n";
			res.pb(s);
			s = make(s,i+1);
		}
		if(!b) cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(auto x:res) cout<<x<<"\n";
		}
	}
	
	
	
	return 0;
}

