#include <iostream>
#include <string>
#include <vector>

class Numbers {
    std::string nickname;
    std::string number;

public:
    std::string getNickname () {
        return nickname;
    }

    std::string getNumber () {
        return number;
    }

    void initialize (const std::string &name, std::string &num) {
        nickname=name;
        number =num;
    }
};

class Phone {
    std::vector<Numbers> addressBook;

public:
    void addNumber (Numbers* number) {
        addressBook.push_back(*number);
    }

    int find () {
        std::cout<<"Enter the subscriber's nickname or phone number:"<<std::endl;
        std::string user;
        std::cin>>user;
        int check=0;

        if (user.substr(0,1)=="+") {
            for (int i = 0; i < addressBook.size(); ++i) {
                if (addressBook[i].getNumber()==user) {
                    check=i+1;
                }
            }
        } else {
            for (int i = 0; i < addressBook.size(); ++i) {
                if (addressBook[i].getNickname()==user) {
                    check=i+1;
                }
            }
        }
        return check;
    }

    void add (Phone *phone) {
        std::cout<<"Enter the phone number in the format +70000000000 and the subscriber's nickname"<<std::endl;
        std::string nameUser;
        std::string numUser;
        std::cin>>numUser>>nameUser;

        Numbers *number = new Numbers;
        number->initialize(nameUser,numUser);
        phone->addNumber(number);
        delete number;
    }

    void call () {
        int check = find();

        if (check == 0) {
            std::cout << "Number not found." << std::endl;
        } else {
            std::cout << "CALL: " << addressBook[check - 1].getNumber() << std::endl;
        }
    }

    void sms () {
        int check = find();

        if (check == 0) {
            std::cout << "Number not found." << std::endl;
        } else {
            std::cout << "Enter sms: " << std::endl;
            std::string sms;
            std::cin.ignore();
            std::getline(std::cin, sms);
            std::cout<<"SMS send on number "<<addressBook[check-1].getNumber()<<std::endl;
        }
    }
};

int main() {
    Phone *phone = new Phone;
    while (true) {
        std::cout << "Enter the command (add/call/sms/exit):" << std::endl;
        std::string command;
        std::cin >> command;

        if (command=="add") {
            phone->add(phone);
        } else {
            if (command=="call" ) {
                phone->call();
            } else {
                if (command=="sms") {
                    phone->sms();
                } else {
                    if (command=="exit") {
                        break;
                    }
                }
            }
        }
    }

    delete phone;
}
