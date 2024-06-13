Here is a JavaScript solution for finding the contiguous subarray with the largest product:

```javascript
function maxProduct(nums) {
    let max = nums[0];
    let min = nums[0];
    let result = nums[0];
    for(let i = 1; i < nums.length; i++){
        let temp = max;
        max = Math.max(Math.max(max * nums[i], min * nums[i]), nums[i]);
        min = Math.min(Math.min(temp * nums[i], min * nums[i]), nums[i]);
        if(max > result){
            result = max;
        }
    }
    return result;
}

console.log(maxProduct([2,3,-2,4]));
```

This solution uses a dynamic programming approach. It keeps track of the maximum and minimum product of the subarray that ends at each position in the array. The maximum product of the subarray ending at the current position is either the current number itself, the maximum product of the subarray ending at the previous position times the current number, or the minimum product of the subarray ending at the previous position times the current number. The reason to keep track of the minimum product is that a negative number times a negative number becomes a positive number. The result is the maximum of all maximum products.