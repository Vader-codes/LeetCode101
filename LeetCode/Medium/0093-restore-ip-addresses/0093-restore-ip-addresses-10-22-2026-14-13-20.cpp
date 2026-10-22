class Solution {
 private:
 vector<string>ans;

 public:

 bool isValid(string part){
    //leadeing zero
    if(part.size() > 1 && part[0] == '0') return false;
    int num = stoi(part);
     
     return (num >=0 && num <= 255);
 }
 void solve(int idx, int parts, string curr, string &s){
    
    // we have created 4 parts
    if(parts == 4){
        if(idx == s.size()){
            curr.pop_back(); // removes last .
            ans.push_back(curr);
        }
        return;
    }

    // try take 1,2, 3, digits
    for(int len =1; len<=3; len++){
        if(idx + len > s.size()) break;

        string part = s.substr(idx, len);

        if(!isValid(part)) continue;

        solve(idx+len, parts+1, curr+part+"." , s);
    }
 }
public:
    vector<string> restoreIpAddresses(string s) {
        solve( 0, 0 , "" , s);
        return ans;
    }
};