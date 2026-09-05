class SnapshotArray {
public:
vector<vector<pair<int,int>>>arr; // index = {snap_id , val}
int timer;
    SnapshotArray(int length) {
        timer =0;
        arr.resize(length);
        for(int i=0; i<length; i++){
            arr[i].push_back({0,0});
        }
     
    }
    
    void set(int index, int val) {
        arr[index].push_back({timer, val});
    }
    
    int snap() {
        timer++;
        return timer-1;
    }
    
    int get(int index, int snap_id) {
       auto &v  = arr[index];
       int l=0 ,r=v.size()-1;

       int ans =0;
       while( l <= r){
        int mid = l+(r-l)/2;

        if(v[mid].first <= snap_id){
            // could be the answer
            ans = v[mid].second;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
       }
       return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */