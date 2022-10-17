#include <iostream>
#include <conio.h>
#include<fstream>
using namespace std;

int main();
int c = 0;
int d=0;
class Bank{
    public:
    double balance = 0;
    string pin;
    string name;
    string phoneNo;
    long int accountNo;
    Bank *next; 
    string add;
    string pan;
    string adhar;
};

class Loan{
        public:
        string phoneNo;
        long int laccountNo;
        string add;
        int lamount;
        int interest;
        int tamount;
        int left;
        int paid;
        int time;
        Loan *next;
        string pan;
        string adhar;
        string pin;
        string name;
    };


Bank *head = NULL;
Loan *lhead = NULL;
Loan *lheads = NULL;
static string bankName = "L&G Bank";
static string IFSC = "6969696969";
long int accountno = 6969696;
long int laccountno = 7894566;
double lr = 8.5;

void stop()
    {
        string s;
        cout << "\t\t\t\t\tPress any key to continue....";
        cin >> s;
        cout<<endl;
        return;
    }

class Address{
    public:
    string houseNo;
    string area;
    string city;
    string pin;
    string add;
    Address()
    {
        houseNo = "Nil ";
        area = "Nil ";
        city = "Nil ";
        pin = "Nil ";
        add = houseNo + area + city + pin;
    }
    string address(Bank **head)
    {
        cout << "\t\t\t\t\tEnter House No. = ";
        cin>>ws;
        getline(cin,houseNo);
        cout << endl;
        cout << "\t\t\t\t\tEnter Area = ";
        cin>>ws;
        getline(cin,area);
        cout << endl;
        cout << "\t\t\t\t\tEnter City = ";
        cin>>ws;
        getline(cin,city);
        cout << endl;
        cout << "\t\t\t\t\tEnter PIN Code = ";
        cin >> pin;
        cout << endl;
        add = houseNo + ", " + area + ", " + city + ", " + pin + ". ";
        return add;
    }
    string address(Loan **lhead)
    {
        cout << "\t\t\t\t\tEnter House No. = ";
        cin>>ws;
        getline(cin,houseNo);
        cout << endl;
        cout << "\t\t\t\t\tEnter Area = ";
        cin>>ws;
        getline(cin,area);
        cout << endl;
        cout << "\t\t\t\t\tEnter City = ";
        cin>>ws;
        getline(cin,city);
        cout << endl;
        cout << "\t\t\t\t\tEnter PIN Code = ";
        cin >> pin;
        cout << endl;
        add = houseNo + ", " + area + ", " + city + ", " + pin + ". ";
        return add;
    }
};

