#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<ctime>
#include<windows.h>
#include<string>
#include"��ɾ�Ͷ�����ͷ�ļ�.h"
using namespace std;
int main()
{   
    std::string rubbish;
    std::string a[23767];
    int number=0;
    START:
    std::cout<<"��ӭʹ��ѧ������ϵͳ(��ԭ���Ҳ���Qt)\n\n��������Ҫȷ�����Ƿ���Ҫ��������ѧ�������Ͱ༶�������������ʹ��,����Ҫ(����)����༶������ѧ������\n�Ƿ���Ҫ¼���������¼��ѧ������?\n"
    <<"ע�⣺ѧ���������������ֿ�ͷ";
    std::cout<<"\t0. ��,��Ҫ(����)¼��\t1.��, ����Ҫ(����)¼��\t2. ��Ҫ��������\t3.��Ҫ��������\t4.�ر�\n";
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
                std::cout<<"¼��ʧ�ܣ�����˳���(�ļ�)�Ƿ��д洢/�޸��ļ���Ȩ��\n";
                Sleep(5000);
            }
            else
            {
                system("cls");
                std::cout<<"����ѧ������\n";
                std::cin>>number;
                fout<<number<<'\n';
                for(int i=0;i<number;i++)
                {
                std::cout<<"�������"<<i+1<<"��ѧ��������,�ǵ�������֮��ͻ���\n";
                if(i==0)
                {
                    std::cin>>rubbish;
                }
                std::getline(cin,a[i]);
                fout<<a[i]<<'\n';
                }
                std::cout<<"¼��ɹ�\n";
                fout.close();
            }
            system("cls");
            goto START;
            break;
        case 1:
        {
            fin.open("name.txt",std::ios::in);
            fin>>number;
            std::cout<<"�ϴ������������"<<number<<'\n';
            std::cout<<"���ڴ洢��\" ����\"�������ͺ���Ҫ�Ĵ��������Ͳ�ƥ�䣬������ѧ������\n";
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
                std::cout<<"�˴�Ҫ�ش��������"<<a[another_int]<<'\n'<<"�Ƿ�Ҫ����ѡ��?\n";
                std::cout<<"\n1, ����ѡ��                                              0, ������ѡ�񲢹رճ���"<<std::endl;
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
                std::cout<<"¼��ʧ�ܣ�����˳���(�ļ�)�Ƿ��д洢/�޸��ļ���Ȩ��\n";
            }
            else
            {
                system("cls");
                fin>>number;
                std::cout<<"�ϴ������������"<<number<<'\n';
                std::cout<<"���ڴ洢��\" ����\"�������ͺ���Ҫ�Ĵ��������Ϳ��ܲ�ƥ�䣬�����ϴ������ѧ������\n";
                std::cin>>number;
                std::cout<<"��������Ҫ���ӵ�ѧ������\n";
                int add=0;
                std::cin>>add;
                fout<<number+add<<'\n';
                for(int i=number-1;i<number+add;i++)
                {
                std::cout<<"�������"<<i+1<<"��ѧ��������,ÿ������һ�����ּǵû���һ��\n";
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
                std::cout<<"¼��ɹ�\n";
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
                std::cout<<"¼��ʧ�ܣ�����˳���(�ļ�)�Ƿ��д洢/�޸��ļ���Ȩ��\n";
            }
            else
            {
                system("cls");
                fin>>number;
                std::cout<<"�ϴ������������"<<number<<'\n';
                std::cout<<"���ڴ洢��\" ����\"�������ͺ���Ҫ�Ĵ��������Ϳ��ܲ�ƥ�䣬�����ϴ������ѧ������\n";
                std::cin>>number;
                for(int i=0;i<number;i++)
                {
                fin>>a[i];
                }
                std::cout<<"��������Ҫ��ȥ��ѧ������\n";
                int add=0;
                std::cin>>add;
                fout<<number-add<<'\n';
                for(int i=0;i<add;i++)
                {
                std::string subtract;
                std::cout<<"��������Ҫ��ȥ��ѧ������,ÿ������һ�����ּǵû���һ��\n";
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
                std::cout<<"¼��ɹ�\n";
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
