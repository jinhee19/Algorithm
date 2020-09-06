#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int checked[9] = { 0 }; // 사용된 user_id check 용도
int user_size;
int banned_size;
set<vector<int>> list;
vector<int> id_set;
vector<int> set_copy;
vector<string> user_list;
vector<string> banned_list;

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

// user_id가 banned_id와 일치하는지(*제외)
bool isMatch(string user, string banned){ 
    string star = "*";
    int num = 0;
    
    if(user.size() != banned.size())
        return false;
    
    for (int i = 0; i < banned.size(); i++) {
		if (banned.compare(i, 1, star, 0, 1) == 0){
            num++;
			continue;
        }
		if (user.compare(i, 1, banned, i, 1) == 0)
            num++;
	}

    if(num == banned.size())
        return true;
    else
        return false;
}


void find_case(int loc, int count){    
    if(count == banned_size){
        set_copy = id_set;
        sort(set_copy.begin(), set_copy.end());
        list.insert(set_copy);
        return;
    }
    
    for(int i = 0; i < user_size; i++){
        if(isMatch(user_list[i], banned_list[loc]) && checked[i] == 0){
            checked[i] = 1;
            id_set.push_back(i);
            find_case(loc+1, count+1);
            id_set.pop_back();
            checked[i] = 0;
        }        
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user_size = user_id.size();
    banned_size = banned_id.size();
    
    user_list = user_id;
    banned_list = banned_id;
    
    find_case(0, 0);
    
    answer = list.size();
    return answer;
}