void insert_end(Bank** root, Bank* value) {
    Bank* new_node = new Bank();
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->balance = value->balance;
    new_node->pin = value->pin;
    new_node->name = value->name;
    new_node->phoneNo = value->phoneNo;
    new_node->accountNo = value->accountNo;
    new_node->add = value->add;
    new_node->pan = value->pan;
    new_node->adhar = value->adhar;
    
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    
    Bank* curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void serialize(Bank** root) {
    ofstream file("bank.txt");
    if (!file.is_open()) {
        exit(1);
    }

    for (Bank* curr = *root; curr != NULL; curr = curr->next) {
            file << curr->balance;
            file << endl;
            file << curr->pin;
            file << endl;
            file << curr->name;
            file << endl;
            file << curr->phoneNo;
            file << endl;
            file << curr->accountNo;
            file << endl;
            file << curr->add;
            file << endl;
            file << curr->pan;
            file << endl;
            file << curr->adhar;
            file << endl;
    }
    file.close();
}

void deserialize(Bank** root) {
    ifstream file("bank.txt");
    double a;
    long int e;
    string s,b,namer,d,f,g,h;
    if (file.is_open()) {
        int c = 0;
        while(getline(file,s))
        {if(s>""){
            if(c==0)
            {
            a = stod(s);
            
            }
            if(c==1)
            {
            b = s;
            
            }
            if(c==2)
            {
            namer = s;
           
            }
            if(c==3)
            {
            d = s;
            
            }
            if(c==4)
            {
            e = stol(s);    
            
            }
            if(c==5)
            {
            f = s;
            
            }
            if(c==6)
            {
            g = s; 
            
            }
            if(c==7)
            {
            h = s;
            cout<<"c";
            }
            c++;
            if(c>7)
            {
            Bank *val = new Bank;
            val->balance = a;
            val->pin = b;
            val->name = namer;
            val->phoneNo = d;
            val->accountNo =e;
            val->add = f;
            val->pan = g;
            val->adhar = h;
            insert_end(&head,val);
            c=0;
            }
        }
        }
    }
    char filename[] = "bank.txt";
    remove(filename);
}

class Transaction{
    protected:
    void depositMoney(Bank **head, string phoneNo)
     {
         double amount;
         Bank *temp = *head;
         cout << "\t\t\t\t\tEnter Money to be deposited.";
         cin >> amount;
         cout<<endl;
         while(temp != NULL)
         {
             if(temp->phoneNo == phoneNo)
             {
                 temp->balance += amount;
                 cout << "\t\t\t\t\tNew Balance = " << temp->balance;
                 stop();
                 return;
            }
            temp = temp->next;
         }
     }

     void withdrawMoney(Bank **head, string phoneNo)
    {
        double amount;
        Bank *temp = *head;
        cout << "\t\t\t\t\tEnter Money to be withdrawn.";
        cin >> amount;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                if(temp->balance < amount)
                {
                    cout << "\t\t\t\t\tInsufficient Funds" << endl;
                    stop();
                    return;
                }
                temp->balance -= amount;
                cout << "\t\t\t\t\tMoney Debited = " << amount << endl;
                cout << "\t\t\t\t\tNew Balance = " << temp->balance << endl;
                stop();
                return;
            }
            temp = temp->next;
        }
    }

    void checkBalance(Bank **head, string phoneNo)
    {
        Bank *temp = *head;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                cout << "\t\t\t\t\tCurrent Balance = " << temp->balance;
                stop();
                return;
            }
            temp = temp->next;
        }
    }

    void Transactions(Bank **head, string phoneNo){
        system("cls");
        int choice;
        cout << "\t\t\t\t\t\tTransaction  Operations for You" << endl;
        cout<<"\t\t\t\t\t***********************************************"<<endl;
        cout<<endl;
        cout << "\t\t\t\t\t\1. Withdraw" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\2. Deposit" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\3. Check Balance" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\4. Go back to  Operations Menu" << endl;
        cout<<endl;
        cout << "\t\t\t\t\tEnter Your Choice";
        cin >> choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
                withdrawMoney(head,phoneNo);
                Transactions(head,phoneNo);
                break;
            case 2:
                depositMoney(head,phoneNo);
                Transactions(head,phoneNo);
                break;
            case 3:
                checkBalance(head,phoneNo);
                Transactions(head,phoneNo);
                break;
            case 4:
                return;
            default:
                cout << "\t\t\t\t\tEnter Valid Choice." << endl;
                Transactions(head,phoneNo);
                break;
    }
}
};

