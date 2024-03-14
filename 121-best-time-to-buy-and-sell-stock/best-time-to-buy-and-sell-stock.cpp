class Solution {
public:
    int maxProfit(vector<int>& p) {
        int profit=0;
        int mini=p[0];
        for(int i=1;i<p.size();i++){
            int diff=p[i]-mini;
            profit=max(profit,diff);
            mini=min(p[i],mini);
        }
        return profit;
    }
};