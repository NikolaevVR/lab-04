#include <iostream>
#include <assert.h>
#include <cstdint>

struct Student{
    char name[17];
    int year;
    double sred_ball;
    int sex:1;
    int classes;
    Student* Starosta;
};

char nibble_m_hex (size_t i);

void Test();

void print_in_hex(uint8_t byte);

const uint8_t* as_bytes(const void* data);

void print_in_hex(const void* data, size_t size);

char bit_digit(uint8_t byte, uint8_t bit);

void print_in_binary(uint8_t byte);

void print_in_binary(const void* data, size_t size);

uint32_t calculator(uint32_t value_1, char sing, uint32_t value_2);

int main() {
    Test();
   Student students[3] = {{"Nicita", 2017, 4, 1, 1, nullptr},{"Alecsandr",2017,3.5
, 1, 1, &students[0]},{"Pavel", 2017, 4, 1, 1, &students[0]}};
    // адрес и размер


    std::cout << "Adrees of array" << &students << std::endl << "Size of array " <<
            sizeof(students) << std::endl;
    for (size_t i =0 ; i <3; i++){
        std::cout << i+1 << ':' << " Adrees of array elements" << &students[i] <<
                std::endl << "Size of array element " << sizeof(students[i]) <<
                std::endl << std::endl;
    }

    std::cout << "Element #2:" << '\n';
    std::cout << "\tAddress of field:" << "\t Size of field:" << "\t offset" << '\n';
    std::cout << "Name:\t\t" << &students[1].name << "\t\t" << sizeof
    (students[1].name) << "\t\t" << offsetof(struct Student,name)<< std::endl;
    std::cout << "Year:\t\t" << &students[1].year << "\t\t" << sizeof
    (students[1].year) << "\t\t" << offsetof(struct Student,year)<< std::endl;
    std::cout << "Sred_ball:\t" << &students[1].sred_ball << "\t\t" << sizeof
    (students[1].sred_ball) << "\t\t" << offsetof(struct Student,sred_ball)<< std::endl;
    std::cout << "Classes:\t" << &students[1].classes<< "\t\t" << sizeof
    (students[1].classes) << "\t\t" << offsetof(struct Student,classes)<< std::endl;
    std::cout << "Starosta:\t" << students[1].Starosta << "\t\t" << sizeof
    (students[1].Starosta) << "\t\t" << offsetof(struct Student,Starosta)<< std::endl;

    std::cout << "\nElement #3:" << '\n';
    std::cout << "\tAddress of field:" << "\t Size of field:" << "\t offset" << '\n';
    std::cout << "Name:\t\t" << &students[2].name << "\t\t" << sizeof
    (students[2].name) << "\t\t" << offsetof(struct Student,name)<< std::endl;
    std::cout << "Year:\t\t" << &students[2].year << "\t\t" << sizeof
    (students[2].year) << "\t\t" << offsetof(struct Student,year)<< std::endl;
    std::cout << "Sred_ball:\t" << &students[2].sred_ball << "\t\t" << sizeof
    (students[2].sred_ball) << "\t\t" << offsetof(struct Student,sred_ball)<< std::endl;
    std::cout << "Classes:\t" << &students[2].classes<< "\t\t" << sizeof
    (students[2].classes) << "\t\t" << offsetof(struct Student,classes)<< std::endl;
    std::cout << "Starosta:\t" << students[2].Starosta << "\t\t" << sizeof
    (students[2].Starosta) << "\t\t" << offsetof(struct Student,Starosta)<< std::endl;
for(size_t i = 0; i < 3; i++) {
    std::cout << "\nElement #"<< i+1 <<":" << '\n';
    std::cout << "\nName\nbinary: ";
    print_in_binary(&students[i].name, sizeof(students[i].name));
    std::cout << std::endl << "Hex: ";
    print_in_hex(&students[i].name, sizeof(students[i].name));
    std::cout << "\n\nYear\nbinary: ";
    print_in_binary(&students[i].year, sizeof(students[i].year));
    std::cout << std::endl << "Hex: ";
    print_in_hex(&students[i].year, sizeof(students[i].year));
    std::cout << "\n\nSred_ball\nbinary: ";
    print_in_binary(&students[i].sred_ball, sizeof(students[i].sred_ball));
    std::cout << std::endl << "Hex: ";
    print_in_hex(&students[i].sred_ball, sizeof(students[i].sred_ball));
    std::cout << "\n\nClasses\nbinary: ";
    print_in_binary(&students[i].classes, sizeof(students[i].classes));
    std::cout << std::endl << "Hex: ";
    print_in_hex(&students[i].classes, sizeof(students[i].classes));
    std::cout << "\n\nStarosta\nbinary: ";
    print_in_binary(&students[i].Starosta, sizeof(students[i].Starosta));
    std::cout << std::endl << "Hex: ";
    print_in_hex(&students[i].Starosta, sizeof(students[i].Starosta));
    std::cout << std::endl;
}



    uint32_t value_1,value_2, result;
    char sing;
    std::cout << "Введите пример ";
    std::cin >> value_1 >> sing >> value_2;
    result = calculator(value_1,sing,value_2);
    print_in_hex(&value_1, sizeof(value_1));
    std::cout << ' ' << sing << ' ';
    print_in_hex(&value_2, sizeof(value_2));
    std::cout << " = ";
    print_in_hex(&result,sizeof(result));
    print_in_hex(&value_1, sizeof(value_1));
    std::cout << ' ' << sing << ' ';
    print_in_hex(&value_2, sizeof(value_2));
    std::cout << " = ";
    print_in_hex(&result,sizeof(result));
    std::cout << std::endl;
    print_in_binary(&value_1, sizeof(value_1));
    std::cout << ' ' << sing << ' ';
    print_in_binary(&value_2, sizeof(value_2));
    std::cout << " = ";
    print_in_binary(&result,sizeof(result));


    return 0;
}