class NewUser
{
    public : 
    Loan *cloanuser;
    string getId(Bank **head)
    {
        string phone_number;
        cout << "\t\t\t\t\tEnter your Phone Number = ";
        cin >> phone_number;
        cout << endl;
        Bank *temp = *head;
        while(temp != NULL)
        { 
            if(temp->phoneNo == phone_number)
            {
                cout << "\t\t\t\t\tPhone Number already exists." << endl;
                getId(head);
            }
            temp = temp->next;
        }
        return phone_number;
    }
    void newUserRegistration(Bank **head)
    {
        string phoneNo,pin,name,pan,adhar;
        Bank *node = new Bank();
        Bank *last = *head;
        int deposit;
        cout << "\t\t\t\t\tEnter Your Name = ";
        cin>>ws;
        getline(cin,name);
        cout << endl;
        Address a1;
        node->add = a1.address(head);
         cout << "\t\t\t\t\tEnter Adhar Number = ";
        cin >> adhar;
         cout << "\t\t\t\t\tEnter PAN = ";
        cin >> pan;
        cout << "\t\t\t\t\tEnter Phone Number = ";
        cin >> phoneNo;
        cout << endl;
        cout << "\t\t\t\t\tCreate Your PIN = ";
        int length = 0;
        char password;
        while( length != 4)
        {
            if (password>=48 && password<=57)
            {
                pin.push_back(password);
                cout <<"*";
                length++;
            }
            password = getch();
        }
        cout << endl;
        cout << "\t\t\t\t\tEnter initial deposit = ";
        cin >> deposit;
        cout << endl;
        node->phoneNo = phoneNo;
        node->balance = deposit;
        node->name = name;
        node->pin = pin;
        node->accountNo = accountno;
        node->adhar = adhar;
        node->pan = pan;
        accountno++;
        node->next = NULL;
        if(*head == NULL)
        {
            *head = node;
            return;
        }
        while(last->next != NULL)
        {
            last = last->next;
        } 
        last->next = node;
        return;
    }

    void newLoanUserRegistration(Loan **lhead)
    {
        string phoneNo,pin,name,pan,adhar;
        Loan *node = new Loan();
        
        Loan *last = *lhead;
        int deposit;
        cout << "\t\t\t\t\t\tEnter Your Name = ";
        cin>>ws;
        getline(cin,name);
        cout << endl;
        Address a2;
        node->add = a2.address(lhead);
         cout << "\t\t\t\t\t\tEnter Adhar Number = ";
        cin >> adhar;
         cout << "\t\t\t\t\t\tEnter PAN = ";
        cin >> pan;
        cout << "\t\t\t\t\t\tEnter Phone Number = ";
        cin >> phoneNo;
        cout << endl;
        cout << "\t\t\t\t\t\tCreate Your PIN = ";
        int length = 0;
        char password;
        while( length != 4)
        {
            if (password>=48 && password<=57)
            {
                pin.push_back(password);
                cout <<"*";
                length++;
            }
            password = getch();
        }
        cout << endl;
        node->phoneNo = phoneNo;
        node->name = name;
        node->pin = pin;
        node->laccountNo= laccountno;
        node->adhar = adhar;
        node->pan = pan;
        laccountno++;
        node->next = NULL;
        cloanuser=node;
        cout << node->add<<endl;
        cout << node->adhar<<endl;
        cout << node->name<<endl;
        cout << node->phoneNo<<endl;
        cout << node->pan<<endl;
        cout << node->pin<<endl;
        stop();
        return;
    }
};


class  Operations : private Transaction
{
    protected:

