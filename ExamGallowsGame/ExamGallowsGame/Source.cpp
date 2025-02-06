#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <clocale>
using namespace std;

struct TAM {
	string time;
	//	  And
	int mistakes;
};
std::string decypt(std::string input);
void CoutStageGellows(const int stage);
void WordFromFile(vector<string>* obj, const std::string fileWay);
void UpdateResultFile(const string time, const int mistakes);
string GetTimeInterval(const string start_date, const string end_date);
bool TheGame(const string theWord);

int main() {
	setlocale(LC_ALL, "");
	srand(time(nullptr));

	vector<string>* wordlist = new vector<string>;
	WordFromFile(wordlist, "secret/WordList.txt");
	
	CoutStageGellows(0);
	cout << endl;
	string enter = "";
	while (enter != "3") {
		cout << "\n1 - Play\n2 - Rating\n3 - Exit\n- ";
		cin >> enter;
		if (enter == "1") {
			string theWord = wordlist->at(rand() % wordlist->size());
			TheGame(theWord);
		}
		else if (enter == "2") {
			system("cls");
			cout << "\tThe Gallows\n";
			CoutStageGellows(0);
			cout << endl;
			ifstream file_read("public/Results.txt");
			if (!file_read.is_open()) {
				continue;
			}
			string line;
			for (size_t i = 0; i < 5; i++)
			{
				getline(file_read, line);
				if (i < 2) {
					continue;
				}
				if (line == "") {
					break;
				}
				cout << "Time: " << line.substr(line.find(" ") + 1, line.find(" ") + 3)
				<< " - Mistakes: " << stoi(line.substr(line.rfind(" "), line.length())) << endl;
			}
			file_read.close();
		}
		else if (enter == "3") {
			system("cls");
			cout << "\tThe Gallows\n";
			CoutStageGellows(0);
			cout << endl;
			cout << "\nThanks for playing" << endl;
			break;
		}
		else {
			system("cls");
			cout << "\tThe Gallows\n";
			CoutStageGellows(0);
			continue;
		}
	}

	delete wordlist;
}

bool TheGame(const string theWord) {
	vector<string>* stages = new vector<string>;
	for (size_t i = 0; i < 7; i++)
	{
		ifstream file("public/stages/stage_" + to_string(i) + ".txt");
		string stage = "";
		string line;
		while (getline(file, line)) {
			if (stage == "") {
				stage.append(line);
				continue;
			}
			stage.append("\n" + line);
		}
		stages->push_back(stage);
		file.close();
	}

	std::time_t start = std::time(nullptr);
	std::tm start_local_time;
	localtime_s(&start_local_time, &start);

	string start_time =
		to_string(start_local_time.tm_hour) + ":" +
		to_string(start_local_time.tm_min) + ":" +
		to_string(start_local_time.tm_sec);

	string mistakes_letters = "";
	string word_letters;
	for (size_t i = 0; i < theWord.length(); i++)
	{
		word_letters.append("_");
	}
	char letter;

	while (word_letters != theWord) {
		system("cls");
		cout << "\tThe Gallows\n";
		cout << stages->at(mistakes_letters.length()) << endl;
		cout << "\nWord:";
		for (size_t i = 0; i < theWord.length(); i++)
		{
			cout << " " << word_letters[i];
		}
		cout << "\nMistakes (" << mistakes_letters.length() << ")";
		for (size_t i = 0; i < mistakes_letters.length(); i++)
		{
			cout << " " << mistakes_letters[i];
		}
		cout << endl;
		cout << "Letter: ";
		cin >> letter;
		if (int(letter) >= 97 && int(letter) <= 122) {
			letter = char(int(letter) - 32);
		}
		if (int(letter) < 65 || int(letter) > 90) {
			continue;
		}
		if (theWord.find(letter) == string::npos) {
			if (mistakes_letters.find(string(1, letter)) == string::npos) {
				mistakes_letters.append(string(1, letter));
				if (mistakes_letters.length() >= 6) {
					system("cls");
					cout << "\tYou lost\n";
					cout << stages->at(mistakes_letters.length()) << endl;
					cout << "\nWord: " << theWord;
					cout << "\nMistakes (" << mistakes_letters.length() << ")";
					for (size_t i = 0; i < mistakes_letters.length(); i++)
					{
						cout << " " << mistakes_letters[i];
					}
					cout << endl;

					std::time_t end = std::time(nullptr);
					std::tm end_local_time;
					localtime_s(&end_local_time, &end);
					string end_time =
						to_string(end_local_time.tm_hour) + ":" +
						to_string(end_local_time.tm_min) + ":" +
						to_string(end_local_time.tm_sec);
					cout << "Time: " << GetTimeInterval(start_time, end_time) << endl;
					return false;
				}
				continue;
			}
			else {
				continue;
			}
		}
		if (word_letters.find(letter) == string::npos) {
			string temp_theWord = theWord;
			int findme = temp_theWord.find(letter);
			while (findme != string::npos) {
				word_letters.replace(findme, 1, string(1, letter));
				temp_theWord.replace(findme, 1, "_");
				findme = temp_theWord.find(letter);
			}
		}
	}

	std::time_t end = std::time(nullptr);
	std::tm end_local_time;
	localtime_s(&end_local_time, &end);
	string end_time =
		to_string(end_local_time.tm_hour) + ":" +
		to_string(end_local_time.tm_min) + ":" +
		to_string(end_local_time.tm_sec);
	string time = GetTimeInterval(start_time, end_time);
	UpdateResultFile(time, mistakes_letters.length());
	system("cls");
	cout << "\tYou saved your life\n";
	cout << stages->at(0) << endl;
	cout << "\nWord: " << theWord;
	cout << "\nMistakes (" << mistakes_letters.length() << ")";
	for (size_t i = 0; i < mistakes_letters.length(); i++)
	{
		cout << " " << mistakes_letters[i];
	}
	cout << endl;
	cout << "Time: " << time << endl;
	delete stages;
	return true;
}

