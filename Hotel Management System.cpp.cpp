#include<iostream>
#include<conio.h>
using namespace std;

class node
{
	public:
	string name_of_customer,ID_Card,Address,Phone_num,feedback;
	int members,no_of_days,total_hours,room_no;
	node *next;
};

class linklist
{
	
	node *head;//for linked list
	node *temp;//for traversing
	node *newnodeptr;//for creating the new node
	node *head_2;//for meeting purpose
	public :
	linklist();
	//check whether node is empty or not
	int check();
	//check for meeting's
	int check_M();
	//check whether room/ID is booked or not
	int check_room(string,int);
	//function to book room
	void Book_a_Room();
	//function to cancel a room
	void Delete_a_Room();
	//function to book a meeting
	void Book_a_Meeting();
	//function to cancel the meeting
	void Cancel_a_Meeting();
	//function to change customer detail by admin
	void Change_Details();
	//function to check the details
	void Check_Details();
	//function to view mettings details
	void Meeting_Details();
	//function to see the bill
	void Check_Bill();
	//function to take feedback by customer
	void FeedBacks();
	//function to view feedback
	void View_FeedBacks();	
	//destructure
	~linklist();
};		
linklist::linklist()
{
    head = NULL;
    head_2 = NULL;
}

int linklist::check()
{
			temp = head;
			if(temp == NULL)
			{
				return 1;
			}
			else 
			{
				return 0;
			}
			
}
		
