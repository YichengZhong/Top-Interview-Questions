class Bank {
public:
vector<long long> accountlist;
    Bank(vector<long long>& balance) {
        accountlist=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>accountlist.size() || account2>accountlist.size()) 
            return false;

        if(accountlist[account1-1]>=money)
        {
            accountlist[account1-1]=accountlist[account1-1]-money;
            accountlist[account2-1]=accountlist[account2-1]+money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>accountlist.size()) 
            return false;

        accountlist[account-1]=accountlist[account-1]+money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>accountlist.size()) 
            return false;
            
        if(accountlist[account-1]>=money)
        {
            accountlist[account-1]=accountlist[account-1]-money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */