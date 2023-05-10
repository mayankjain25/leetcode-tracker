/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let sz = nums.length
    if(sz===0) return init 
    let val = init
    for(let i=0;i<sz;i++){
        val = fn(val,nums[i])
    }

    return val
};