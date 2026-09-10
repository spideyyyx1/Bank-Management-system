#include <iostream>
#include <string>
using namespace std;
bool acc_created=false;
struct acc
    {
        string name;
        string acc_number;
        string acc_type;
        float balance;

    };
acc details;
void create_acc(){
    cout<<"Enter the name of the account holder:- ";
    cin>>details.name;
    cout<<"Enter the account number:- ";
    cin>>details.acc_number;
    cout<<"Enter the account type:- ";
    cin>>details.acc_type;
    cout<<"Enter the balance:- ";
    cin>>details.balance;
    cout<<"Account created successfully"<<endl;  
    acc_created=true;  
}
void deposit(){
    float dep_amt;
    if (acc_created){
        cout<<"Enter the amount You want to deposit:- ";
        cin>>dep_amt;
        if (dep_amt>0){
            details.balance=details.balance+dep_amt;
            cout<<"Money Deposited"<<endl;
            cout<<"New Balance:- "<<details.balance<<endl;
        }
        else{
            cout<<"Invalid Amount"<<endl;
        }
    }
    else{
        cout<<"Please create an account first ! ! !"<<endl;
    }
}
void withdraw(){
    int wtd_amt;
    if (acc_created){
        cout<<"Enter the amount you want to withdraw:- ";
        cin>>wtd_amt;
        if (wtd_amt>0){
            if (wtd_amt<=details.balance){  
                details.balance=details.balance-wtd_amt;
                cout<<"Money withdrawn successfully"<<endl;
                cout<<"New Balance:- "<<details.balance<<endl;
            }
            else{
                cout<<"Insufficient balance"<<endl;
            }
        }
        else{
            cout<<"Invalid Amount"<<endl;
        }

    }
    else{
        cout<<"Please create an account first ! ! !"<<endl;
    }
}
void chk_balance(){
    if (acc_created)
    {
        cout<<"Current Balance:- "<<details.balance<<endl;
    }
    else
    {
        cout<<"Please Create a Account First ! ! !"<<endl;
    }
}
void acc_details(){
    if (acc_created==true){
    cout<<"===========================================    ACCOUNT DETAILS     ==========================================\n";
    cout<<"Account Holder:- " <<details.name<<endl;
    cout<<"Account Number:- "<<details.acc_number<<endl;
    cout<<"Account Type:-"<<details.acc_type<<endl;
    cout<<"Balance:- "<<details.balance<<endl;
    cout<<"==============================================================================================================\n";
    }
    else{
        cout<<"Please Create a Account First ! ! !"<<endl;
    }
}
int main()
{   
    bool x=true;
    
    int choice;
    cout<<"==========================================\n     WELCOME TO BANK MANAGEMENT SYSTEM    \n==========================================\n";
    while (x){
        cout<<"1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Account Details\n6. Exit\n";
        cout<<"Enter your choice:-";
        cin>>choice;
        switch (choice){
            case 1:
                create_acc();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                chk_balance();
                break;
            case 5:
                acc_details();
                break;
            case 6:
                x=false;
                break;
            default:
                cout<<"INVALID CHOICE ! ! !"<<endl;
                break;
        }
    }


}