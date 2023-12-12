#include <iostream>
#include <vector>
#include <stdexcept>

class Person {
public:
    Person(const std::string& name, const std::string& gender, int age)
        : name(name), gender(gender), age(age) {}

    virtual ~Person() = default;

    virtual void input() {
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter gender: ";
        std::cin >> gender;
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    virtual void output() const {
        std::cout << "Name: " << name << "\nGender: " << gender << "\nAge: " << age << std::endl;
    }

protected:
    std::string name;
    std::string gender;
    int age;
};

class Student : public Person {
public:
    Student(const std::string& name, const std::string& gender, int age,
        const std::string& course, const std::string& group, const std::string& university)
        : Person(name, gender, age), course(course), group(group), university(university) {}

    void input() override {
        Person::input();
        std::cout << "Enter course: ";
        std::cin >> course;
        std::cout << "Enter group: ";
        std::cin >> group;
        std::cout << "Enter university: ";
        std::cin >> university;
    }

    void output() const override {
        Person::output();
        std::cout << "Course: " << course << "\nGroup: " << group << "\nUniversity: " << university << std::endl;
    }

private:
    std::string course;
    std::string group;
    std::string university;
};

class Teacher : public Person {
public:
    Teacher(const std::string& name, const std::string& gender, int age,
        const std::string& university, const std::string& position, double salary)
        : Person(name, gender, age), university(university), position(position), salary(salary) {}

    void input() override {
        Person::input();
        std::cout << "Enter university: ";
        std::cin >> university;
        std::cout << "Enter position: ";
        std::cin >> position;
        std::cout << "Enter salary: ";
        std::cin >> salary;
    }

    void output() const override {
        Person::output();
        std::cout << "University: " << university << "\nPosition: " << position << "\nSalary: " << salary << std::endl;
    }

private:
    std::string university;
    std::string position;
    double salary;
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(const std::string& name, const std::string& gender, int age,
        const std::string& course, const std::string& group, const std::string& university,
        const std::string& position, double salary)
        : Student(name, gender, age, course, group, university), Teacher(name, gender, age, university, position, salary) {
    }

    const std::string& getUniversity() const {
        if (Student::university != Teacher::university) {
            return Student::university;
        }
        else {
            return Teacher::university;
        }
    }

    void output() const override {
        Student::output();
        Teacher::output();
    }
};

int main() {
    std::vector<Person*> people;

    try {
        int numPeople;
        std::cout << "Enter the number of people: ";
        std::cin >> numPeople;

        for (int i = 0; i < numPeople; ++i) {
            std::cout << "Enter details for person " << i + 1 << ":\n";
            std::cout << "1. Student\n2. Teacher\n3. Graduate Student\nChoose type (1/2/3): ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                people.push_back(new Student("", "", 0, "", "", ""));
            }
            else if (choice == 2) {
                people.push_back(new Teacher("", "", 0, "", "", 0.0));
            }
            else if (choice == 3) {
                people.push_back(new GraduateStudent("", "", 0, "", "", "", "", 0.0));
            }
            else {
                throw std::invalid_argument("Invalid choice. Choose 1, 2, or 3.");
            }

            people.back()->input();
        }

        for (const auto& person : people) {
            std::cout << "University: " << dynamic_cast<GraduateStudent*>(person)->getUniversity() << std::endl;
            std::cout << "-------------------------\n";
        }

        for (const auto& person : people) {
            person->output();
            std::cout << "-------------------------\n";
        }

        for (const auto& person : people) {
            delete person;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        for (const auto& person : people) {
            delete person;
        }
    }

    return 0;
}