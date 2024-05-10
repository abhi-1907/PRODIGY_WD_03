#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string name;
    int phone;
    string email;
    int option;
    char c='y';
    do{
    cout<<"Enter an option:\n1.Add contact\n2.View contacts\n3.Edit contacts\n4.Delete contacts";
    cin>>option;

    fstream ob;
    
    

    if(option==1)
    {
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"Enter phone number: ";
        cin>>phone;
        cout<<"Enter email address: ";
        cin>>email;
        ob.open("contacts.txt",ios::app);
        if (!ob.is_open())
        {
        cout << "Error opening contacts file!" << endl;
        return 1; 
        }
        ob<<name<<" "<<phone<<" "<<email<<endl;
        ob.close();

    }
    else if(option==2)
    {
        ob.open("contacts.txt",ios::in);
        if (!ob.is_open())
        {
        cout << "Error opening contacts file!" << endl;
        return 1; 
        }
        
        ob.seekg(0);
        while(!ob.eof())
        {
            ob>>name>>phone>>email;
            cout<<name<<" "<<phone<<" "<<email<<endl;
        }
        ob.close();
    }
    else if(option==3)
    {
        string tempname1;
        int tempphone1;
        string tempemail1;
        string tempname2;
        int tempphone2;
        string tempemail2;
        


        cout<<"\nEnter existing name: ";
        cin>>tempname1;
        cout<<"Enter existing phone number: ";
        cin>>tempphone1;
        cout<<"Enter existing email address: ";
        cin>>tempemail1;

        cout<<"\nEnter new name: ";
        cin>>name;
        cout<<"Enter new phone number: ";
        cin>>phone;
        cout<<"Enter new email address: ";
        cin>>email;
        ob.open("contacts.txt",ios::in | ios::out);
        if (!ob.is_open())
        {
        cout << "Error opening contacts file!" << endl;
        return 1; 
        }

        ob.seekg(0);

        int done=0;

        while(!ob.eof())
        {
            ob>>tempname2>>tempphone2>>tempemail2;

            if(tempname2==tempname1&&tempphone1==tempphone2&&tempemail2==tempemail1)
            {
                done=1;
                ob.seekp(ob.tellg());
                ob<<name<<" "<<phone<<" "<<email<<endl;
                break;
            }
        }
        if(done==0)
        {
            cout<<"\nNo such contact found.";
        }
        else
        cout<<"\nContact edited";
        ob.close();
    }
    else if(option==4)
    {
        string tempname1;
        int tempphone1;
        string tempemail1;
        string tempname2;
        int tempphone2;
        string tempemail2;

        cout<<"\nEnter existing name: ";
        cin>>tempname1;
        cout<<"Enter existing phone number: ";
        cin>>tempphone1;
        cout<<"Enter existing email address: ";
        cin>>tempemail1;
        ob.open("contacts.txt",ios::in|ios::out);
        if (!ob.is_open())
        {
        cout << "Error opening contacts file!" << endl;
        return 1; 
        }

        ob.seekg(0);

        int done=0;
        while(!ob.eof())
        {
            ob>>tempname2>>tempphone2>>tempemail2;

            if(tempname2==tempname1&&tempphone1==tempphone2&&tempemail2==tempemail1)
            {
                done=1;
                ob.seekp(ob.tellg());
                ob<<""<<" "<<""<<" "<<""<<endl;
                break;
            }
        }
        if(done==0)
        {
            cout<<"\nNo such contact found.";
        }
        else
        cout<<"\nContact deleted";
        ob.close();


    }
    else 
    cout<<"\nEnter a valid option!!!";
    cout<<"\nDo you want to continue?(y/n): ";
    cin>>c;
    }while(c=='y');
    return 0;
}