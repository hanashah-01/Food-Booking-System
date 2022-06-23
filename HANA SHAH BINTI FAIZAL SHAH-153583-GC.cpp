/*******************************************************************************
/* Assignment 2
/* What the program do: Food Ordering System
/* Programmer name: HANA SHAH BINTI FAIZAL SHAH
/* Programmer Matric #: 153583
/******************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int MENUrow = 12;

int mainmenu();
void isManager(string [],double [], int[], int[]);
void isCustomer(string [],double [], int[], int[]);
void open_menu(int, string [],double [], int[], int[]);
void checkStock(string [],double [], int[], int[]);
bool acceptOrders(bool,int,int,string[], int[]);
int customerService(string [],double [], int[], int[]);

int main()
{
	int option; //Variable option is declared as int
	string input,count;
	string Menu[MENUrow]={};
	double prices[MENUrow]={};
	int delivery[MENUrow]={}, stock[MENUrow]={};
	
    cout << "\t\t##################################################\n"; 
	cout << "\t\t#    ______  ____  _____     ____  _____  _____  #\n";                      
	cout << "\t\t#   |       |        |      |     |     |   |    #\n";
	cout << "\t\t#   |   __  |        |      |     |     |   |    #\n";
	cout << "\t\t#   |  |  | |----    |      |---- |-----|   |    #\n";
	cout << "\t\t#   |     | |        |      |     |     |   |    #\n";
	cout << "\t\t#   |_____| |____    |      |____ |     |   |    #\n";
	cout << "\t\t#                                                #\n"; 
	cout << "\t\t##################################################\n"; 
	
	cout << "\n\t\t We deliver 5-star meals right at your front door!\n";
	
	system("pause"); //Program pauses until user enters a key
	system("cls");  // Program will change to another output screen
	
	fstream inputMenu;
	inputMenu.open("Menu.txt", ios::in); // Open input file containing menu of the restaurant
	
	if (inputMenu)
	{
		int i = 0;
		while (inputMenu)
		{
			getline(inputMenu,Menu[i]); //menu names
			inputMenu>> prices[i]; //price
			inputMenu>> delivery[i]; //delivery times
			inputMenu>> stock[i];//stock
			inputMenu.ignore();
			i++;
		}
		inputMenu.close();
	}
	else
	{
		cout << "Error opening file.\n";
	}

	cout << "\t\t************************************************\n";
	cout << "\t\t                  Hello There!                  \n";
	cout << "\t\t************************************************\n\n";
	cout << "\t\t************************************************\n";
	cout << "\t\t        Welcome to Galactica Pizzeria ! !       \n";
	cout << "\t\t************************************************\n\n";
	
	cout << "\t\t -------------------------------------------\n";
	cout << "\t\t|                        |                  |\n";
	cout << "\t\t| [1]Restaurant Manager  |    [2]Customer   |\n";
	cout << "\t\t|                        |                  |\n";
    cout << "\t\t -------------------------------------------\n";
	cout << "\nTo access our services, please pick option [1/2]\nWho are you accessing as? : ";
	cin >> option; //User must enter option 1 or 2 to access the rest of the program according to their choice
	
	while (option != 1 && option != 2) //User Input Validation
	{
		// An error message will appear if user enters an incorrect output
		cout << "\nERROR! Option entered does not exist. Please enter [1/2].\nWho are you accessing as? : ";
		cin >> option; // User is asked to enter an option again.
	}
	
	cout << "Loading...\n";
	system("pause"); // Program will pause until user enters a key
	system("cls");  // Program will change to another output screen
	
	if (option == 1)
	isManager(Menu,prices,delivery,stock);      //Function call if user chooses to access as a customer
	if (option == 2)
	isCustomer(Menu,prices,delivery,stock);   //Function call if user chooses to access as a manager
	
	return 0;	
}
void isCustomer(string Menu[],double prices[],int delivery[],int stock[]) //Function definiton for users who choose as customers
{
	string option; // Variable option is declared as string
	
	cout << "\t\t\t         *****      \n";
	cout << "\t\t\t       *       *     \n";
	cout << "\t\t\t      *  O   /  *    \n";
	cout << "\t\t\t     * /       O *    \n";
	cout << "\t\t\t     *   O   /   *    \n";
	cout << "\t\t\t      *   /  O  *    \n";
	cout << "\t\t\t       *       *    \n";
	cout << "\t\t\t         *****       \n";
	
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Welcome to Galactica Pizzeria where we serve out-of-the-world pizzas!!\n";
	// User is asked if they want to look at the restaurant's menu
	cout << "Would you like to look at our menu? (YES/NO) : ";
	cin >> option; // User must enter option "yes" if they want to look at the menu and "no" otherwise
	
	//User input validation
	while (option != "YES" && option != "yes" && option != "Yes" && option != "NO" && option != "no" && option != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nWould you like to look at out menu? [YES/NO]: ";
		cin >> option;
	}
	
	if (option == "YES" || option == "yes" || option == "Yes")
	{
		customerService(Menu,prices,delivery,stock); // Function call to look at menu
	}
	if (option == "NO" || option == "no" || option == "No")
	{
		cout << "\nToo bad :( You're missing out!\nThank you for visiting our website.\n"; 
		//Prints message to show dissapointment
	}
}
void isManager(string Menu[],double prices[],int delivery[],int stock[]) // Function definition for users who choose as managers
{
	int service; // variable service is declared as int
		
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Welcome back Sir/Madam !\n"; // Prints welcome message
	int numSections = 4; // size of array
	string sections[numSections] = {"Create/Update Menu","Update Prices","Check Remaining Stock",
	                                "Update Estimated Delivery Time"};
	                                // array is defined as string and assigned string values to it
	cout << "\n -------------------------------------------\n";
	for (int x=0;x < numSections; x++) // a for loop to print out the contents of the array
	{
		cout << "| ["<<x+1<<"] "<<sections[x]<<"\n";
		cout << " -------------------------------------------\n";
	}
	
	cout << "Please choose one service that you would like to update [1-4]: ";
	cin >> service; // User enters a number from 1 to 6 to access service of their choice
	
	// User input validation
	while (service != 1 && service != 2 && service != 3 && service != 4  )
	{
		// Prints Error message if user enters incorrect input
		cout << "\nERROR! Option entered does not exist. Please enter [1-4].\nChoose one service that you would like to update/view [1-6]: ";
		cin >> service;
	}
	
	// User will be directed to separate functions according to the option they entered
	if (service==1 || service==2 || service==4)
	open_menu(service,Menu,prices,delivery,stock);
	else if (service==3)
	checkStock(Menu,prices,delivery,stock);
}
void open_menu(int option,string Menu[],double prices[],int delivery[],int stock[])
//Function definition to update/change menu or update/change prices
{
	system("cls"); // Program will change to another output screen
	
	cout << "This is our current menu: \n\n";
	cout<<"==========================================================================\n";
	
		cout<<"\tMenu Names"<<setw(25)<<"\tPrice (RM)"<<setw(10)<<"\tDelivery Time(mins)"<<endl;
		cout<<"==========================================================================\n";
		for (int i =0; i<MENUrow; i++)
		{
			cout<<fixed<<showpoint<<setprecision(2);
            cout<<"["<<i+1<<"]\t"<<left<<setw(25)<<Menu[i];
			cout<<right<<setw(15)<<prices[i];
			cout<<setw(15)<<delivery[i]<<endl;
			cout<<"----------------------------------------------------------------------\n";
		}
    
 if (option==1) //Update menu
 {
  string newMenu,answer1,option1; //declare variable to store updated menu
  int choice,num; 
  
  	cout << "\nDo you want to update menu? [YES/NO]: ";
	cin >> option1;
    //User input validation
	while (option1 != "YES" && option1 != "yes" && option1 != "Yes" && option1 != "NO" && option1 != "no" && option1 != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to update menu? [YES/NO]: ";
		cin >> option1;
	}
a:  
do{
  if (option1 == "YES" || option1 == "yes" || option1 == "Yes")
  {
  	cout << "\nEnter number of dish/drink that you would like to update [1-12]: ";
    cin >> choice; // User enters the number of dish/drink that they want to update
  
  while (choice < 1 || choice > 12) //Input validation
  {
  	cout << "\nERROR! Input Invalid. Please enter number between 1 to 12 ONLY.\n";
  	cout << "Enter number of dish/drink that you would like to update [1-12]: ";
  	cin >> choice;
  }
  
  cin.ignore(); //Ignore buffer
  cout << "\nEnter new menu: "; 
  getline(cin,newMenu); //User enters the new name of the menu
  
  ofstream outputMenu; //File declaration
  outputMenu.open("Menu.txt"); //Open file
  
    
    if(outputMenu) //Check if file is open
    {
    	for (int j=0; j <MENUrow; j++) //Go through contents of the array
     {	
		if (j==choice-1) //Updates the menu that was changed into the file
		{
			if ( j == MENUrow-1) // If user choose to update the last menu
		  {
		  	Menu[j]=newMenu;	
		    outputMenu << Menu[j] << endl;
		    outputMenu << prices[j]<<endl;
		    outputMenu << delivery[j] << endl;
		    outputMenu << stock[j];
		    continue;
		  }
		  Menu[j]=newMenu;	
		  outputMenu << Menu[j] << endl;
		  outputMenu << prices[j]<<endl;
		  outputMenu << delivery[j] << endl;
		  outputMenu << stock[j]<<endl;
		  continue;
		}
		if (j == MENUrow-1) //To prevent a blank space at the last line in the file
		{
		  outputMenu << Menu[j] << endl;
          outputMenu << prices[j] << endl;
          outputMenu << delivery[j]<<endl;
          outputMenu << stock[j];
		  continue;	
		}
		outputMenu << Menu[j] << endl; //Stores back other contents into the file
        outputMenu << prices[j] << endl;
        outputMenu << delivery[j] << endl;
        outputMenu << stock[j] << endl;
     }
	 outputMenu.close(); //Close file
    }
	else
	{
		cout << "Error opening file.\n"; //Error message if file fails to open
	} 
  }
		if (option1 == "NO" || option1 == "no" || option1 == "No")
	{
		mainmenu();
	}
    cout << "Do you want to update more menu? [YES/NO]: "; //Asks if user want to update more
	cin >> answer1;
}while (answer1 == "YES" || answer1 == "yes" || answer1 == "Yes");//execute do-while loop if
                                                                  //user inputs "Yes"
    	//User input validation
		while (answer1 != "YES" && answer1 != "yes" && answer1 != "Yes" && answer1 != "NO" && answer1 != "no" && answer1 != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to update more menu? [YES/NO]: ";
		cin >> answer1;
    }
	    //If user inputs yes, the program will go back to the start of the do while loop
		if (answer1 == "YES" || answer1 == "yes" || answer1 == "Yes")
	  {
         goto a;
	  }
	  else
	  {
		mainmenu(); //Calling function
	  }
}
else if(option==2) //Update price
{
  int choice2,newPrice; //Declare variable to store updated price
  string answer2,option2;
  
    cout << "\nDo you want to update price? [YES/NO]: "; //Asks user if they want to update price
	cin >> option2;
    //User input validation
	while (option2 != "YES" && option2 != "yes" && option2 != "Yes" && option2 != "NO" && option2 != "no" && option2 != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to update price? [YES/NO]: ";
		cin >> option2;
	}
 b: 
 do{
  cout << "\nEnter number of dish/drink that you would like to update its price [1-12]: ";
  cin >> choice2; // User enters the number of dish/drink that they want to update its price
  
  while (choice2 < 1 || choice2 > 12) //Input validation
  {
  	cout << "\nERROR! Input Invalid. Please enter number between 1 to 12 ONLY.\n";
  	cout << "Enter number of dish/drink that you would like to update its price [1-12]: ";
  	cin >> choice2;
  }
  
  cin.ignore(); //Ignore buffer
  cout << "\nEnter new price: RM";
  cin >> newPrice; //User enters the new price of the menu
  
  ofstream outputMenu2; //FIle declaration
  outputMenu2.open("Menu.txt"); //Open file
  

    if(outputMenu2) //Check if file is open
    {
    	for (int j=0; j <MENUrow; j++) //Go through contents of the array
     {	
		if (j==choice2-1) //Updates the price that was changed into the file
		{
			if ( j == MENUrow-1) // If user choose to update the last menu's price
		  {
		  	prices[j]=newPrice;	
		    outputMenu2 << Menu[j] << endl;
		    outputMenu2 << prices[j]<<endl;
		    outputMenu2 << delivery[j] << endl;
		    outputMenu2 << stock[j];
		    continue;
		  }
		  prices[j]=newPrice;	
		  outputMenu2 << Menu[j] << endl;
		  outputMenu2 << prices[j]<<endl;
		  outputMenu2 << delivery[j] << endl;
		  outputMenu2 << stock[j] << endl;
		  continue;
		}
		if (j == MENUrow-1) //To prevent a blank space at the last line in the file
		{
		  outputMenu2 << Menu[j] << endl;
          outputMenu2 << prices[j] << endl;
          outputMenu2 << delivery[j] << endl;
          outputMenu2 << stock[j];
		  continue;	
		}
		outputMenu2 << Menu[j] << endl; //Stores back other contents into the file
        outputMenu2 << prices[j] << endl;
        outputMenu2 << delivery[j] << endl;
        outputMenu2 << stock[j] << endl;
     }
	 outputMenu2.close(); //Close file
    }
	else
	{
		cout << "Error opening file.\n"; //Error message if file fails to open
	} 
	
		if (option2 == "NO" || option2 == "no" || option2 == "No")
	{
		mainmenu(); //Calling function
	}
	    cout << "Do you want to update more prices? [YES/NO]: ";//Asks user if they want to update more prices
	    cin >> answer2;
}while (answer2 == "YES" || answer2 == "yes" || answer2 == "Yes");//executes loop if user inputs "Yes"
        //User input validation
    	while (answer2 != "YES" && answer2 != "yes" && answer2 != "Yes" && answer2 != "NO" && answer2 != "no" && answer2 != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to update more prices? [YES/NO]: ";
		cin >> answer2;
    }   
		if (answer2 == "YES" || answer2 == "yes" || answer2 == "Yes")
	  {
         goto b;//Program will go back to the beginning of loop
	  }
	  else
	  {
		mainmenu(); //Calling function
	  }
}
else //Update delivery time
{
	int choice3,newTime; //Declare variable to store updated time
	string answer3,option3;
	//Asks user if they want to update delivery time
	cout << "\nDo you want to update delivery time? [YES/NO]: ";
	cin >> option3;
    //User input validation
	while (option3 != "YES" && option3 != "yes" && option3 != "Yes" && option3 != "NO" && option3 != "no" && option3 != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to update delivery time? [YES/NO]: ";
		cin >> option3;
	}
c: 
do{
if (option3 == "YES"|| option3 == "Yes"|| option3 == "yes")
	{
	   cout << "\nEnter number of dish/drink that you would like\nto update its delivery time [1-12]: ";
       cin >> choice3; // User enters the number of dish/drink that they want to update its delivery time
  
  while (choice3 < 1 || choice3 > 12) //Input validation
  {
  	cout << "\nERROR! Input Invalid. Please enter number between 1 to 12 ONLY.\n";
  	cout << "Enter number of dish/drink that you would like\n to update its delivery time [1-12]: ";
  	cin >> choice3;
  }
  
  cin.ignore(); //Ignore buffer
  cout << "\nEnter new delivery time: ";
  cin >> newTime; //User enters the new delivery time of the menu
  
  ofstream outputMenu3; //File declaration
  outputMenu3.open("Menu.txt"); //Open file
  
    if(outputMenu3) //Check if file is open
    {
    	for (int j=0; j <MENUrow; j++) //Go through contents of the array
     {	
		if (j==choice3-1) //Updates the delivery time that was changed into the file
		{
		  if ( j == MENUrow-1) // If user choose to update the last menu's delivery time
		  {
		  	delivery[j]=newTime;	
		    outputMenu3 << Menu[j] << endl;
		    outputMenu3 << prices[j]<<endl;
		    outputMenu3 << delivery[j] << endl;
		    outputMenu3 << stock[j];
		    continue;
		  }
		  	delivery[j]=newTime;	
		    outputMenu3 << Menu[j] << endl;
		    outputMenu3 << prices[j]<<endl;
		    outputMenu3 << delivery[j] << endl;
		    outputMenu3 << stock[j] << endl;
		    continue;
		}
		if (j == MENUrow-1) //To prevent a blank space at the last line in the file
		{
		  outputMenu3 << Menu[j] << endl;
          outputMenu3 << prices[j] << endl;
          outputMenu3 << delivery[j] << endl;
          outputMenu3 << stock[j];
		  continue;	
		}
		outputMenu3 << Menu[j] << endl; //Stores back other contents into the file
        outputMenu3 << prices[j] << endl;
        outputMenu3 << delivery[j] << endl;
        outputMenu3 << stock[j] << endl;
     }
	 outputMenu3.close(); //Close file
    }
	else
	{
		cout << "Error opening file.\n"; //Error message if file fails to open
	}
}
		if (option3 == "NO" || option3 == "no" || option3 == "No")
	{
		mainmenu();//Calling function
	}   //Asks user if they want to update more delivery times
	    cout << "Do you want to update more delivery times? [YES/NO]: ";
	    cin >> answer3;
}while (answer3 == "YES" || answer3 == "yes" || answer3 == "Yes");//Loop will execute if condition fulfilled
        //User input validation
    	while (answer3 != "YES" && answer3 != "yes" && answer3 != "Yes" && answer3 != "NO" && answer3 != "no" && answer3 != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to update more ";
		cout<<"delivery times? [YES/NO]: ";
		cin >> answer3;
    }
		if (answer3 == "YES" || answer3 == "yes" || answer3 == "Yes")
	  {
         goto c; //Program will go back to the beginning of loop
	  }
	  else
	  {
		mainmenu();//Calling function
	  }
}
}
void checkStock(string Menu[],double prices[],int delivery[],int stock[]) //Check and update stock
{
	system("cls");
   cout << "\t\t#####################################\n";
   cout << "\t\t          SYSTEM STOCK CHECK         \n";
   cout << "\t\t#####################################\n";
		cout<<"\tMenu Names"<<setw(25)<<"\tStock"<<endl;
		cout<<"==================================================\n";
		for (int i =0; i<MENUrow; i++) //Outputs number of stocks for each menu
		{
			cout<<fixed<<showpoint<<setprecision(2);
            cout<<"["<<i+1<<"]\t"<<left<<setw(25)<<Menu[i];
			cout<<right<<setw(10)<<stock[i]<<endl;
			cout<<"-----------------------------------------------\n";
		}
	string option,answer;
	int choice,newStock;
    //Asks user if they want to add stock
	cout << "\nDo you want to add stock? [YES/NO]: ";
	cin >> option;
    //User input validation
	while (option != "YES" && option != "yes" && option != "Yes" && option != "NO" && option != "no" && option != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to add stock? [YES/NO]: ";
		cin >> option;
	}
a:
do{	
	if (option == "YES" || option == "yes" || option == "Yes")
	{
		cout << "\nEnter number of dish/drink that you would like to add its stock [1-12]: ";
        cin >> choice; // User enters the number of dish/drink that they want to update its price
  
       while (choice < 1 || choice > 12) //Input validation
      {
  	    cout << "\nERROR! Input Invalid. Please enter number between 1 to 12 ONLY.\n";
  	    cout << "Enter number of dish/drink that you would like to add its stock [1-12]: ";
  	    cin >> choice;
      }
  
      cin.ignore(); //Ignore buffer
      cout << "\nEnter amount of stock: ";
      cin >> newStock; //User enters the new price of the menu
  
      ofstream outputMenu; //File declaration
      outputMenu.open("Menu.txt"); //Open file
  
    
    if(outputMenu) //Check if file is open
    {
    	for (int j=0; j <MENUrow; j++) //Go through contents of the array
     {	
		if (j==choice-1) //Updates the price that was changed into the file
		{
			if ( j == MENUrow-1) // If user choose to update the last menu's stock
		  {
		  	stock[j]+=newStock;	
		    outputMenu << Menu[j] << endl;
		    outputMenu << prices[j]<<endl;
		    outputMenu << delivery[j] << endl;
		    outputMenu << stock[j];
		    continue;
		  }
		  stock[j]+=newStock;	
		  outputMenu << Menu[j] << endl;
		  outputMenu << prices[j]<<endl;
		  outputMenu << delivery[j] << endl;
		  outputMenu << stock[j] << endl;
		  continue;
		}
		if (j == MENUrow-1) //To prevent a blank space at the last line in the file
		{
		  outputMenu << Menu[j] << endl;
          outputMenu << prices[j] << endl;
          outputMenu << delivery[j] << endl;
          outputMenu << stock[j];
		  continue;	
		}
		outputMenu << Menu[j] << endl; //Stores back other contents into the file
        outputMenu << prices[j] << endl;
        outputMenu << delivery[j] << endl;
        outputMenu << stock[j] << endl;
     }
	 outputMenu.close(); //Close file
    }
	else
	{
		cout << "Error opening file.\n"; //Error message if file fails to open
	}
    }
	
	if (option == "NO" || option == "no" || option == "No")
	{
		mainmenu();//Calling function
	}//Asks user if they want to add more stocks
	cout << "Do you want to add more stocks? [YES/NO]: ";
	cin >> answer;
}while (answer == "YES" || answer == "yes" || answer == "Yes");//Loop will execute if condition fulfilled
        //User input validation
    	while (answer != "YES" && answer != "yes" && answer != "Yes" && answer != "NO" && answer != "no" && answer != "No")
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nDo you want to add more stocks? [YES/NO]: ";
		cin >> answer;
    }
		if (answer == "YES" || answer == "yes" || answer == "Yes")
		goto a;//Program will go back to the beginning of loop
		
		else
		mainmenu();//Calling function
}
int customerService(string Menu[],double prices[],int delivery[],int stock[])//Function definition
{//if user is customer
	//Variable declaration
	string foodName,count,option,ans;
	int order,pizzaNum,time2=0,numCustomers=0,answer,
        sales1=0,sales2=0,sales3=0,sales4=0,sales5=0,sales6=0,sales7=0,sales8=0,sales9=0,sales10=0,sales11=0,sales12=0;
	double price,price1,price2,price3,price4,price5,price6,price7,price8,price9,price10,price11,price12, total=0;
	bool availability,stockAvailability = true;
a:
do{
	system("cls"); // Program will change to another output screen
	cout << "\t\t##########MENU########### \n\n";
		cout<<"====================================================\n";
		cout<<"\tMenu Names"<<setw(25)<<"\tPrice (RM)"<<setw(10)<<endl;
		cout<<"====================================================\n";
		for (int i =0; i<MENUrow; i++)//Outputs menu and prices
		{
			cout<<fixed<<showpoint<<setprecision(2);
            cout<<"["<<i+1<<"]\t"<<left<<setw(25)<<Menu[i];
			cout<<right<<setw(15)<<prices[i]<<endl;
			cout<<"-------------------------------------------------\n";
		}

	back:
	cout << "\n\tEnter your order [1-12]: ";//User enter their order
	cin >> order;	
	       while (order < 1 || order > 12) //Input validation
      {
  	    cout << "\nERROR! Input Invalid. Please enter number between 1 to 12 ONLY.\n";
  	    cout << "\n\tEnter your order [1-12]: ";
  	    cin >> order;
      }	
	switch(order) //Each case represents number of order according to customers's input
   {
   	case 1:
   		cout<<"\n\tEnter amount of pizza you desire : ";
   		cin>>pizzaNum;//number of order
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);//Function call
   		//Check if stock is available
   		if (availability == false) //If stock not available
   		{
			goto forward; //Go to end of function 
		}
        else // If stock is available
		{
			stock[0] -= pizzaNum; //Substracts number of order bought from remaining stock of the menu
   		    price1=prices[0];// Price of the menu
   		    total=total+price1*pizzaNum; //Total price of order
   		    time2 += delivery[0]; //Delivery time of the menu
   		    sales1 += price1*pizzaNum; //The overall total sales of the menu 
			cout<<"\tYou ordered "<<Menu[0]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price1*pizzaNum;
   		    cout<<"\n\tAmount of pizza : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[0]<<endl<<"\tYOUR ORDER IS SUCCESSFULLY SAVED "<<endl;
		}	
   	break;
   	case 2:
   		cout<<"\n\tEnter amount of pizza you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{   	   
		    stock[1] -= pizzaNum;
   		    price2=prices[1];
   	     	total=total+price2*pizzaNum;
   	    	time2 += delivery[1];
   	    	sales2 += price2*pizzaNum;
			cout<<"\tYou ordered "<<Menu[1]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price2*pizzaNum;
   		    cout<<"\n\tAmount of pizza : "<<pizzaNum<<"\n";
        	cout<<"\n\n\n\tYOU ORDERED "<<Menu[1]<<endl<<"\tYOUR ORDER IS SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 3:
   		cout<<"\n\tEnter amount of pizza you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
            stock[2] -= pizzaNum;
   		    price3=prices[2];
   		    total=total+price3*pizzaNum;
   		    time2 += delivery[2];
   		    sales3 += price3*pizzaNum;
			cout<<"\tYou ordered "<<Menu[2]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price3*pizzaNum;
   		    cout<<"\n\tAmount of pizza : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[2]<<endl<<"\tYOUR ORDER IS SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 4:
   		cout<<"\n\tEnter amount of pizza you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[3] -= pizzaNum;
		    price4=prices[3];
   		    total=total+price4*pizzaNum;
   		    time2 += delivery[3];
   		    sales4 += price4*pizzaNum;
			cout<<"\tYou ordered "<<Menu[3]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price4*pizzaNum;
   		    cout<<"\n\tAmount of pizza : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[3]<<endl<<"\tYOUR ORDER IS SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 5:
   		cout<<"\n\tEnter amount of side dish you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[4] -= pizzaNum;
		    price5=prices[4];
   		    total=total+price5*pizzaNum;
   		    time2 += delivery[4];
   	     	sales5 += price5*pizzaNum;
			cout<<"\tYou ordered "<<Menu[4]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price5*pizzaNum;
   		    cout<<"\n\tAmount of side dish : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[4]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 6:
   		cout<<"\n\tEnter amount of side dish you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[5] -= pizzaNum;
		    price6=prices[5];
   		    total=total+price6*pizzaNum;
   		    time2 += delivery[5];
   		    sales6 += price6*pizzaNum;
			cout<<"\tYou ordered "<<Menu[5]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price6*pizzaNum;
   		    cout<<"\n\tAmount of side dish : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[5]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 7:
   		cout<<"\n\tEnter amount of drinks you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[6] -= pizzaNum;
			price7=prices[6];
   			total=total+price7*pizzaNum;
   			time2 += delivery[6];
   			sales7 += price7*pizzaNum;
			cout<<"\tYou ordered "<<Menu[6]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price7*pizzaNum;
   		    cout<<"\n\tAmount of drinks : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[6]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 8:
   		cout<<"\n\tEnter amount of drinks you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[7] -= pizzaNum;
			price8=prices[7];
   			total=total+price8*pizzaNum;
   			time2 += delivery[7];
   			sales8 += price8*pizzaNum;
			cout<<"\tYou ordered "<<Menu[7]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price8*pizzaNum;
   		    cout<<"\n\tAmount of drinks : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[7]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 9:
   		cout<<"\n\tEnter amount of drinks you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[8] -= pizzaNum;
			price9=prices[8];
   			total=total+price9*pizzaNum;
   			time2 += delivery[8];
   			sales9 += price9*pizzaNum;
			cout<<"\tYou ordered "<<Menu[8]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price9*pizzaNum;
   		    cout<<"\n\tAmount of drinks : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[8]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 10:
   		cout<<"\n\tEnter amount of drinks you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[9] -= pizzaNum;
			price10=prices[9];
   			total=total+price10*pizzaNum;
   			time2 += delivery[9];
   			sales10 += price10*pizzaNum;
		    cout<<"\tYou ordered "<<Menu[9]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price10*pizzaNum;
   		    cout<<"\n\tAmount of drinks : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[9]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;	
		}
   	break;
   	case 11:
   		cout<<"\n\tEnter amount of desserts you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[10] -= pizzaNum;
			price11=prices[10];
   			total=total+price11*pizzaNum;
   			time2 += delivery[10];
   			sales11 += price11*pizzaNum;
			cout<<"\tYou ordered "<<Menu[10]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price11*pizzaNum;
   		    cout<<"\n\tAmount of dessert : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[10]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	case 12:
   		cout<<"\n\tEnter amount of dessert you desire : ";
   		cin>>pizzaNum;
   		availability=acceptOrders(stockAvailability,order,pizzaNum,Menu,stock);
   		if (availability == false)
   		{
			goto forward;
		}
		else
		{
			stock[11] -= pizzaNum;
			price12=prices[11];
   			total=total+price12*pizzaNum;
   			time2 += delivery[11];
   			sales12 += price12*pizzaNum;
			cout<<"\tYou ordered "<<Menu[11]<<fixed<<showpoint<<setprecision(2)<<" : RM"<<price12*pizzaNum;
   		    cout<<"\n\tAmount of dessert : "<<pizzaNum<<"\n";
   	        cout<<"\n\n\n\tYOU ORDERED "<<Menu[11]<<endl<<"\tORDER SUCCESSFULLY SAVED "<<endl;
		}
   	break;
   	default : cout << "\nERROR! Invalid Input. "; //User input validation
   	          goto back; //Go back to beginning of function
   	
}
    forward:
    int sales[MENUrow]={sales1,sales2,sales3,sales4,sales5,sales6,sales7,sales8,sales9,sales10,sales11,sales12};
    //Store number of sales for each menu into an array
    cout << "\nWould you like to add another order? [YES/NO]: ";//Asks user if they want to add order
    cin >> option;
        //User input validation
    	while (option != "YES" && option != "yes" && option != "Yes" && option != "NO" && option != "no" && option != "No")
	{
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [YES/NO].\nWould you like to add another order? [YES/NO]: ";
		cin >> option;
	}
	
	if (option == "YES" || option == "yes" || option == "Yes")
	{
		goto back; //Go back to beginning of function
	}
	if (option == "NO" || option == "no" || option == "No")
	{
		if (availability == true ) //If order is available
		{
			cout << "\nOkay! :D Generating bill....\n";
			numCustomers++; //number of customers is incremented because the customer pays for the order
		}
		if (availability == false) //If last order is not available
		{
			if (pizzaNum <= 0) //If customer didn't order anything before
			{
			   cout << "\nToo bad :( Please come again and have a nice day!\n";
			   return 0; 
		    }
		    else //If customer ordered something else that is available before
		    {
		    	cout << "\nOkay! :D Generating bill....\n";
		    	numCustomers++;//number of customers is incremented
			}
		}
	}
	
	//This is to update the remaining amount of stock left after customer made their order
	ofstream outputMenu; //FIle declaration
    outputMenu.open("Menu.txt"); //Open file
  
    
    if(outputMenu) //Check if file is open
    {
    	for (int j=0; j <MENUrow; j++) //Go through contents of the array
     {	
		if (j == MENUrow-1) //To prevent a blank space at the last line in the file
		{
		  outputMenu << Menu[j] << endl;
          outputMenu << prices[j] << endl;
          outputMenu << delivery[j] << endl;
          outputMenu << stock[j];
		  continue;	
		}
		outputMenu << Menu[j] << endl; //Stores back other contents into the file
        outputMenu << prices[j] << endl;
        outputMenu << delivery[j] << endl;
        outputMenu << stock[j] << endl;
     }
	 outputMenu.close(); //Close file
    }
	else
	{
		cout << "Error opening file.\n"; //Error message if file fails to open
	} 	        
	    double totalPaid=0;
	    totalPaid += total; //Total payment of current customer
	    ofstream customerInfo; //File declaration
	    customerInfo.open("CustomerPayment.txt", ios_base::app);//Open file
	    
	    if(customerInfo)//Check if file is open
		{
	        customerInfo << totalPaid; //Add data to file after each customer made payment
			customerInfo << endl;	
		}
		else
			cout << "Error opening file.\n";//Displays error message
	    customerInfo.close();//Close file
	    
		ofstream salefile2;//File declaration
		salefile2.open("TotalSales.txt");//Open file
		if (salefile2){
			for (int count=0;count<MENUrow;count++)
	    {
			salefile2 << sales[count]; //Store number of sales of each menu
	    	salefile2 << endl;
		}}
		else
		    cout << "Error opening file.\n";//Displays error message
		salefile2.close(); //Close file
	
	system("pause");//Program pauses until user enters a key
	system("cls"); //Program changes to another output screen
	//Displays the order bill
	cout << "\t\t ======================================== \n";
	cout << "\t\t|            GALACTIC PIZZERIA           |\n";
	cout << "\t\t ========================================\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t| Order number: #HNS-210                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t| Generated by: GET EAT                  |\n";
	cout << "\t\t| Total order : RM"<<total<<"                     \n";
	cout << "\t\t| Estimated Delivery Time: "<<time2<<" mins       |\n";
	cout << "\t\t|________________________________________|\n";
	cout << "\n\t Thank you for ordering at Galactic Pizzeria using GET EAT!\n";
	cout << "\n\t The bill is automatically deducted from your banking account linked to \n\t our website.\n";
	cout << "\n\t Enjoy your meals! May the force be with you !\n";

    system("pause");
    system("cls");
	double totalSales = 0; //Variable declaration and initialization of total menu sales
	
	int highest = sales[0];//Initialize highest sales to first element of array
	int lowest = sales[0];//Initialize highest sales to first element of array
	//Calculate total sales, highest-selling and lowest-selling menu
	for (int count = 0; count < MENUrow; count++)
	{
		totalSales += sales[count];
		if(sales[count] > highest)
		   highest = sales[count];
	    if(sales[count] < lowest)
		   lowest = sales[count];
	}

	cout << "\t\t#########EACH MENU AND ITS SALES TODAY##########\n"<<endl;	
	for (int count=0;count<MENUrow;count++)
	{
		cout<<"| ["<<count+1<<"]\t"<<left<<setw(25)<<Menu[count]<<":RM"<<sales[count]<<endl;
	}
	cout << endl;
	// Display the results
	cout << "Total Sales for Today: RM"<<totalSales<<endl;
		for (int count = 0; count < MENUrow; count++)
	{
		if(sales[count]==highest)
		cout << "Highest selling menu is "<<Menu[count]<<" which is RM"<<highest<<endl;
		else if(sales[count]==lowest)
		cout << "Lowest selling menu is "<<Menu[count] << " which is RM"<<lowest<<endl;
	}	
	cout << endl;
	
	   cout << "\t\t###Galactica Pizzeria's Customer Info###\n";

    // Display the number of customers
    cout << "\n\nNumber of customers: "<<numCustomers<<endl;
    cout<<endl;
	cout << "\nPress 1 to order again,otherwise press 2..\n";
	cin >> answer;
}while(answer == 1);
    while (answer != 1 && answer != 2) //Input validation
    {
    	cout << "\nINVALID! Press 1 to order again,otherwise press 2..\n ";
    	cin >> answer;
	}
	if ( answer == 1)
	goto a;
	if (answer == 2)
	mainmenu(); // Calling function
	return 0;
}
bool acceptOrders(bool availability,int order,int pizzaNum,string Menu[], int stock[])//Function declaration
{  //When customers chooses order, the program will check whether their order has sufficient amount of stocks\
     or not
   string stockName;
   switch(order)
   {
   	case 1: stockName = Menu[0];
   	        if (stock[0]< pizzaNum) //if stock is less than number of order
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;//return false if order is out of stock
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;//return true if order have stock
			}
	break;
	case 2: stockName = Menu[1];
   	        if (stock[1]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 3: stockName = Menu[2];
   	        if (stock[2]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 4: stockName = Menu[3];
   	        if (stock[3]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
 	case 5: stockName = Menu[4];
   	        if (stock[4]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 6: stockName = Menu[5];
   	        if (stock[5]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
   	        	
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
   	case 7: stockName = Menu[6];
   	        if (stock[6]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 8: stockName = Menu[7];
   	        if (stock[7]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 9: stockName = Menu[8];
   	        if (stock[8]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 10: stockName = Menu[9];
   	        if (stock[9]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
 	case 11: stockName = Menu[10];
   	        if (stock[10]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;
	case 12: stockName = Menu[11];
   	        if (stock[11]< pizzaNum)
   	        {
   	        	cout << "\n\t\t*We're really sorry :( "<<stockName<<" is OUT OF STOCK*\n";
   	        	return availability = false;
			}
			else
			{
				cout << "\n\t\t*Order Available!*\n";
				return availability = true;
			}
	break;	
			
   }
}
int mainmenu() //Function definition
{
	char option;
	//User choose to go back to start of the program or exit program
	cout << "\nPress Y to go back to main menu or press X to exit. [Y/X]: ";
	cin >> option;
	//User input validation
	while (option != 'Y' && option != 'y'&& option != 'X'&& option != 'x')
	{
		// An error message will appear if user enters incorrect input
		cout << "\nERROR! We didn't quite catch that T_T'. Please enter [Y/X].\n";
		cout << "Press Y to go back to main menu or press X to exit. [Y/X]: ";
		cin >> option;
    }
    if (option=='Y'|| option == 'y')
    {
    	system("cls");
    	main(); //Calling function - go back to function main
	}
    if (option=='X'||option=='x')
    exit(EXIT_FAILURE);//Terminate program
}
