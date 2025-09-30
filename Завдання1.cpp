#include <iostream>
using namespace std;

int main() {
    cout << "=== ЗАВДАННЯ 1: static_cast ===" << endl;
    
    double doubleValue;
    
    // Отримуємо число від користувача
    cout << "Enter a double: ";
    cin >> doubleValue;
    
    // Перетворення за допомогою static_cast
    int intValue = static_cast<int>(doubleValue);
    
    // Виводимо результати
    cout << "Double: " << doubleValue << endl;
    cout << "Integer: " << intValue << endl;
    
    // Додаткові приклади для демонстрації
    cout << "\n--- Додаткові приклади static_cast ---" << endl;
    
    // Приклад 1: Втрата дробової частини
    double d1 = 9.99;
    int i1 = static_cast<int>(d1);
    cout << "double " << d1 << " -> int " << i1 << endl;
    
    // Приклад 2: Від'ємні числа
    double d2 = -3.14;
    int i2 = static_cast<int>(d2);
    cout << "double " << d2 << " -> int " << i2 << endl;
    
    // Приклад 3: Великі числа
    double d3 = 123456789.987;
    int i3 = static_cast<int>(d3);
    cout << "double " << d3 << " -> int " << i3 << endl;
    
    // Приклад 4: Перетворення між цілими типами
    long long bigNumber = 1234567890123LL;
    int smallNumber = static_cast<int>(bigNumber); // Можлива втрата даних!
    cout << "long long " << bigNumber << " -> int " << smallNumber << endl;
    
    return 0;
}