void UpdateResultFile(string time, const int mistakes) {
	ifstream file_read("public/Results.txt");
	if (!file_read.is_open()) {
		return;
	}
	string line;
	TAM top[3]{"", 0, "", 0, "", 0};
	for (size_t i = 0; i < 5; i++)
	{
		getline(file_read, line);
		if (i < 2) {
			continue;
		}
		if (line == "") {
			break;
		}
		top[i - 2].time = line.substr(line.find(" ")+1, line.find(" ") + 3);
		top[i - 2].mistakes = stoi(line.substr(line.rfind(" "), line.length()));
	}
	file_read.close();
	if (time.length() < 6) {
		time.insert(0, "00:");
	}
	else if (time.length() < 8) {
		time.insert(0, "0");
	}

	if (top[2].time == "" || GetTimeInterval(top[2].time, time).find("-") != string::npos) {
		if (top[1].time == "" || GetTimeInterval(top[1].time, time).find("-") != string::npos) {
			
			swap(top[2], top[1]);

			if (top[0].time == "" || GetTimeInterval(top[0].time, time).find("-") != string::npos) {
				swap(top[1], top[0]);
				top[0].time = time;
				top[0].mistakes = mistakes;
			}
			else if (top[0].time == time) {
				if (top[0].mistakes > mistakes) {
					top[0].mistakes = mistakes;
				}
			}
			else {
				top[1].time = time;
				top[1].mistakes = mistakes;
			}

		}
		else if (top[1].time == time) {
			if (top[1].mistakes > mistakes) {
				top[1].mistakes = mistakes;
			}
		}
		else {
			top[2].time = time;
			top[2].mistakes = mistakes;
		}

	}
	else if (top[2].time == time) {
		if (top[2].mistakes > mistakes) {
			top[2].mistakes = mistakes;
		}
	}
	else {
		return;
	}

	std::ofstream file_write("public/Results.txt");
	if (!file_write.is_open()) {
		return;
	}
	file_write << "== TOP-3 ==\n\n";
	for (size_t i = 0; i < 3; i++)
	{
		if (top[i].time == "") {
			break;
		}
		file_write << "Time: " << top[i].time << " - Mistakes: " << top[i].mistakes << "\n";
	}
	file_write.close();
}
string GetTimeInterval(const string start_date, const string end_date) {
	string start_date_list[3];
	string copy_date = start_date;
	for (size_t i = 0; i < 3; i++)
	{
		if (copy_date.find(':') == string::npos) {
			start_date_list[i] = copy_date;
			break;
		}
		start_date_list[i] = copy_date.substr(0, copy_date.find(':'));
		copy_date.erase(0, copy_date.find(':') + 1);
	}

	string end_date_list[3];
	copy_date = end_date;
	for (size_t i = 0; i < 3; i++)
	{
		if (copy_date.find(':') == string::npos) {
			end_date_list[i] = copy_date;
			break;
		}
		end_date_list[i] = copy_date.substr(0, copy_date.find(':'));
		copy_date.erase(0, copy_date.find(':') + 1);
	}

	string result;
	if (start_date_list[0] == end_date_list[0]) {
		if (start_date_list[1] == end_date_list[1]) {
			if (start_date_list[2] == end_date_list[2]) {
				result = "Impossible...";
			}
			else {
				string temp_sec = to_string(stoi(end_date_list[2]) - stoi(start_date_list[2]));
				if (temp_sec.length() <= 1) {
					temp_sec.insert(0, "0");
				}
				result = "00:" + temp_sec;
			}
		}
		else {
			string temp_min;
			string temp_sec;
			if (stoi(end_date_list[2]) - stoi(start_date_list[2]) < 0) {
				temp_min = to_string(stoi(end_date_list[1]) - stoi(start_date_list[1]) - 1);
				temp_sec = to_string(60 + (stoi(end_date_list[2]) - stoi(start_date_list[2])));
			}
			else {
				temp_min = to_string(stoi(end_date_list[1]) - stoi(start_date_list[1]));
				temp_sec = to_string(stoi(end_date_list[2]) - stoi(start_date_list[2]));
			}

			if (temp_min.length() <= 1) {
				temp_min.insert(0, "0");
			}
			if (temp_sec.length() <= 1) {
				temp_sec.insert(0, "0");
			}
			result = temp_min + ":" + temp_sec;
		}
	}
	else {

		string temp_hour;
		string temp_min;
		string temp_sec;
		if (stoi(start_date_list[0]) > stoi(end_date_list[0])) {
			temp_hour = to_string((24 - stoi(start_date_list[0])) + stoi(end_date_list[0]));
			temp_min = to_string((60 - stoi(start_date_list[1])) + stoi(end_date_list[1]));
			temp_sec = to_string((60 - stoi(start_date_list[2])) + stoi(end_date_list[2]));
			if (stoi(temp_sec) > 59) {
				temp_sec = to_string(stoi(temp_sec) - 60);
				temp_min = to_string(stoi(temp_min) + 1);
			}
			if (stoi(temp_min) > 59) {
				temp_min = to_string(stoi(temp_min) - 60);
				temp_hour = to_string(stoi(temp_hour) + 1);
			}
		}
		else {
			temp_hour = to_string(stoi(end_date_list[0]) - stoi(start_date_list[0]));
			if (stoi(end_date_list[2]) - stoi(start_date_list[2]) < 0) {
				temp_min = to_string(stoi(end_date_list[1]) - stoi(start_date_list[1]) - 1);
				temp_sec = to_string(60 + (stoi(end_date_list[2]) - stoi(start_date_list[2])));
			}
			else {
				temp_min = to_string(stoi(end_date_list[1]) - stoi(start_date_list[1]));
				temp_sec = to_string(stoi(end_date_list[2]) - stoi(start_date_list[2]));
			}

			if (temp_min.length() <= 1) {
				temp_min.insert(0, "0");
			}
			if (temp_sec.length() <= 1) {
				temp_sec.insert(0, "0");
			}
		}
		result = temp_hour + ":" + temp_min + ":" + temp_sec;
	}

	return result;
}
void CoutStageGellows(const int stage) {
	ifstream file("public/stages/stage_" + to_string(stage) +".txt");
	if (!file.is_open()) {
		cout << "Stage_" + to_string(stage) << endl;
	}
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}

std::string encypt(std::string input) {
	const std::string alphabet_count = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (size_t i = 0; i < input.length(); i++)
	{
		for (size_t j = 0; j < alphabet_count.length(); j++)
		{
			if (input[i] == alphabet_count[j]) {
				input[i] = alphabet_count[(j + 11) % 52];
				break;
			}
		}
	}
	return input;
}
std::string decypt(std::string input) {
	const std::string alphabet_count = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (size_t i = 0; i < input.length(); i++)
	{
		for (size_t j = 0; j < alphabet_count.length(); j++)
		{
			if (input[i] == alphabet_count[j]) {
				if (int(j) - 11 <= 0) {
					input[i] = alphabet_count[(41 + j) % 52];
				}
				else {
					input[i] = alphabet_count[(j - 11) % 52];
				}
				if (input[i] >= 'a' && input[i] <= 'z') {
					input[i] = char(int(input[i]) - 32);
				}
				break;
			}
		}
	}
	return input;
}
void WordFromFile(vector<string>* obj, const std::string fileWay) {
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

			obj->push_back(decypt(encrypted_card_data));
		}
		file.close();
	}
	catch (...)
	{
		throw std::runtime_error("FILE IS DAMAGED");
	}
}