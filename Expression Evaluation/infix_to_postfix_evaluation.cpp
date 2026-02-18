#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

int precedence(char ch){
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    return 0;
}

string to_post(string inf){
    stack<char> op;
    string ans = "";
    int n = inf.size();
    for(int i=0; i<n; i++){
        if(isspace(inf[i])){
            continue;
        }
        if(isdigit(inf[i])){
            while(i<n && isdigit(inf[i])){
                ans += inf[i];
                i++;
            }
            ans += " ";
            i--;
        }else if(inf[i]=='('){
            op.push('(');
        }else if(inf[i]==')'){
            while(!op.empty() && op.top() != '('){
                ans += op.top();
                ans += " ";
                op.pop();
            }
            op.pop();
        }else{
            while(!op.empty() && precedence(op.top()) >= precedence(inf[i])){
                ans += op.top();
                ans += " ";
                op.pop();
            }
            op.push(inf[i]);
        }
    }
    while(!op.empty()){
        ans += op.top();
        ans += " ";
        op.pop();
    }

    return ans;
}

int evaluate_post(string exp){
    stack<int> num;
    stringstream ss(exp);
    string tok;

    while(ss >> tok){
        if(isdigit(tok[0])){
            num.push(stoi(tok));
        }else{
            int second = num.top();
            num.pop();
            int first = num.top();
            num.pop();
            if(tok[0]=='+'){
                num.push(first+second);
            }else if(tok[0]=='-'){
                num.push(first-second);
            }else if(tok[0]=='*'){
                num.push(first*second);
            }else if(tok[0]=='/'){
                num.push(first/second);
            }
        }
    }
    return num.top();
}

int main(){
    string inf = "8+9*(2+5)/3 ";
    string ans = to_post(inf);
    cout<<ans<<endl;
    int res = evaluate_post(ans);
    cout<<res<<endl;
    return 0;
}
