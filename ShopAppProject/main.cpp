#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

#if defined(max)
#undef max
#endif

/*
	Меню магазина
	Сиситема продажи
	Скидки
	Склад
	Нейминги/запреты
	Управление сладом
	Динамический склад
	Чек
	Чистота кода
*/

// Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//-----------------------------------------------------------------------


// Склад
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

// Чек
int checkSize = 1;
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];
std::string* nameCheckArr = new std::string[checkSize];

//Функции
void Start();
bool Login();

void ShopAdminMenu();
void ShopUserMenu();

void CreateStaticStorage();
void CreateDynamicStorage();

void Selling();

void ShowStorage();
void RefilStorage();
void WriteOfFromStorage();
void ChangePrice();

void ChangeSraff();
void AddEmployer();
void EmployeeEdit();
void DeleteEmployee();

void ChangeStorage();
void AddProduct();
void ChangeProductName();
void DeleteProduct();


bool IsNumber(std::string string);

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);


//===================
int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;

	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;

	delete[]countCheckArr;
	delete[]priceCheckArr;
	delete[]totalPriceCheckArr;
	delete[]nameCheckArr;

	return 0;
}
//===================


void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t\tТаймлайн\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout
					<< "Использовать готовый или создать новый?\n"
					<< "1. Готовый скад\n"
					<< "2. Создать новый\n\n ?> ";

				std::getline(std::cin, choose, '\n');

				system("cls");
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// создание динамического склада
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		isAdmin = false;
		for (int i = 0; i < userCount; i++)// сам сделал)
		{
			if (login == loginArr[i] && pass == passwordArr[i]) {

				system("cls");
				std::cout << "Добро пожаловать " << loginArr[i] << '\n';

				if (i == 0)
				{
					isAdmin = true;
				}

				return true;
			}

		}
		system("cls");
		std::cout << "Неверно введён логин или пароль.\n";

	}


}


void ShopAdminMenu()
{
	std::string choose{};

	while (true)
	{
		do
		{
			system("pause");
			system("cls");

			std::cout
				<< "1. Начать продажу\n"
				<< "2. Показать склад\n"
				<< "3. Пополнить склад\n"
				<< "4. Списать со склада\n"
				<< "5. Изменить цену\n"
				<< "6. Изменить склад\n"
				<< "7. Изменить персонал\n"
				<< "8. Отчёт о прибыли\n\n"
				<< "0. Закрыть смену\n\n\n ?> ";

			std::getline(std::cin, choose, '\n');

			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);

		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefilStorage();
		}
		else if (choose == "4")
		{
			WriteOfFromStorage();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeSraff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			system("cls");
			std::cout << "\n\n\n\t\t\tAdminMenuError\n\n\n";
		}

	}
}

void ShopUserMenu()
{
	std::string choose{};

	while (true)
	{
		do
		{
			system("pause");
			system("cls");

			std::cout
				<< "1. Начать продажу\n"
				<< "2. Покзать склад\n"
				<< "3. Пополнить склад\n"
				<< "4. Изменить склад\n"
				<< "5. Отчёт о прибыли\n\n"
				<< "0. Закрыть смену\n\n\n ?> ";

			std::getline(std::cin, choose, '\n');

			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefilStorage();
		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			system("cls");
			std::cout << "\n\n\n\t\t\tUserMenuError\n\n\n";
		}

	}
}


void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::string nameStaticArr[staticSize]{
		"Карманные часы","Напольные часы","Наручные часы","Настенные часы","Настольные часы",
		"Электронные часы","Песочные часы","Солнечные часы","Водяные часы","Шахматные часы"
	};

	int countStaticArr[staticSize]{ 20, 10, 50, 40, 35, 40, 25, 10, 15, 25 };

	double priceStaticArr[staticSize]{ 3649.0, 6689.0, 3565.0, 1137.0, 3995.0, 9990.0, 1990.0, 990.0, 888.0, 2174.0 };

	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
}

void CreateDynamicStorage() 
{

}

void Selling()
{

}


void ShowStorage()
{
	std::cout << "ID\tНазвание\t\tЦена\tКол-во\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << '\t' << std::left << std::setw(20) << nameArr[i] << '\t' << priceArr[i] << '\t' << countArr[i] << '\n';
	}
	std::cout << "\n\n\n\n";
}

