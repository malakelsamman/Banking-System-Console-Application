#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

class Transaction
{
    int transactionID;
    string transactionName;
    string transactionDate;
    public:
    Transaction()
    {
        transactionID=0;
        transactionName="NULL";
        transactionDate="NULL";
    }
    Transaction(int id, string name, string date)
    {
        transactionID = id;
        transactionName = name;
        transactionDate = date;
    }
    void settID(int id)
    {
       transactionID=id;
    }

    void settName(string name)
    {
       transactionName=name;
    }

    void settDate(string date)
    {
       transactionDate=date;
    }

    int gettransactionID()
    {
        return transactionID;
    }

    string gettransactionName()
    {
        return transactionName;
    }

    string gettransactionDate()
    {
        return transactionDate;
    }

    void display_transaction_info()
    {

    cout<<"transaction name : "<< gettransactionName()<<endl;
    cout<<"transaction date : "<< gettransactionDate()<<endl;
    cout<<"transaction id : "<< gettransactionID()<<endl;
    }
};


class Client
{
    private:
        string clientName;
        string clientEmail;
        string clientPhone;
        string clientAddress;
        string clientPassword;
        int clientID;
        Transaction arr[5];
        int index; //dah ashan ama nygy ne7ot transaction fy el array of transaction ely 3and kol client, kol ama nezawed t el index betzyd
    public:
    Client()
    {
        clientName="NULL";
        clientEmail="NULL";
        clientPhone="null";
        clientAddress="NULL";
        clientPassword="NULL";
        clientID=0;
        index=0;
        for(int i=0;i<5;i++)
        {
            arr[i].settID(0);
            arr[i].settName("NULL");
            arr[i].settDate("NULL");

        }

    }
	Client(string cn, string ce, string cph, string ca)
    {
		clientName = cn;
        clientEmail = ce;
        clientPhone = cph;
        clientAddress = ca;
        clientID=rand();
        clientPassword="NULL";
        index=0;
        for(int i=0;i<5;i++)
        {
            arr[i].settID(0);
            arr[i].settName("NULL");
            arr[i].settDate("NULL");

        }
    }

    void setClientname(string n)
    {
        clientName=n;
    }

    void setClientemail(string e)
    {
        clientEmail=e;
    }

    void setClientphone(string ph)
    {
        clientPhone=ph;
    }

    void setClientaddress(string a)
    {
        clientAddress=a;
    }

    void setClientpass(string p)
    {
        clientPassword=p;
    }

    void settransaction(Transaction t)  //ben add el transaction lel array
    {
        if(index==5 )
        {
            cout<<"cant add any transactions"<<endl;
            return;
        }
        arr[index]=t;
        index++;
        cout<<"*****TRANSACTION IS ADDED*******"<<endl<<endl;
    }

    void deletetransaction(int id)
    {
        for(int i=0;i<5;i++)
        {
            if(arr[i].gettransactionID()==id)
            {
                arr[i].settDate("NULL");
                arr[i].settID(0);
                arr[i].settName("NULL");
                cout<<"transaction is deleted"<<endl;
                return;
            }

        }
        cout<<"*****************THERE IS NO TRANSACTION WITH THIS ID****************"<<endl;
    }

    bool loop(int id) //dyh ashan law el client da5al transaction leeha id zay id beta3 transactin already 3ando fy el arr of t
    {
        for(int i=0;i<5;i++)
        {
            if(arr[i].gettransactionID()==id) //law fy transaction fy el array 3andaha nafs el id?
            {

                return true; //teraga3 true
            }

        }
        return false;
    }

    int getclientID()
    {
        return clientID;
    }

    string getClientname()
    {
        return clientName;
    }

    string getClientemail()
    {
        return clientEmail;
    }

    string getClientphone()
    {
        return clientPhone;
    }

    string getClientaddress()
    {
        return clientAddress;
    }

    string getClientpass()
    {
        return clientPassword;
    }

