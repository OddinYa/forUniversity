#include <iostream>
#include "LinkingList.h"
#include <algorithm>


void input();
void test1();
void test2();
void display();
void doSwitch(int,LinkingList*);
bool checkToError(int);


int main() {

    display();

    // input(); // ввод с клавиатуры
    
   //  test1();
   //  test2();

    return 0;
}


void input() {

    setlocale(LC_ALL, "RU");

    LinkingList* listK = new LinkingList();
    LinkingList* listM = new LinkingList();
    LinkingList* listN = new LinkingList();

    int K;
    int M;
    int N;
    int min;


    std::cout << "Enter K: ";
    std::cin >> K;
    std::cout << "Enter M: ";
    std::cin >> M;
    std::cout << "Enter N: ";
    std::cin >> N;

    if (K < M) {
        if (K < N) {
            min = K;
        }
        else
        {
            min = N;
        }
    }
    else {
        if (M < N) {
            min = M;
        }
        else
        {
            min = N;
        }
    }
    if(min==0){
        std::cout << "No result";
        delete listK;
        delete listM;
        delete listN;
        
        return;
    }
    char inputChar;

    std::cout << "Enter s x K:";
    for (int i = 0; i < K; i++)
    {   

        std::cin >> inputChar;
        listK->add(inputChar);
    }

    std::cout << "Enter t x M :";
    for (int i = 0; i < M; i++)
    {   

        std::cin >> inputChar;
        listM->add(inputChar);
    }

    std::cout << "Enter u x N :";
    for (int i = 0; i < N; i++)
    {
        std::cin >> inputChar;
        listN->add(inputChar);
    }
    char* result = new char[min];

    Node* node = listK->get(0);

    int count = 0;

    while (node != nullptr) {

        if (listM->containsChar(node->ch) && listN->containsChar(node->ch)) {
            result[count] = node->ch;
            count++;
        }
        node = node->next;


     }
    if (count == 0) {
        std::cout << "No result";
        delete listK;
        delete listM;
        delete listN;
        delete[] result;
        return;
    }

    std::sort(result, result + count);

    for (int i = 0; i < count; i++)
    {
        std::cout << result[i] << " ";
    }

    delete listK;
    delete listM;
    delete listN;
    delete[] result;
}

void test1()
{
    char a = 'a';
    char b = 'b';
    char c = 'c';

    int lenResult = 3;

    setlocale(LC_ALL, "RU");

    LinkingList* listK = new LinkingList();
    LinkingList* listM = new LinkingList();
    LinkingList* listN = new LinkingList();

    listK->add(c);
    listK->add(b);
    listK->add(a);

    listM->add(b);
    listM->add(c);
    listM->add(a);

    listN->add(c);
    listN->add(a);
    listN->add(b);

    char* result = new char[lenResult];

    Node* node = listK->get(0);

    int count = 0;

    while (node != nullptr) {

        if (listM->containsChar(node->ch) && listN->containsChar(node->ch)) {
            result[count] = node->ch;
            count++;
        }
        node = node->next;


    }
    if (count == 0) {
        std::cout << "No Result";
        delete listK;
        delete listM;
        delete listN;
        delete[] result;
        return;
    }

    std::sort(result, result + count);
    std::cout << "test 1" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << result[i] << " ";  // ответ: a b c
    }

    std::cout << std::endl;

    delete listK;
    delete listM;
    delete listN;
    delete[] result;


}

void test2()
{
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char x = 'x';
    char e = 'e';

    int lenResult = 3;

    setlocale(LC_ALL, "RU");

    LinkingList* listK = new LinkingList();
    LinkingList* listM = new LinkingList();
    LinkingList* listN = new LinkingList();

    listK->add(c);
    listK->add(b);
    listK->add(a);

    listM->add(x);
    listM->add(c);
    listM->add(e);

    listN->add(c);
    listN->add(x);
    listN->add(b);

    char* result = new char[lenResult];

    Node* node = listK->get(0);

    int count = 0;

    while (node != nullptr) {

        if (listM->containsChar(node->ch) && listN->containsChar(node->ch)) {
            result[count] = node->ch;
            count++;
        }
        node = node->next;


    }
    if (count == 0) {
        std::cout << "No Result";
        delete listK;
        delete listM;
        delete listN;
        delete[] result;
        return;
    }

    std::sort(result, result + count);

    std::cout << "test 2" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << result[i] << " ";  // ответ: c
    }

    delete listK;
    delete listM;
    delete listN;
    delete[] result;


}

void display() {

    bool flag = true;

    int inp = 7;
    LinkingList* custom = new LinkingList();
    do {
        if (!flag) {
            std::cout << "Error. Try Again" << std::endl;
        }
        
        std::cout << "\n";
        std::cout << "Menu:" << std::endl;
        std::cout << "1.Create Linking List for task" << std::endl;
        std::cout << "2.Create custom Linking List" << std::endl;
        std::cout << "3.Get element from castom Linking List" << std::endl;
        std::cout << "4.Cheking element" << std::endl;
        std::cout << "5.Get last and Head" << std::endl;
        std::cout << "6.Remove element" << std::endl;
        std::cout << "7.Exit" << std::endl;

        std::cout << "Enter numb:";
        std::cin >> inp;

       

        doSwitch(inp,custom);

        if (inp < 1 || inp >7) {
            flag = false;
        }
        else if (inp == 7) {
            delete custom;
        }
        

    } while (inp != 7);

    

 }

void doSwitch(int inputNumb,LinkingList* custom) {

  

    switch (inputNumb)
    {
    case 1: {
        input();
        break; }
    case 2: {
        std::cout << "Enter Node Number: " << std::endl;
        int numb;

        std::cin >> numb;

        if (checkToError(numb)){
            
            break;
        }
        for (int i = 0; i < numb; i++) {
           
            char date;

            std::cout << "Enter date: " << std::endl;
            std::cin >> date;
            custom->add(date);

            }
        std::cout << "Completed" << std::endl;
        break;
    }
    case 3: {
        int numb = 0;
        std::cout << "Enter Index: " << std::endl;
        std::cin >> numb;

        if (checkToError(numb)) {
            break;
        }

        Node* node = custom->get(numb);
        
        std::cout << node->ch << std::endl;
        break;
    }
    case 4: {
        int numb = 0;

        char find;
        std::cout << "Enter char: " << std::endl;
        std::cin >> find;

        bool req = custom->containsChar(find);
        if (req) {
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout << "No" << std::endl;
        }

        std::cout << "Completed" << std::endl;
        break;
    }
    case 5: {
        Node* tempNode = custom->getHead();
        std::cout << "Head: " << tempNode->ch<< std::endl;

        tempNode = custom->getLast();
        std::cout << "End: " << tempNode->ch;
        break;
    }
    case 6: {
        std::cout << "Enter index: ";
        int numb;
        std::cin >> numb;

        custom->remove(numb);
        std::cout << "Completed" << std::endl;
        break;
    }case 7: break;




    default:
        std::cout << "Error" << std::endl;
        break;
    }

      
}

bool checkToError(int numb) {

    if (numb < 0) {
        std::cout << "Error Node Number < 0, go to menu" << std::endl;
        return true;
    }
    return false;
}