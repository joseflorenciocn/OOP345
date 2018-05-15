#ifndef W7_SALE_H_
#define W7_SALE_H_

#include <iostream>
#include <vector>
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w7
{
	class Sale
	{

	private:
	//	std::vector<int> id;
	//	std::vector<double> price;
	//	std::vector<std::string> tax;
		std::vector<iProduct*> prod;


	public:

		Sale(const char* filename);
		void display(std::ostream& out) const;

	};
	
	iProduct* readProduct(std::ifstream& file);

}

#endif
