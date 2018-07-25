public class Solution {
    public int reverseBits(int n) {
        int temp=0;
        int i=0;
        for(;i<32;i++)
        {
            temp*=2;
            temp+=((n>>i)&0x01);
        }
        return temp;
    }
}