    void accountdetails(Bank **head, string phoneNo)
    {
        Bank *temp = *head;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                cout << "\t\t\t\t\tBank Name = " << bankName << endl;
                cout << "\t\t\t\t\tIFSC Code = " << IFSC << endl;
                cout << "\t\t\t\t\tAccount Number = " << temp->accountNo << endl;
                cout << "\t\t\t\t\tAccount Holder Name = " << temp->name << endl;
                cout << "\t\t\t\t\tAccount Holder Phone Number = " << temp->phoneNo << endl;
                cout << "\t\t\t\t\tAccount Balance = " << temp->balance << endl;
                cout << "\t\t\t\t\tAccount Holder Address = " << temp->add << endl;
                cout << "\t\t\t\t\tFor queries contact +91-9876543210" << endl; 
                stop();
                return;
            }
            temp = temp->next;
        }
    }

    void closeAccount(Bank **head, string phoneNo)
    {
        Bank *temp = *head;
        Bank *prev = NULL;
        if (temp != NULL && temp ->phoneNo == phoneNo)
        {
            *head = temp->next;
            delete temp;
            cout << "\t\t\t\t\tAccount Deactivated" << endl;
            stop();
            main();
        }
        else
        {
            while(temp != NULL && temp ->phoneNo !=phoneNo)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout << "\t\t\t\t\tAccount Not Found" << endl;
                stop();
                main();
            }
            prev->next = temp->next;
            cout << "\t\t\t\t\tAccount Deactivated" << endl;
            delete temp;
            stop();
            main();
        }
    }

    void  Operation(Bank **head, string phoneNo){
        system("cls");
        int choice;
        cout << "\t\t\t\t\t\t Operations for You." << endl;
        cout<<"\t\t\t\t***********************************************"<<endl;
        cout<<endl;
        cout << "\t\t\t\t\t\1. Transactions" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\2. Delete Account" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\3. Log Out" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\4. Account Details" << endl;
        Bank *temp = *head;
        int amount;
        while(temp != NULL)
        {
            if(temp->phoneNo == phoneNo)
            {
                amount = temp->balance;
            }
            temp = temp->next;
        } 
        cout << "\t\t\t\t\tEnter Your Choice";
        cin >> choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
                Transactions(head,phoneNo);
                 Operation(head,phoneNo);
                break;
            case 2:
                closeAccount(head,phoneNo);
                 Operation(head,phoneNo);
                break;
            case 3:
                cout << "\t\t\t\t\tUser Logged Out!" << endl;
                stop();
                main();
                break;
            case 4:
                accountdetails(head,phoneNo);
                 Operation(head,phoneNo);
                break;
            default:
                cout << "\t\t\t\t\tEnter Valid Choice." << endl;
                 Operation(head,phoneNo);
                break;  
        }
    }
};

int lmenu();

class LoanApply : public NewUser{
    public:

    void linsert_end(Loan** root, Loan* value) {
        Loan* new_node = new Loan();
        if (new_node == NULL) {
            exit(1);
        }
        new_node->next = NULL;
        new_node->phoneNo = value->phoneNo;
        new_node->laccountNo = value->laccountNo;
        new_node->lamount = value->lamount;
        new_node->interest = value->interest;
        new_node->tamount = value->tamount;
        new_node->left = value->left;
        new_node->paid = value->paid;
        new_node->time = value->time;
        new_node->name=value->name;
        new_node->add=value->add;
        new_node->adhar=value->adhar;
        new_node->pan=value->pan;
        new_node->pin=value->pin;
        
        if (lheads == NULL) {
            lheads = new_node;
            lhead=new_node;
            *root=new_node;
            return;
        }
        
        Loan* curr = *root;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }

    void lserialize(Loan** root) {
        ofstream file("loan.txt");
        if (!file.is_open()) {
            exit(1);
        }

        for (Loan* curr = lheads; curr != NULL;) {
                file << curr->phoneNo;
                file << endl;
                file << curr->laccountNo;
                file << endl;
                file << curr->lamount;
                file << endl;
                file << curr->interest;
                file << endl;
                file << curr->tamount;
                file << endl;
                file << curr->left;
                file << endl;
                file << curr->paid;
                file << endl;
                file << curr->time;
                file << endl;
                file << curr->name;
                file << endl;
                file << curr->add;
                file << endl;
                file << curr->adhar;
                file << endl;
                file << curr->pan;
                file << endl;
                file << curr->pin;
                file << endl;
                curr = curr->next;
        }
        file.close();
    }

