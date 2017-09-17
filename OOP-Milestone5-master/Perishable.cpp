#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include "Perishable.h"

namespace ict {
	char Perishable::signature() const {
		return 'P';
	}

	Perishable::Perishable() {
		m_expiry.dateOnly(true);
	}

	std::istream & Perishable::read(std::istream & istr){
		std::cout << "Perishable ";
		NonPerishable::read(istr);
		if (ok()) {
			std::cout << "Expiry date (YYYY/MM/DD): ";
			
			istr >> m_expiry;
			if (m_expiry.errCode() == CIN_FAILED) {
				error("Invalid Date Entry");
				istr.setstate(std::ios::failbit);
			}
			else if (m_expiry.errCode() == YEAR_ERROR) {
				error("Invalid Year in Date Entry");
				istr.setstate(std::ios::failbit);
			}
			else if (m_expiry.errCode() == MON_ERROR) {
				error("Invalid Month in Date Entry");
				istr.setstate(std::ios::failbit);
			}
			else if (m_expiry.errCode() == DAY_ERROR) {
				error("Invalid Day in Date Entry");
				istr.setstate(std::ios::failbit);
			}
		}
		
		return istr;
	}

	std::fstream & Perishable::save(std::fstream & file) const {
		NonPerishable::save(file);
		file << "," << m_expiry;

		return file;
	}

	std::fstream & Perishable::load(std::fstream & file) {
		NonPerishable::load(file);
		file.ignore(1);
		file >> m_expiry;

		return file;
	}

	std::ostream & Perishable::write(std::ostream & os, bool linear) const {
		NonPerishable::write(os, linear);
		if (ok() && linear == false) {
			os << "Expiry date: " << m_expiry << std::endl;
		}

		return os;
	}
}
