class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourHandAngle = 0.0, minHandAngle = 0.0 ;
        double res;
        hourHandAngle = ((hour * 30) % 360)  + minutes * 0.5;
        
        minHandAngle = minutes * 6;
        
        res = abs(hourHandAngle - minHandAngle);
        
        double otherAngle = 360.0 - res;
        return min(res , otherAngle);
    }
};