    void display_client_info()
    {
    cout<<"         DIPLAYING THE CLIENT'S INFORMATION            "<<endl;
    cout<<"client's name : "<< getClientname()<<endl;
    cout<<"client's email : "<< getClientemail()<<endl;
    cout<<"client's phone : "<< getClientphone()<<endl;
    cout<<"client's address : "<< getClientaddress()<<endl;
    cout<<"client's ID : "<< getclientID()<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"         DIPLAYING transaction "<< i+1<<" INFORMATION            "<<endl;
        arr[i].display_transaction_info();

    }
    }

    void displaytrans()
    {
        for(int i=0;i<5;i++)
        {
            cout<<"         DIPLAYING transaction "<< i+1<<" INFORMATION            "<<endl;
            arr[i].display_transaction_info();

        }

    }

};

template <class T>
class LinkedListNode
{
    public:
        T data;
        LinkedListNode<T>* next;

        LinkedListNode(T e)
        {
            data = e;
            next = NULL;
        }
};

template <class T>
class ClientsLinkedList    //dah el single linked list kol node feeh 2o3bara 3an client
{
    public:
	LinkedListNode<T>* head;
    int listsize=0; //el size dah han7tago fy 7etet el quick sort ba3deen
	ClientsLinkedList()
    {
        head=NULL;
    }

	bool insert_client(T e)
    {
        LinkedListNode<T>* newemployee = new LinkedListNode<T>(e);
        if(head ==NULL)     //law el employee ely ha inserto fy el awel
        {
            head= newemployee;
            listsize++;
            /*cout<<"******************************client is added*************"<<endl;
            cout<<endl;
            cout<<endl;*/
            return true;
        }

        LinkedListNode<T>* temp = head;
        while(temp!= NULL)   //loop law el user name already exists
        {
            if (temp->data.getClientemail()==e.getClientemail())  //law ely hainserto dah already mawgoooood
            {
                cout<<"******************email already exists**********"<<endl;
                cout<<endl;
                cout<<endl;
                return false;
            }
            temp=temp->next;  //7afdal alef lehad ama yo2af 3and ba3d a5er node
        }

        LinkedListNode<T>* curr = head;
        while(curr->next!=NULL) //7afdal a loop lehad ama yegey a5er node (ely el next beta3o =null) we hainsert ba3do
        {
            curr=curr->next;
        }

        curr->next = newemployee;
        listsize++;
        /*cout<<"**********client is added*************"<<endl;
        cout<<endl;
        cout<<endl;*/

        return true;

    }

    int getclientslinkedlistsize()
    {
        return listsize;
    }
    bool print_clients()
    {
        if(head ==NULL)
        {
            cout<<"*********the list is empty********"<<endl;
            return false;
        }

        LinkedListNode<T>* temp = head;
        while(temp != NULL)
        {
            cout<<"#####################################################################"<<endl;
            temp->data.display_client_info();
            temp = temp->next;
        }

        return true;


    }

