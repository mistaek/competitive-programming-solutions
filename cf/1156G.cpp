/*
1156G
AC!!!!
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 
struct Line; 
vector<Line> lines; 
vector<string> ans; 
map<string, string> aEQa; //maps variable to its current equivalent
map<string, string> bEQa; //maps expression to its variable
map<string, int> lineOf; // maps variable to the line it refers to 
map<string, bool> built; //whether the var has been built

string getNextVariableName(){
    static int curVarName = 1; 
    auto genName = [&](){
        int cur = curVarName++; 
        string name; 
        while(cur){
            name.push_back((char)('a' + cur%26)); 
            cur /= 26; 
        } 
        return name; 
    };

    string name; 
    do{
        name = genName(); 
    } while(aEQa.find(name) != aEQa.end());
    return name; 
}

string getEquivVar(const string& var){
    if(aEQa.find(var) == aEQa.end()){
        aEQa[var] = var; 
    }
    return aEQa[var]; 
}

int getLineOf(const string& var){
    if(lineOf.find(var) == lineOf.end()){
        lineOf[var] = -1; 
    }
    return lineOf[var];
}

string getVarOf(const string& expr){
    if(bEQa.find(expr) == bEQa.end()){
        //build a new variable for this expr
        bEQa[expr] = getNextVariableName(); 
    }
    return bEQa[expr]; 
}


struct Line{
    string lhs, rhs1, rhs2, op; 

    Line(int lineNum, const string& s){
        auto eqpos = s.find_first_of("="); 
        lhs = s.substr(0, eqpos); 
        auto oppos = s.find_first_of("&#$^"); 
        if(oppos == string::npos){
            rhs1 = s.substr(eqpos+1); 
            rhs1 = getEquivVar(rhs1); 
            aEQa[lhs] = rhs1; 
        }
        else{
            rhs1 = s.substr(eqpos+1, oppos - eqpos-1); 
            op = s[oppos]; 
            rhs2 = s.substr(oppos+1); 
            rhs1 = getEquivVar(rhs1); rhs2 = getEquivVar(rhs2); 
            aEQa[lhs] = getVarOf(rhs1 + op + rhs2); // unique variable
            lineOf[aEQa[lhs]] = lineNum; 
            //cout << aEQa[lhs] << " ASSIGNED " << rhs1 + op + rhs2 << "\n";
        }
    }

    string rhs(){ return rhs1 + op + rhs2;}
};

void build(int lineNum, const string& var){
    // builds the RHS of line lineNum, then assigns it to var
    if(lineNum == -1){
        return; 
    }
    if(built[var]) return; 
    Line& line = lines[lineNum]; 
    build(getLineOf(line.rhs1), line.rhs1); 
    if(line.op != "") build(getLineOf(line.rhs2), line.rhs2); //builds the rhs of current equation
    ans.push_back(var + "="+line.rhs()); 
    built[var] = true; 
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n; cin >> n; 
    vector<string> strs(n); 
    for(int i = 0; i < n; ++i){
        //reserve var names
        cin >> strs[i]; 
        auto eqpos = strs[i].find_first_of("="); 
        auto oppos = strs[i].find_first_of("&#$^");     
        string lhs = strs[i].substr(0, eqpos); 
        aEQa[lhs] = lhs; 
        if(oppos != string::npos){
            string rhs = strs[i].substr(eqpos+1, oppos - eqpos - 1); 
            aEQa[rhs] = rhs; 
            rhs = strs[i].substr(oppos+1); 
            aEQa[rhs] = rhs; 
        }
        else{
            string rhs = strs[i].substr(eqpos+1); 
            aEQa[rhs] = rhs; 
        }
    }
    for(int i = 0; i < n; ++i){

        lines.push_back(Line(i, strs[i])); 

    }

    //for(auto&[k, v] : aEQa) cout << k << " " << v << "\n";

    if(aEQa.find("res") == aEQa.end() || aEQa["res"] == "res"){
        cout << 0 << "\n"; 
    }
    else{
        if(getLineOf(aEQa["res"]) != -1)build(getLineOf(aEQa["res"]), "res");
        else ans.push_back(std::string("res=")+aEQa["res"]); 
        cout << ans.size() << "\n"; 
        for(string& s : ans) cout << s << "\n";
    }
    return 0;
}