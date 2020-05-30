#include <iostream>
#include <string>
using namespace std;
class Foods{
	private:
		string foodname;
		int quantity,data;
		double price;
			public:	Foods(int data,string foodname,int quantity,double price);
		
		void setName(string foodname);
	    void setQuantity(const int &quantity);
	    void setData(const int &data);
	    void setPrice(const double &price);
	    string getName() const;
	    int getQuantity() const;
	    int getData()const;
	    double getPrice()const;
	    
	    
	    
	    
	    
};
