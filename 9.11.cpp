#include <iostream> 
#include <iomanip>
#include <string>

using namespace std; 

class BankAccount { 
    public: 
        BankAccount(); 
        BankAccount(double initial_balance); 
        void deposit(double amount); 
        void withdraw(double amount);
        void add_interest(double rate);
        double get_balance() const;
    private:
        double balance;
}; 

BankAccount::BankAccount()  { 
    balance = 0; 
} 

BankAccount::BankAccount(double initial_balance)  { 
    balance = initial_balance; 
} 

void BankAccount::deposit(double amount)  { 
    balance = balance + amount; 
} 

void BankAccount::withdraw(double amount) { 
    const double PENALTY = 10; 
    if (amount > balance)   { 
        balance = balance - PENALTY; 
    } 
    else    { 
        balance = balance - amount; 
    }
}

void BankAccount::add_interest(double rate) { 
   double amount = balance * rate / 100; 
   deposit(amount); 
} 

double BankAccount::get_balance() const { 
   return balance; 
}

class Portfolio: private BankAccount {
    public:
        void depo(double amount, string account);
        void with(double amount, string account);
        void transfer(double amount, string account);
        void print_bal();
    private:
        double savings;
        double checkings;
};

void Portfolio::depo(double amount, string account) {
    if(account == "S") {
        savings += amount;
    } else if (account == "C") {
        checkings += amount;
    }
}

void Portfolio::with(double amount, string account) {
    if(account == "S") {
        savings -= amount;
    } else if (account == "C") {
        checkings -= amount;
    }
}

void Portfolio::transfer(double amount, string account) {
    if(account == "S") {
        savings -= amount;
        checkings += amount;
    } else if (account == "C") {
        checkings -= amount;
        savings += amount;
    }
}

void Portfolio::print_bal() {
    cout << fixed << setprecision(2) << "Savings: " << savings << endl;
    cout << fixed << setprecision(2) << "Checkings: " << checkings << endl;
}


int main()  {
    Portfolio jims_account;
    jims_account.depo(1000, "S");
    jims_account.depo(2000, "C");
    jims_account.transfer(500, "C");
    jims_account.print_bal();
    return 0; 
}