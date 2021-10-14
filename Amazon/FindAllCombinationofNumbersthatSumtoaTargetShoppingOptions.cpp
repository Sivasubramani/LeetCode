#include <iostream>
#include <vector>
using namespace std;

void combinationSum(int target, int curSum, int start, vector<int> &res, vector<vector<int>> &out){
    if(target == curSum){
        out.push_back(res);
    }

    for(int i=1;i<target;i++){
        int targetSum = curSum +i;
        if(targetSum <= target){
            res.push_back(i);
            combinationSum(target,targetSum,i,res,out);
            res.pop_back();
        }
        else return;
    }

}

int main() {
    cout<<"Combination of sums\n";
    vector<int> res;
    vector<vector<int>> out;
    combinationSum(4,0,1, res,out);
    for(auto a: out){
        for(auto p : a){
            cout<<p<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
