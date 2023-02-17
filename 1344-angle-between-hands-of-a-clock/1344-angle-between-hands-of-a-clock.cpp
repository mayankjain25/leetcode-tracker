class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Minute Hand
        // Moves 360 Degree in 1 hour...360 in 60 minutes...5 degree in 1 minute

        //Hour hand
        //Moves 360 degree in 12 hours...30 degree in 1 hour...30 degree in 60 mins...0.5 degree in 1 minute

        double hour_angle = (60*hour + minutes) * 0.5;
        double minutes_angle=minutes * 6;
        double angle = abs(hour_angle - minutes_angle);

        cout<<angle<<endl;

        return angle<=180?angle:360-angle;

        
    }
};