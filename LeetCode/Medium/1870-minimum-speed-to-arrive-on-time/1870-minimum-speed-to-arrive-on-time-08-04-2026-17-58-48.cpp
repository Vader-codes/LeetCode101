class Solution {
double canTravel(vector<int>&dist, double hour, int speed){ 
    double time =0.0;
    int n = dist.size();
    for(int i=0; i<n; i++){
        // for this current dist how much time will it take
        if(i != n-1)
        time+= ceil((double)dist[i]/speed);

        else time+=(double)dist[i]/speed;
    }

    return time;
}
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // the speed range can be from 1 to INT_MAX
    
       

        int low = 0, high = 10000000;
        int ans = -1;
        while( low <= high){
            int mid = low+(high - low)/2;

            double time = canTravel(dist,  hour, mid);

            if( time <= hour){
                ans = mid;
                // we have to minimise the speed so letes try witht the smaller speed
                high = mid-1;
            }
            else{ // time > hour
                // since we are taking more time we have to increse the speed
                low = mid+1;

            }
        }
        return ans;
    }
};