int linklist::check_M()
{
	temp = head_2;
	if(temp == NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
			
}
		
int linklist::check_room(string ID,int room)
{
			temp =head;
			int flag=0;
			
			while(temp!= NULL)
			{
				if(ID == temp->ID_Card && room == temp->room_no)
				{
					flag =1;
					return 1;
				}
				temp = temp->next;
			}
			if(flag == 0)
			{
				return 0;
			}
}
		
//function to book a room
void linklist::Book_a_Room()
{
	system("cls");
	string name,ID,address,phone;
	int member_no,days,room,flag;
			
	cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|     BOOK A ROOM    |\n";
    cout<<"\t\t\t\t|____________________|\n";
	A :
	cout<<"Enter Customer's ID : ";
	cin>>ID;
	cout<<"Enter Room No : ";
	cin>>room;
	flag = check_room(ID,room);
	if(flag == 0)
	{
			
		cout<<"Enter Customer's Name : ";	
		cin>>name;
		cout<<"Enter Customer's Address : ";
		getline(cin,address);
		cin>>address;
		cout<<"Enter Customer's Phone No : ";
		cin>>phone;
		cout<<"Enter Total Members : ";
		cin>>member_no;
		cout<<"Enter Days of Stay : ";
		cin>>days;
			
		newnodeptr = new node;
		newnodeptr->name_of_customer = name;
		newnodeptr->ID_Card = ID;
		newnodeptr->Address = address;
		newnodeptr->Phone_num = phone;
		newnodeptr->members = member_no;
		newnodeptr->no_of_days = days;
		newnodeptr->room_no = room;
		//lifo
		newnodeptr->next = head;
		head = newnodeptr;	
	}
	else
	{
		cout<<"ID Already In Use.....! "<<endl;
		goto A;
	}
	getch();
								
}
		
//function to cancel a room
void linklist::Delete_a_Room()
{
	system("cls");
			
	cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|   DELETE A ROOM    |\n";
    cout<<"\t\t\t\t|____________________|\n";
			
	string ID;
	int room;
	cout<<"Enter ID No : ";
	cin>>ID;
	cout<<"Enter Room No : ";
	cin>>room;
			
	//node *temp ,*next_node,*temp2,*temp3;
		
	int flag=0,i=0,flag2=0;
	//checking the list
	flag = check();
	//checking the room
	flag2= check_room(ID,room);
	if(flag == 1)
	{
		cout<<"Node is Empty "<<endl;
	}
	else if(flag2==0)
	{
		cout<<"\n\tRecord Not Found.....!\n";
		getch();
	}
	else
	{
//		node *temp ,*next_node,*temp2;
		node *temp2;	
		temp = head;
		temp2 = head;
		while(temp2->ID_Card != ID)
		{		   
		     	   
			temp2 = temp2->next;
			i++;
		}
			    
		if(i == 0)
		{
			head = temp2->next;
		}
		else
		{
			while(temp->next->ID_Card != ID)
		    {                 
				temp = temp->next;
			}
			temp->next = temp2->next;			
					
		}
			   
			    
			delete (temp2);
				   
			cout<<"\n\n\tRecord Deleted.....!\n";
			getch();    
				   
		}
}
		
//function to book a meeting

void linklist::Book_a_Meeting()
{
			system("cls");
			string name,ID,address,phone;
			int member_no,hours;
						
			cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|   BOOK A MEETING   |\n";
            cout<<"\t\t\t\t|____________________|\n";
			
			cout<<"Enter Customer's Name : ";
			cin>>name;
			cout<<"Enter Customer's ID No : ";
			cin>>ID;
			cout<<"Enter Customer's Address : ";
			cin>>address;
			cout<<"Enter Customer's Phone No : ";
			cin>>phone;
			cout<<"Enter Total Members : ";
			cin>>member_no;
			cout<<"Enter Timing : ";
			cin>>hours;
			
				newnodeptr = new node;
			
			    newnodeptr->name_of_customer = name;
				newnodeptr->ID_Card = ID;
				newnodeptr->Address = address;
				newnodeptr->Phone_num = phone;
				newnodeptr->members = member_no;
				newnodeptr->total_hours = hours;
			//lifo principle
			newnodeptr->next = head_2;
			head_2 = newnodeptr;
}		
//function to cancel a meeting
void linklist::Cancel_a_Meeting()
{
			system("cls");
			cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|  CANCEL A MEETING  |\n";
            cout<<"\t\t\t\t|____________________|\n";
            
            if(head_2 == NULL)
			{
				cout<<"Empty"<<endl;
				getch();//waiting for user to press enter
			}
			else
			{
				
				temp = head_2;
				
				cout<<"Customer's Name : "<<temp->name_of_customer<<endl;
				cout<<"Customer's ID : "<<temp->ID_Card<<endl;
				cout<<"Customer's Address : "<<temp->Address<<endl;
				cout<<"Customer's Phone No : "<<temp->Phone_num<<endl;
				cout<<"Total Members : "<<temp->members<<endl;
				cout<<"Hours : "<<temp->total_hours<<endl;
				
				head_2 = head_2 ->next;
				temp->next = NULL;
				delete(temp);
				cout<<"\t\tMEETING CANCELLED\n";
				getch();
			}
			
}
		
//function to change customers details by admin
void linklist::Change_Details()
		{
			system("cls");
			cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|   CHANGE DETAILS   |\n";
            cout<<"\t\t\t\t|____________________|\n";
            
			temp = head_2;
			
			string name,ID,address,phone;
			int member_no,days,room;
			
			int flag=0,i=0,flag2=0;
			flag = check();
			
			cout<<"Enter ID : ";
			cin>>ID;
			
			if(flag == 1)
			{
				cout<<"Node is Empty "<<endl;
			}
			else
			{
				while(temp!= NULL)
				{
					if(temp->ID_Card == ID)
					{
						cout<<"Customer's Name : "<<temp->name_of_customer<<endl;
			        	cout<<"Customer's ID : "<<temp->ID_Card<<endl;
				        cout<<"Customer's Address : "<<temp->Address<<endl;
				        cout<<"Customer's Phone No : "<<temp->Phone_num<<endl;
				        cout<<"Total Members : "<<temp->members<<endl;
				        cout<<"Days of Stay: "<<temp->no_of_days<<endl;
				        cout<<"Room No: "<<temp->room_no<<endl;
				        
				        cout<<"Enter New Details : "<<endl;

						cout<<"Enter Customer's Name : ";
						cin>>name;
						cout<<"Enter Customer's Address : ";
						cin>>address;
						cout<<"Enter Customer's Phone No : ";
						cin>>phone;
						cout<<"Enter Total Members : ";
						cin>>member_no;
						cout<<"Enter Days of Stay : ";
						cin>>days;
					                   
					    temp->name_of_customer = name;
						temp->ID_Card = ID;
						temp->Address = address;
						temp->Phone_num = phone;
						temp->members = member_no;
						temp->no_of_days = days; 
						flag2 =1;	
					}
					temp = temp->next;
				}
				if(flag2 == 0)
				{
					cout<<"ID not Found.....!"<<endl;
				}          				                
				        
				        
			}
			
			getch();	
}
		
//function to view details 
void linklist::Check_Details()
{
			system("cls");
			cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|    CHECK DETAILS   |\n";
            cout<<"\t\t\t\t|____________________|\n";
			
			temp = head;
			
			string name,ID,address,phone;
			int member_no,days;
			
			int flag=0,i=0,flag2=0;
			flag = check();
			
			cout<<"Enter ID : ";
			cin>>ID;
			
			if(flag == 1)
			{
				cout<<"Node is Empty "<<endl;
			}
			else
			{
				while(temp!= NULL)
				{
					if(temp->ID_Card == ID)
					{
						cout<<"Customer's Name : "<<temp->name_of_customer<<endl;
			        	cout<<"Customer's ID : "<<temp->ID_Card<<endl;
				        cout<<"Customer's Address : "<<temp->Address<<endl;
				        cout<<"Customer's Phone No : "<<temp->Phone_num<<endl;
				        cout<<"Total Members : "<<temp->members<<endl;
				        cout<<"Days of Stay: "<<temp->no_of_days<<endl;
				        flag2=1;
					}
					temp = temp->next;
				}
				if(flag2 == 0)
				{
					cout<<"ID not Found.....!"<<endl;
				}          				                
				        
				        
			}
			
		getch();	
}
		
void linklist::Meeting_Details()
{
			system("cls");
			cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|    CHECK DETAILS   |\n";
            cout<<"\t\t\t\t|____________________|\n";
			
			temp = head_2;
			
			string ID;
			int flag=0,i=0,flag2=0;
			flag = check_M();
			
			cout<<"Enter ID : ";
			cin>>ID;
			
			if(flag == 1)
			{
				cout<<"Node is Empty "<<endl;
			}
			else
			{
				while(temp!= NULL)
				{
					if(temp->ID_Card == ID)
					{
						cout<<"Customer's Name : "<<temp->name_of_customer<<endl;
			        	cout<<"Customer's ID : "<<temp->ID_Card<<endl;
				        cout<<"Customer's Address : "<<temp->Address<<endl;
				        cout<<"Customer's Phone No : "<<temp->Phone_num<<endl;
				        cout<<"Total Members : "<<temp->members<<endl;
				        cout<<"Total hours: "<<temp->total_hours<<endl;
				        flag2=1;
					}
					temp = temp->next;
				}
				if(flag2 == 0)
				{
					cout<<"ID not Found.....!"<<endl;
				}          				                
				        
				        
			}
			
		getch();	
}
		
//function to view bills of room
void linklist::Check_Bill()
{
		system("cls");
		
		    cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|     CHECK BILL     |\n";
            cout<<"\t\t\t\t|____________________|\n";
			
		int room,flag;
		string ID;
		
		cout<<"Enter ID No : ";
		cin>>ID;
		cout<<"Enter Room No : ";
		cin>>room;
		
		flag = check_room(ID,room);
		if(flag == 1)
		{
			temp = head;
			while(temp!=NULL)
			{
				if(temp->ID_Card == ID)
				{
					if(temp->room_no<=30 )
					{
						cout<<"\t Bill For Your Room : 20,000 \n";
					}
					else if(temp->room_no<=40 )
					{
						cout<<"\t Bill For Your Room : 30,000 \n";
					}
					else if(temp->room_no>=41 )
					{
						cout<<"\t Bill For Your Room : 40,000 \n";
					}
				}
				temp = temp->next;
			}
		}
		else
		{
			cout<<"\n\tRecord Not Found....!";
			
		}
		getch();
}
	
//function to enter feedbacks by customer
void linklist::FeedBacks()
{
		system("cls");
		
		    cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|      FEEDBACKS     |\n";
            cout<<"\t\t\t\t|____________________|\n";
            
            
		    temp = head;
			
			string ID,fdk;
			int member_no,days,room;
			
			int flag=0,i=0,flag2=0;
			flag = check();
			
			cout<<"Enter ID : ";
			cin>>ID;
			
			if(flag == 1)
			{
				cout<<"Node is Empty "<<endl;
			}
			else
			{
				while(temp!= NULL)
				{
					if(temp->ID_Card == ID)
					{
						cout<<"Customer's Name : "<<temp->name_of_customer<<endl;									        
				        cout<<"Enter FEEDBACK : ";
						cin>>fdk;
                        
                        temp->feedback = fdk;
			
					flag2 =1;	
					}
					temp = temp->next;
				}
				if(flag2 == 0)
				{
					cout<<"ID not Found.....!"<<endl;
				}          				                
				        
				        
			}
			
		getch();
}
	
//function to view feedbacks by new customers
void linklist::View_FeedBacks()
{
		system("cls");
			cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|      FEEDBACKS     |\n";
            cout<<"\t\t\t\t|____________________|\n";
			
			temp = head;
			
			int flag=0;
			flag = check();
			
			
			
			if(flag == 1)
			{
				cout<<"No Record Found "<<endl;
			}
			else
			{
				while(temp!= NULL)
				{
						cout<<"Customer's Name : "<<temp->name_of_customer<<endl;
			        	cout<<"Customer's ID : "<<temp->ID_Card<<endl;
				        cout<<"FeedBack : "<<temp->feedback<<endl;
				        
					temp = temp->next;
				}  
				        
			}
			
		getch();	
		
}
//end class
linklist::~linklist()
{
	//deallocating the memory
	delete head;
	delete temp;
	delete newnodeptr;
	delete head_2;
}
//some function declaractions 
void Administration();//for adminstrative purpose
void Customer();//for customer
void Description();//to show description
void main_menu();//to display main menu
//main function
int main()
{
	//main menu is called from main so that different functions can be called
	main_menu();
	return 0;
}

//creating the class instance globally 
linklist L;		
//function to use all authorities by ADMIN
void Administration()
{
	system("cls");
	
	int choice;
	do
	{
		system("cls");
		
	cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t| ENTER YOU CHOICE : |\n";
    cout<<"\t\t\t\t|____________________|\n";
    
    cout<<"\t\t\t\t|1- BOOK A ROOM\n";
    cout<<"\t\t\t\t|2- DELETE A ROOM\n";
    cout<<"\t\t\t\t|3- BOOK A MEETING\n";
    cout<<"\t\t\t\t|4- CANCEL A MEETING\n";
    cout<<"\t\t\t\t|5- DETAILS OF MEETINGS\n";
    cout<<"\t\t\t\t|6- CHANGE DETAILS\n";
    cout<<"\t\t\t\t|7- TO GO BACK  \n";
    cout<<"\t\t\t\t|0- TO EXIT\n";
    
    cout<<"Press Any Choice : ";
    cin>>choice;
    
        if(choice == 1)
        {
            L.Book_a_Room();
		}
		else if(choice == 2)
		{
			L.Delete_a_Room();
		}
		else if(choice == 3)
		{
			L.Book_a_Meeting();
		}
    	else if(choice == 4)
    	{
    		L.Cancel_a_Meeting();
		}
		else if(choice == 5)
    	{
    		L.Meeting_Details();
		}
		else if(choice == 6)
    	{
    		L.Change_Details();
		}
		else if(choice == 7)
    	{
    		main_menu();
		}
		
		else if(choice >= 8 )
		{
			cout<<"Wrong Choice .....!"<<endl;
		}
		else if(choice == 0)
    	{
    		exit(1);
		}
	}
	while(choice !=0);
    getch();
}


//Decsription of hotel containing bills,menu,services etc
void Description()
{
	system("cls");
	cout<<" __________________________________________________________________________________________________________________"<<endl;
	cout<<"|  ______________________________________________________________________________________________________________  |"<<endl;
	cout<<"| |DATE: 20-May-2024                                                                           YOU! WHO MATTERS  | |"<<endl;
	cout<<"| |                                                 WELCOME TO                                                   | |"<<endl;
	cout<<"| |                                              The Stanley Hotel                                               | |"<<endl;
	cout<<"| |                                              HOTEL AND RESORT                                                | |"<<endl;
	cout<<"| |                                                                                                              | |"<<endl;
	cout<<"| |THE MALL, SADAR                                                                         CONTACT : 0320-1154354| |"<<endl;
	cout<<"| |RAWALPINDI, PAKISTAN                                                                              090078609   | |"<<endl;
	cout<<"| |______________________________________________________________________________________________________________| |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________|"<<"\n\n"<<endl;


    cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|  HOTEL DESCRIPTION |\n";
    cout<<"\t\t\t\t|____________________|\n\n\n";
    
    
    cout<<"\t\tROOM DETAILS \t| RENT \t| DAYS"<<endl<<endl;
    cout<<"\t\tFAMILY ROOM  \t| 20000\t| 7 Days"<<endl;
    cout<<"\t\tLUXURY ROOM  \t| 30000\t| 7 Days"<<endl;
    cout<<"\t\tROYAL ROOM   \t| 40000\t| 7 Days"<<endl<<endl<<endl;
    
    cout<<"\t\tMEETING ROOM \t| RENT \t| TIME"<<endl<<endl;
    cout<<"\t\tOFFICE CABIN \t| 10000\t| 1-3 Hours"<<endl<<endl<<endl;
    
    cout<<"\t\tFOOD MENU         \t| PRICE \t| DELIVERY STATUS"<<endl<<endl;
    cout<<"\t\tITALIAN PIZZA(L)  \t| 1600  \t| ALLOWED"<<endl;
    cout<<"\t\tITALIAN PIZZA(M)  \t| 1200  \t| ALLOWED"<<endl;
    cout<<"\t\tITALIAN PIZZA(S)  \t| 900   \t| ALLOWED"<<endl;
    cout<<"\t\tSAVOUR FOOD       \t| 500   \t| NOT ALLOWED"<<endl;
    cout<<"\t\tZINGER ROLL(S)    \t| 350   \t| ALLOWED"<<endl;
    cout<<"\t\tCHICEKEN KARAHI(F)\t| 1050  \t| NOT ALLOWED"<<endl;
    cout<<"\t\tCHICEKEN KARAHI(H)\t| 650   \t| NOT ALLOWED"<<endl<<endl<<endl;
    
    cout<<"\t\tLAUNDRY + PRESS   \t| 750   \t| SERVED TO ROOM"<<endl<<endl<<endl;
    
    
    getch();



}

//function to either login as a customer or admin or visit as a new customer
void main_menu()
{
	int choice;
	do
	{
		system("cls");
	cout<<" __________________________________________________________________________________________________________________"<<endl;
	cout<<"|  ______________________________________________________________________________________________________________  |"<<endl;
	cout<<"| |DATE: 20-May-2024                                                                           YOU! WHO MATTERS  | |"<<endl;
	cout<<"| |                                                  WELCOME TO                                                  | |"<<endl;
	cout<<"| |                                                 THE STANLEY                                                  | |"<<endl;
	cout<<"| |                                               HOTEL AND RESORT                                               | |"<<endl;
	cout<<"| |                                                                                                              | |"<<endl;
	cout<<"| |THE MALL, SADAR                                                                        CONTACT : 0320-1154354 | |"<<endl;
	cout<<"| |RAWALPINDI, PAKISTAN                                                                             090078609    | |"<<endl;
	cout<<"| |______________________________________________________________________________________________________________| |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________|"<<"\n\n"<<endl;

    
    cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t| ENTER YOU CHOICE : |\n";
    cout<<"\t\t\t\t|____________________|\n";
    
    cout<<"\t\t\t\t|1- LOGIN AS ADMIN\n";
    cout<<"\t\t\t\t|2- LOGIN AS CUSTOMER\n";
    cout<<"\t\t\t\t|3- READ HOTEL DISCRIPTIONS\n";
    cout<<"\t\t\t\t|4- FEED BACKS AND SUGGESTONS\n";
    cout<<"\t\t\t\t|0- TO EXIT\n";
    
    
    cout<<"Press Any Choice : ";
    cin>>choice;
    
    if(choice == 1)
    {
    	string ID_no,pswrd;
    	
    	A:
    		system("cls");
    		cout<<"\t\t\t\t ____________________\n";
            cout<<"\t\t\t\t|                    |\n";
            cout<<"\t\t\t\t|    ADMIN PORTAL    |\n";
            cout<<"\t\t\t\t|____________________|\n";
            
    	cout<<"Enter LOGIN ID : ";
    	cin>>ID_no;
    	cout<<"Enter Password : ";
    	cin>>pswrd;
    	
    	if(ID_no == "adminG" && pswrd == "adminG")
    	{
    		Administration();
		}
		else
		{
			cout<<"Wrong ID or Password \n";
			cout<<"Enter Again \n\n";
			goto A;
		}
		
	}
	else if(choice == 2)
		{
			Customer();
		}
	else if(choice == 3)
		{
			Description();
		}
    else if(choice == 4)
    	{
            L.View_FeedBacks();
		}
	else if(choice >= 5 )
		{
			cout<<"Wrong Choice .....!"<<endl;
			getch();
		}
	else if(choice == 0)
    	{
            exit(1);
		}
	}
	while(choice != 0);  
    getch();
}

//function to use all authorities by CUSTOMER
void Customer()
{
	system("cls");
	cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|   CUSTOMER PORTAL  |\n";
    cout<<"\t\t\t\t|____________________|\n";
	string ID;
	int flag,room;
    	
    	A:
    	cout<<"Enter ID : ";
    	cin>>ID;
    	cout<<"Enter Room No : ";
    	cin>>room;
    	
    	flag = L.check_room(ID,room);
    if(flag ==1)
    {
    		int choice;
	do
	{
		system("cls");
	cout<<"\t\t\t\t ____________________\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t| ENTER YOU CHOICE : |\n";
    cout<<"\t\t\t\t|____________________|\n";
    
    cout<<"\t\t\t\t|1- CHECK DETAILS\n";
    cout<<"\t\t\t\t|2- DELETE A ROOM\n";
    cout<<"\t\t\t\t|3- CHANGE DETAILS\n";
    cout<<"\t\t\t\t|4- CHECK BILL\n";
    cout<<"\t\t\t\t|5- FEEDBACK\n";
    cout<<"\t\t\t\t|6- TO GO BACK  \n";
    cout<<"\t\t\t\t|0- TO EXIT\n";
    
    cout<<"Press Any Choice : ";
    cin>>choice;
    
        if(choice == 1)
        {
            L.Check_Details();
		}
		else if(choice == 2)
		{
			L.Delete_a_Room();
		}
		else if(choice == 3)
    	{
    		L.Change_Details();
		}
		else if(choice == 4)
    	{
    		L.Check_Bill();
		}
		else if(choice == 5)
    	{
    		L.FeedBacks();
		}
		else if(choice == 6)
    	{
    		main_menu();
		}
		else if(choice > 6 )
		{
			cout<<"Wrong Choice .....!"<<endl;
		}
		else if(choice == 0)
    	{
    		exit(1);
		}
	}
	while(choice !=0);
	
	}
		else
		{
			cout<<"Wrong ID \n";
			cout<<"Try Again \n\n";
			goto A;
		}
		
    getch();
}





