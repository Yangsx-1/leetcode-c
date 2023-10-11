class Bank {
private:
    vector<long long> acc;
public:
    Bank(vector<long long>& balance) {
        acc.push_back(0);
        int length = balance.size();
        for(int i=0;i<length;++i){
            acc.push_back(balance[i]);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if( account1>(acc.size()-1) || account2>(acc.size()-1) || acc[account1] < money) 
            return false;
        else{
            acc[account1]-=money;
            acc[account2]+=money;
            return true;
        }
    }
    
    bool deposit(int account, long long money) {
        if(account>(acc.size()-1)) return false;
        else{
            acc[account]+=money;
            return true;
        }
    }
    
    bool withdraw(int account, long long money) {
        if(account>(acc.size()-1) || acc[account] < money) return false;
        else{
            acc[account]-=money;
            return true;
        }
    }
};
