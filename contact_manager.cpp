#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 性别.
 * */
enum Gender {
    MALE,
    FEMALE
};

/*
 * 联系人类.
 * */
class Person {
    int m_age;
    string m_name;
    Gender m_gender;
    string m_address;
    string m_telephone;

private:
    /*
     * 格式化手机号字符串为000-0000-0000.
     * */
    inline string formatTelephone(string telephone) {
        if ((int)telephone.length() < 11) {
            telephone += string(11 - (int)telephone.length(), '0');
        }
        return telephone.substr(0, 3) + "-"
            + telephone.substr(3, 4) + "-"
            + telephone.substr(7, 4);
    }

public:
    /*
     * 将字符串转换成枚举值。
     * */
    static Gender toGender(const string &gender) {
        return gender == "male" ? MALE : FEMALE;
    }

    /*
     * 重载函数实现数据的读入
     * */
    friend istream& operator >> (istream &in, Person &person) {
        string gender_str;
        string telephone_str;
        in >> person.m_name >> person.m_age >> gender_str >> person.m_address >> telephone_str;
        person.setGender(gender_str);
        person.setTelephone(telephone_str);
        return in;
    }

    /*
     * 数据的导出
     * */
    friend ostream& operator << (ostream &out, const Person &person) {
        out << person.getName() << " "
            << person.getAge() << " "
            << person.getGenderString() << " "
            << person.getAddress() << " "
            << person.getTelephone();
        return out;
    }

    friend bool operator == (const Person &person1, const Person &person2) {
        return person1.m_name == person2.m_name
            && person1.m_age == person2.m_age
            && person1.m_gender == person2.m_gender
            && person1.m_address == person2.m_address
            && person1.m_telephone == person2.m_telephone;
    }

    Person() {}

    Person(int age, string name, string gender, string address, string telephone)
            : m_age(age),
              m_name(name),
              m_gender(toGender(gender)),
              m_address(address),
              m_telephone(formatTelephone(telephone)) {
    }

    inline void setAge(int age) {
        m_age = age;
    }

    inline int getAge() const {
        return m_age;
    }

    inline void setName(const string &name) {
        m_name = name;
    }

    inline string getName() const {
        return m_name;
    }

    inline void setGender(const string &gender) {
        m_gender = toGender(gender);
    }

    inline Gender getGender() const {
        return m_gender;
    }

    inline string getGenderString() const {
        return m_gender == MALE ? "male" : "female";
    }

    inline void setAddress(const string &address) {
        m_address = address;
    }

    inline string getAddress() const {
        return m_address;
    }

    inline void setTelephone(const string &telephone) {
        m_telephone = formatTelephone(telephone);
    }

    inline string getTelephone() const {
        return m_telephone;
    }
};

class ContactsManager {
    vector<Person> m_persons;

private:
    inline bool isMatch(int tar, int cur) {
        return cur == tar;
    }

    inline bool isMatch(const string &tar, const string &cur) {
        return (cur == "" || cur == tar);
    }

public:
    /*
     * 添加一个新的联系人。
     * */
    bool addPerson(const Person &person) {
        if (find(m_persons.begin(), m_persons.end(), person) != m_persons.end()) {
            return false;
        }
        m_persons.push_back(person);
        return true;
    }

    /*
     * 删除一个已有的联系人。
     * */
    bool deletePerson(const Person &person) {
        vector<Person> :: iterator pos = remove(m_persons.begin(), m_persons.end(), person);
        if (pos == m_persons.end()) {
            return false;
        }
        m_persons.erase(pos, m_persons.end());
        return true;
    }

    /*
     * 查找联系人。
     * */
    std::vector<Person> findPerson(int age, string name, Gender gender, string address, string telephone) {
        vector<Person> persons;
        for (int i = 0; i < (int)m_persons.size(); ++i) {
            const Person &person = m_persons[i];
            cout << person << endl;
            if (isMatch(person.getAge(), age)
             || isMatch(person.getName(), name)
             || isMatch(person.getGender(), gender)
             || isMatch(person.getAddress(), address)
             || isMatch(person.getTelephone(), telephone)) {
                persons.push_back(person);
            }
        }
        return persons;
    }

    std::vector<Person> findPerson(const Person &person) {
        return findPerson(person.getAge(), person.getName(), person.getGender(), person.getAddress(), person.getTelephone());
    }

    const std::vector<Person>& getPersonList() const {
        return m_persons;
    }
};

class System {
    enum Message {
        INIT,
        RUNNING,
        EXIT
    };

    Person m_shared_person;
    ContactsManager m_manager;

public:
    void printUsage() const {
        cout << endl;
        cout << " | " << "0. Add a person" << endl;
        cout << " | " << "1. Find a person" << endl;
        cout << " | " << "2. Delete a person" << endl;
        cout << " | " << "3. Show all persons" << endl;
        cout << " | " << "4. Exit" << endl;
        cout << endl;
    }

    void printInputPrompt() {
        cout << "Please input informations for the person: name, age, gender[\"male\" or \"female\"], address and telephone number" << endl;
    }

    bool doAdd() {
        cin >> m_shared_person;
        return m_manager.addPerson(m_shared_person);
    }

    vector<Person> doFind() {
        cin >> m_shared_person;
        return m_manager.findPerson(m_shared_person);
    }

    bool doDelete() {
        cin >> m_shared_person;
        return m_manager.deletePerson(m_shared_person);
    }

    vector<Person> doShowAll() {
        return m_manager.getPersonList();
    }

    void showPersonList(const vector<Person> &persons) {
        for (int i = 0; i < (int)persons.size(); ++i) {
            cout << ">> " << persons[i] << endl;
        }
    }

    /*
     * 主要执行流程。
     * */
    void run() {
        int choice;
        vector<Person> result;
        for (Message message = INIT; message != EXIT; ) {
            printUsage();
            scanf("%d", &choice);
            message = RUNNING;
            bool state = true;
            switch (choice) {
                case 0:
                    printInputPrompt();
                    state = doAdd();
                    break;
                case 1:
                    printInputPrompt();
                    showPersonList(doFind());
                    state = true;
                    break;
                case 2:
                    printInputPrompt();
                    state = doDelete();
                    break;
                case 3:
                    showPersonList(doShowAll());
                    state = true;
                    break;
                case 4:
                    message = EXIT;
                    break;
                default:
                    cerr << "No such operation!" << endl;
                    state = false;
                    break;
            }
            if (!state) {
                cerr << "An error occured when parsing the operation!!" << endl;
            }
        }
        cout << "Bye :)" << endl;
    }
};

int main(int argc, char *argv[]) {
    System system;
    system.run();
    return 0;
}
