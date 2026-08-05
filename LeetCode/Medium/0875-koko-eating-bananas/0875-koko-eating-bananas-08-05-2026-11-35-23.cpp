class Solution {
 bool canEat(vector<int>&piles, int speed, int hour){
    long long time =0;
    for(int i=0; i<piles.size();  i++){
        time+= ceil((double)piles[i] /(double)speed);
    }
    
    return time<=hour;
 }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int maxSpeed = INT_MIN;
        for(int p : piles){
            maxSpeed = max(maxSpeed, p);
        }

        int low =1 , high = maxSpeed;
        while( low <= high){
            int mid = low+(high - low)/2;
                // can possible we need the minimum speed
            if(canEat(piles, mid, h)) high = mid-1;

            else low = mid+1;
        }

        return low;
    }
};