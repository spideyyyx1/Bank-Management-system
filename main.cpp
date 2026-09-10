#include <iostream>
using namespace std;

void create_acc(){
    cout<<"Create account selected"<<endl;
}
void deposit(){
    cout<<"Deposit selected"<<endl;
}
void withdraw(){
    cout<<"Withdraw selected"<<endl;
}
void chk_balance(){
    cout<<"Check balance selected"<<endl;
}
void acc_details(){
    cout<<"Account details selected"<<endl;
}
int main()
{   
    bool x=true;
    while (x){
        int choice;
        cout<<"==========================================\n     WELCOME TO BANK MANAGEMENT SYSTEM    \n==========================================\n";
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