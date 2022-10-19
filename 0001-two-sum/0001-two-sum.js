/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var i=0;
    var j=0,s=0;
    for(i=0;i<nums.length;i++)
        {
            for (j=i+1;j<nums.length;j++)
                {
                    s=nums[i]+nums[j];
                    
                    if(s==target)
                        {
                            var r=[i,j];
                            return r;
                        }
                }
        }
    
};