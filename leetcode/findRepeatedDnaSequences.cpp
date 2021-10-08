#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;
//187. 重复的DNA序列
vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> m;
        int n=s.size();
        for(int i=0;i<=n-10;++i){
            string sb=s.substr(i,10);
            m[sb]++;
            if(m[sb]==2){
                ans.push_back(sb);
            }
        }
        return ans;
}

int main(){
    string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans;
    ans=findRepeatedDnaSequences(s);
    
    for(auto& str:ans){
        cout<<"ans = " << str<<endl;
    }
    return 0;
}