    void ldeserialize(Loan** root)
    {
        ifstream file("loan.txt");
        int d;
        long int f;
        string a,s,i,j,k,l,m;
        int b,c1,e,g,h;
        if (file.is_open()) 
        {
            int c = 0;
            while(getline(file,s))
            {if(s>"")
            {
                if(c==0)
                {
                a = s;
                }
                if(c==1)
                {
                b = stoi(s);  
                }
                if(c==2)
                {
                c1 = stoi(s);
                }
                if(c==3)
                {
                d = stoi(s);
                }
                if(c==4)
                {
                e = stoi(s);
                }
                if(c==5)
                {
                f = stol(s);
                }
                if(c==6)
                {
                g = stoi(s); 
                }
                if(c==7)
                {
                h = stoi(s);
                }
                if(c==8)
                {
                i = s;
                }
                if(c==9)
                {
                j = s;
                }
                if(c==10)
                {
                k = s;
                }
                if(c==11)
                {
                l = s;
                }
                if(c==12)
                {
                m = s;
                }
                c++;
                if(c>12)
                {
                    Loan *val = new Loan;
                    val->phoneNo = a;
                    val->laccountNo = b;
                    val->lamount = c1;
                    val->interest = d;
                    val->tamount = e;
                    val->left = f;
                    val->paid = g;
                    val->time = h;
                    val->name=i;
                    val->add=j;
                    val->adhar=k;
                    val->pan=l;
                    val->pin=m;
                    linsert_end(&lhead,val);
                    c=0;
                }
            }
        }
        }
        file.close();
        char filename[] = "loan.txt";
        remove(filename);
    }

    void newLoan(Loan **lhead,Loan *loanuser, string ph)
    {
        system("cls");
        int amount;
        Loan *new_node = new Loan();
        new_node->phoneNo=ph;
        cout << "\t\t\t\t\t\t Enter Loan Amount == ";
        cin >> new_node->lamount;
        cout << "\t\t\t\t\t\t Enter Loan Duration(In years) == ";
        cin >> new_node->time;
        new_node->phoneNo = ph;
        new_node->paid = 0;
        new_node->laccountNo = laccountno;
        laccountno ++;
        new_node->next = NULL;
        new_node->interest = ((new_node->lamount * lr * new_node->time)/100);
        new_node->tamount = new_node->lamount + new_node->interest;
        new_node->left = new_node->tamount;
        new_node->add=loanuser->add;
        new_node->adhar=loanuser->adhar;
        new_node->name=loanuser->name;
        new_node->pan=loanuser->pan;
        new_node->pin=loanuser->pin;
        system("cls");
        cout << "\t\t\t\t\t\t Loan Approved :)" << endl;
        cout << "\t\t\t\t\t Loan Amount  ==  " << new_node->lamount << endl;
        cout << "\t\t\t\t\t Loan Accout Number  ==  " << new_node->laccountNo << endl;
        cout << "\t\t\t\t\t Loan Duration  ==  " << new_node->time << " years." << endl;
        cout << "\t\t\t\t\t Loan Interest  ==  " << new_node->interest << endl;
        cout << "\t\t\t\t\t Loan Amount to Repay  ==  " << new_node->tamount  << endl;
        cout << "\t\t\t\t\t Loan Amount Left  ==  " << new_node->left  << endl;
        cout << "\t\t\t\t\t Loan Amount Paid  ==  " << new_node->paid  << endl;
        stop();
        Loan *llast = lheads;
        if(lheads == NULL)
        {
            *lhead = new_node;
            lheads = new_node;
            return;
        }
        while(llast->next != NULL)
        {
            llast = llast->next;
        } 
        llast->next = new_node;
    }

