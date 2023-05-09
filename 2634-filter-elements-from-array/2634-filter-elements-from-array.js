/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let a = new Array()

    let n = arr.length
    
    for(let i = 0;i<n;i++){
        if(fn(arr[i],i)) a[a.length] = arr[i]
    }


    return a
};