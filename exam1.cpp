#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
class person
{   public:
	virtual void Set_money(float)=0;
	virtual void Delete() = 0;
};
class Employee:public person
{   protected:
	string name;
	string IDnumber;
	string position;
	string sex;
	int year;
	int month;
	int day;
	float money;
public:
	Employee(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000);//可不输入工资，默认值为3000；其余为基本信息，必须输入 
	friend ostream &operator<<(ostream &, Employee &);
	friend istream &operator>>(istream &, Employee &);
	virtual void Set(Employee &p) {cin>>p;}; 
	virtual void Set_money(float x) { money = x; };
	virtual void Search_correct(int n1, Employee *p1);
	virtual void Search_show(int n2, Employee *p2);
	virtual void Search_delete(int n3, Employee *p3);
	virtual void Delete();
};
ostream &operator<<(ostream &output, Employee &p)
{
	output << "姓名为: " << p.name << ",编号为: " << ",职位为: " << p.position<< p.IDnumber  << ",性别为: " << p.sex
		<< ",出生时间: " << p.year << " " << p.month << " " << p.day << ",工资为: " << p.money;
	return output;
}
istream &operator>>(istream &input, Employee &p1)
{
	cout << "请输入成员信息,包括姓名、编号、性别、生日 (注: 写成1999 03 08的形式) : ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day;
	p1.position = "employee";
	return input;
}
Employee::Employee(string i, string j, string k, int a, int b, int c, float x)
{
	name = i;
	IDnumber = j;
	position = "employee";
	sex = k;
	year = a;
	month = b;
	day = c;
	money = x;
}
void Employee::Search_correct(int n1, Employee *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "请输入姓名: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p1[i].name == Name1)
			{	cin >> p1[i];
				break;
		    }
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "请输入编号: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "没有该编号的普通员工。" << endl;
				else if (p1[i].IDnumber == ID1)
				{	cin >> p1[i];
				    break;
		       }
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Employee::Search_show(int n2, Employee *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "请输入姓名: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "没有该编号的普通员工。" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Employee::Search_delete(int n3,Employee *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "请输入姓名: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "没有该编号的普通员工。" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Employee::Delete()
{
	name = IDnumber = position = sex = "";
	year = month = day = 0;
}
class Manager :virtual public Employee
{
protected:
	float accumPay1;
public:
	Manager(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000, float = 12000);//设经理的基本工资为12000。 
	friend ostream &operator<<(ostream &, Manager &);
	friend istream &operator>>(istream &, Manager &);
	virtual void set_money(float x) { accumPay1 = x; }
	virtual void Set(Manager &p) {cin>>p;} 
	virtual void Search_correct(int n1, Manager *p1);
	virtual void Search_show(int n2, Manager *p2);
	void Search_delete(int n3,Manager *p3);
	virtual void Delete();
};
Manager::Manager(string i, string j, string k, int a, int b, int c, float x, float y)
{
	Employee(i, j, k, a, b, c, x);
	accumPay1 = y;
}
ostream &operator<<(ostream &output, Manager &p)
{
	output << "姓名为: " << p.name << ",编号为: " << p.IDnumber << ",职位为: " << p.position << ",性别为: " << p.sex
		<< ",出生时间: " << p.year << " " << p.month << " " << p.day << ",工资为: " << p.accumPay1;
	return output;
}
istream &operator>>(istream &input, Manager &p1)
{
	cout << "请输入成员信息,包括姓名、编号、性别、生日 (注: 写成1999 03 08的形式)、 : ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day;
	p1.position = "Manager";
	return input;
}
void Manager::Search_correct(int n1, Manager *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "请输入姓名: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "没有该姓名的经理。" << endl;
			else if (p1[i].name == Name1)
			{
				p1[i].Delete();
				cin >> p1[i];
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "请输入编号: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "没有该编号的经理。" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Manager::Search_show(int n2, Manager *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "请输入姓名: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "没有该姓名的经理。" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "没有该编号的经理。" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Manager::Search_delete(int n3,Manager *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "请输入姓名: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "没有该编号的普通员工。" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Manager::Delete()
{
	name = IDnumber = position = sex = "";
	year = month = day = 0;
}
class Technician :virtual public Employee
{
protected:
	float accumPay2;
	float hour;
	float money_per;
public:
	Technician(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000, float = 0, float = 0, float = 0);
	friend ostream &operator<<(ostream &, Technician &);
	friend istream &operator>>(istream &, Technician &);
	void set_money_per(float x) { money_per = x; }
	virtual void set_money();
	virtual void Set(Technician &p) {cin>>p;} 
	virtual void Search_correct(int n1, Technician *p1);
	virtual void Search_show(int n2, Technician *p2);
	virtual void Search_delete(int n3,Technician *p3);
	virtual void Delete();
};
Technician::Technician(string i, string j, string k, int a, int b, int c, float x, float y, float z, float w)
{
	Employee(i, j, k, a, b, c, x);
	accumPay2 = y;
	hour = z;
	money_per = w;
}
void Technician::set_money()
{
	accumPay2 = hour * money_per;
}
ostream &operator<<(ostream &output, Technician &p)
{
	output << "姓名为: " << p.name << ",编号为: " << p.IDnumber << ",职位为: " << p.position << ",性别为: " << p.sex
		<< ",出生时间: " << p.year << " " << p.month << " " << p.day << ",工资为: " << p.accumPay2 ;
	return output;
}
istream &operator>>(istream &input, Technician &p1)
{
	cout << "请输入成员信息,包括姓名、编号、性别、生日 (注: 写成1999 03 08的形式)、工作时间 : ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day >> p1.hour;
	p1.position = "Technician";
	return input;
}
void Technician::Search_correct(int n1, Technician *p1)
{	int i;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "请输入姓名: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "没有该姓名的技术人员。" << endl;
			else if (p1[i].name == Name1)
			{
				p1[i].Delete();
				cin >> p1[i];
				p1[i].set_money();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "请输入编号: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "没有该编号的技术人员。" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					p1[i].set_money();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Technician::Search_show(int n2, Technician *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "请输入姓名: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "没有该姓名的技术人员。" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "没有该编号的技术人员。" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Technician::Search_delete(int n3,Technician *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "请输入姓名: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "没有该编号的普通员工。" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Technician::Delete()
{
	name = IDnumber = position = sex = "";
	year = month = day = 0;
	hour=0;
}
class Salesman :virtual public Employee
{
protected:
	float accumPay3;
	float saleroom;
	float rate1;
public:
	Salesman(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000, float = 0, float = 0, float = 0);
	friend ostream &operator<<(ostream &, Salesman &);
	friend istream &operator>>(istream &, Salesman &);
	virtual void set_rate(float y) { rate1 = y; }
	virtual void set_money();
	virtual void Set(Salesman &p) {cin>>p;}
	virtual void Search_correct(int n1, Salesman *p1);
	virtual void Search_show(int n2, Salesman *p2);
	virtual void Search_delete(int n3,Salesman *p3);
	virtual void Delete();
};
Salesman::Salesman(string i, string j, string k, int a, int b, int c, float x, float y, float z, float w)
{
	Employee(i, j, k, a, b, c, x);
	accumPay3 = y;
	saleroom = z;
	rate1 = w;
}
void Salesman::set_money()
{
	accumPay3 = rate1 * saleroom;
}
ostream &operator<<(ostream &output, Salesman &p)
{
	output << "姓名为: " << p.name << ",编号为: " << p.IDnumber << ",职位为: " << p.position << ",性别为: " << p.sex
		<< ",出生时间: " << p.year << " " << p.month << " " << p.day << ",工资为: " << p.accumPay3 ;
	return output;
}
istream &operator>>(istream &input, Salesman &p1)
{
	cout << "请输入成员信息,包括姓名、编号、性别、生日 (注: 写成1999 03 08的形式)、销售额: ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day >> p1.saleroom;
	p1.position = "Salesman";
	return input;
}
void Salesman::Search_correct(int n1, Salesman *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "请输入姓名: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "没有该姓名的销售人员。" << endl;
			else if (p1[i].name == Name1)
			{
				p1[i].Delete();
				cin >> p1[i];
				p1[i].set_money();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "请输入编号: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "没有该编号的销售人员。" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					p1[i].set_money();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Salesman::Search_show(int n2, Salesman *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "请输入姓名: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "没有该姓名的销售人员。" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "没有该编号的销售人员。" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Salesman::Search_delete(int n3,Salesman *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "请输入姓名: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "没有该编号的普通员工。" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Salesman::Delete()
{
	name = IDnumber = position = sex = "";
	year = month = day = 0;
	saleroom =0;
}
class Salemanager :public Manager, public Salesman
{
protected:
	float accumPay4;
	float base_money;
	float rate2;
public:
	Salemanager(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000, float = 0, float = 0, float = 0, float = 0, float = 0, float = 0, float = 0);
	friend ostream &operator<<(ostream &, Salemanager &);
	friend istream &operator>>(istream &, Salemanager &);
	void set_base_money(float k) { base_money = k; }
	virtual void set_rate(float z) { rate2 = z; }
	virtual void set_money();
	virtual void Set(Salemanager &p) {cin>>p;} 
	virtual void Search_correct(int n1, Salemanager *p1);
	virtual void Search_show(int n2, Salemanager *p2);
	virtual void Search_delete(int n3,Salemanager *p3);
	virtual void Delete();
};
Salemanager::Salemanager(string i, string j, string k, int a, int b, int c, float m, float n, float x, float y, float z, float r, float s, float t)
//m为employee的工资；n为经理的固定工资；x,y,z代表Salesman的三个参数；r,s,t代表Salemanage三个参数。 
{
	Manager(i, j, k, a, b, c, m, n);
	Salesman(i, j, k, a, b, c, m, x, y, z);
}
ostream &operator<<(ostream &output, Salemanager &p)
{
	output << "姓名为: " << p.name << ",编号为: " << p.IDnumber << ",职位为: " << p.position << ",性别为: " << p.sex
		<< ",出生时间: " << p.year << " " << p.month << " " << p.day << ",工资为: " << p.accumPay4;
	return output;
}
void Salemanager::set_money()
{
	accumPay4 = base_money + rate2 * saleroom;
}
istream &operator>>(istream &input, Salemanager &p1)
{
	cout << "请输入成员信息,包括姓名、编号、性别、生日 (注: 写成1999 03 08的形式)、销售额: ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day>>p1.saleroom;
	p1.position = "Salemanager";
	return input;
}
void Salemanager::Search_correct(int n1, Salemanager *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "请输入姓名: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "没有该姓名的销售经理。" << endl;
			else if (p1[i].name == Name1)
			{
				p1[i].Delete();
				cin >> p1[i];
				p1[i].set_money();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "请输入编号: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "没有该编号的销售经理。" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					p1[i].set_money();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Salemanager::Search_show(int n2, Salemanager *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "请输入姓名: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "没有该姓名的销售经理。" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "没有该编号的销售经理。" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Salemanager::Search_delete(int n3,Salemanager *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "是否使用姓名查找法？(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "请输入姓名: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "没有该姓名的普通员工。" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "是否使用编号查找法？(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "请输入编号: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "没有该编号的普通员工。" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "无法通过搜索查找您要的成员信息。"<<endl;
	}
}
void Salemanager::Delete()
{
	name = IDnumber = position = sex = "";
	year = month = day = 0;
}
void title()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('+') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(24) << "xxx公司人事管理系统" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('+') << setw(2) << a;
	}
	cout << endl << endl;
}
void menu()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(17) << "主菜单" << endl;
	cout << setw(19) << "1.基本员工" << endl;//这样设计是为了保证员工只能看到与自己职位相同的人的信息。 
	cout << setw(17) << "2.经理" << endl;
	cout << setw(19) << "3.技术人员" << endl;
	cout << setw(19) << "4.销售人员" << endl;
	cout << setw(19) << "5.销售经理" << endl;
	cout << setw(17) << "6.退出" << endl;
	cout << setw(23) << "请输入序号（1-6）" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu_Employee()
{
	string a;
	a = " ";
	int i;
	cout << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(23) << "子菜单(普通员工)" << endl;
	cout << setw(19) << "1.设置工资" << endl;
	cout << setw(19) << "2.添加信息" << endl;
	cout << setw(19) << "3.修改信息" << endl;
	cout << setw(19) << "4.显示信息" << endl;
	cout << setw(19) << "5.删除人员" << endl;
	cout << setw(20) << "6.返回主菜单" << endl;
	cout << setw(23) << "请输入序号（1-5）" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu_Manager()
{
	string a;
	a = " ";
	int i;
	cout << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(20) << "子菜单(经理)" << endl;
	cout << setw(21) << "1.设置经理工资" << endl;//这里把经理当作普通经理，工资相同。 
	cout << setw(19) << "2.添加信息" << endl;
	cout << setw(19) << "3.修改信息" << endl;
	cout << setw(19) << "4.显示信息" << endl;
	cout << setw(19) << "5.删除人员" << endl;
	cout << setw(20) << "6.返回主菜单" << endl;
	cout << setw(23) << "请输入序号（1-6）" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu_Technician()
{
	string a;
	a = " ";
	int i;
	cout << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(22) << "子菜单(技术人员)" << endl;
	cout << setw(21) << "1.设置单位工资" << endl;//所以技术人员共享money_per。 
	cout << setw(19) << "2.添加信息" << endl;
	cout << setw(19) << "3.修改信息" << endl;
	cout << setw(19) << "4.显示信息" << endl;
	cout << setw(19) << "5.删除人员" << endl;
	cout << setw(20) << "6.返回主菜单" << endl;
	cout << setw(23) << "请输入序号（1-6）" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu_Salesman()
{
	string a;
	a = " ";
	int i;
	cout << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(22) << "子菜单(销售人员)" << endl;
	cout << setw(21) << "1.设置销售额率" << endl;//即rate1。 
	cout << setw(19) << "2.添加信息" << endl;
	cout << setw(19) << "3.修改信息" << endl;
	cout << setw(19) << "4.显示信息" << endl;
	cout << setw(19) << "5.删除人员" << endl;
	cout << setw(20) << "6.返回主菜单" << endl;
	cout << setw(23) << "请输入序号（1-6）" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu_Salemanager()
{
	string a;
	a = " ";
	int i;
	cout << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(22) << "子菜单(销售经理)" << endl;
	cout << setw(21) << "1.设置销售额率" << endl;//即rate2。 
	cout << setw(21) << "2.设置基本工资" << endl;//即base_money。 
	cout << setw(19) << "3.添加信息" << endl;
	cout << setw(19) << "4.修改信息" << endl;
	cout << setw(19) << "5.显示信息" << endl;
	cout << setw(19) << "6.删除人员" << endl;
	cout << setw(20) << "7.返回主菜单" << endl;
	cout << setw(23) << "请输入序号（1-7）" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
int main()
{   Employee Emp[100];
	Manager Man[100];
	Technician Tec[100];
	Salesman Sal[100];
	Salemanager sal[100];
	int p=1, q=1, i, s = 0, t = 0, n = 0, m = 0, k = 0;
	float Money = 3000, Money1 = 12000, per_money = 100, Rate1 = 0.05, Rate2 = 0.04, Base_money = 10000;
	while (p!=7)
	{   menu();
		cin >> p;
		if (p == 1)
		{   submenu_Employee();
			while (q!=6)
			{   cin >> q;
				if (q == 1)
				{   cout<<"请输入员工的基本工资: "; 
					cin >> Money;
					{
						for (i = 0; i <= s - 1; i++)
						{
							Emp[i].Set_money(Money);
						}
					}
					cout<<"普通员工基本工资设置完成。"<<endl;
					cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 2)
				{   
					Emp[s].Set(Emp[s]);
					Emp[s].Set_money(Money);
					s = s + 1;
					cout<<"已完成添加。"<<endl;
					cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 3)
				{
					if (s == 0) cout << "目前没有普通员工。" << endl;
					else
					{
						Emp[0].Search_correct(s, Emp);
						cout<<"已完成修改。"<<endl;
						cout << "请输入序号（1-6）: " << endl; 
					}
				}
				else if (q == 4)
				{
					if (s == 0) cout << "目前没有普通员工。" << endl;
					else
					{	Emp[0].Search_show(s, Emp);
					    cout<<"已完成显示。"<<endl;
						cout << "请输入序号（1-6）: " << endl; 
					} 
				}
				else if(q==5)
				{  if (s == 0) cout << "目前没有普通员工。" << endl;
					else
					{	Emp[0].Search_delete(s, Emp);
						s=s-1;
						cout<<"已完成删除。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
					} 
				}
				else if(q==6)
				 break;
				 else cout<<"请重新输入。"<<endl; 
			}
		}
		else if (p == 2)
		{
			submenu_Manager();
			while (q!=6)
			{   cin >> q;
				if (q == 1)
				{   cout<<"请输入经理工资: "; 
					cin >> Money1; 
						for (i = 0; i <= t - 1; i++)
						{
							Man[i].set_money(Money1);
						}
						cout<<"以完成经理工资设置。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 2)
				{
					Man[t].Set(Man[t]);
					Man[t].set_money(Money1);
					t = t + 1;
					cout<<"已完成添加。"<<endl;
					cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 3)
				{
					if (t == 0) cout << "目前没有经理。" << endl;
					else
					{	Man[0].Search_correct(t, Man);
					    cout<<"已完成修改。"<<endl;
						cout << "请输入序号（1-6）: " << endl; 
					} 
				}
				else if (q == 4)
				{
					if (t == 0) cout << "目前没有经理。" << endl;
					else 
					{  Man[0].Search_show(t, Man);
					   cout<<"已完成显示。"<<endl;
						cout << "请输入序号（1-6）: " << endl; 
					} 
				}
				else if(q==5)
				{  if (t == 0) cout << "目前没有经理。" << endl;
				   else 
				   {  Man[0].Search_delete(t, Man);
                      t=t-1;
                      	cout<<"已完成删除。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
				   }
				}
				else if(q==6)
				break;
				else cout<<"请重新输入。"<<endl; 
			}
		}
		else if (p == 3)
		{
			submenu_Technician();
			while (q!=6)
			{   cin >> q;
				if (q == 1)
				{  cout<<"请设置技术人员的单位工资: "; 
					cin >> per_money;
						for (i = 0; i <= n - 1; i++)
						{	Tec[i].set_money_per(per_money);
						    Tec[i].set_money(); 
                        } 
                    cout<<"已完成设置。"<<endl;
                    cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 2)
				{
					Tec[n].Set(Tec[n]);
					Tec[n].set_money_per(per_money);
					Tec[n].set_money();
					n = n + 1;
					cout<<"已完成添加。"<<endl;
					cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 3)
				{
					if (n == 0) cout << "目前没有技术人员。" << endl;
					else
					{	Tec[0].Search_correct(n, Tec);
					    cout<<"已完成修改。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
					} 
				}
				else if (q == 4)
				{
					if (n == 0) cout << "目前没有技术人员。" << endl;
					else 
					{  Tec[0].Search_show(n, Tec);
					   cout<<"已完成显示。"<<endl;
						cout << "请输入序号（1-6）: " << endl; 
				    }
				}
				else if(q==5)
				{   	if (n == 0) cout << "目前没有技术人员。" << endl;
					else 
					{   Tec[0].Search_delete(n, Tec);
					    n=n-1;
					    cout<<"已完成删除。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
					} 
				}
				else if(q==6)
				break;
				else cout<<"请重新输入。"<<endl; 
			}
		}
		else if (p == 4)
		{
			submenu_Salesman();
			while (q!=6)
			{   cin >> q;
				if (q==1)
				{   cout<<"请设置销售人员的销售额率: "; 
					cin >> Rate1;
						for (i = 0; i <= m - 1; i++)
						{	Sal[i].set_rate(Rate1);
						    Sal[i].set_money(); 
                        } 
                    cout<<"已完成设置。"<<endl;
                    cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 2)
				{
					Sal[m].Set(Sal[m]);
					Sal[m].set_rate(Rate1);
					Sal[m].set_money();
					m = m + 1;
					cout<<"已完成添加。"<<endl;
					cout << "请输入序号（1-6）: " << endl;
				}
				else if (q == 3)
				{
					if (m == 0) cout << "目前没有销售人员。" << endl;
					else
					{	Sal[0].Search_correct(m, Sal);
					    cout<<"已完成修改。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
					} 
				}
				else if (q == 4)
				{
					if (m == 0) cout << "目前没有销售人员。" << endl;
					else 
					{  Sal[0].Search_show(m, Sal);
					   cout<<"已完成显示。"<<endl;
					   cout << "请输入序号（1-6）: " << endl; 
					}		   
				}
				else if(q==5)
				{  if (m == 0) cout << "目前没有销售人员。" << endl;
					else 
					{  Sal[0].Search_delete(m, Sal);
					   m=m-1;
					   cout<<"已完成删除。"<<endl;
						cout << "请输入序号（1-6）: " << endl;
					}
				}
				else if(q==6)
				break;
				else cout<<"请重新输入。"<<endl; 
			}
		}
		else if (p == 5)
		{
			submenu_Salemanager();
			while (q!=7)
			{   cin >> q;
				if (q == 1)
				{   cout<<"请设置销售经理的销售额率: "; 
					cin >> Rate2;
						for (i = 0; i <= k - 1; i++)
						{	sal[i].set_rate(Rate2);
						    sal[i].set_money();
						}
                    cout<<"已完成设置。"<<endl;
					cout << "请输入序号（1-7）: " << endl;
				}
				else if (q == 2)
				{   cout<<"请设置销售经理的基本工资: ";
					cin >> Base_money;
						for (i = 0; i <= k - 1; i++)
						{	sal[i].set_base_money(Base_money);
						    sal[i].set_money();
						}
						cout<<"已完成设置。"<<endl;
					cout << "请输入序号（1-7）: " << endl;
				}
				else if (q == 3)
				{
					sal[k].Set(sal[k]);
					sal[k].set_base_money(Base_money);
					sal[k].set_rate(Rate2);
					sal[k].set_money();
					k++;
					cout<<"已完成添加。"<<endl;
					cout << "请输入序号（1-7）: " << endl;
				}
				else if (q == 4)
				{
					if (k == 0) cout << "目前没有销售经理。" << endl;
					else
					{	sal[0].Search_correct(k, sal);
					    cout<<"已完成修改。"<<endl;
						cout << "请输入序号（1-7）: " << endl;
				    }
				}
				else if (q == 5)
				{
					if (k == 0) cout << "目前没有销售经理。" << endl;
					else 
					{  sal[0].Search_show(k, sal);
					   cout<<"已完成显示。"<<endl;
					   cout << "请输入序号（1-7）: " << endl;
					} 
				}
				else if(q==6)
				{  	if (k == 0) cout << "目前没有销售经理。" << endl;
					else 
					{  sal[0].Search_delete(k, sal); 
					   k=k-1;
					   cout<<"已完成修改。"<<endl;
					   cout << "请输入序号（1-7）: " << endl;
					}
				}
				else if(q==7)
				break;
				else cout<<"请重新输入。"<<endl; 
			}
		}
		else if(p==7)
		exit(0);
		else cout<<"请重新输入。"<<endl; 
	}
	return 0;
}

