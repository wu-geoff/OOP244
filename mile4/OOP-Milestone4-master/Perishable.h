#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__
#include <iostream>
#include "PosIO.h"
#include "NonPerishable.h"
#include "Date.h"

namespace ict {
	class Perishable : public NonPerishable {
	private:
		Date m_expiry;
	protected:
		char signature()const;
	public:
		std::istream& read(std::istream& istr);
		std::fstream& save(std::fstream& file)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		Perishable();
	};
}

#endif
