/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let i = 0
    const n = arr.length;
    for(i=0;i<n;i++) arr[i] = fn(arr[i],i);
    return arr;
};