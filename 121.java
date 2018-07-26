class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        if(prices.length==0){
            return 0;
        }
        int max = prices[0];
        int min = prices[0];
        int max_index = 0;
        int min_index = 0;
        for(int i=0;i<prices.length;i++){
            if(prices[i]<=min){
                min = prices[i];
                min_index = i;
            }else if(prices[i]>=max || (max_index<=min_index)){
                max = prices[i];
                max_index = i;
            }
            if(max_index>=min_index){
                int temp = max-min;
                profit = profit>=temp?profit:temp;
            }
        }
        return profit;
    }
}