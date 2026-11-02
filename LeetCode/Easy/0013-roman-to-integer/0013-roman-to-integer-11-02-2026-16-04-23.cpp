class Solution {
public:
    int romanToInt(string s) {
    
        int ans =0;
        int n = s.size();
        for(int i=0; i<n; i++){

            if(s[i] == 'I'){
                if(i+1 <n && s[i+1] == 'V'){
                    ans+=4;
                    i+=1;
                }
               else if(i+1 <n && s[i+1]=='X'){
                    ans+=9;
                    i+=1;
                }
                else ans+=1;
            }
            else if(s[i] =='V')ans+=5;

            else if(s[i] == 'X'){
                if(i+1 <n && s[i+1] == 'L' ){
                    ans+=40;
                    i+=1;
                }
                else if(i+1 <n && s[i+1] == 'C' ){
                    ans+=90;
                    i+=1;
                }
                else ans+=10;
            }
            else if(s[i] == 'L')ans+=50;
            
            else if( s[i] =='C'){
                if(i+1 <n && s[i+1] == 'D'){
                    ans+=400;
                    i+=1;
                }
                else if(i+1 <n && s[i+1]=='M'){
                    ans+=900;
                    i+=1;
                }
                else ans+=100;
            }
            else if(s[i] == 'D')ans+=500;
            else if(s[i] == 'M')ans+=1000;
            
        }
        return ans;
    }
};