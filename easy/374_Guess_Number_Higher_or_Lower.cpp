/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int guess_res = 1;
        unsigned int left = 1;
        unsigned int right = n;
        unsigned int med;
        while(1){
            med = (left + right) / 2;
            guess_res = guess(med);
            if(guess_res < 0)
                right = med - 1;
            else if(guess_res > 0)
                left = med + 1;
            else
                break;
        }
        return med;
    }
};