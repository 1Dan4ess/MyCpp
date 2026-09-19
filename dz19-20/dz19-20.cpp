#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <fstream>

using namespace std;

struct Book
{
    char* name = nullptr;
    char* author = nullptr;
    char* edition = nullptr;
    char* genre = nullptr;

    void print()
    {
        cout << "Назва      : " << (name ? name : "") << endl;
        cout << "Автор      : " << (author ? author : "") << endl;
        cout << "Видавництво: " << (edition ? edition : "") << endl;
        cout << "Жанр       : " << (genre ? genre : "") << endl;
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




    void save()
    {
        ofstream out("library.txt");
        if (!out.is_open()) return;

        for (size_t i = 0; i < size; i++)
        {
            out << (books[i].name ? books[i].name : "") << endl;
            out << (books[i].author ? books[i].author : "") << endl;
            out << (books[i].edition ? books[i].edition : "") << endl;
            out << (books[i].genre ? books[i].genre : "") << endl;
        }
        out.close();
    }

    void load()
    {
        books = new Book[size];
        char name[256];
        char author[256];
        char edition[256];
        char genre[256];
        ifstream in("library.txt");
        if (!in.is_open()) return;

        for (size_t i = 0; i < size; i++)
        {
            in.getline(name, 256);
            in.getline(author, 256);
            in.getline(edition, 256);
            in.getline(genre, 256);
            createBook(i, name, author, edition, genre);
        }
        in.close();
    }




    void menu()
    {
        load();
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
        cout << "Редагування" << endl << endl;

        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << books[i].name << endl;
        }
        cout << "Введіть номер книги: ";

        int num;
        cin >> num;
        if (num < 1 || num > size)
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

        cin.clear();
        cin.ignore(10000, '\n');

        wchar_t wbuffer[256];
        char bufferUTF8[512];
        cout << "Введіть нове значення: ";

        DWORD read;
        ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), wbuffer, 255, &read, NULL);
        if (read >= 2 && wbuffer[read - 2] == L'\r') wbuffer[read - 2] = L'\0';
        else if (read >= 1 && wbuffer[read - 1] == L'\n') wbuffer[read - 1] = L'\0';
        else wbuffer[read] = L'\0';

        WideCharToMultiByte(65001, 0, wbuffer, -1, bufferUTF8, 512, NULL, NULL);

        switch (choice)
        {
        case 1:
            delete[] books[num].name;
            books[num].name = new char[strlen(bufferUTF8) + 1];
            strcpy(books[num].name, bufferUTF8);
            break;
        case 2:
            delete[] books[num].author;
            books[num].author = new char[strlen(bufferUTF8) + 1];
            strcpy(books[num].author, bufferUTF8);
            break;
        case 3:
            delete[] books[num].edition;
            books[num].edition = new char[strlen(bufferUTF8) + 1];
            strcpy(books[num].edition, bufferUTF8);
            break;
        case 4:
            delete[] books[num].genre;
            books[num].genre = new char[strlen(bufferUTF8) + 1];
            strcpy(books[num].genre, bufferUTF8);
            break;
        default:
            cout << "Невірний вибір" << endl;
            system("pause");
            return;
        }

        cout << "Дані успішно оновлено" << endl;
        save();
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
        cout << "Пошук" << endl << endl;
        cout << "Введіть автора для пошуку: ";
        cin.clear();
        cin.ignore(10000, '\n');

        wchar_t wsearch[256];
        char searchUTF8[512];

        DWORD read;
        ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), wsearch, 255, &read, NULL);
        if (read >= 2 && wsearch[read - 2] == L'\r') wsearch[read - 2] = L'\0';
        else if (read >= 1 && wsearch[read - 1] == L'\n') wsearch[read - 1] = L'\0';
        else wsearch[read] = L'\0';

        WideCharToMultiByte(65001, 0, wsearch, -1, searchUTF8, 512, NULL, NULL);

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
            cout << "Книгу з таким автором не знайдено" << endl;
        }
        system("pause");
    }




    void findName()
    {
        system("cls");
        cout << "Пошук" << endl << endl;
        cout << "Введіть назву для пошуку: ";
        cin.clear();
        cin.ignore(10000, '\n');

        wchar_t wsearch[256];
        char searchUTF8[512];

        DWORD read;
        ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), wsearch, 255, &read, NULL);
        if (read >= 2 && wsearch[read - 2] == L'\r') wsearch[read - 2] = L'\0';
        else if (read >= 1 && wsearch[read - 1] == L'\n') wsearch[read - 1] = L'\0';
        else wsearch[read] = L'\0';

        WideCharToMultiByte(65001, 0, wsearch, -1, searchUTF8, 512, NULL, NULL);

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
        save();
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
        save();
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
        save();
        system("pause");
    }
};

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Library lib;
    lib.menu();
}