#include <iostream>
#include <cstring>

class Student
{
private:
    int id;
    char name[50];
    int age;
    double grade;

public:
    Student()
    {
        id = 0;
        strcpy_s(name, "");
        age = 0;
        grade = 0;
    }

    Student(int studentId, const char studentName[], int studentAge, double studentGrade)
    {
        id = studentId;
        strcpy_s(name, studentName);
        age = studentAge;
        grade = studentGrade;
    }

    void show()
    {
        std::cout << "ID: " << id << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Average grade: " << grade << "\n";
        std::cout << "----------------------\n";
    }

    int getId()
    {
        return id;
    }

    void edit()
    {
        std::cout << "Enter new name: ";
        std::cin.ignore();
        std::cin.getline(name, 50);

        std::cout << "Enter new age: ";
        std::cin >> age;

        std::cout << "Enter new average grade: ";
        std::cin >> grade;
    }
};

int main()
{
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];

    int count = 0;
    int choice;

    do
    {
        std::cout << "\n===== STUDENT MANAGEMENT =====\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Show all students\n";
        std::cout << "3. Search student\n";
        std::cout << "4. Edit student\n";
        std::cout << "5. Delete student\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 1)
        {
            if (count >= MAX_STUDENTS)
            {
                std::cout << "Student list is full!\n";
                continue;
            }

            int id;
            int age;
            double grade;
            char name[50];

            std::cout << "Enter ID: ";
            std::cin >> id;

            std::cout << "Enter name: ";
            std::cin.ignore();
            std::cin.getline(name, 50);

            std::cout << "Enter age: ";
            std::cin >> age;

            std::cout << "Enter average grade: ";
            std::cin >> grade;

            students[count] = Student(id, name, age, grade);
            count++;

            std::cout << "Student added successfully!\n";
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                std::cout << "No students.\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    students[i].show();
                }
            }
        }
        else if (choice == 3)
        {
            int searchId;

            std::cout << "Enter student ID: ";
            std::cin >> searchId;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (students[i].getId() == searchId)
                {
                    students[i].show();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Student not found.\n";
            }
        }
        else if (choice == 4)
        {
            int editId;

            std::cout << "Enter student ID: ";
            std::cin >> editId;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (students[i].getId() == editId)
                {
                    students[i].edit();
                    std::cout << "Student updated successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Student not found.\n";
            }
        }
        else if (choice == 5)
        {
            int deleteId;

            std::cout << "Enter student ID: ";
            std::cin >> deleteId;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (students[i].getId() == deleteId)
                {
                    for (int j = i; j < count - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }

                    count--;
                    found = true;

                    std::cout << "Student deleted successfully!\n";
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Student not found.\n";
            }
        }
        else if (choice == 0)
        {
            std::cout << "Goodbye!\n";
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}