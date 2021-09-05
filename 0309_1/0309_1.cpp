#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct student
{
    char firstname[30],
        name[30],
        address[50],
        phone[30];
   
};
int RW(student* arr,int N, char vul[30])
{
    ofstream out("info.dat", ios::binary);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (strstr(arr[i].address, vul) != NULL)
        {
            out.write((char*)&arr[i], sizeof(arr[i]));
            count++;
        }
    }
    out.close();
    return count;
}
void RD(int k)
{
    ifstream in("info.dat", ios::binary);
    student* arr = new student[k];
    
    for (int i = 0; i < k; i++)
    {
        in.read((char*)&arr[i], sizeof(arr[i]));
        cout << "Student " << (i + 1) << ":" << endl;
        cout << "First name:"; cout << arr[i].firstname<<endl;
        cout << "Name:"; cout<<arr[i].name<<endl;
        cout << "Address:"; cout<< arr[i].address << endl;
        cout << "Phone:"; cout<< arr[i].phone << endl;
        cout << endl;
    }
    in.close();
}
int RW(student* arr, int N, char vul[30],int b)
{
    ofstream out("info.txt", ios::out);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (strstr(arr[i].address, vul) != NULL)
        {
            out << arr[i].firstname << endl;
            out << arr[i].name << endl;
            out << arr[i].address << endl;
            out << arr[i].phone << endl;
            out << endl;
            count++;
        }
    }
    out.close();
    return count;
}
void RD(int k,int b)
{
    ifstream in("info.txt", ios::in);
    student* arr = new student[k];
    char buff[10];
    for (int i = 0; i < k; i++)
    {
        cout << "Student " << (i + 1) << ":" << endl;
        cout << "First name:"; 
        in >> arr[i].firstname;
        cout << arr[i].firstname << endl;
        cout << "Name:"; 
        in >> arr[i].name;
        cout << arr[i].name << endl;
        cout << "Address:"; 
        in.getline(arr[i].address, sizeof(arr[i].address));
        in.getline(arr[i].address, sizeof(arr[i].address));
        cout << arr[i].address << endl;
        cout << "Phone:";
        in >> arr[i].phone;
        cout << arr[i].phone << endl<<endl;
        in.getline(buff, sizeof(buff));
    }
}
int main()
{
    int N;
    cout << "N=";
    cin >> N;
    student* arr = new student[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Student " << (i + 1)<<":"<< endl;
        cout << "First name:"; cin >> arr[i].firstname;
        cout << "Name:"; cin >> arr[i].name;
        cout << "Address:"<<endl;        
        cin.getline(arr[i].address, sizeof(arr[i].address));
        cin.getline(arr[i].address, sizeof(arr[i].address));
        cout << "Phone:"; cin >> arr[i].phone;
    }
    char vul[30];
    cout << "Needed street:";
    cin >> vul;
    cout << "Students with needed street in address:" << endl;
    int count = RW(arr, N, vul);
    cout << endl<<"Count:" << count << endl;
    cout << "Binary:" << endl;
    cout << "--------------------" << endl;    
    RD(count);
    cout << "--------------------" << endl;
    cout << "Txt:" << endl;
    cout << "--------------------" << endl;
    int count1 = RW(arr, N, vul, 0);
    RD(count1, 0);
    cout << "--------------------" << endl;
}

