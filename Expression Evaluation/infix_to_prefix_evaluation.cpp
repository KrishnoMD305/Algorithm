#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;

int precedence(char c){
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }

    return 0;
}

string rev_str(string str){
    string res = "";
    for(int i=str.size()-1; i>=0; i--){
        if(str[i]=='('){
            res += ')';
        }else if(str[i]==')'){
            res += '(';
        }else{
            res += str[i];
        }
    }
    return res;
}

string inf_to_pre(string inf){
    stack<char> op;
    string ans;
    string rev = rev_str(inf);
    int n = inf.size();
    
    for(int i=0; i<n; i++){
        if(isspace(rev[i])){
            continue;
        }
        if(isdigit(rev[i])){
            while(i<n && isdigit(rev[i])){
                ans += rev[i];
                i++;
            }
            ans += " ";
            i--;
        }else if(rev[i]=='('){
            op.push(rev[i]);
        }else if(rev[i]==')'){
            while(!op.empty() && op.top() != '('){
                ans += op.top();
                ans += " ";
                op.pop();
            }
            op.pop();
        }else{
            while(!op.empty() && precedence(op.top()) > precedence(rev[i])){
                ans += op.top();
                ans += " ";
                op.pop();
            }
            op.push(rev[i]);
        }
    }
    while(!op.empty()){
        ans += op.top();
        ans += " ";
        op.pop();
    }
    string final = rev_str(ans);
    
    return final;
}

int evaluate_prefix(string exp){
    stack<int> num;
    vector<string> tok;
    string str;
    stringstream ss(exp);
    while(ss >> str){
        tok.push_back(str);
    }

    for(int i=tok.size()-1; i>=0; i--){
        if(isdigit(tok[i][0])){
            num.push(stoi(tok[i]));
        }else{
            int first = num.top();
            num.pop();
            int second = num.top();
            num.pop();
            if(tok[i]=="+"){
                num.push(first+second);
            }else if(tok[i]=="-"){
                num.push(first-second);
            }else if(tok[i]=="*"){
                num.push(first*second);
            }else if(tok[i]=="/"){
                num.push(first/second);
            }
        }
    }

    return num.top();

}

int main(){
    string str = "8+9*(2+5)/3 ";
    string result = inf_to_pre(str);
    cout<<result<<endl;
    int sum = evaluate_prefix(result);
    cout<<sum<<endl;
    return 0;
}
