#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long max_sum = 0;

long long calculate(long long a, long long b, char op){
    switch(op){
        case '+' : 
            return a + b;
        case '-' :
            return a - b;
        case '*' : 
            return a * b;         
    }
}

void do_calculate(string op, vector<string> ex){
    string s = "";
    long long result;
    
    for(int i = 0; i < 3; i++){
        s = op[i];
        for(int j = 0; j < ex.size(); j++){
            if(ex[j] == s){
                result = calculate(stoll(ex[j-1]), stoll(ex[j+1]), op[i]);
                ex.erase(ex.begin() + j-1, ex.begin() + j+2);
                ex.emplace(ex.begin() + j-1, to_string(result));
                j = 0;
            }
        }
        s = "";
    }
    
    result = stoll(ex[0]);
    if(result < 0)
        result = -result;

    if(max_sum < result)
        max_sum = result;
    
    return;
}

long long solution(string expression) {
    long long answer = 0;
    string s = "";
    string a = "";
    vector<string> total;
    vector<string> ex;
    
    // 문자열에서 피연산자랑 연산자 구분
    for(int i = 0; i <= expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            total.push_back(s);
            a += expression[i];
            total.push_back(a);
            s = "";
            a = "";
        }
        else
            s+= expression[i];
    }
    total.push_back(s);
    
    ex = total;
    
    do_calculate("+-*", ex);
    do_calculate("+*-", ex);
    do_calculate("-+*", ex);
    do_calculate("-*+", ex);
    do_calculate("*+-", ex);
    do_calculate("*-+", ex);
    
    answer = max_sum;
    return answer;
}
