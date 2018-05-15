#ifndef W7_TAXABLEPRODUCT_H_
#define W7_TAXABLEPRODUCT_H_

// Workshop 7 - STL Containers
// TaxableProduct.h

#include <iostream>
#include <vector>
#include <string>
#include "Product.h"


namespace w7 {

	class TaxableProduct : public Product {

	private:
		std::string m_tax;

	public:
		TaxableProduct(int id, double price, std::string msg);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;

	};

}
#endif

