#pragma once

#include <string>

class CostHistory
{
private:
	std::string transfer_sum;
	std::string category;
	std::string date;
public:
	CostHistory(const std::string transfer_sum, const std::string category, const std::string date)
		: transfer_sum(transfer_sum), category(category), date(date) {
		if (this->transfer_sum[0] == '*') {
			this->transfer_sum.replace(0, 1, "-");
		}
		else if (this->transfer_sum[0] == '~') {
			this->transfer_sum.replace(0, 1, "+");
		}
		if (this->transfer_sum.find("#") != std::string::npos) {
			this->transfer_sum.replace(this->transfer_sum.find("#"), 1, ".");
		}
		for (size_t i = 2; i < 6; i += 3)
		{
			this->date.insert(i, ".");
		}
	}
	std::string TransferSumGet() const {
		return transfer_sum;
	}
	std::string CategoryGet() const {
		return category;
	}
	std::string DateGet() const {
		return date;
	}
};

