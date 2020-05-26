class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num == 1)
        {
            return false;
        }
        int sum = 0;
        int i = 2;
        for(; i < Math.sqrt(num); i++) 
        {
            if(num % i == 0)
            {
                sum += i;
                sum += num / i;
            }
        }
        if(i * i == num)
        {
            sum += i;
        }
        sum += 1;
        return sum == num ? true : false;        
    }
}