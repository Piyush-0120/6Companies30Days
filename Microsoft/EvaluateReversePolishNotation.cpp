// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Reverse Polish notation (RPN)is a mathematical notation in which operators follow their operands.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>s;
        map<string,int>m;
        m["+"]=0;
        m["-"]=1;
        m["*"]=2;
        m["/"]=3;
        
        for(auto it:tokens){
            if(it=="+" ||it=="-" ||it=="*" ||it=="/"){
                int n1=s.top();
                s.pop();
                int n2= s.top();
                s.pop();

                switch(m[it]){
                    case 0 : s.push(n2+n1);break;
                    case 1 : s.push(n2-n1);break;
                    case 2 : s.push(1ll*n2*n1);break; // to avoid integer overflow error.
                    case 3 : s.push(n2/n1);break;
                }
            }
            else{
                s.push(stoi(it)); // converting string to integer
            }
        }
        return s.top();
    }
};