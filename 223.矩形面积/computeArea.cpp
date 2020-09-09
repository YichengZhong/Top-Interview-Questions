class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long long area1=(C-A)*(D-B);//面积一
        long long area2=(G-E)*(H-F);//面积二
        return area1+area2-childArea(A,B,C,D,E,F,G,H);
    }

    //计算折叠面积
    long long childArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long long x1=max(A,E),y1=max(B,F);//左下交点
        long long x2=min(C,G),y2=min(D,H);//右上交点
        if(x1<=x2&&y1<=y2)
        {//说明有重叠
            return (x2-x1)*(y2-y1);
        }
        return 0;
    }

};