    void repayLoan(Loan **lhead,string ph)
    {
        Loan *temp = lheads;
        int amount;
        Loan *ltemp = *lhead;
        int *paid,*left;
        while(temp != NULL)
        {
            if(temp==ltemp)
            {
                int a;
                cout << "\t\t\t\t\t\t Enter Amount to Repay" << endl;
                cin >> a;
                if(a < 0 && a > ltemp->left)
                {
                    cout << "\t\t\t\t\t\t Invalid Amount" << endl;
                    stop();
                    repayLoan(lhead,ph);
                }
                ltemp->left = ltemp->left - a;
                ltemp->paid = ltemp->paid + a;
                cout << "\t\t\t\t\t\t Transaction Succesful :)" << endl;
                cout << "\t\t\t\t\t Loan Amount  ==  " << ltemp->lamount << endl;
                cout << "\t\t\t\t\t Loan Accout Number  ==  " << ltemp->laccountNo << endl;
                cout << "\t\t\t\t\t Loan Duration  ==  " << ltemp->time << " years." << endl;
                cout << "\t\t\t\t\t Loan Interest  ==  " << ltemp->interest << endl;
                cout << "\t\t\t\t\t Loan Amount to Repay  ==  " << ltemp->tamount  << endl;
                cout << "\t\t\t\t\t Loan Amount Left  ==  " << ltemp->left  << endl;
                cout << "\t\t\t\t\t Loan Amount Paid  ==  " << ltemp->paid  << endl;
                stop();
                return;
            }
            temp=temp->next;
        }
        system("cls");
        cout << "\t\t\t\t\t You don't have any Loan :(" << endl;
        stop();
    }

    void loanDetails(Loan **clhead,string ph)
    {
        Loan *ltemp = *clhead;
                system("cls");
                cout << "\t\t\t\t\t Loan Amount  ==  " << ltemp->lamount << endl;
                cout << "\t\t\t\t\t Loan Accout Number  ==  " << ltemp->laccountNo << endl;
                cout << "\t\t\t\t\t Loan Duration  ==  " << ltemp->time << " years." << endl;
                cout << "\t\t\t\t\t Loan Interest  ==  " << ltemp->interest << endl;
                cout << "\t\t\t\t\t Loan Amount to Repay  ==  " << ltemp->tamount  << endl;
                cout << "\t\t\t\t\t Loan Amount Left  ==  " << ltemp->left  << endl;
                cout << "\t\t\t\t\t Loan Amount Paid  ==  " << ltemp->paid  << endl;
                stop();
                return;
        system("cls");
        cout << "\t\t\t\t\t You don't have any Loan :(" << endl;
        stop();
    }
    int e = 0;
    void loan(Loan **luser)
    {
        Loan *temp = *luser;
        string phoneNo=temp->phoneNo;
        string name;
        int choice;
        system("cls");
        cout << "\t\t\t Welocome to Loan Department of Lakshmi Chit Fund. We provide following Loan related services." << endl;
        cout << "\t\t\t\t\t\t 1. Apply for new Loan." << endl;
        cout << "\t\t\t\t\t\t 2. Repay Loan." << endl;
        cout << "\t\t\t\t\t\t 3. Loan Details." << endl;
        cout << "\t\t\t\t\t\t 4. Press any key to return." << endl;
        cout << "\t\t\t\t\t\t    Enter your choice  ==  ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            newLoan(luser,temp,phoneNo);
            loan(luser);
            break;
            case 2:
            repayLoan(luser,phoneNo);
            loan(luser);
            break;
            case 3:
            loanDetails(luser,phoneNo);
            loan(luser);
            break;
            default :
            lmenu();
            break;
        }
    }
};

class Login : private  Operations, private LoanApply{
    public:
    void loginUser(Bank **head)
    {
        string phoneNo,pin;
        cout << "\t\t\t\t\tEnter Phone No.";
        cin >> phoneNo;
        cout<<endl;
        Bank *temp = *head;
        if(*head == NULL)
        {
            cout << "\t\t\t\t\tPhone No. does not Exist! Create One new account" << endl;
            stop();
            return;
        }
        while(temp != NULL)
        { 
            if(temp->phoneNo == phoneNo)
            {
                cout << "\t\t\t\t\tEnter PIN";
                int length = 0;
                char password;
                while( length != 4)
                {
                    if (password>=48 && password<=57)
                    {
                        pin.push_back(password);
                        cout <<"*";
                        length++;
                    }
                    password = getch();
                }
                cout << endl;
                if(temp->pin == pin)
                {
                    cout << "\t\t\t\t\tWelcome " << temp->name << "!" << endl;
                    stop();
                     Operation(head,phoneNo);
                }
                else
                {
                    cout << "\t\t\t\t\tWrong PIN" << endl;
                    stop();
                    return ;
                }
                cout<<endl;
            }
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout << "\t\t\t\t\tPhone No. does not Exist! Enter Correct Phone No. or create a new account." << endl;
            stop();    
            return;
        }
    }