    bool is_client_in_list(string email, string pass) //benecheck law el email wel pass mawgodyn wala la
    {
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)
        {
            if (temp->data.getClientemail()==email && temp->data.getClientpass()==pass)  //law el email wel pass mawgooooodeen
            {
                cout<<"*********client in list*************"<<endl;
                cout<<endl;
                cout<<endl;
                return true;
            }
            temp=temp->next;  //7afdal alef lehad ama yo2af 3and ba3d a5er node
        }
        cout<<"***********wrong email or password********"<<endl;
        cout<<endl;
        cout<<endl;
        return false;

    }


    bool is_email_in_list(string email) //dyh ashan law el user nesy el pass beta3o (forgot function)
    {
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)   //loop law el user name already exists
        {
            if (temp->data.getClientemail()==email)
            {
                cout<<"THE CLIENTS PASSWORD :"<<endl;
                cout<<temp->data.getClientpass()<<endl;
                return true;
            }
            temp=temp->next;
        }
        cout<<"*********wrong email********"<<endl;
        cout<<endl;
        cout<<endl;
        return false;

    }

    bool clientsinfo(string email) //3ashan atba3 el info beta3t el client
    {
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)   //loop law el user name already exists
        {
            if (temp->data.getClientemail()==email)
            {
                temp->data.display_client_info();
                return true;
            }
            temp=temp->next;
        }
        cout<<"***********wrong email or password***********"<<endl;
        cout<<endl;
        cout<<endl;
        return false;

    }


    void settrans(string email,Transaction t) //ama a7eb 2aadd transaction le client badawar aleh el awel fy el linked list ba3dyha ba3dyhaa aadd
    {
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)   //badawar 3ala el client
        {
            if (temp->data.getClientemail()==email)
            {
                if(temp->data.loop(t.gettransactionID()))  //law id el transaction kan mawgod already fy el list
                {
                    cout<<"******** THERE IS A TRANSACTION WITH THE SAME ID ************* "<<endl;
                    return;
                }
                temp->data.settransaction(t);
                return;
            }
            temp=temp->next;
        }
        cout<<"***********wrong email"<<endl;
        cout<<endl;
        cout<<endl;
        return;

    }

    void deletetrans(string email,int id)
    {
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)
        {
            if (temp->data.getClientemail()==email)  //law el client dah mawgoooood
            {
                temp->data.deletetransaction(id);
                return;
            }
            temp=temp->next;
        }
        //cout<<"***********wrong email"<<endl;
        cout<<endl;
        cout<<endl;
        return;

    }

    void viewtrans(string email) //neshof el transactions beta3t kol client
    {
    LinkedListNode<T>* temp = head;
    while(temp!= NULL)
    {
    if (temp->data.getClientemail()==email)  //nedawar 3ala el email el awel fy el ll
    {
        temp->data.displaytrans();
        return;
    }
    temp=temp->next;
    }
    cout<<"***********wrong email"<<endl;
    cout<<endl;
    cout<<endl;
    return;

    }

    void namesforhashing()  //lel hashinggggggg ashan netala3 el emails beto3 kolel clients ely fy list
    {
        if(listsize==0)
        {
            return;
        }
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)
        {
            cout<<temp->data.getClientemail()<<"-->";
            temp=temp->next;
        }
    }

    void idsforhashing()  //lel hashinggggggg ashan netala3 el id beto3 kolel clients ely fy list
    {
        if(listsize==0)
        {
            return;
        }
        LinkedListNode<T>* temp = head;
        while(temp!= NULL)
        {
            cout<<temp->data.getclientID()<<"-->";
            temp=temp->next;
        }
    }

    void sortbyid()
    {
        Client x; //ashan n5azen fyh el client ely han3mlo sort
        if(head ==NULL)
        {
            //cout<<"*********the list is empty********"<<endl;
            return;
        }

        //amany(19) malak(9) hana(20) lara (4)

        LinkedListNode<T>* temp = head; //temp=amany
        LinkedListNode<T>* index = NULL;
        while(temp != NULL)
        {
            //el client ely ba33d el head
            index=temp->next; //index = malak

            while(index!=NULL) //benlef
            {
                if(temp->data.getclientID() > index->data.getclientID()) //19>9
                {
                    x=temp->data; //x= temp (amany)
                    temp->data=index->data; //temp(amany)= index (malak)
                    index->data=x; //index(malak) = x(amany)
                    //malak(9) amany(19) hana(20) lara(4)
                      //   ^     //   ^
                    //temp |  //index |
                }
                index=index->next;
            }
            temp=temp->next;

        }
    }

};

//***********************HASHING**********************
    int hashFunction(int x) //el x dah el id beta3 el client
    {
        return (x % 10);
    }

    template <class T>
    void insertItem(Client x, ClientsLinkedList<T> (&arr)[10]) //3ashan ne insert fy el arr[10]
    {
        int index = hashFunction(x.getclientID());
        arr[index].insert_client(x);
    }

    template <class T>
    void displayHash(ClientsLinkedList<T> (&arr)[10])
    {
        cout<<endl;
        cout<<endl;
        cout<<"REVIEWING THE ARRAY by email"<<endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i<<"--> ";
            arr[i].namesforhashing();
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        cout<<"REVIEWING THE ARRAY by id"<<endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i<<"--> ";
            arr[i].idsforhashing();
            cout<<endl;
        }

    }
//************************Quick sorting el arr[10] bel sizeee**************
template <class T>
void swap(ClientsLinkedList<T>* a, ClientsLinkedList<T>* b) //dyh ashan nebadl ll be ll
{
    ClientsLinkedList<T> t = *a;
    *a = *b;
    *b = t;
}

 template <class T>
