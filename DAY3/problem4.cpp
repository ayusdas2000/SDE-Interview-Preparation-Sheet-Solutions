//this question requires an basic understanding of boyer moore algorithm
//1. By observation we can know that there can be no more than two elements having frequency greater that n/3;
//2.num1 and num2 is initialized to -1 and cnt1 and cnt2 to 0 in the first step.
//3. When element equal to num1 or num2 encountered we increase the count by one.
//4. When different than that encountered we decrease that by one.
//5. When cnt1 or cnt2 again become 0 we change the num
//6. At last we have two candidates num1 and num2, we iterate over the array to find out is the frequency of num1 and num2 greater than n/3.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int num1=-1;
        int num2=-1;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(num1==nums[i]){
                cnt1++;
            }
            else if(num2==nums[i]){
                cnt2++;
            }
            else if(cnt1==0){
                num1=nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                num2=nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int occurrences_of_num1=0;
        int occurrences_of_num2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                occurrences_of_num1++;
            }
            else if(nums[i]==num2){
                occurrences_of_num2++;
            }
        }
        if(occurrences_of_num1>nums.size()/3){
            ans.push_back(num1);
        }
        if(occurrences_of_num2>nums.size()/3){
            ans.push_back(num2);
        }
        return ans;
    }
};