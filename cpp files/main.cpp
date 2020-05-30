#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "windows.h" 
#include <ctype.h>
#include "foods.h"
#include "design.h"
#include <new>          // std::bad_alloc
using namespace std;

//Function for Printing the menu
void foodlist(Foods *menu){

   Design designd;
   designd.cls();
   cout<< endl<< "\t" << "\t"; 
   cout<< "______________________________________________________ ";
   cout<< endl<< "\t" << "\t"; 

   cout<< "|  Item No.  |   Food Name   |  Price  |   In Stock   |";
   cout<< endl << "\t" << "\t"; 

   cout<< "-------------------------------------------------------";
	 
  
    for(int i=0;i<5;i++){
	    cout<< endl<< "\t"<< "\t"; 
	    cout<< "|     "<< menu[i].getData() << "      |    " << menu[i].getName()<< "  |    "<<	menu[i].getPrice()
	    << "   |    "<< menu[i].getQuantity()<< "    |";
	
	    cout<< endl<< "\t"<< "\t"; 
		cout<< "-------------------------------------------------------";

    }
	

	Sleep(100);

}





int main(){
	
	int d=0,order,adminchoice,num,quantity,data=0,test;
	double totalcash=0;
	double price=0;
	string name;
	bool quit1=true;
	//Creating object from Design class to call design functions
	Design designobject=Design();
	//Loading bar that fills up to 100%
	designobject.loadingbar();
	//Clear the screen
	designobject.cls();
	//Welcome page
    designobject.pwellcome();
	Sleep(300);
	designobject.cls();
	//Creating 5 objects from Food class by calling corresponding constructor
	Foods *menu= new Foods[5]{{1,"Pork Ribs",23,120.23},{2,"Chicken Biryani",13,100.67},{3,"Sandwich",8,720.83},
   {4,"KFC Wings",46,70.23},{5,"Chicken Pizza",46,70.23}};
    char main_menu_choice;
  
  //Main part of the program :I used while(true) for switch-case menu
	while(true){
		designobject.cls();
		designobject.main_menu();
	
	    cin >> main_menu_choice;
	
	   //Checking if user entered number or not
	   while(!isdigit(main_menu_choice)){
	      cout << "Please Enter a Number: " << endl;
		  cin >> main_menu_choice;	
	   }
	
	   switch(main_menu_choice){
	   		case '1':
			{
			
				foodlist(menu);
				cout<< endl << endl << "Place your order:  "<< endl;
			

   
     			while (!(cin >> order)) {
    				cout << "you entered a non-digit character\n";
    				cin.clear();   // making sure that cin can work now 
    				cin.ignore();  // ignore the offending character
				}
    	
				cout<<"Enter quantity : "<<endl;
			
				while (!(cin >> quantity)) {
    				cout << "you entered a non-digit character\n";
    				cin.clear();   // makeing sure  that cin work now
    				cin.ignore();  // ignore the offending character
				}
				designobject.cls();
				cout<<endl<<endl<<endl;
				designobject.pre(2);
				totalcash+=menu[order].getPrice()*quantity;
	
                //Total cash amount for 1 day is updated
				ofstream myfile;
				myfile.open("samp_file.txt");
    			myfile<<totalcash<<endl;
    			myfile.close();
	            cout<<"Total amount: "<<menu[order].getPrice()*quantity<<" $"<<endl;
                cout<<endl<<endl<<"1- Return to Main menu"<<endl<<"2- Exit"<<endl;
   				while (!(cin >> test)) {
    			cout << "you entered a non-digit character\n";
    			cin.clear();   // makeing sure  that cin work now
    			cin.ignore();  // ignore the offending character
				}
	          
			   //If user wants to exit from program
				if(test==2){
	
     			designobject.cls();
				cout<<"Thanks for using our system.Project by Subhan Hagverdiyev";
				exit(1);
				}
				break;
		}

   
        	case 	'2':
        	{
			
				quit1=true;
        		designobject.cls();
				cout<<" 1. Total Cash Today \n\n";
				cout<<" 2. Add Food To Menu\n\n";
				cout<<" 3. Return to main menu\n\n";
				while (!(cin >> adminchoice)) {
    				cout << "you entered a non-digit character\n";
    				cin.clear();   // makeing sure  that cin work now
   					cin.ignore();  // ignore the offending character
				}	
	
				while(quit1==true){
				
					switch(adminchoice){

					case 1:
					{
		
						ifstream myfiles;
	   					double mydata=0;
	    				myfiles.open("samp_file.txt");
	    
						//checking error while reading file
	    				if(!myfiles	.fail())
	    					myfiles>>mydata;
	    				else
	    					cout<<"Error occured while reading the file"<<endl;
        
						cout<<"Total cash for today: "<<mydata;
       					myfiles.close();
          				cout<<endl<<endl<<"1- Return to Main menu"<<endl<<"2- Exit"<<endl;
           
    					while (!(cin >> test)) {
    						cout << "you entered a non-digit character\n";
    						cin.clear();   // makeing sure  that cin work now
    						cin.ignore();  // ignore the offending character
						}
	
    					if(test==2){
	
     						designobject.cls();
							cout<<"Thanks for using our system.Project by Subhan Hagverdiyev";
							exit(1);
						}
						quit1=false;
        				break;
       
					}
					case 2:
					{
						ofstream myfilez;
	    				myfilez.open("menu.txt");
					
						//Creating Dynamic array and checking if allocation has done succesfully by exception handling
	    				Foods *foods=NULL;
       					cout<<"How many foods do u want to add?"<<endl;
       					while (!(cin >> num)) {
    						cout << "you entered a non-digit character\n";
    						cin.clear();   // makeing sure  that cin work now
    						cin.ignore();  // ignore the offending character
						}
       					for(int i=0;i<num;i++){
		   					
							   cin>>name;
    	   						while (!(cin >> quantity)) {
    								cout << "you entered a non-digit character\n";
    								cin.clear();   // makeing sure  that cin work now
    								cin.ignore();  // ignore the offending character
								}
    	  						while (!(cin >> price)) {
    								cout << "you entered a non-digit character\n";
    								cin.clear();   // makeing sure  that cin work now
   							 		cin.ignore();  // ignore the offending character
								}
    	   //allocation function to report failure to allocate storage.
    	    					 try {
            					foods= new Foods(i,name,quantity,price);
    							} 
								catch (const bad_alloc& e) {
        						cout << "Allocation failed: " << e.what() << endl;
    							}
           						myfilez<<foods->getName()<<" ";
          						myfilez<<foods->getPrice()<<" ";
          						myfilez<<foods->getQuantity()<<endl;
      				 	}
	       
     					myfilez.close();
   						
						   //freeing allocated memory
        				delete foods;
       					designobject.br(3);
       					designobject.pre(3);
       					cout<<"Thank you menu updated!"<<endl;
       					cout<<endl<<endl<<"1- Return to Main menu"<<endl<<"2- Exit"<<endl;
  						while (!(cin >> test)) {
    						cout << "you entered a non-digit character\n";
    						cin.clear();   // makeing sure  that cin work now
    						cin.ignore();  // ignore the offending character
						}
    					if(test==2){
	
     						designobject.cls();
							cout<<"Thanks for using our system.Project by Subhan Hagverdiyev";
							exit(1);
						}
      				quit1=false;
       				
					break;
					
					}
					
					case 3:
			
						quit1=false;
						break;
						default:
						cout<<"Enter correct option: ";
						cin>>adminchoice;
						break;
					}
					}
	 		break;

			}
	  		case '3':
	  				
					designobject.cls();
					cout<<"Thanks for using our system.Project by Subhan Hagverdiyev";
					exit(1);
					break;
	 		case '0':
	 
	 				designobject.main_menu();
	 				cin>>main_menu_choice;
	 				break;
     		default:
     				cout<<"Enter correct number";
	
			}	

    
		}
   
	return 0;
	
	
}
