#include <iostream>
#include "windows.h" 
#include "design.h"
using namespace std;


void Design::br(int line){
	for(int i=0; i<line;i++){
		cout<<endl;
	}
}

void Design::pre  (int tab){

	for(int i=0; i<tab;i++){
	cout<<"\t";
	}

}
void Design :: span(int space){

	for(int i=0; i<space;i++){
		cout<<" ";
	}

}
void Design::cls(){

	system("cls");


}
void Design:: loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		cout<<"";

		for (int j=0; j<i;j+=2){

		
			cout<<" ";
		

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}

void Design:: pwellcome(){


	char welcome[50]="Welcome";
	char welcome2[50]=" To BME";
	char welcome3[50]=" Food Information";
	char welcome4[50]=" And Order System";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		cout<<" "<<welcome[wlc];
		Sleep(100);
	}

	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		cout<<" "<<welcome2[wlc2];
		Sleep(100);
	}
	cout<<endl<<endl<<endl<<"\t"<<"\t"<<"\t ";
	
		for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		
				cout<<" "<<welcome3[wlc3];
	
				Sleep(100);
		}
		
		printf("\n\n\n\t\t\t\t ");
		
		for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E')

			cout<<" "<<welcome4[wlc3];
		
		else

			cout<<" "<<welcome4[wlc3];
		
		Sleep(100);
	}


}
void Design :: main_menu(){
	
		br(5); pre(3); cout<<"1. Our menu"; Sleep(400);
		br(2); pre(3); cout<<"2. If you are admin select this"; Sleep(400);
		br(2); pre(3); cout<<"3. Exit";  Sleep(400);
	
	
		br(1);
}
