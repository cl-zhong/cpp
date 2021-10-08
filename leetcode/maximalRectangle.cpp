#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;
//85. 最大矩形
int maximalRectangle(vector<vector<char>>& matrix) {
    //暴力法
    int m=matrix.size();
    if(m==0) return 0;
    int n=matrix[0].size();
    vector<vector<int>> left(m,vector<int>(n,0));
    for(int i=0;i<m;++i){
        if(matrix[i][0]=='1'){
            left[i][0]=1;
        }
    }
    for(int i=0;i<m;++i){
        for(int j=1;j<n;++j){
            if(matrix[i][j]=='1'){
                left[i][j]=left[i][j-1]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(matrix[i][j]=='0') continue;
            int width=left[i][j];
            int area=width;
            for(int k=i-1;k>=0;--k){
                width=min(width,left[k][j]);
                area=max(area,width*(i-k+1));
            }
            ans=max(ans,area);
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},
                                    {'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans=maximalRectangle(matrix);
    cout<<"ans = "<< ans<<endl;
    return 0;
}