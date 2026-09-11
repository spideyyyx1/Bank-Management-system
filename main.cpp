#include <iostream>
#include <string>
using namespace std;
struct acc
    {
        string name;
        string acc_number;
        string acc_type;
        float balance;

    };
acc details;
acc accounts[100];
int acc_ct=0;
int get_acc_seq(int branch_code){
    string qry="python account_seq.py "+to_string(branch_code);
    FILE* pipe=_popen(qry.c_str(),"r");
    char buffer[100];
    fgets(buffer,sizeof(buffer),pipe);
    string result=buffer;
    _pclose(pipe);
    return stoi(result);
}
string gen_acc_num(int branch_code,int seq){
    string acc_num="AXB"+to_string(branch_code);
    int s=to_string(seq).length();
    for (int i=0;i<5-s;i++){
        acc_num+="0";
    }
    acc_num+=to_string(seq);
    return acc_num;
}
int get_branch_code(string branchname){
    string qry="python branch_lookup.py "+branchname;
    FILE* pipe=_popen(qry.c_str(),"r");
    char buffer[100];
    fgets(buffer,sizeof(buffer),pipe);
    string result=buffer;
    if (result=="0\n")
    {
        _pclose(pipe);
        return 0;
    }
    else
    {
        int num=stoi(result);   
        _pclose(pipe);
        return num;
    }
}
int save_acc(string acc_no,string name,int branch_code,string acc_type,float bal){
    string qry="python save_acc.py "+acc_no+" "+name+" "+to_string(branch_code)+" "+acc_type+" "+to_string(bal);
    FILE* pipe=_popen(qry.c_str(),"r");
    char buffer[100];
    fgets(buffer,sizeof(buffer),pipe);
    string result=buffer;
    _pclose(pipe);
    return stoi(result);
}
void create_acc(){
    cout<<"Enter the name of the account holder:- ";
    cin>>details.name;
    cout<<"Enter the branch name:- ";
    string branch_name;
    cin>>branch_name;
    int b_code=get_branch_code(branch_name);
    if(b_code==0){
        cout<<"Branch Not Found ! ! !"<<endl;
        return;
    }
    cout<<"Enter the account type:- ";
    cin>>details.acc_type;
    cout<<"Enter the balance:- ";
    cin>>details.balance;
    int sequ=get_acc_seq(b_code);
    string acc_no=gen_acc_num(b_code,sequ);
    details.acc_number=acc_no;
    int result=save_acc(
        acc_no,
        details.name,
        b_code,
        details.acc_type,
        details.balance
    );
    if(result==1){
        accounts[acc_ct]=details;
        cout<<"Account created successfully!"<<endl;
        cout<<"Your account number is: "<<acc_no<<endl;
        acc_ct+=1;
    }
    else{
        cout<<"Account creation failed!"<<endl;
    }
}
void deposit(){
    float dep_amt;
    if (acc_ct!=0){
        cout<<"Enter the amount You want to deposit:- ";
        cin>>dep_amt;
        if (dep_amt>0){
            accounts[acc_ct-1].balance=accounts[acc_ct-1].balance+dep_amt;
            cout<<"Money Deposited"<<endl;
            cout<<"New Balance:- "<<accounts[acc_ct-1].balance<<endl;
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
    if (acc_ct!=0){
        cout<<"Enter the amount you want to withdraw:- ";
        cin>>wtd_amt;
        if (wtd_amt>0){
            if (wtd_amt<=accounts[acc_ct-1].balance){  
                accounts[acc_ct-1].balance=accounts[acc_ct-1].balance-wtd_amt;
                cout<<"Money withdrawn successfully"<<endl;
                cout<<"New Balance:- "<<accounts[acc_ct-1].balance<<endl;
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
    if (acc_ct!=0)
    {
        cout<<"Current Balance:- "<<accounts[acc_ct-1].balance<<endl;
    }
    else
    {
        cout<<"Please Create a Account First ! ! !"<<endl;
    }
}
void acc_details(){
    if (acc_ct!=0){
    cout<<"===========================================    ACCOUNT DETAILS     ==========================================\n";
    cout<<"Account Holder:- " <<accounts[acc_ct-1].name<<endl;
    cout<<"Account Number:- "<<accounts[acc_ct-1].acc_number<<endl;
    cout<<"Account Type:-"<<accounts[acc_ct-1].acc_type<<endl;
    cout<<"Balance:- "<<accounts[acc_ct-1].balance<<endl;
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