// ����������
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int print_int() {
	int res;
	do {
		try {
			string numStr;
			cout << "������� �����: ";
			getline(cin, numStr);
			res = stoi(numStr);
			return res;
		}
		catch (const exception& ex)
		{
			cout << "������: " << ex.what() << ".\n";
		}
	} while (true);
}
double division(double A, double B);
template <typename T> void showArr(T arr[], int length);
template <typename T> void fillArr(T arr[], int length, int min, int max);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ����� �� �������� ��������
	try { // ����������
		cout << "������� ����� �� 1 �� 10: ";
		cin >> n;
		if (n < 1)
			throw 0; // �������
		if (n > 10)
			throw "�������� ����� ������ ���������� ���������.";
		cout << "����� ������� ���������.\n";
	}
	catch (const int ex) { // �������, ������
		// ����� ������������ switch...case
		if (ex == 0)
			cout << "������! �������� ����� ������ " << 
					"���������� ���������.\n";
	}
	catch (const char ex[]) {
		cout << "������! " << ex << endl;
	}

	// ������ �� ����
	bool check = false;
	do {
		system("cls");
		try
		{
			string numStr;
			cout << "������� �����: ";
			getline(cin, numStr);
			n = stoi(numStr);
			cout << "������� ����� " << n << endl;
			check = true;
		}
		catch (const exception& ex)
		{
			cout << "������: " << ex.what() << ".\n";
		}
	} while (!check);
	n = print_int();
	cout << "������� " << n << endl;


	// �������
	try {
		cout << "������� ��� �����: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const logic_error &ex) { // ��������� ������, ������� ����� ������
	// ����� ������� ����� ������ catch � ���������� �����������, � ����������� �� ���������� ������
		cout << "������: " << ex.what() << endl;
	}

	string path = "file.txt";

	// �������� �������� �����, ��������� ����������
	ofstream out;
	// ��������� ������� ������ ������� ����������
	out.exceptions(ios::badbit | ios::failbit | ios::eofbit);

	try {
		out.open(path);

		string str;
		cout << "������� ������:\n";
		getline(cin, str);
		out << str + "\n";
		cout << "������ �������� � ����.\n";

		out.close();
	}
	catch (const ios::failure &ex) { // ����� ���������� failure � �������� � ������ code,
									// ����� ����������, ����� ������ ������ ��������� ��� �������� �����
		cout << "������: " << ex.what() << endl;
		cout << "��� ������: " << ex.code() << endl;
	}

	cout << "������� ����� �������: ";
	cin >> n;
	try {
		int* arr = new int[n] {}; // �� ��������� ��� �������� ������� ����� ����
		// int k{}; // �� ��������� �������� ���������� k ����� ����.
		cout << "����������� ������:\n";
		showArr(arr, n);
		fillArr(arr, n, 10, 31);
		cout << "�������� ������:\n";
		showArr(arr,n);
	}
	catch (const underflow_error &ex) {
		cout << "������: " << ex.what() << endl;
	}
	catch (const bad_array_new_length& ex) {
		cout << "������ �������� �������: " << ex.what() << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "������ ���������: " << ex.what() << endl;
	}

	return 0;
}
// ������� ���� �����
double division(double A, double B) {
	if (B == 0)
		throw logic_error("Division by zero");
	return A / B;
}
// ����� �������
template <typename T> void showArr(T arr[], int length) {
	if (length <= 0)
		throw underflow_error(
			"����� ������� ������ ���� �������������"
		);
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// ���������� �������
template <typename T> void fillArr(T arr[], int length, int min, int max) {
	if (length <= 0)
		throw underflow_error(
			"����� ������� ������ ���� �������������"
		);
	if (max <= min)
		throw invalid_argument(
			"����� ��������� ������ ���� ������, ��� ������"
		);
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}