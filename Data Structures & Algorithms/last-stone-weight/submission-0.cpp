class Solution {
    priority_queue<int> p;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int s:stones){
            p.push(s);
        }
        while(p.size()>1){
            int first=p.top();
            p.pop();
            int second=p.top();
            p.pop();
            if(second!=first){
                p.push(first-second);
            }
        }
        return p.empty()?0:p.top();
    }
};
