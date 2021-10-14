class Solution {
public:
    vector<int> asteroidCollision(vector<int> asteroids) {
        while(1)
        {
            int flag=0;
            for(int i=0;i<asteroids.size()-1;++i)
            {
                if(asteroids[i]>0 && asteroids[i+1]<0)
                {
                    flag=1;
                    if(asteroids[i]+asteroids[i+1]==0)
                    {
                        asteroids.erase(asteroids.begin()+i,asteroids.begin()+i+2);
                    }
                    else if(asteroids[i]+asteroids[i+1]>0)
                    {
                        asteroids.erase(asteroids.begin()+i+1);
                    }
                    else if(asteroids[i]+asteroids[i+1]<0)
                    {
                        asteroids.erase(asteroids.begin()+i);
                    }
                    break;
                }
            }

            if(flag==0 || asteroids.size()==0)
            {
                break;
            }
        }

        return asteroids;
    }
};