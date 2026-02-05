#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

map<char,string> par;
map<string,char> ser;
map<char,char> op;

void init(){
    par['0'] = "0000";
    ser["0000"] = '0';
    op['0'] = 'F';

    par['1'] = "0001";
    ser["0001"] = '1';
    op['1'] = 'E';

    par['2'] = "0010";
    ser["0010"] = '2';
    op['2'] = 'D';

    par['3'] = "0011";
    ser["0011"] = '3';
    op['3'] = 'C';

    par['4'] = "0100";
    ser["0100"] = '4';
    op['4'] = 'B';

    par['5'] = "0101";
    ser["0101"] = '5';
    op['5'] = 'A';

    par['6'] = "0110";
    ser["0110"] = '6';
    op['6'] = '9';

    par['7'] = "0111";
    ser["0111"] = '7';
    op['7'] = '8';

    par['8'] = "1000";
    ser["1000"] = '8';
    op['8'] = '7';

    par['9'] = "1001";
    ser["1001"] = '9';
    op['9'] = '6';

    par['A'] = "1010";
    ser["1010"] = 'A';
    op['A'] = '5';

    par['B'] = "1011";
    ser["1011"] = 'B';
    op['B'] = '4';

    par['C'] = "1100";
    ser["1100"] = 'C';
    op['C'] = '3';

    par['D'] = "1101";
    ser["1101"] = 'D';
    op['D'] = '2';

    par['E'] = "1110";
    ser["1110"] = 'E';
    op['E'] = '1';

    par['F'] = "1111";
    ser["1111"] = 'F';
    op['F'] = '0';
}

void enc(string s){
    string extra = "";
    for(ll i = 0;i<16;i+=2){
        extra.pb(par[s[i]][0]);
        // cout<<"andoisando   "<<s[i]<<" "<<par[s[i]]<<"\n";
    }
    cout<<s;
    string ex1 = "", ex2 = "";
    fore(i,0,4) ex1.pb(extra[i]);
    fore(i,4,8) ex2.pb(extra[i]);
    cout<<ser[ex1]<<ser[ex2]<<"\n";
}

void dec(string s){
    string check = "";
    for(ll i = 0;i<16;i+=2) check.pb(par[s[i]][0]);
    ll mistakes = 0;
    string nueve = par[s[16]] + par[s[17]];
    fore(i,0,8) if(nueve[i] != check[i]) mistakes++;
    if(mistakes >= 5) fore(i,0,8) nueve[i] ^= 1;
    fore(i,0,8) if(nueve[i] != check[i]){
        s[2*i] = op[s[2*i]];
        s[2*i+1] = op[s[2*i+1]];
    }
    fore(i,0,16) cout<<s[i];
    cout<<"\n";
}

int main(){
    JET
    init();
    ll t; cin>>t;
    string w; cin>>w;
    bool e = w[0] == 'e';
    while(t--){
        string s; cin>>s;
        e ? enc(s) : dec(s);
    }
    return 0;
}
