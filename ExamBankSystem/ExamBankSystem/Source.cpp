#include <iostream>
#include <string>
#include <fstream>
#include "MainBankForm.h"
#include <Windows.h>
#include "MyQueue.h"

using namespace ExamBankSystem;
using namespace System;
using namespace System::Windows::Forms;

MyQueue<CreditCard>* CreditCardList = new MyQueue<CreditCard>();
MyQueue<CostHistory>* CostHistoryList = new MyQueue<CostHistory>();

std::string encypt(std::string input);

void CostHistoryFromFile(MyQueue<CostHistory>* obj, const std::string fileWay);
void CardFromFile(MyQueue<CreditCard>* obj, const std::string fileWay);


[STAThreadAttribute]
int main(array<String^>^ args) {
	CardFromFile(CreditCardList, "private/CreditCardList.txt");
	CostHistoryFromFile(CostHistoryList, "private/CostHistoryList.txt");

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	ExamBankSystem::MainBankForm form;
	Application::Run(% form);
}

std::string encypt(std::string input) {
	const std::string numbers_count = "1234567890";
	const std::string alphabet_count = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] >= 48 && input[i] <= 57) {
			for (size_t j = 0; j < numbers_count.length(); j++)
			{
				if (input[i] == numbers_count[j]) {
					input[i] = numbers_count[(j + 7) % 10];
					break;
				}
			}
		}
		else if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) {
			for (size_t j = 0; j < alphabet_count.length(); j++)
			{
				if (input[i] == alphabet_count[j]) {
					input[i] = alphabet_count[(j + 11) % 52];
					break;
				}
			}
		}
	}
	return input;
}

void CostHistoryFromFile(MyQueue<CostHistory>* obj, const std::string fileWay) {
	try
	{
		std::ifstream file;
		file.open(fileWay);
		if (!file.is_open()) {
			throw std::runtime_error("FILE IS DAMAGED");
		}
		while (!file.eof()) {

			std::string encrypted_card_data = "";
			file >> encrypted_card_data;

			if (encrypted_card_data == "") break;

			std::string card_number = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);

			std::string card_date = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);

			std::string card_s_number = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);
			obj->AddToEnd(CostHistory(
				card_number,
				card_date,
				card_s_number
			));
		}
		file.close();
	}
	catch (...)
	{
		throw std::runtime_error("FILE IS DAMAGED");
	}
}
void CardFromFile(MyQueue<CreditCard>* obj, const std::string fileWay) {
	try
	{
		std::ifstream file;
		file.open(fileWay);
		if (!file.is_open()) {
			throw std::runtime_error("FILE IS DAMAGED");
		}
		while (!file.eof()) {

			std::string encrypted_card_data = "";
			file >> encrypted_card_data;

			if (encrypted_card_data == "") break;

			std::string card_number = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);

			std::string card_date = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);

			std::string card_s_number = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);

			std::string card_color = encrypted_card_data.substr(0, encrypted_card_data.find('&'));
			encrypted_card_data.erase(0, encrypted_card_data.find('&') + 1);

			obj->AddToEnd(CreditCard(
				card_number,
				card_date,
				card_s_number,
				card_color,
				encrypted_card_data
			));
		}
		file.close();
	}
	catch (...)
	{
		throw std::runtime_error("FILE IS DAMAGED");
	}
}