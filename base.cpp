#include <iostream> // Подключение библиотеки ввода-вывода
#include <fstream> // Подключение библиотеки работы с файлами
#include <vector> // Подключение библиотеки векторов
#include <map> // Подключение библиотеки ассоциативных массивов (карт)
#include <iomanip> // Подключение библиотеки для управления выводом
#include <string> // Подключение библиотеки для работы со строками

// Класс для записи трат и прихода денег
class AccountManager {
public:
    void recordExpense(double amount, const std::string& category) { // Функция для записи расхода
        std::ofstream file("expenses.txt", std::ios::app); // Открытие файла для записи в режиме добавления (append)
        file << amount << "," << category << std::endl; // Запись суммы и категории расхода в файл
        file.close(); // Закрытие файла
    }

    void recordIncome(double amount) { // Функция для записи дохода
        std::ofstream file("income.txt", std::ios::app); // Открытие файла для записи в режиме добавления (append)
        file << amount << std::endl; // Запись суммы дохода в файл
        file.close(); // Закрытие файла
    }
};

// Класс для расчета баланса и процентов трат
class ExpenseAnalyzer {
public:
    void calculateBalance() { // Функция для расчета баланса
        double totalExpenses = 0; // Общая сумма расходов
        double totalIncome = 0; // Общая сумма доходов

        std::ifstream expenseFile("expenses.txt"); // Открытие файла с расходами для чтения
        double amount;
        std::string category;
        while (expenseFile >> amount >> std::ws && std::getline(expenseFile, category)) {
            // Чтение суммы и категории расхода из файла
            totalExpenses += amount; // Увеличение общей суммы расходов
            categoryExpenses[category] += amount; // Увеличение суммы расходов по определенной категории
        }
        expenseFile.close(); // Закрытие файла с расходами

        std::ifstream incomeFile("income.txt"); // Открытие файла с доходами для чтения
        while (incomeFile >> amount) {
            // Чтение суммы дохода из файла
            totalIncome += amount; // Увеличение общей суммы доходов
        }
        incomeFile.close(); // Закрытие файла с доходами

        double balance = totalIncome - totalExpenses; // Расчет баланса (разницы между доходами и расходами)
        std::cout << "Balance: " << balance << std::endl; // Вывод баланса на экран
    }

    void calculateCategoryPercentagesLastMonth() { // Функция для расчета процентов расходов по категориям за последний месяц
        std::map<std::string, double> categoryPercentages; // Ассоциативный массив для хранения процентов расходов по категориям
        double totalExpenses = 0; // Общая сумма расходов

        std::ifstream expenseFile("expenses.txt"); // Открытие файла с расходами для чтения
        double amount;
        std::string category;
        while (expenseFile >> amount >> std::ws && std::getline(expenseFile, category)) {
            // Чтение суммы и категории расхода из файла
            totalExpenses += amount; // Увеличение общей суммы расходов
            if (categoryExpenses.find(category) != categoryExpenses.end()) {
                categoryPercentages[category] += amount; // Увеличение суммы расходов по определенной категории
            }
        }
        expenseFile.close(); // Закрытие файла с расходами

        std::cout << "Category Percentages Last Month:" << std::endl; // Вывод заголовка на экран
        for (const auto& pair : categoryPercentages) {
            // Расчет и вывод процентов расходов по каждой категории
            double percentage = (pair.second / totalExpenses) * 100; // Расчет процента от общей суммы расходов
            std::cout << pair.first << ": " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl; // Вывод категории и процента на экран
        }
    }

    void calculateCategoryPercentagesAllTime() { // Функция для расчета процентов расходов по категориям за все время
        std::map<std::string, double> categoryPercentages; // Ассоциативный массив для хранения процентов расходов по категориям
        double totalExpenses = 0; // Общая сумма расходов

        std::ifstream expenseFile("expenses.txt"); // Открытие файла с расходами для чтения
        double amount;
        std::string category;
        while (expenseFile >> amount >> std::ws && std::getline(expenseFile, category)) {
            // Чтение суммы и категории расхода из файла
            totalExpenses += amount; // Увеличение общей суммы расходов
            categoryPercentages[category] += amount; // Увеличение суммы расходов по определенной категории
        }
        expenseFile.close(); // Закрытие файла с расходами

        std::cout << "Category Percentages All Time:" << std::endl; // Вывод заголовка на экран
        for (const auto& pair : categoryPercentages) {
            // Расчет и вывод процентов расходов по каждой категории
            double percentage = (pair.second / totalExpenses) * 100; // Расчет процента от общей суммы расходов
            std::cout << pair.first << ": " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl; // Вывод категории и процента на экран
        }
    }

private:
    std::map<std::string, double> categoryExpenses; // Ассоциативный массив для хранения сумм расходов по категориям
};

int main() {
    AccountManager accountManager; // Создание объекта класса для управления записью трат и прихода денег
    ExpenseAnalyzer expenseAnalyzer; // Создание объекта класса для анализа расходов

    int choice; // Переменная для выбора опции меню
    double amount; // Переменная для ввода суммы
    std::string category; // Переменная для ввода категории

    do {
        // Вывод меню на экран и чтение выбранной опции
        std::cout << "1. Record expense" << std::endl;
        std::cout << "2. Record income" << std::endl;
        std::cout << "3. Calculate balance" << std::endl;
        std::cout << "4. Calculate category percentages (last month)" << std::endl;
        std::cout << "5. Calculate category percentages (all time)" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Запись расхода
                std::cout << "Enter expense amount: ";
                std::cin >> amount;
                std::cout << "Enter expense category: ";
                std::cin >> category;
                accountManager.recordExpense(amount, category);
                break;
            case 2:
                // Запись дохода
                std::cout << "Enter income amount: ";
                std::cin >> amount;
                accountManager.recordIncome(amount);
                break;
            case 3:
                // Расчет баланса
                expenseAnalyzer.calculateBalance();
                break;
            case 4:
                // Расчет процентов расходов за последний месяц по категориям
                expenseAnalyzer.calculateCategoryPercentagesLastMonth();
                break;
            case 5:
                // Расчет процентов расходов за все время по категориям
                expenseAnalyzer.calculateCategoryPercentagesAllTime();
                break;
            case 0:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;

    } while (choice != 0);

    return 0;
}