int partition(ClientsLinkedList<T> (&arr)[10], int low, int high) //low dah arr[0] we high dah arr[9]
{
    int pivot = arr[high].getclientslinkedlistsize(); // pivot (size beta3 a5er linkedlist fy el arr)
    int i= (low-1); // i= arr[-1]

    //law el arr[0,1,3,2,3,1,3,0,2,3] for example
    for (int j = low; j <= high - 1; j++) //j=0, law el pivot el size beta3o 3 we dah akbar haga mawgoda el func dyh bet5aly el arr[0,1,2,1,0,2,3,3,3,3]
    {
        // If current element is smaller than the pivot
        if (arr[j].getclientslinkedlistsize() < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);//7an5aly el 3 ely fy el a5er dyh teb2a awel 3 ashan law fy arkam akbar men 3 tethat el 3 el awel
    return (i + 1); //el index beta3 awel 3 / el index ely ba3d a5er rakam as8ar men el pivot
}

template <class T>
void quickSort(ClientsLinkedList<T> (&arr)[10], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high); //pi=6 (awel 3)

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1); //hena el high haykon a5er rakam abl 3 ashan nerateb kol ely abloo
        quickSort(arr, pi + 1, high);// hena el low haykon awel rakam ba3d el 3 ashan nerateb kol ely ba3do
    }
}

template <class T>
void displayqq(ClientsLinkedList<T> (&arr)[10])
{
    cout<<"REVIEWING THE ARRAY"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<< arr[i].getclientslinkedlistsize()<<" CLIENTS AT INDEX "<<i<<" : "<<endl;
        arr[i].print_clients();
        cout<<endl;
    }
}
//******************************quick sorting el arr bel id*********************************************
template <class T>
void sorting(ClientsLinkedList<T> (&arr)[10])
{
    for(int i=0;i<10;i++)
    {
        arr[i].sortbyid();
    }
}
//HENA 7ETET EL FUNCTIONS
template <class T>
void transactionmenu(string email,ClientsLinkedList<T>& c,ClientsLinkedList<T> (&arr)[10])
{
    cout<<endl;
    cout<<endl;
    cout<<"<<<<<<<<<CHOOSE ONE OF THE FOLLOWING OPTIONS>>>>>>>>>>>>>"<<endl;
    cout<<"1.create a new transaction"<<endl;
    cout<<"2.View your transactions"<<endl;
    cout<<"3.delete a transaction by its id"<<endl;
    cout<<"4.go back to the client's menu"<<endl;
    cout<<"5.go back to the main menu"<<endl;


    int x;
    cin>>x;
    if(x==1)
    {
        cout<<"enter transactions name :"<<endl;
        string name;
        cin>>name;
        cout<<"enter transactions date :"<<endl;
        string date;
        cin>>date;
        cout<<"enter transactions id :"<<endl;
        int id;
        cin>>id;
        Transaction t (id,name,date);
        c.settrans(email,t);
       // cout<<"*****TRANSACTION IS ADDED*******"<<endl<<endl;
        transactionmenu(email,c,arr);
        return;

    }

    if(x==2)
    {
        c.viewtrans(email);
        cout<<endl;
        transactionmenu(email,c,arr);
        return;

    }

    if(x==3)
    {
        int idd;
        cout<<"enter the id of the transaction that you want to delete"<<endl;
        cin>>idd;
        c.deletetrans(email,idd);
        transactionmenu(email,c,arr);
        return;

    }

    if(x==4)
    {
        clienthome(email,c,arr);
        return;
    }

    if(x==5)
    {
        mainmenu(c,arr);
        return;
    }
}

template <class T>
void loginmenu(ClientsLinkedList<T>& c,ClientsLinkedList<T> (&arr)[10])
{
    cout<<endl;
    cout<<endl;
    cout<<"Welcome back"<<endl;
    cout<<"please enter your email"<<endl;
    string emaill;
    cin>>emaill;
    cout<<"Please enter your password"<<endl;
    string pass;
    cin>>pass;
    if(c.is_client_in_list(emaill,pass))
    {
        clienthome(emaill,c,arr);
        return;
    }
    mainmenu(c,arr);
    return;
}


