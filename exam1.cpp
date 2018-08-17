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
	Employee(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000);//�ɲ����빤�ʣ�Ĭ��ֵΪ3000������Ϊ������Ϣ���������� 
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
	output << "����Ϊ: " << p.name << ",���Ϊ: " << ",ְλΪ: " << p.position<< p.IDnumber  << ",�Ա�Ϊ: " << p.sex
		<< ",����ʱ��: " << p.year << " " << p.month << " " << p.day << ",����Ϊ: " << p.money;
	return output;
}
istream &operator>>(istream &input, Employee &p1)
{
	cout << "�������Ա��Ϣ,������������š��Ա����� (ע: д��1999 03 08����ʽ) : ";
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
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "����������: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p1[i].name == Name1)
			{	cin >> p1[i];
				break;
		    }
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "��������: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p1[i].IDnumber == ID1)
				{	cin >> p1[i];
				    break;
		       }
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Employee::Search_show(int n2, Employee *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "����������: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Employee::Search_delete(int n3,Employee *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "����������: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
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
	Manager(string = "zhonght", string = "100", string = "man", int = 0, int = 0, int = 0, float = 3000, float = 12000);//�辭��Ļ�������Ϊ12000�� 
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
	output << "����Ϊ: " << p.name << ",���Ϊ: " << p.IDnumber << ",ְλΪ: " << p.position << ",�Ա�Ϊ: " << p.sex
		<< ",����ʱ��: " << p.year << " " << p.month << " " << p.day << ",����Ϊ: " << p.accumPay1;
	return output;
}
istream &operator>>(istream &input, Manager &p1)
{
	cout << "�������Ա��Ϣ,������������š��Ա����� (ע: д��1999 03 08����ʽ)�� : ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day;
	p1.position = "Manager";
	return input;
}
void Manager::Search_correct(int n1, Manager *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "����������: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "û�и������ľ���" << endl;
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
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "��������: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "û�иñ�ŵľ���" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Manager::Search_show(int n2, Manager *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "����������: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "û�и������ľ���" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "û�иñ�ŵľ���" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Manager::Search_delete(int n3,Manager *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "����������: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
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
	output << "����Ϊ: " << p.name << ",���Ϊ: " << p.IDnumber << ",ְλΪ: " << p.position << ",�Ա�Ϊ: " << p.sex
		<< ",����ʱ��: " << p.year << " " << p.month << " " << p.day << ",����Ϊ: " << p.accumPay2 ;
	return output;
}
istream &operator>>(istream &input, Technician &p1)
{
	cout << "�������Ա��Ϣ,������������š��Ա����� (ע: д��1999 03 08����ʽ)������ʱ�� : ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day >> p1.hour;
	p1.position = "Technician";
	return input;
}
void Technician::Search_correct(int n1, Technician *p1)
{	int i;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "����������: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "û�и������ļ�����Ա��" << endl;
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
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "��������: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "û�иñ�ŵļ�����Ա��" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					p1[i].set_money();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Technician::Search_show(int n2, Technician *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "����������: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "û�и������ļ�����Ա��" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "û�иñ�ŵļ�����Ա��" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Technician::Search_delete(int n3,Technician *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "����������: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
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
	output << "����Ϊ: " << p.name << ",���Ϊ: " << p.IDnumber << ",ְλΪ: " << p.position << ",�Ա�Ϊ: " << p.sex
		<< ",����ʱ��: " << p.year << " " << p.month << " " << p.day << ",����Ϊ: " << p.accumPay3 ;
	return output;
}
istream &operator>>(istream &input, Salesman &p1)
{
	cout << "�������Ա��Ϣ,������������š��Ա����� (ע: д��1999 03 08����ʽ)�����۶�: ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day >> p1.saleroom;
	p1.position = "Salesman";
	return input;
}
void Salesman::Search_correct(int n1, Salesman *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "����������: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "û�и�������������Ա��" << endl;
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
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "��������: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "û�иñ�ŵ�������Ա��" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					p1[i].set_money();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Salesman::Search_show(int n2, Salesman *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "����������: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "û�и�������������Ա��" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "û�иñ�ŵ�������Ա��" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Salesman::Search_delete(int n3,Salesman *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "����������: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
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
//mΪemployee�Ĺ��ʣ�nΪ����Ĺ̶����ʣ�x,y,z����Salesman������������r,s,t����Salemanage���������� 
{
	Manager(i, j, k, a, b, c, m, n);
	Salesman(i, j, k, a, b, c, m, x, y, z);
}
ostream &operator<<(ostream &output, Salemanager &p)
{
	output << "����Ϊ: " << p.name << ",���Ϊ: " << p.IDnumber << ",ְλΪ: " << p.position << ",�Ա�Ϊ: " << p.sex
		<< ",����ʱ��: " << p.year << " " << p.month << " " << p.day << ",����Ϊ: " << p.accumPay4;
	return output;
}
void Salemanager::set_money()
{
	accumPay4 = base_money + rate2 * saleroom;
}
istream &operator>>(istream &input, Salemanager &p1)
{
	cout << "�������Ա��Ϣ,������������š��Ա����� (ע: д��1999 03 08����ʽ)�����۶�: ";
	input >> p1.name >> p1.IDnumber >> p1.sex >> p1.year >> p1.month >> p1.day>>p1.saleroom;
	p1.position = "Salemanager";
	return input;
}
void Salemanager::Search_correct(int n1, Salemanager *p1)
{
	int i;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name1;
		cout << "����������: ";
		cin >> Name1;
		for (i = 0; i <= n1 - 1; i++)
		{
			if (i == n1 - 1 && p1[i].name != Name1)
				cout << "û�и����������۾���" << endl;
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
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		if (q == 'Y')
		{
			string ID1;
			cout << "��������: ";
			cin >> ID1;
			for (i = 0; i <= n1 - 1; i++)
			{
				if (i == n1 - 1 && p1[n1 - 1].IDnumber != ID1)
					cout << "û�иñ�ŵ����۾���" << endl;
				else if (p1[i].IDnumber == ID1)
				{
					p1[i].Delete();
					cin >> p1[i];
					p1[i].set_money();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Salemanager::Search_show(int n2, Salemanager *p2)
{
	int j;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name2;
		cout << "����������: ";
		cin >> Name2;
		for (j = 0; j <= n2 - 1; j++)
		{
			if (j == n2 - 1 && p2[j].name != Name2)
				cout << "û�и����������۾���" << endl;
			else if (p2[j].name == Name2)
			{
				cout << p2[j] << endl;
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID2;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID2;
			for (j = 0; j <= n2 - 1; j++)
			{
				if (j == n2 - 1 && p2[n2 - 1].IDnumber != ID2)
					cout << "û�иñ�ŵ����۾���" << endl;
				else if (p2[j].IDnumber == ID2)
				{
					cout << p2[j] << endl;
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
	}
}
void Salemanager::Search_delete(int n3,Salemanager *p3)
{   int k;
	char p = 'N', q = 'N';
	cout << "�Ƿ�ʹ���������ҷ���(Y/N): ";
	cin >> p;
	if (p == 'Y')
	{
		string Name3;
		cout << "����������: ";
		cin >> Name3;
		for (k = 0; k <= n3 - 1; k++)
		{
			if (k == n3 - 1 && p3[k].name != Name3)
				cout << "û�и���������ͨԱ����" << endl;
			else if (p3[k].name == Name3)
			{
				p3[k].Delete();
				break;
			}
		}
	}
	else
	{
		cout << "�Ƿ�ʹ�ñ�Ų��ҷ���(Y/N): ";
		cin >> q;
		string ID3;
		if (q == 'Y')
		{
			cout << "��������: ";
			cin >> ID3;
			for (k = 0; k <= n3 - 1; k++)
			{
				if (k == n3 - 1 && p3[n3 - 1].IDnumber != ID3)
					cout << "û�иñ�ŵ���ͨԱ����" << endl;
				else if (p3[k].IDnumber == ID3)
				{
					p3[k].Delete();
					break;
				}
			}
		}
		else cout << "�޷�ͨ������������Ҫ�ĳ�Ա��Ϣ��"<<endl;
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
	cout << setfill(' ') << setw(24) << "xxx��˾���¹���ϵͳ" << endl;
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
	cout << setfill(' ') << setw(17) << "���˵�" << endl;
	cout << setw(19) << "1.����Ա��" << endl;//���������Ϊ�˱�֤Ա��ֻ�ܿ������Լ�ְλ��ͬ���˵���Ϣ�� 
	cout << setw(17) << "2.����" << endl;
	cout << setw(19) << "3.������Ա" << endl;
	cout << setw(19) << "4.������Ա" << endl;
	cout << setw(19) << "5.���۾���" << endl;
	cout << setw(17) << "6.�˳�" << endl;
	cout << setw(23) << "��������ţ�1-6��" << endl;
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
	cout << setfill(' ') << setw(23) << "�Ӳ˵�(��ͨԱ��)" << endl;
	cout << setw(19) << "1.���ù���" << endl;
	cout << setw(19) << "2.�����Ϣ" << endl;
	cout << setw(19) << "3.�޸���Ϣ" << endl;
	cout << setw(19) << "4.��ʾ��Ϣ" << endl;
	cout << setw(19) << "5.ɾ����Ա" << endl;
	cout << setw(20) << "6.�������˵�" << endl;
	cout << setw(23) << "��������ţ�1-5��" << endl;
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
	cout << setfill(' ') << setw(20) << "�Ӳ˵�(����)" << endl;
	cout << setw(21) << "1.���þ�����" << endl;//����Ѿ�������ͨ����������ͬ�� 
	cout << setw(19) << "2.�����Ϣ" << endl;
	cout << setw(19) << "3.�޸���Ϣ" << endl;
	cout << setw(19) << "4.��ʾ��Ϣ" << endl;
	cout << setw(19) << "5.ɾ����Ա" << endl;
	cout << setw(20) << "6.�������˵�" << endl;
	cout << setw(23) << "��������ţ�1-6��" << endl;
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
	cout << setfill(' ') << setw(22) << "�Ӳ˵�(������Ա)" << endl;
	cout << setw(21) << "1.���õ�λ����" << endl;//���Լ�����Ա����money_per�� 
	cout << setw(19) << "2.�����Ϣ" << endl;
	cout << setw(19) << "3.�޸���Ϣ" << endl;
	cout << setw(19) << "4.��ʾ��Ϣ" << endl;
	cout << setw(19) << "5.ɾ����Ա" << endl;
	cout << setw(20) << "6.�������˵�" << endl;
	cout << setw(23) << "��������ţ�1-6��" << endl;
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
	cout << setfill(' ') << setw(22) << "�Ӳ˵�(������Ա)" << endl;
	cout << setw(21) << "1.�������۶���" << endl;//��rate1�� 
	cout << setw(19) << "2.�����Ϣ" << endl;
	cout << setw(19) << "3.�޸���Ϣ" << endl;
	cout << setw(19) << "4.��ʾ��Ϣ" << endl;
	cout << setw(19) << "5.ɾ����Ա" << endl;
	cout << setw(20) << "6.�������˵�" << endl;
	cout << setw(23) << "��������ţ�1-6��" << endl;
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
	cout << setfill(' ') << setw(22) << "�Ӳ˵�(���۾���)" << endl;
	cout << setw(21) << "1.�������۶���" << endl;//��rate2�� 
	cout << setw(21) << "2.���û�������" << endl;//��base_money�� 
	cout << setw(19) << "3.�����Ϣ" << endl;
	cout << setw(19) << "4.�޸���Ϣ" << endl;
	cout << setw(19) << "5.��ʾ��Ϣ" << endl;
	cout << setw(19) << "6.ɾ����Ա" << endl;
	cout << setw(20) << "7.�������˵�" << endl;
	cout << setw(23) << "��������ţ�1-7��" << endl;
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
				{   cout<<"������Ա���Ļ�������: "; 
					cin >> Money;
					{
						for (i = 0; i <= s - 1; i++)
						{
							Emp[i].Set_money(Money);
						}
					}
					cout<<"��ͨԱ����������������ɡ�"<<endl;
					cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 2)
				{   
					Emp[s].Set(Emp[s]);
					Emp[s].Set_money(Money);
					s = s + 1;
					cout<<"�������ӡ�"<<endl;
					cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 3)
				{
					if (s == 0) cout << "Ŀǰû����ͨԱ����" << endl;
					else
					{
						Emp[0].Search_correct(s, Emp);
						cout<<"������޸ġ�"<<endl;
						cout << "��������ţ�1-6��: " << endl; 
					}
				}
				else if (q == 4)
				{
					if (s == 0) cout << "Ŀǰû����ͨԱ����" << endl;
					else
					{	Emp[0].Search_show(s, Emp);
					    cout<<"�������ʾ��"<<endl;
						cout << "��������ţ�1-6��: " << endl; 
					} 
				}
				else if(q==5)
				{  if (s == 0) cout << "Ŀǰû����ͨԱ����" << endl;
					else
					{	Emp[0].Search_delete(s, Emp);
						s=s-1;
						cout<<"�����ɾ����"<<endl;
						cout << "��������ţ�1-6��: " << endl;
					} 
				}
				else if(q==6)
				 break;
				 else cout<<"���������롣"<<endl; 
			}
		}
		else if (p == 2)
		{
			submenu_Manager();
			while (q!=6)
			{   cin >> q;
				if (q == 1)
				{   cout<<"�����뾭����: "; 
					cin >> Money1; 
						for (i = 0; i <= t - 1; i++)
						{
							Man[i].set_money(Money1);
						}
						cout<<"����ɾ��������á�"<<endl;
						cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 2)
				{
					Man[t].Set(Man[t]);
					Man[t].set_money(Money1);
					t = t + 1;
					cout<<"�������ӡ�"<<endl;
					cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 3)
				{
					if (t == 0) cout << "Ŀǰû�о���" << endl;
					else
					{	Man[0].Search_correct(t, Man);
					    cout<<"������޸ġ�"<<endl;
						cout << "��������ţ�1-6��: " << endl; 
					} 
				}
				else if (q == 4)
				{
					if (t == 0) cout << "Ŀǰû�о���" << endl;
					else 
					{  Man[0].Search_show(t, Man);
					   cout<<"�������ʾ��"<<endl;
						cout << "��������ţ�1-6��: " << endl; 
					} 
				}
				else if(q==5)
				{  if (t == 0) cout << "Ŀǰû�о���" << endl;
				   else 
				   {  Man[0].Search_delete(t, Man);
                      t=t-1;
                      	cout<<"�����ɾ����"<<endl;
						cout << "��������ţ�1-6��: " << endl;
				   }
				}
				else if(q==6)
				break;
				else cout<<"���������롣"<<endl; 
			}
		}
		else if (p == 3)
		{
			submenu_Technician();
			while (q!=6)
			{   cin >> q;
				if (q == 1)
				{  cout<<"�����ü�����Ա�ĵ�λ����: "; 
					cin >> per_money;
						for (i = 0; i <= n - 1; i++)
						{	Tec[i].set_money_per(per_money);
						    Tec[i].set_money(); 
                        } 
                    cout<<"��������á�"<<endl;
                    cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 2)
				{
					Tec[n].Set(Tec[n]);
					Tec[n].set_money_per(per_money);
					Tec[n].set_money();
					n = n + 1;
					cout<<"�������ӡ�"<<endl;
					cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 3)
				{
					if (n == 0) cout << "Ŀǰû�м�����Ա��" << endl;
					else
					{	Tec[0].Search_correct(n, Tec);
					    cout<<"������޸ġ�"<<endl;
						cout << "��������ţ�1-6��: " << endl;
					} 
				}
				else if (q == 4)
				{
					if (n == 0) cout << "Ŀǰû�м�����Ա��" << endl;
					else 
					{  Tec[0].Search_show(n, Tec);
					   cout<<"�������ʾ��"<<endl;
						cout << "��������ţ�1-6��: " << endl; 
				    }
				}
				else if(q==5)
				{   	if (n == 0) cout << "Ŀǰû�м�����Ա��" << endl;
					else 
					{   Tec[0].Search_delete(n, Tec);
					    n=n-1;
					    cout<<"�����ɾ����"<<endl;
						cout << "��������ţ�1-6��: " << endl;
					} 
				}
				else if(q==6)
				break;
				else cout<<"���������롣"<<endl; 
			}
		}
		else if (p == 4)
		{
			submenu_Salesman();
			while (q!=6)
			{   cin >> q;
				if (q==1)
				{   cout<<"������������Ա�����۶���: "; 
					cin >> Rate1;
						for (i = 0; i <= m - 1; i++)
						{	Sal[i].set_rate(Rate1);
						    Sal[i].set_money(); 
                        } 
                    cout<<"��������á�"<<endl;
                    cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 2)
				{
					Sal[m].Set(Sal[m]);
					Sal[m].set_rate(Rate1);
					Sal[m].set_money();
					m = m + 1;
					cout<<"�������ӡ�"<<endl;
					cout << "��������ţ�1-6��: " << endl;
				}
				else if (q == 3)
				{
					if (m == 0) cout << "Ŀǰû��������Ա��" << endl;
					else
					{	Sal[0].Search_correct(m, Sal);
					    cout<<"������޸ġ�"<<endl;
						cout << "��������ţ�1-6��: " << endl;
					} 
				}
				else if (q == 4)
				{
					if (m == 0) cout << "Ŀǰû��������Ա��" << endl;
					else 
					{  Sal[0].Search_show(m, Sal);
					   cout<<"�������ʾ��"<<endl;
					   cout << "��������ţ�1-6��: " << endl; 
					}		   
				}
				else if(q==5)
				{  if (m == 0) cout << "Ŀǰû��������Ա��" << endl;
					else 
					{  Sal[0].Search_delete(m, Sal);
					   m=m-1;
					   cout<<"�����ɾ����"<<endl;
						cout << "��������ţ�1-6��: " << endl;
					}
				}
				else if(q==6)
				break;
				else cout<<"���������롣"<<endl; 
			}
		}
		else if (p == 5)
		{
			submenu_Salemanager();
			while (q!=7)
			{   cin >> q;
				if (q == 1)
				{   cout<<"���������۾�������۶���: "; 
					cin >> Rate2;
						for (i = 0; i <= k - 1; i++)
						{	sal[i].set_rate(Rate2);
						    sal[i].set_money();
						}
                    cout<<"��������á�"<<endl;
					cout << "��������ţ�1-7��: " << endl;
				}
				else if (q == 2)
				{   cout<<"���������۾���Ļ�������: ";
					cin >> Base_money;
						for (i = 0; i <= k - 1; i++)
						{	sal[i].set_base_money(Base_money);
						    sal[i].set_money();
						}
						cout<<"��������á�"<<endl;
					cout << "��������ţ�1-7��: " << endl;
				}
				else if (q == 3)
				{
					sal[k].Set(sal[k]);
					sal[k].set_base_money(Base_money);
					sal[k].set_rate(Rate2);
					sal[k].set_money();
					k++;
					cout<<"�������ӡ�"<<endl;
					cout << "��������ţ�1-7��: " << endl;
				}
				else if (q == 4)
				{
					if (k == 0) cout << "Ŀǰû�����۾���" << endl;
					else
					{	sal[0].Search_correct(k, sal);
					    cout<<"������޸ġ�"<<endl;
						cout << "��������ţ�1-7��: " << endl;
				    }
				}
				else if (q == 5)
				{
					if (k == 0) cout << "Ŀǰû�����۾���" << endl;
					else 
					{  sal[0].Search_show(k, sal);
					   cout<<"�������ʾ��"<<endl;
					   cout << "��������ţ�1-7��: " << endl;
					} 
				}
				else if(q==6)
				{  	if (k == 0) cout << "Ŀǰû�����۾���" << endl;
					else 
					{  sal[0].Search_delete(k, sal); 
					   k=k-1;
					   cout<<"������޸ġ�"<<endl;
					   cout << "��������ţ�1-7��: " << endl;
					}
				}
				else if(q==7)
				break;
				else cout<<"���������롣"<<endl; 
			}
		}
		else if(p==7)
		exit(0);
		else cout<<"���������롣"<<endl; 
	}
	return 0;
}

