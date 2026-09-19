class Bank {
public:
     vector<long long>acc;
    Bank(vector<long long>& balance) {
        acc = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > (int)acc.size() || account2 < 1 || account2 > (int)acc.size())return false;
        
        if(acc[account1-1] < money)return false; // not enough balance

        acc[account2-1] +=money;
        acc[account1-1]-=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
         if(account < 1 || account > (int)acc.size())return false;
        acc[account-1] += money;
        return true;

    }
    
    bool withdraw(int account, long long money) {
            if (account < 1 || account > (int)acc.size()) return false;
        if(acc[account-1] < money)return false;
        acc[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */