class Solution {
public:
    string intToRoman(int num) {
        string res;
        while(num > 0){
            std::cout << num << std::endl;
            if(num >= 1000){
                res.push_back('M');
                num -= 1000;
            }else if(num >= 900){
                res.append("CM");
                num -= 900;
            }else if(num >= 500){
                res.push_back('D');
                num -= 500;
            }else if(num >= 400){
                res.append("CD");
                num -= 400;
            }else if(num >= 100){
                res.push_back('C');
                num -= 100;
            }else if(num >= 90){
                res.append("XC");
                num -= 90;
            }else if(num >= 50){
                res.push_back('L');
                num -= 50;
            }else if(num >= 40){
                res.append("XL");
                num -= 40;
            }else if(num >= 10){
                res.push_back('X');
                num -= 10;
            }else if(num >= 9){
                res.append("IX");
                num -= 9;
            }else if(num >= 5){
                res.push_back('V');
                num -= 5;
            }else if(num >= 4){
                res.append("IV");
                num -= 4;
            }else if(num >= 1){
                res.push_back('I');
                num -= 1;
            }
        }
        return res;
    }
};