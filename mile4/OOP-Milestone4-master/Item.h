#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "PosIO.h"
#include "POS.h"

#include <fstream> 

namespace ict{
  // class Item
	class Item:public PosIO {
	private:
		char m_sku[MAX_SKU_LEN + 1]; char *m_name;
		double m_price; int m_quantity;
		bool m_taxed;

	public:
		Item();
		Item(const char sku[], const char name[], double price, bool isTaxed = true);
		Item(const Item &i);
		virtual ~Item();
		Item& operator=(Item& i);
		void set(const char*,const char*, double, int, bool);

		//setters
		void sku(const char sku[]);
		void price(double price);
		void name(const char name[]);
		void taxed(bool isTaxed);
		void quantity(int quantity);

		//getter
		const char* sku() const;
		double price()const;
		char* name()const;
		bool taxed()const;
		int quantity()const;

		double cost()const;
		bool isEmpty()const;

		bool operator==(const char* input);
		int operator+=(int d), operator-=(int d);

	};

  // end class Item
	double operator+=(double& d, const Item& I);

  // operator << and operator >>
	std::ostream& operator<<(std::ostream& ostr, const Item& I);
	std::istream & operator>> (std::istream & in, Item& I);
}


#endif