void RefilStorage()
{
	std::string idStr, addStr;
	int id{}, add{};


	while (true)
	{
		std::cout << "Введите ID товара\n0) Выход\n\n ?> ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << '\n';

			while (true)
			{
				std::cout << "Введите количество товара на пополнение: ";
				std::getline(std::cin, addStr, '\n');
				if (IsNumber(addStr))
				{
					add = std::stoi(addStr);
					if (add >= 0 && add < 1000)
					{
						countArr[id - 1] += add;
						std::cout << "\n\nТовар успешно пополнен\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nНеверно ведённо число\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}

void WriteOfFromStorage()
{
	std::string idStr, delStr;
	int id{}, del{};


	while (true)
	{
		std::cout << "Введите ID товара\n0) Выход\n\n ?> ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << '\n';

			while (true)
			{
				std::cout << "Введите количество товара списание: ";
				std::getline(std::cin, delStr, '\n');
				if (IsNumber(delStr))
				{
					del = std::stoi(delStr);
					if (del >= 0 && del <= countArr[id - 1])
					{
						countArr[id - 1] -= del;
						std::cout << "\n\nТовар успешно списан\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nНеверно ведённо число\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}

void ChangePrice()
{
	std::string idStr, newPriceStr;
	int id{};
	double newPrice{};


	while (true)
	{
		std::cout << "Введите ID товара\n0) Выход\n\n ?> ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << priceArr[id - 1] << '\n';

			while (true)
			{
				std::cout << "Введите новую цену: ";
				std::getline(std::cin, newPriceStr, '\n');
				if (IsNumber(newPriceStr))
				{
					newPrice = std::stod(newPriceStr);
					if (newPrice >= 0 && newPrice <= 10000000)
					{
						priceArr[id - 1] = newPrice;
						std::cout << "\n\nНовая цена принята\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nНеверно ведённо число\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}

void ChangeSraff()
{
	std::string choose;
	std::cout << "Изменение персонала магазина\n";
	for (int i = 0; i < userCount; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
	}

	do
	{
		std::cout << '\n'
			<< "1) Добавить нового сотрудника\n"
			<< "2) Изменить логин или пароль\n"
			<< "3) Удалить сотрудника\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		system("cls");
	} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 51);
	if (choose == "1")
	{
		AddEmployer();
	}
	else if (choose == "2")
	{
		EmployeeEdit();
	}
	else if (choose == "3")
	{
		DeleteEmployee();
	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cout << "ChangeStaffError";
	}
}

void AddEmployer()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	//std::swap(loginArr, tempLogin);

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}

	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPass;

	//test
	for (int i = 0; i < userCount; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
	}
}

void EmployeeEdit()
{
	std::string chooseId, newLogin, newPass;
	int empId{};

	while (true)
	{
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
		}
		std::cout << "\nВыберите ID пользователя для изменения\n\n0) Выход\n\n\n ?> ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (IsNumber(chooseId))
		{
			empId = std::stoi(chooseId);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empId - 1)
				{
					std::cout << "Ведите новый логин: ";
					std::getline(std::cin, newLogin, '\n');
					std::cout << "Ведите новый пароль: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newLogin;
					passwordArr[i] = newPass;
					system("cls");
					break;
				}
			}
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}

void DeleteEmployee()
{
	std::string chooseId;
	int empId{};
	while (true)
	{

		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << '\n';
		}

		std::cout << "\nВыберите Выберите ID пользователя для удаления\n\n0) Выход\n\n\n ?> ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (IsNumber(chooseId))
		{

			empId = std::stoi(chooseId);
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}
			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];

			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empId - 1)
				{
					i++;
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
				else
				{
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}


void ChangeStorage()
{
	std::string choose;
	std::cout << "Изменение склада магазина\n";

	do
	{
		std::cout << '\n'
			<< "1) Добавить новый товар\n"
			<< "2) Изменить имя товара\n"
			<< "3) Удалить товар\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		system("cls");
	} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 51);

	if (choose == "1")
	{
		AddProduct();
	}
	else if (choose == "2")
	{
		ChangeProductName();

	}
	else if (choose == "3")
	{
		DeleteProduct();
	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cout << "ChangeStorageError";
	}
}

void AddProduct()
{

	std::string choose;

	while (true)
	{
		std::cout
			<< "1) Добавить новый товар\n\n"
			<< "0) Выход\n\n\n ?> ";
			std::getline(std::cin, choose, '\n');

			if (choose == "0")
			{
				break;
			}
			else if (choose == "1")
			{
				int* tempId = new int[size];
				int* tempCount = new int[size];
				double* tempPrice = new double[size];
				std::string* tempName = new std::string[size];

				for (int i = 0; i < size; i++)
				{
					tempId[i] = idArr[i];
					tempCount[i] = countArr[i];
					tempPrice[i] = priceArr[i];
					tempName[i] = nameArr[i];
				}

				delete[]idArr;
				delete[]countArr;
				delete[]priceArr;
				delete[]nameArr;

				size++;

				idArr = new int[size];
				countArr = new int[size];
				priceArr = new double[size];
				nameArr = new std::string[size];

				for (int i = 0; i < size - 1; i++)
				{
					idArr[i] = tempId[i];
					countArr[i] = tempCount[i];
					priceArr[i] = tempPrice[i];
					nameArr[i] = tempName[i];
				}

				std::string newCountStr, newPriceStr, newName;
				idArr[size - 1] = idArr[size - 2] + 1;

				while (true)
				{
					std::cout << "Введите имя нового товара: ";
					std::getline(std::cin, newName, '\n');

					if (newName.size() <= 30)
					{
						nameArr[size - 1] = newName;
						break;
					}
					else
					{
						std::cout << "Максимальная длинна названия 30 символов.";
					}
				}

				while (true)
				{
					std::cout << "Введите количество нового товара: ";
					std::getline(std::cin, newCountStr, '\n');

					if (IsNumber(newCountStr))
					{
						if (std::stoi(newCountStr) >= 0 && std::stoi(newCountStr) < 1000)
						{
							countArr[size - 1] = std::stoi(newCountStr);
							break;
						}
					}
					else
					{
						std::cout << "Некоректный ввод.";
					}
				}

				while (true)
				{
					std::cout << "Введите цену нового товара: ";
					std::getline(std::cin, newPriceStr, '\n');
					if (IsNumber(newPriceStr))
					{
						if (std::stod(newPriceStr) >= 0 && std::stod(newPriceStr) < 10000000)
						{
							priceArr[size - 1] = std::stod(newPriceStr);
							break;
						}
						else
						{
							std::cout << "Некоректная цена.";
						}
					}
					else
					{
						std::cout << "Некоректный ввод.";
					}
				}


				delete[]tempId;
				delete[]tempCount;
				delete[]tempPrice;
				delete[]tempName;
				break;
			}
			else
			{
				std::cout << "Некоректный ввод.";
			}
	}
}

void ChangeProductName()
{
	std::string choose;

	while (true)
	{
		std::cout
			<< "1) Изменить имя товара\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			std::string idStr, newName;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара: ";
				std::getline(std::cin, idStr, '\n');
				if (IsNumber(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ID\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}
			while (true)
			{
				std::cout << "Введите имя товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\n\nМаксимальная длинна названия 30 символов\n\n";
				}
			}
		}
		else
		{
			std::cout << "\n\nНекоректный ввод\n\n";
		}
		
	}
}

void DeleteProduct()
{
	std::string choose;

	while (true)
	{
		std::cout
			<< "1) Удалить товар\n\n"
			<< "0) Выход\n\n\n ?> ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			
			
			std::string idStr;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара для удаления: ";
				std::getline(std::cin, idStr, '\n');
				if (IsNumber(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ID\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}

			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size--;

			tempId = new int[size];
			tempCount = new int[size];
			tempPrice = new double[size];
			tempName = new std::string[size];

			for (int i = 0, j = 0; i < size, j < size; i++, j++)
			{
				if (i == id - 1)
				{
					i++;
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
					idArr[j] = tempId[j];
				}
				else
				{
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
					idArr[j] = tempId[j];
				}
			}

			std::cout << "\n\nТовар успешно удалён\n\n";

			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;
		}
		else
		{
			std::cout << "Некоректный ввод.";
		}
	}
}




bool IsNumber(std::string string)//проверка на число ли в строке
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}

