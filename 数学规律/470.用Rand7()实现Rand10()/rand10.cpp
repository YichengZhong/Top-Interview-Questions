// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //(randX() - 1)*Y + randY() 
        //1-XY是均匀的
        // 首先得到一个数
        int num = (rand7() - 1) * 7 + rand7();
        // 只要它还大于10，那就给我不断生成，因为我只要范围在1-10的，最后直接返回就可以了
        while (num > 10){
            num = (rand7() - 1) * 7 + rand7();
        }
        return num;        
    }
};