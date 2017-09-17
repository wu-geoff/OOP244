#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <cstring>
// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"
using namespace std;

namespace ict{
  // class Item implementaion


	Item::Item(){
		set("", "", 0, 0, false);
	}

	Item::Item(const char sku[],const char name[], double price, bool isTaxed){
		set(sku, name, price, 0, isTaxed);
	}

	Item::Item(const Item & i){
		set(i.m_sku, i.m_name, i.m_price, i.m_quantity, i.m_taxed);
	}

	Item::~Item(){
		delete[] m_name;
	}

	Item & Item::operator=(Item & i){
		if (!i.isEmpty()) {
			set(i.m_sku, i.m_name, i.m_price, i.m_quantity, i.m_taxed);
		}
		return *this;
	}

	void Item::set(const char* sku_, const char* name_, double price_, int quantity_, bool isTaxed){
		sku(sku_);
		name(name_);
		quantity(quantity_);
		price(price_);
		taxed(isTaxed);
	}

	void Item::sku(const char sku[]){
		strcpy(m_sku, sku);
	}

	void Item::price(double price){
		m_price = price;
	}

	//void Item::name(const char name[]){
	//	if (name == nullptr) {
	//		strcpy(m_name, "");
	//	}
	//	else {
	//		m_name = new char[strlen(name) + 1];
	//		strcpy(m_name, name);
	//	}
	//}

	void Item::name(const char name[]) {
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void Item::taxed(bool isTaxed){
		m_taxed = isTaxed;
	}

	void Item::quantity(int quantity){
		m_quantity = quantity;
	}

	const char* Item::sku() const{
		return m_sku;
	}

	double Item::price() const{
		return m_price;
	}

	char * Item::name() const{
		return m_name;
	}

	bool Item::taxed() const{
		return m_taxed;
	}

	int Item::quantity() const{
		return m_quantity;
	}

	double Item::cost() const{
		double result;
		if (taxed()) {
			result = price() * (1 + TAX);
		}
		else {
			result = price();
		}

		return result;
	}

	bool Item::isEmpty() const{
		return strcmp(sku(), "") == 0 && name() == nullptr && price() == 0 && taxed() == true && quantity() == 0;
	}

	bool Item::operator==(const char * input){
		return strcmp(sku(), input) == 0;
	}

	int Item::operator+=(int d){
		return (quantity() + d);
	}

	int Item::operator-=(int d){
		return (quantity() - d);
	}

	double operator+=(double & d, const Item & I){
		d = (double)I.quantity() * I.price();
		return d;
	}

	std::ostream & operator<<(std::ostream & ostr, const Item & I){
		return I.write(ostr, true);
	}

	std::istream & operator >> (std::istream & in, Item & I){
		return I.read(in);
	}

}
