#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iomanip>
#include <cstring>
#include "NonPerishable.h"

using namespace std;

namespace ict {
    //protected
    bool NonPerishable::ok()const{
		return m_err.isClear();
    }
    
    void NonPerishable::error(const char* message){
		m_err = message;
    }
    
    char NonPerishable::signature()const{
        return 'N';
    }
    
    //public
    fstream& NonPerishable::save(fstream& file)const{
        char comma = ',';
        file << signature() << comma << sku() << comma << name() << comma << price() << comma << taxed() << comma << quantity();
        return file;
    }
    
    std::fstream& NonPerishable::load(std::fstream& file){
        char sku[MAX_SKU_LEN + 1]; char name[128];
        double price; int quantity, taxed;
		file.getline(sku, MAX_SKU_LEN, ',');
        file.getline(name, 128,',');
		file >> price;
		file.ignore(256, ',');
		file >> taxed;
        file.ignore(256, ',');
		file >> quantity;

		NonPerishable::sku(sku);
		NonPerishable::name(name);
		NonPerishable::price(price);
		NonPerishable::quantity(quantity);
		NonPerishable::taxed(taxed == 1);

        return file;
    }
	std::ostream & NonPerishable::write(std::ostream & ostr, bool linear) const{
		if (ok()) {
			if (linear == true) {
				char bar = '|', taxStatus = (taxed()) ? 'T' : ' ';
				ostr << setw(MAX_SKU_LEN) << left << sku() << bar << setw(20) << left << name() << bar << setw(7) << right << fixed << setprecision(2) << price() <<
					bar << ' ' << taxStatus << signature() << bar << setw(4) << right << quantity() << bar << setw(9) << right << (quantity() * cost()) << bar;
			}
			else {
				if (taxed()) {
					ostr << "Name:" << endl  << left << name() << endl << "Sku: " << sku() << endl << "Price: " << price() << endl << "Price after tax: " << cost() << endl << "Quantity: " << quantity() << endl << "Total Cost: " << cost() * quantity() << endl;
				}
				else {
					ostr << "Name:" << endl << left << setfill(' ') << name() << endl << "Sku: " << sku() << endl << "Price: " << price() << endl << "Price after tax: N/A" << endl << "Quantity: " << quantity() << endl << "Total Cost: " << cost() * quantity() << endl;
				}
			}
		}
		else {
			ostr << m_err;
		}

		return ostr;
	}
	std::istream & NonPerishable::read(std::istream & is){
		char sku_[MAX_SKU_LEN + 1], name_[128], taxed_;
		double price_; int quantity_;
		m_err.clear();

		if (!is.fail()) {
			cout << "Item Entry:" << endl << "Sku: ";
			is >> sku_;
			sku(sku_);
			cout << "Name:" << endl;
			is >> name_;
			name(name_);
			cout << "Price: ";
			is >> price_;
			if (is.fail()) {
				m_err.message("Invalid Price Entry");
			}
			else {
				price(price_);
				cout << "Taxed: ";
				is >> taxed_;
				if (is.fail() || !(taxed_ == 'y' || taxed_ == 'n')) {
					m_err.message("Invalid Taxed Entry, (y)es or (n)o");
					is.setstate(ios::failbit);
				}
				else {
					taxed(taxed_ == 'y' || taxed_ == 'Y');
					cout << "Quantity: ";
					is >> quantity_;
					if (is.fail()) {
						m_err.message("Invalid Quantity Entry");
					}
					else {
						quantity(quantity_);
					}
				}
			}
		}
		return is;
	}
}

