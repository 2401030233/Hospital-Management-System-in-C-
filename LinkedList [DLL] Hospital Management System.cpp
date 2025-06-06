# include <iostream>
using namespace std;
int listSize = 0; //global variable for O (1) time complexity
struct Node
{
    Node *prev;
    int ID;
    string name;
    string disease;
    Node *next;
} *head=nullptr, *rear=nullptr;
void addPatient (int id, string n, string d)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->next=nullptr;
    temp->ID=id;
    temp->name=n;
    temp->disease=d;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    listSize++;
    cout<<"\nInserted new Patient with required data at position : "<<listSize<<endl;
}
void displayForward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Patient List is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nDisplaying Patient list in forward direction :-\n\n";
        Node *temp=head;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->ID<<", "<<temp->name<<", "<<temp->disease<<" ] -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void displayBackward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Patient List is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nDisplaying Patient list in backward direction :-\n\n";
        Node *temp=rear;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->ID<<", "<<temp->name<<", "<<temp->disease<<" ] -> ";
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }
}
void insert_first (int id, string n, string d)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->next=nullptr;
    temp->ID=id;
    temp->name=n;
    temp->disease=d;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    listSize++;
    cout<<"\nInserted new Patient at 1st position with required data..\n";
}
void insert_last (int id, string n, string d)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->next=nullptr;
    temp->ID=id;
    temp->name=n;
    temp->disease=d;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    listSize++;
    cout<<"\nInserted new patient at last position with required data..\n";
}
void insert_specified (int pos, int id, string s, string d)
{
    if (pos<=0)
    {
        cerr<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (pos==1)
        {
            insert_first (id, s, d);
        }
        else if (pos>1 && pos <=listSize)
        {
            Node *n=head->next, *p=head;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next;
                i++;
            }
            Node *temp=new Node ();
            p->next=temp;
            temp->prev=p;
            temp->next=n;
            n->prev=temp;
            temp->ID=id;
            temp->name=s;
            temp->disease=d;
            cout<<"\nInserted Patient with required data at position : "<<pos<<endl;
            listSize++;
        }
        else if (pos==listSize+1)
        {
            insert_last (id, s, d);
        }
        else
        {
            cerr<<"\nERROR : Position out of range!\n";
        }
    }
}
void delete_first ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Patient list is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr && head!=nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nDeleted head node!\tRemoved first patient\n";
        listSize--;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        delete temp;
        temp=nullptr;
        head->prev=nullptr;
        cout<<"\nDeleted first node!\tRemoved first patient\n";
        listSize--;
    }
}
void delete_last ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Patient List is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr && head!=nullptr)
    {
        delete head;
        cout<<"\nDeleted head node!\tRemoved first patient\n";
        head=nullptr;
        rear=nullptr;
        listSize--;
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        delete temp;
        temp=nullptr;
        rear->next=nullptr;
        cout<<"\nDeleted last node!\tRemoved last patient\n";
        listSize--;
    }
}
void delete_specified (int pos)
{
    if (pos<=0)
    {
        cerr<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (pos==1)
        {
            delete_first ();
        }
        else if (pos>1 && pos<listSize)
        {
            Node *n=head->next, *p=head;
            int i=1;
            while (i<pos-1)
            {
                p=n;
                n=n->next;
                i++;
            }
            Node *temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            delete temp;
            listSize--;
            temp=nullptr;
        }
        else if (pos==listSize)
        {
            delete_last ();
        }
        else
        {
            cerr<<"\nPosition out of range!\n";
        }
    }
}
void searchPatientByPosition (int pos)
{
    if (pos<=0)
    {
        cerr<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (head==nullptr)
        {
            cout<<"\nPatient list is empty!\tNothing to search for\n";
        }
        else
        {
            Node *temp=head;
            int i=0;
            bool flag=0;
            while (temp!=nullptr)
            {
                i++;
                if (i==pos)
                {
                    flag=1;
                    cout<<"\nFound patient with ID : "<<temp->ID<<" at position : "<<pos<<endl;
                    break;
                }
                temp=temp->next;
            }
            if (!flag)
            {
                cout<<"\nPosition out of range!\n";
            }
        }
    }
}
void searchPatientByID (int id)
{
    if (head==nullptr)
    {
        cout<<"\nPatient list is empty!\nNothing to search for\n";
    }
    else
    {
        Node *temp=head;
        int i=0;
        bool flag=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->ID == id)
            {
                flag=1;
                cout<<"\nFound patient [ "<<temp->ID<<", "<<temp->name<<", "<<temp->disease<<" ] at position : "<<i<<endl;
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nPatient NOT found!\n";
        }
    }
}
void deletePatientByID (int id)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Patient list is empty!\nNothing to delete\n";
    }
    else
    {
        Node *temp=head;
        bool flag=0;
        int i=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->ID==id)
            {
                flag=1;
                delete_specified (i);
                cout<<"\nFound patient [ "<<temp->ID<<", "<<temp->name<<", "<<temp->disease<<" ] at position : "<<i<<endl;
                break;
            }
            temp=temp->next;
        }
    }
}
void displayMenu ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Create Node\t             2.Display Forward\t              ";
    cout<<"3.Display Backward\n4.Insert patient at first    5.Insert patient at last\t      ";
    cout<<"6.Insert patient at specified position\n7.Remove first patient\t     ";
    cout<<"8.Remove last patient\t      9.Remove patient at specified position\n10.Count Patients\t";
    cout<<"     11.Search patient by position    12.Search patient by ID\n";
    cout<<"13.Delete patient by ID\t     14.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, id, pos;
    string n, d;
    do
    {
        displayMenu ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput ID : ";
            cin>>id;
            cout<<"Input name of patient : ";
            cin>>n;
            cout<<"Input disease suffering : ";
            cin>>d;
            addPatient (id, n, d);
            break;
        case 2:
            displayForward ();
            break;
        case 3:
            displayBackward ();
            break;
        case 4:
            cout<<"\nInput ID : ";
            cin>>id;
            cout<<"Input name of patient : ";
            cin>>n;
            cout<<"Input disease suffering : ";
            cin>>d;
            insert_first (id, n, d);
            break;
        case 5:
            cout<<"\nInput ID : ";
            cin>>id;
            cout<<"Input name of patient : ";
            cin>>n;
            cout<<"Input disease suffering : ";
            cin>>d;
            insert_last (id, n, d);
            break;
        case 6:
            cout<<"\nInput position at which patient is to be inserted : ";
            cin>>pos;
            cout<<"\nInput ID : ";
            cin>>id;
            cout<<"Input name of patient : ";
            cin>>n;
            cout<<"Input disease suffering : ";
            cin>>d;
            insert_specified (pos, id, n, d);
            break;
        case 7:
            delete_first ();
            break;
        case 8:
            delete_last ();
            break;
        case 9:
            cout<<"\nInput position at which patient is to be deleted : ";
            cin>>pos;
            delete_specified (pos);
            break;
        case 10:
            cout<<"\nSize of patient list is : "<<listSize<<endl;
            break;
        case 11:
            cout<<"\nInput position of patient to be searched : ";
            cin>>pos;
            searchPatientByPosition (pos);
            break;
        case 12:
            cout<<"\nInput ID of patient to be searched : ";
            cin>>id;
            searchPatientByID (id);
            break;
        case 13:
            cout<<"\nInput ID of patient to be deleted : ";
            cin>>id;
            deletePatientByID (id);
            break;
        case 14:
            cout<<"\n======[Exiting the program...]======\n";
            exit (0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=14);
    return 0;
}
