#ifndef W7_PRODUCT_H_
#define W7_PRODUCT_H_

// Workshop 7 - STL Containers
// Product.h

#include <iostream>
#include <vector>
#include "iProduct.h"


namespace w7 {

	class Product : public iProduct {

	private:
		int m_id;
		double m_price;

	public:
		Product(int id, double price);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;

	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}
#endif
