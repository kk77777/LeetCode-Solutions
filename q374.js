/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function (n) {
  let l = 1,
    h = n;
  while (l <= h) {
    let mid = parseInt(l + (h - l) / 2);
    let vr = guess(mid);
    if (vr === 0) return mid;
    if (vr === 1) l = mid + 1;
    else h = mid - 1;
  }
  return 0;
};
