#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void minMax(vector<int> const &nums,int low,int high,int &min,int &max)
{
    if(low==high)
    {
        if(max<nums[low]){
            max=nums[low];
        }
        if(min>nums[high]){
            min=nums[high];
        }
        return ;
    }

    if(high-low==1)
    {
        if(nums[low]<nums[high])
        {
            if(min>nums[low]){
                min=nums[low];
            }
            if(max<nums[high]){
                min=nums[high];
            }
        }
        else
        {
            if(min>nums[high]){
                min=nums[high];
            }
            if(max<nums[low]){
                max=nums[low];
            }
        }
        return;
    }

    int mid=(low+high)/2;

    minMax(nums,low,mid,min,max);

    minMax(nums,mid+1,high,min,max);
}

int main()
{
    vector <int> nums = {7,2,9,3,1,6,7,8,4};

    int max=INT_MIN,min=INT_MAX;

    int n=nums.size();

    minMax(nums,0,n-1,min,max);

    cout<<"Maximum element = "<<min<<endl;
    cout<<"Minimum element = "<<max<<endl;
}