void Test(){
    assert(nibble_m_hex(0x0) == '0');
    assert(nibble_m_hex(0x1) == '1');
    assert(nibble_m_hex(0x2) == '2');
    assert(nibble_m_hex(0x3) == '3');
    assert(nibble_m_hex(0x4) == '4');
    assert(nibble_m_hex(0x5) == '5');
    assert(nibble_m_hex(0x6) == '6');
    assert(nibble_m_hex(0x7) == '7');
    assert(nibble_m_hex(0x8) == '8');
    assert(nibble_m_hex(0x9) == '9');
    assert(nibble_m_hex(0xa) == 'a');
    assert(nibble_m_hex(0xb) == 'b');
    assert(nibble_m_hex(0xc) == 'c');
    assert(nibble_m_hex(0xd) == 'd');
    assert(nibble_m_hex(0xe) == 'e');
    assert(nibble_m_hex(0xf) == 'f');
} // тест

char nibble_m_hex (size_t i){
    char value [] = "0123456789abcdef";
    assert(0x0 <= i && i <= 0xf);
    return value [i];
}  // перевод в 16 одного nibble

void print_in_hex(uint8_t byte){
    std::cout << nibble_m_hex((byte >> 4));
    std::cout << nibble_m_hex(byte & 0xf);
} // печать одного байта в 16 сис

const uint8_t* as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
} // как это работает, посмотреть

void print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);

        if ((i + 1) % 16 == 0) {
            std::cout << '\n';
        }
        else {
            std::cout << ' ';
        }
    }
} // печать массива байт

char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
} // перевод в 2 сис одного nibble

void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 8; 0 < bit ; bit--) {
        std::cout << bit_digit(byte, bit-1);
    }
} // печать одного байта в 2 сис

void print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

        if ((i + 1) % 4 == 0) {
            std::cout << '\n';
        }
        else {
            std::cout << ' ';
        }
    }
}  // печать массива байт в 2 сис

uint32_t calculator(uint32_t value_1, char sing, uint32_t value_2){
    switch(sing){
    case '&': return value_1&value_2; break;
    case '|': return value_1|value_2; break;
    case '^': return value_1^value_2; break;
    }
} // калькулятор


