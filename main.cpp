#include <iostream>
#include <vector>
#include <list>
#include <clocale>
#include <cstdlib>
using namespace std;
/*В части № 1 выполнить следующее:
+1) Создать объект-контейнер и заполнить его данными.
+2) Просмотреть контейнер.
+3) Изменить контейнер, удалив из него одни элементы и заменив другие.
+4) Просмотреть контейнер, используя для доступа к его элементам итераторы.
+5) Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
+6) Изменить первый контейнер, удалив из него n элементов после заданного и добавив затем в него все элементы из второго контейнера.
+7) Просмотреть первый и второй контейнеры.
+В части № 2 выполнить то же самое, но для данных пользовательского типа (желательно использовать тип контейнера, отличный от используемого в части № 1).
+В части № 3 выполнить следующее:
+1. Создать контейнер, содержащий объекты пользовательского типа.
+2. Отсортировать его по убыванию элементов.
+3. Просмотреть контейнер.
+4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
+5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер.
+6. Просмотреть второй контейнер.
+7. Отсортировать первый и второй контейнеры по возрастанию элементов.
+8. Просмотреть их.
+9. Получить третий контейнер путем слияния первых двух.
+10. Просмотреть третий контейнер.
+11 .Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.
12. Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"rus");
//задание 1
    cout<<"Создание и инциализация 1 объекта STL контейнера Вектор. Текущие значения:"<<endl;
    vector <int> vec1={7, 5, 16, 8};
    srand(time(NULL));
    vec1.push_back(25);
    vec1.push_back(13);
    vec1.insert(vec1.begin()+2, 4);
    for(int n:vec1)
           std::cout<<n<<'\n';
    cout<<endl;
    cout<<"Создание и инциализация 2 объекта STL контейнера Вектор. Текущие значения:"<<endl;
    vector <int> vec2;
    for(int i=0;i<4;i++)
        vec2.push_back(rand());
    for(int n:vec2)
           std::cout<<n<<'\n';
    cout<<endl;
    vec1.erase(vec1.begin()+4, vec1.begin()+7);
    for(int i=0;i<4;i++)
        vec1.push_back(vec2[i]);
    cout<<"Вывод после изменений значений двух объектов vector:\n";
    for(int n:vec1)
           std::cout<<n<<' ';
    cout<<endl;
    for(int n:vec2)
           std::cout<<n<<' ';
    cout<<endl;
//задание 2
    struct userType{
        int value;
        string name;
    }struct1,struct2,struct3;
    struct1.name="qw";
    struct2.name="qq";
    struct3.name="qwerty";
    struct1.value=rand();
    struct2.value=rand();
    struct3.value=rand();

    cout<<"Создание и инциализация 1 объекта STL контейнера List. Текущие значения:"<<endl;
    list <userType> lis1;
    for(int i=0;i<2;i++){
        lis1.push_back(struct1);
        cout<<struct1.value<<" ";
    }
    lis1.push_back(struct3);
    lis1.push_back(struct2);
    //lis1.insert(lis1.begin()+2, struct2);
    cout<<"\nСоздание и инциализация 2 объекта STL контейнера List. Текущие значения:"<<endl;
    list <userType> lis2;
    for(int i=0;i<3;i++){
        lis2.push_back(struct3);
        cout<<struct3.value<<" ";
    }
    lis2.push_back(struct2);
    lis1.splice(lis1.begin(),lis2,lis2.begin(),lis2.end());
    //lis2.insert(lis2.begin()+1, struct1);
    cout<<"\nВывод после изменений значений двух объектов List:\n";
    for(list<userType>::iterator i=lis1.begin();i!=lis1.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    cout<<endl;
    for(list<userType>::iterator i=lis2.begin();i!=lis2.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    cout<<endl;
//задание 3
    userType data1, data2, data3, data4;
    cout<<"Создание и инциализация 1 объекта STL контейнера List c пользовательскими данными. Текущие значения:"<<endl;
    list<userType> firstKont={data1, data2, data3, data4};
    list<userType> secondKont;
    list<userType> thirdKont;
    firstKont.sort(std::greater<userType>());
    for(list<userType>::iterator i=firstKont.begin();i!=firstKont.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    cout<<endl;
    for(list<userType>::iterator i=firstKont.begin();i!=firstKont.end();i++){
        if(i->value==struct1.value) cout<<i->value<<" ";
        secondKont.splice(i, secondKont);
    }
    cout<<"Создан 2 объект STL контейнера List c пользовательскими данными. Текущие значения:"<<endl;
    for(list<userType>::iterator i=secondKont.begin();i!=secondKont.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    cout<<endl;
    firstKont.sort();
    secondKont.sort();
    cout<<"Элементы 1 и 2 объектов после сортировки. 1 объект:"<<endl;
    for(list<userType>::iterator i=firstKont.begin();i!=firstKont.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    cout<<endl;
    cout<<"2 объект:"<<endl;
    for(list<userType>::iterator i=secondKont.begin();i!=secondKont.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    thirdKont.merge(firstKont);
    thirdKont.merge(secondKont);
    cout<<"Создан 3 объект STL контейнера List c пользовательскими данными путем слияния 1 и 2 объектов. Текущие значения:"<<endl;
    for(list<userType>::iterator i=thirdKont.begin();i!=thirdKont.end();i++)
        cout<<"value: "<<i->value<<" name: "<<i->name<<"\n";
    int count=0;
    for(list<userType>::iterator i=thirdKont.begin();i!=thirdKont.end();i++){
        if(i->value==struct2.value) count++;
    }
    cout<<"Количество совпавших с struct2.value элементов="<<count<<endl;
    if(count!=0)
        cout<<"В третьем контейнере есть элемент, совпадающий с заданным."<<endl;
    return 0;
}
