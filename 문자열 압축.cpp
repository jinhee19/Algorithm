#include <string>
#include <vector>
#include <iostream>

using namespace std;

int len[1001] = {0};

int solution(string s) {
    int answer = 0;
    answer = s.size();
    int size;
    int a = 1;
    string words;
    string new_s;
    vector<string> v;
    
    for(int i = 1; i < s.size(); i++){ // 문자열 자르는 개수
        if(s.size()/i == 0)
            size = s.size();
        else
            size = s.size()/i + 1;
    
        for(int j = 0; j < size; j++){ // 새롭게 문자열 생성
            words = s.substr(j*i, i);
            v.push_back(words);   
        }
        
        for(int k = 0; k < v.size()-1; k++){
            if(v[k].compare(v[k+1]) == 0)
                a += 1;
            else{
                if(a == 1)
                    new_s += v[k];
                else
                    new_s += to_string(a) + v[k];
                a = 1;
            }
        }
        new_s += v[v.size()-1];
        
        v.clear();
        if(answer > new_s.size())
            answer = new_s.size();
        new_s = "";
    }
    
    return answer;
}
