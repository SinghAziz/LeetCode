// Last updated: 16/02/2026, 11:58:27
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int arr[201]={0};
        int num;
        int count=0;
        int index=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]<0){
                num=nums[i];
                if (arr[100+abs(num)]==0){
                cout<<"index: "<<i<<endl;
                count++;
                arr[100+abs(num)]=1;
                nums[index]=num;
                index++;
            }
            }
            else{
            num=nums[i];
            if (arr[num]==0){
                cout<<"index: "<<i<<endl;
                count++;
                arr[num]=1;
                nums[index]=num;
                index++;
            }
            }
        }
        return count;
    }
};