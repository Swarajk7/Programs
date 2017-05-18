#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
class MinCost {
    int max_flow();
    int bfs();
};
int MinCost::max_flow() {
    int result=0;
    while(true) {
        int path_capacity=find_path();
        if(path_capacity==0) break;
        else result+=path_capacity;
    }
    return result;
}
int MinCost::bfs() {
    //do bfs
    //return path_capacity of bfs path

}
int main() {
    return 0;
}
