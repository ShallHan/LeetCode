class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() ==0) {
            return 0;
        }
        
        int lineMax = 0;
        
        for (int i = 0; i < points.size(); i++) {
                std::unordered_map<float, int> map;
                int nVertical = 0;
                int same = 0;
                int iMax = 0;
                for (int j = 0; j < points.size(); j++) {
                        if (points[i].x == points[j].x && points[i].y == points[j].y) {
                                same ++;
                        } else if (points[i].x == points[j].x && points[i].y != points[j].y) {
                                nVertical++;
                                if (nVertical > iMax) {
                                        iMax = nVertical;
                                }
                        } else {
                                float k = ((float)(points[j].y - points[i].y))/(points[j].x - points[i].x);
                                map[k]++;

                                if (map[k] > iMax) {
                                        iMax = map[k];
                                }
                        }
                }
                if (iMax + same > lineMax) {
                    lineMax = iMax + same;
                }
        }
        return lineMax;
    }
};
