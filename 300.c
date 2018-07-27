class Solution {
public:
    int find(vector<int>&a,int low,int high,int key){
        if(low>high) return -1;
        while(low<=high){
		    if(a[high] < key ) return high+1;
		    if(a[low] > key) return low;
		    int mid=(low+high)/2;
		    if(a[mid]==key) return -1;//说明已经在序列中
		    if(a[mid] > key) high = mid;
		    else low = mid+1;
	    }
	    return -1;
    }
 
    int lengthOfLIS(vector<int>&nums){
	    int len=nums.size();
	    if(len==0) return 0;
	    vector<int> s(len+1);
	    s[1]=nums[0];
	    int pos=1;
	    for(int i=1;i<len;i++){
		    int tmp=find(s,1,pos,nums[i]);
		    if(tmp==-1) continue;
		    else s[tmp]=nums[i];
		    if(tmp==pos+1) pos++;
	    }
	    return pos;
    }
};