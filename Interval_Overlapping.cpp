#include<bits/stdc++.h>
using namespace std;
 struct Interval {
     int start;
    int end;
  Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public:
    bool static comp(Interval a,Interval b) {
        if (a.end==b.end) { return a.start<=b.start;}
        else return a.end<b.end;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        int s,e;
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end(),Solution::comp);
        s=intervals[0].start;
        e=intervals[0].end;
        vector<Interval> v;
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i].start<=e) {
                e=intervals[i].end;
                s=min(intervals[i].start,s);
            } else {
                v.push_back(Interval(s,e));
                s=intervals[i].start;
                e=intervals[i].end;
            }
        }
        v.push_back(Interval(s,e));
        return v;
    }
};
int main() {
    vector<Interval> v;
    v.push_back(Interval(10,11));
    v.push_back(Interval(0,6));
    Solution s;
    vector<Interval> v1=s.merge(v);
    for(int i=0;i<v1.size();i++) {
        cout<<v1[i].start<<" "<<v1[i].end<<endl;
    }
    return 0;
}
