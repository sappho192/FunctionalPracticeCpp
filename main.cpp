#include "main.h"

template <typename T>
std::string strFormat(stringstream& sstream, T param)
{
	sstream << param;
	auto result = sstream.str();
	sstream.str(std::string());
	sstream.clear();

	return result;
}

template <typename T0, typename ... Tn>
std::string strFormat(stringstream& sstream, T0 param0, Tn... paramN)
{
	sstream << param0;
	return strFormat(sstream, paramN...);
}

int main()
{
	stringstream sstream;

	for (int i = 0; i < 10; i++)
	{
		unique_ptr<CustomerOriginal> customer = std::make_unique<CustomerOriginal>();

		customer->name = strFormat(sstream, "Person ", i);
		customer->address = strFormat(sstream, "Addr", i);
		customer->domain = strFormat(sstream, "Domain", i);
		customer->id = i;
		customer->state = strFormat(sstream, "State", (i % 2));
		customer->primarycontact = "111";
		if (i % 2 == 1) { customer->enabled = false; }
		CustomerOriginal::allCustomers.push_back(std::move(customer));
	}

	auto list = CustomerOriginal::getEnabledCustomerAddress();
	for (auto addr : *list)
	{
		cout << addr << endl;
	}

	system("pause");
	return 0;
}