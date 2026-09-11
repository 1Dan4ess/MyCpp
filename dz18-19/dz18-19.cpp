#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>

using namespace std;

void convertToUTF8(char* text, char* result)
{
    wchar_t wide[80];

    MultiByteToWideChar(1251, 0, text, -1, wide, 80);
    WideCharToMultiByte(65001, 0, wide, -1, result, 160, NULL, NULL);
}

struct Book
{
    char* name = nullptr;
    char* author = nullptr;
    char* edition = nullptr;
    char* genre = nullptr;

    bool nameChanged = false;
    bool authorChanged = false;
    bool editionChanged = false;
    bool genreChanged = false;

    void print()
    {
        cout << "Назва      : ";
        if (nameChanged)
        {
            SetConsoleOutputCP(1251);
        }
        cout << name;
        SetConsoleOutputCP(65001);
        cout << endl;

        cout << "Автор      : ";
        if (authorChanged)
        {
            SetConsoleOutputCP(1251);
        }
        cout << author;
        SetConsoleOutputCP(65001);
        cout << endl;

        cout << "Видавництво: ";
        if (editionChanged)
        {
            SetConsoleOutputCP(1251);
        }
        cout << edition;
        SetConsoleOutputCP(65001);
        cout << endl;

        cout << "Жанр       : ";
        if (genreChanged)
        {
            SetConsoleOutputCP(1251);
        }
        cout << genre;
        SetConsoleOutputCP(65001);
        cout << endl;
        cout << "-----------------------------------" << endl;
    }
};

struct Library
{
    Book* books = nullptr;
    int size = 5;

    void createBook(int i, const char* name, const char* author, const char* edition, const char* genre)
    {
        books[i].name = new char[strlen(name) + 1];
        strcpy(books[i].name, name);
        books[i].author = new char[strlen(author) + 1];
        strcpy(books[i].author, author);
        books[i].edition = new char[strlen(edition) + 1];
        strcpy(books[i].edition, edition);
        books[i].genre = new char[strlen(genre) + 1];
        strcpy(books[i].genre, genre);
    }

    void create()
    {
        books = new Book[size];
        createBook(0, "Кобзар", "Т. Шевченко", "Основи", "Поезія");
        createBook(1, "Дюна", "Френк Герберт", "КСД", "Фантастика");
        createBook(2, "Місто", "В. Підмогильний", "КСД", "Роман");
        createBook(3, "Кайдашева сім'я", "І. Нечуй-Левицький", "Знання", "Повість");
        createBook(4, "Тигролови", "І. Багряний", "Знання", "Роман");
    }

    void menu()
    {
        create();

        while (true)
        {
            system("cls");
            cout << "Library" << endl;
            cout << "----------------------" << endl;
            cout << "1. Редагувати книгу" << endl;
            cout << "2. Друк усіх книг" << endl;
            cout << "3. Пошук книги за автором" << endl;
            cout << "4. Пошук книги за назвою" << endl;
            cout << "5. Сортування за назвою" << endl;
            cout << "6. Сортування за автором" << endl;
            cout << "7. Сортування за видавництвом" << endl;
            cout << "8. Вихід" << endl;
            cout << "Ваш вибір: ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                editBook();
                break;
            case 2:
                printAll();
                break;
            case 3:
                findAuthor();
                break;
            case 4:
                findName();
                break;
            case 5:
                sortName();
                break;
            case 6:
                sortAuthor();
                break;
            case 7:
                sortEdition();
                break;
            case 8:
                exit(0);
                return;
            default:
                break;
            }
        }
    }

    void editBook()
    {
        system("cls");
        cout << "Редагування" << endl;
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << books[i].name << endl;
        }
        cout << "Введіть номер книги: ";

        int num;
        cin >> num;
        if (num < 1 or num > size)
        {
            cout << "Невірний номер!" << endl;
            system("pause");
            return;
        }
        num -= 1;

        cout << endl;
        cout << "Що змінити?" << endl;
        cout << "1. Назву" << endl;
        cout << "2. Автора" << endl;
        cout << "3. Видавництво" << endl;
        cout << "4. Жанр" << endl;
        cout << "Ваш вибір: ";

        int choice;
        cin >> choice;
        cin.ignore();
        char buffer[80];
        cout << "Введіть нове значення: ";
        cin.getline(buffer, 80);

        switch (choice)
        {
        case 1:
            books[num].name = new char[strlen(buffer) + 1];
            strcpy(books[num].name, buffer);
            books[num].nameChanged = true;
            break;
        case 2:
            books[num].author = new char[strlen(buffer) + 1];
            strcpy(books[num].author, buffer);
            books[num].authorChanged = true;
            break;
        case 3:
            books[num].edition = new char[strlen(buffer) + 1];
            strcpy(books[num].edition, buffer);
            books[num].editionChanged = true;
            break;
        case 4:
            books[num].genre = new char[strlen(buffer) + 1];
            strcpy(books[num].genre, buffer);
            books[num].genreChanged = true;
            break;
        default:
            cout << "Невірний вибір" << endl;
            break;
        }
        cout << "Дані успішно оновлено" << endl;
        system("pause");
    }

    void printAll()
    {
        system("cls");
        cout << "Всі книги:\n" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Книга " << i + 1 << endl;
            books[i].print();
        }
        system("pause");
    }

    void findAuthor()
    {
        system("cls");
        cout << "Пошук" << endl;
        cout << endl;
        cout << "Введіть автора для пошуку: ";
        cin.clear();
        cin.ignore();
        char search[80];
        cin.getline(search, 80);
        char searchUTF8[160];

        convertToUTF8(search, searchUTF8);

        cout << "----------------------------" << endl;
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(books[i].author, searchUTF8) == 0)
            {
                books[i].print();
                found = true;
            }
        }
        if (!found)
        {
            cout << "Книгу з такою назвою не знайдено" << endl;
        }
        system("pause");
    }

    void findName()
    {
        system("cls");
        cout << "Пошук" << endl;
        cout << endl;
        cout << "Введіть назву для пошуку: ";
        cin.clear();
        cin.ignore();
        char search[80];
        cin.getline(search, 80);
        char searchUTF8[160];

        convertToUTF8(search, searchUTF8);

        cout << "----------------------------" << endl;

        bool found = false;

        for (int i = 0; i < size; i++)
        {
            if (strcmp(books[i].name, searchUTF8) == 0)
            {
                books[i].print();
                found = true;
            }
        }

        if (!found)
        {
            cout << "Книгу з такою назвою не знайдено" << endl;
        }
        system("pause");
    }

    void sortName()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (strcmp(books[j].name, books[j + 1].name) > 0)
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        cout << "Масив відсортовано за назвою" << endl;
        system("pause");
    }


    void sortAuthor()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (strcmp(books[j].author, books[j + 1].author) > 0)
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        cout << "Масив відсортовано за автором" << endl;
        system("pause");
    }

    void sortEdition()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (strcmp(books[j].edition, books[j + 1].edition) > 0)
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
        cout << "Масив відсортовано за видавництвом" << endl;
        system("pause");
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(65001);

    Library lib;
    lib.menu();
}