    void loginLoanUser(Loan **lhead)
    {
        string phoneNo,pin,ph;
        cout << "\t\t\t\t\tEnter Phone No.";
        cin >> phoneNo;
        cout<<endl;
        Loan *temp = lheads;
        if(temp == NULL)
        {
            cout << "\t\t\t\t\tPhone No. does not Exist! Create One new account" << endl;
            stop();
            return;
        }
        while(temp != NULL)
        { 
            if(temp->phoneNo == phoneNo)
            {
                cout << "\t\t\t\t\tEnter PIN";
                int length = 0;
                char password;
                while( length != 4)
                {
                    if (password>=48 && password<=57)
                    {
                        pin.push_back(password);
                        cout <<"*";
                        length++;
                    }
                    password = getch();
                }
                cout << endl;
                cout<<pin<<endl<<temp->pin<<endl;
                if(temp->pin == pin)
                {
                    cout << "\t\t\t\t\tWelcome " << temp->name << "!" << endl;
                    stop();
                    loan(&temp);
                }
                else
                {
                    cout << "\t\t\t\t\tWrong PIN" << endl;
                    stop();
                    return;
                }
                cout<<endl;
            }
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout << "\t\t\t\t\tPhone No. does not Exist! Enter Correct Phone No. or create a new account." << endl;
            stop();    
            return;
        }
    }
};

int lmenu(){
    system("cls");
    system("Color A4");
    LoanApply l;
    if(d == 0)
    {
       l.ldeserialize(&lhead);
       d++; 
    }
    int choice;
    cout << "\t\t\t\t\t\tL&G Bank" << endl; 
    cout<<"\t\t\t\t***********************************************"<<endl;
    cout << "1. Register Here for Loan\n\n2. Existing loan Account.\n\n3. Save Data and Return to Main Menu\n\n\n\n\n\n\t\t\t\t\tEnter Your Choice.";
    cin >> choice;
    switch (choice)
    {
        case 1:
            NewUser user;
            user.newLoanUserRegistration(&lhead);
            l.loan(&user.cloanuser);
            break;
        case 2:
        {
            Login login;
            login.loginLoanUser(&lhead);
            lmenu(); 
        }
        break;
        case 3:
            l.lserialize(&lhead);
            main();
            break;
        default:
            cout << "\t\t\t\t\tEnter A Valid Choice." << endl;
            stop();
            lmenu();
            break;
    }
}

int main()
{
    system("cls");
    system("Color A4");
    if(c == 0)
    {
       deserialize(&head);
       c++; 
    }
    int choice;
    cout << "\t\t\t\t\t\tL&G Bank" << endl; 
    cout<<"\t\t\t\t***********************************************"<<endl;
    cout << "1. Register Here\n\n2. Existing User Login.\n\n3. Loan Menu\n\n4. Save and Exit\n\n\n\n\n\n\t\t\t\t\tEnter Your Choice.";
    cin >> choice;
    switch (choice)
    {
        case 1:
            NewUser user;
            user.newUserRegistration(&head);
            main();
            break;
        case 2:
        {
            Login login;
            login.loginUser(&head);
            main(); 
        }
            break;
        case 3:
            lmenu();
            break;
        case 4:
            serialize(&head);
            exit(0);
        default:
            cout << "\t\t\t\t\tEnter A Valid Choice." << endl;
            stop();
            main();
            break;
    }
}