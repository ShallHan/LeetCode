class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        double tmp = pow(x, n/2);
        if(n>0 && n%2)
            return tmp * tmp * x;
        if(n<0 && n%2)
            return tmp * tmp * (1/x);
        return tmp*tmp;
    }
};
