#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<ctime>
#include<windows.h>
#include<string>
#include"别删就对了是头文件.h"
using namespace std;
int main()
{   
    std::string rubbish;
    std::string a[23767];
    int number=0;
    START:
    std::cout<<"欢迎使用学生提问系统(请原谅我不会Qt)\n\n我首先需要确认你是否需要重新输入学生姓名和班级人数。若你初次使用,则需要(重新)输入班级人数和学生姓名\n是否需要录入或者重新录入学生姓名?\n"
    <<"注意：学生姓名不得以数字开头";
    std::cout<<"\t0. 是,需要(重新)录入\t1.否, 不需要(重新)录入\t2. 需要增加人数\t3.需要减少人数\t4.关闭\n";
    int answer=-1;
    std::cin>>answer;
    std::ofstream fout;
    std::ifstream fin;
    //std::ifstream getline;
    switch(answer)
    {
        case 0:
            system("cls");
            fout.open("name.txt");
            if(!fout.is_open())
            {
                std::cout<<"录入失败，请检查此程序(文件)是否有存储/修改文件的权限\n";
                Sleep(5000);
            }
            else
            {
                system("cls");
                std::cout<<"输入学生人数\n";
                std::cin>>number;
                fout<<number<<'\n';
                for(int i=0;i<number;i++)
                {
                std::cout<<"请输入第"<<i+1<<"个学生的名字,记得输入完之后就换行\n";
                if(i==0)
                {
                    std::cin>>rubbish;
                }
                std::getline(cin,a[i]);
                fout<<a[i]<<'\n';
                }
                std::cout<<"录入成功\n";
                fout.close();
            }
            system("cls");
            goto START;
            break;
        case 1:
        {
            fin.open("name.txt",std::ios::in);
            fin>>number;
            std::cout<<"上次输入的人数是"<<number<<'\n';
            std::cout<<"由于存储的\" 人数\"数据类型和需要的此数据类型不匹配，请输入学生人数\n";
            std::cin>>number;
            for(int j=0;j<number;j++)
            {   
                std::getline(fin,a[j]);
                //fin>>a[j];
            }
            bool answer_2=1;
            while (answer_2==true)
            {
                srand(time(0));
                int another_int=0;
                another_int=rand()%number;
                std::cout<<"此次要回答问题的是"<<a[another_int]<<'\n'<<"是否要重新选择?\n";
                std::cout<<"\n1, 重新选择                                              0, 不重新选择并关闭程序"<<std::endl;
                std::cin>>answer_2;
                system("cls");
            }
        }
            break;
        case 2:
        {
            fin.open("name.txt",std::ios::in);
            fout.open("name.txt");
            if(!fout.is_open())
            {
                std::cout<<"录入失败，请检查此程序(文件)是否有存储/修改文件的权限\n";
            }
            else
            {
                system("cls");
                fin>>number;
                std::cout<<"上次输入的人数是"<<number<<'\n';
                std::cout<<"由于存储的\" 人数\"数据类型和需要的此数据类型可能不匹配，请输上次输入的学生人数\n";
                std::cin>>number;
                std::cout<<"请输入需要增加的学生人数\n";
                int add=0;
                std::cin>>add;
                fout<<number+add<<'\n';
                for(int i=number-1;i<number+add;i++)
                {
                std::cout<<"请输入第"<<i+1<<"个学生的名字,每输入完一个名字记得换行一次\n";
                if(i==0)
                {
                    std::cin>>rubbish;
                }
                std::getline(cin,a[i]);
                std::cout<<'\n';
                }
                for(int i=0;i<number+add;i++)
                {
                fout<<a[i]<<'\n';
                }
                std::cout<<"录入成功\n";
                fout.close();
            }
            system("cls");
            goto START;
        }
            break;
        case 3:
            system("cls");
            fin.open("name.txt",std::ios::in);
            fout.open("name.txt");
            if(!fout.is_open())
            {
                std::cout<<"录入失败，请检查此程序(文件)是否有存储/修改文件的权限\n";
            }
            else
            {
                system("cls");
                fin>>number;
                std::cout<<"上次输入的人数是"<<number<<'\n';
                std::cout<<"由于存储的\" 人数\"数据类型和需要的此数据类型可能不匹配，请输上次输入的学生人数\n";
                std::cin>>number;
                for(int i=0;i<number;i++)
                {
                fin>>a[i];
                }
                std::cout<<"请输入需要减去的学生人数\n";
                int add=0;
                std::cin>>add;
                fout<<number-add<<'\n';
                for(int i=0;i<add;i++)
                {
                std::string subtract;
                std::cout<<"请输入需要减去的学生名字,每输入完一个名字记得换行一次\n";
                if(i==0)
                {
                    std::cin>>rubbish;
                }
                std::getline(cin,subtract);
                    for(int j=0;j<number;j++)
                    {
                        if(a[j]==subtract)
                        {
                            a[i]="\0";
                            break;
                        }
                    }
                }
                for(int i=0;i<number;i++)
                {
                    fout<<number-add;
                    if(a[i]!="\0")
                    {
                        fout<<a[i];
                    }
                    else if(a[i]=="\0")
                    {
                        continue;
                    }
                }
                std::cout<<"录入成功\n";
                fout.close();
            }
            break;
        case 4:
            break;
        default:
            punish();
            goto START;
            break;
    }
    return 0;
}
