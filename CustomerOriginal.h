#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;

class CustomerOriginal
{
public:
	static vector<unique_ptr<CustomerOriginal>> allCustomers;
	int id = 0;
	string name = "";
	string address = "";
	string state = "";
	string primarycontact = "";
	string domain = "";
	bool enabled = true;

	CustomerOriginal();
	~CustomerOriginal();

	static unique_ptr<vector<string>> getEnabledCustomerAddress();
};

vector<unique_ptr<CustomerOriginal>> CustomerOriginal::allCustomers;

CustomerOriginal::CustomerOriginal()
{
}


CustomerOriginal::~CustomerOriginal()
{
}

unique_ptr<vector<string>> CustomerOriginal::getEnabledCustomerAddress()
{
	
	auto outList = std::make_unique<vector<string>>();

	for (auto const &customer : allCustomers)
	{
		if (customer->enabled)
		{
			outList->push_back(customer->address);
		}
	}

	return outList;
}