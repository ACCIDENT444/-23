#include <iostream>
#include <cstring>
using namespace std;

// Функція, яка модифікує рядок
void modify(char* str) {
    cout << "Функція modify() отримала: " << str << endl;
    str[0] = 'H'; // Спроба змінити перший символ
    cout << "Після модифікації: " << str << endl;
}

// Безпечна версія функції
void modifySafe(char* str, size_t size) {
    if (size > 0) {
        str[0] = 'H';
        cout << "Безпечна модифікація: " << str << endl;
    }
}

int main() {
    cout << "\n=== ЗАВДАННЯ 2: const_cast ===" << endl;
    
    // Початковий код з завдання
    const char* text = "hello";
    
    cout << "Початковий рядок: " << text << endl;
    cout << "Адреса тексту: " << (void*)text << endl;
    
    // Демонстрація проблеми з const_cast
    cout << "\n--- НЕБЕЗПЕЧНИЙ СПОСІБ (можлива помилка) ---" << endl;
    
    try {
        // Небезпечне використання const_cast
        char* mutableText = const_cast<char*>(text);
        cout << "Адреса mutableText: " << (void*)mutableText << endl;
        
        // Це може призвести до аварійного завершення!
        modify(mutableText);
    }
    catch (...) {
        cout << "Сталася помилка!" << endl;
    }
    
    // Безпечні альтернативи
    cout << "\n--- БЕЗПЕЧНІ АЛЬТЕРНАТИВИ ---" << endl;
    
    // Спосіб 1: Створення копії
    cout << "Спосіб 1: Створення копії" << endl;
    char safeCopy[20];
    strcpy(safeCopy, text);
    cout << "Копія перед модифікацією: " << safeCopy << endl;
    modify(safeCopy);
    cout << "Оригінал залишився незмінним: " << text << endl;
    
    // Спосіб 2: Використання масиву замість рядкового літералу
    cout << "\nСпосіб 2: Використання масиву" << endl;
    char textArray[] = "hello"; // Це масив, а не вказівник на літерал
    cout << "Масив перед модифікацією: " << textArray << endl;
    modify(textArray);
    cout << "Масив після модифікації: " << textArray << endl;
    
    // Спосіб 3: Використання string
    cout << "\nСпосіб 3: Використання std::string" << endl;
    string strText = "hello";
    cout << "string перед модифікацією: " << strText << endl;
    
    // Для роботи з функцією modify потрібно отримати вказівник на дані
    // Але спочатку переконуємося, що ми можемо модифікувати дані
    if (!strText.empty()) {
        // Створюємо копію для модифікації
        vector<char> temp(strText.begin(), strText.end());
        temp.push_back('\0'); // Додаємо нульовий термінатор
        modify(temp.data());
        strText = temp.data(); // Оновлюємо string
    }
    cout << "string після модифікації: " << strText << endl;
    
    return 0;
}