template <class T>
void clienthome(string email,ClientsLinkedList<T>& c,ClientsLinkedList<T> (&arr)[10])
{

    cout<<endl;
    cout<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<CHOOSE ONE OF THE FOLLOWING OPTIONS >>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"1.Transaction menu"<<endl;
    cout<<"2.View personal info"<<endl;
    cout<<"3.Logout"<<endl;
    int num;
    cin>>num;
    if(num==1)
    {
        transactionmenu(email,c,arr);
        return;
    }

    if(num==2)
    {
        c.clientsinfo(email); //beylef fy el linked list we yedawar ala el email we awel ama yela2y yeb3at el info beta3to
        clienthome(email,c,arr);
        return;
    }

    if(num==3)
    {
        mainmenu(c,arr);
        return;
    }

}


template <class T>
void newclient(ClientsLinkedList<T>& c, ClientsLinkedList<T> (&arr)[10])
{
    cout<<"Please write your name"<<endl;
    string namee;
    getline(cin>> ws, namee); //remove all leading whitespace
    //cin>>namee;

    cout<<"Please write your email"<<endl;
    string emaill;
    cin>>emaill;
    cout<<"please enter your phone"<<endl;
    string phone;
    cin>>phone;
    cout<<"please enter your password"<<endl;
    string pass;
    cin>>pass;
    cout<<"please enter your address"<<endl;
    string adr;
    getline(cin>> ws, adr); //remove all leading whitespace
    //cin>>adr;

    Client c1(namee,emaill,phone,adr);
    c1.setClientpass(pass);
    if(c.insert_client(c1))
    insertItem(c1,arr);
    //h.displayHash();
    //hash el end beta3 el c
    mainmenu(c,arr);
    return;
}


template <class T>
void forgot(ClientsLinkedList<T>& c)
{
    cout<<"enter your email"<<endl;
    string em;
    cin>>em;
    c.is_email_in_list(em);
}


template <class T>
void mainmenu(ClientsLinkedList<T>& c, ClientsLinkedList<T> (&arr)[10]) //hena amalna pass by refrence ashan manst5dmsh copy men el haga nesta5dem el haga nafsaha
{
    cout<<endl;
    cout<<endl;
    cout<<"CHOOSE ONE OF THE FOLLOWING OPTIONS"<<endl;
    cout<<"1. LOGIN to your account"<<endl;
    cout<<"2. NEW CLIENT?"<<endl;
    cout<<"3. FORGOT YOUR PASSWORD?"<<endl;
    cout<<"4. SORT CLIENTS BY LINKED LIST SIZE USING THE QUICKSORT ALGORITHM"<<endl;
    cout<<"5. Display Hash table"<<endl;
    cout<<"6. EXIT THE PROGRAM"<<endl;
    cout<<"7. Arrange array by ID"<<endl;

    int x;
   // int flag =1;
    while(true)
    {
        cin>>x;
        if(x==1)
        {
            loginmenu(c,arr);
            return;
        }

        if(x==2)
        {
            newclient(c,arr);
            return;
        }

        if(x==3)
        {
            forgot(c);
            mainmenu(c,arr);
            return;
        }

        if(x==4)
        {
            quickSort(arr,0,9);
            cout<<"*******AFTER USING QUICKSORT***********"<<endl;
            displayHash(arr);
            displayqq(arr);
            mainmenu(c,arr);
            return;
        }

        if(x==5)
        {
            cout<<"*************AFTER HASHING*************"<<endl;
            displayHash(arr);
            mainmenu(c,arr);
            return;
        }

        if(x==6)
        {
            return;
            //flag=0;

        }

        if(x==7)
        {
            sorting(arr);
            cout<<"*******************AFTER SORTING BY ID******************"<<endl;
            displayHash(arr);
            mainmenu(c,arr);
            return;
        }

        else
        {
            cout<<"the number is not in the list"<<endl;
            cout<<"enter a new number"<<endl;
        }
    }
}

int main()
{
    ClientsLinkedList<Client> c;
    //Hash h;
    ClientsLinkedList<Client> arr[10];
    mainmenu(c,arr);
    return 0;
}
