#include <iostream>
#include <string>
#include "foods.h"
using namespace std;

	
		 Foods::Foods (int data,string foodname,int quantity,double price){
			setName(foodname);
			setQuantity(quantity);
			setData(data);
			setPrice(price);
		}
		void Foods :: setName( string foodname){
				this->foodname=foodname;
				}	
	    void Foods :: setQuantity(const int &quantity){
		this->quantity=quantity;
				}
	    void Foods:: setData(const int &data){
		this->data=data;
				}
		void Foods:: setPrice(const double &price){
			this->price=price;
		}
		string Foods :: getName() const {
			return foodname;
		}
		int Foods :: getQuantity() const {
			return quantity;
		}
		int Foods :: getData() const {
			return data;
		}
		double  Foods :: getPrice() const {
			return price;
		}
		
		
	   
	
	
	


