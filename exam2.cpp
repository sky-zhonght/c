#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <fstream>
using namespace std;
class fun
{
public:
	virtual void set_number()=0;
};
class Matrix :virtual public fun
{
protected:
	int row;
	int column;
	float **matrix;
	int re;
public:
	void set_row(int i);
	void set_column(int j);
	void open_matrix();
	virtual void set_number();
	void set_matrix();
	void show_matrix();
	void delete_matrix();
	friend Matrix operator+(Matrix &c1, Matrix &c2);
	friend Matrix operator-(Matrix &c1, Matrix &c2);
	friend Matrix operator*(Matrix &c1, Matrix &c2);
};
void Matrix::set_number()
{  int i;
   cin>>i;
   re=i;
}
void Matrix::set_row(int i)
{
	row = i;
}
void Matrix::set_column(int j)
{
	column = j;
}
void Matrix::open_matrix()
{
	int i, j;
	matrix = (float**)malloc(sizeof(float*)*row);
	for (i = 0; i<row; i++)
		matrix[i] = (float*)malloc(sizeof(float)*column);
	for (i = 0; i<row; i++)
		for (j = 0; j<column; j++)
			matrix[i][j] = 0;
}
void Matrix::set_matrix()
{
	int i, j;
	cout << "请输入该矩阵 (" << row << "行" << column << "列): " << endl;
	for (i = 0; i<row; i++)
		for (j = 0; j<column; j++)
			cin >> matrix[i][j];
}
void Matrix::delete_matrix()
{
	int i;
	for (i = 0; i<row; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}
void Matrix::show_matrix()
{
	if (re == 1)
	{
		int i, j;
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<column; j++)
			{
				for (j = 0; j<column; j++)
				{
					if ((matrix[i][j]<0 && matrix[i][j]>-10) || (matrix[i][j] >= 10 && matrix[i][j]<100))
						cout << fixed << setprecision(4) << matrix[i][j] << "      ";
					else if (matrix[i][j] >= 0 && matrix[i][j]<10)
						cout << fixed << setprecision(4) << matrix[i][j] << "       ";
					else if (matrix[i][j]<1000 && matrix[i][j] >= 100)
						cout << fixed << setprecision(4) << matrix[i][j] << "      ";
					else
						cout << fixed << setprecision(4) << matrix[i][j] << "      ";//其余数字过大，不再做处理 
				}
				cout << endl;
			}
		}
	}
}
Matrix operator+(Matrix &c1, Matrix &c2)//默认所有异常情况返回0。不对返回0值的矩阵做任何处理。 
{
	Matrix c3;
	c3.re = 1;
	string a = "Y";
	int i, j;
	if (c1.row != c2.row&&c1.column != c2.column)
	{
		cout << "这两个矩阵的行列均不相等，不能相加。" << endl;
		c3.re = 0;
	}
	else if (c1.row == c2.row&&c1.column != c2.column)
	{
		cout << "这两个矩阵列数不同，确定要相加吗？(Y/N): ";//这里默认存到列数较大的矩阵之中。 
		while (a == "Y" || a == "N")
		{
			cin >> a;
			if (a == "Y")
			{
				if (c1.column<c2.column)
				{
					c3.set_row(c1.row);
					c3.set_column(c2.column);
					c3.open_matrix();
					for (i = 0; i<c1.row; i++)
						for (j = 0; j<c2.column; j++)
						{
							if (j<c1.column)
								c3.matrix[i][j] = c1.matrix[i][j] + c2.matrix[i][j];
							else c3.matrix[i][j] = c2.matrix[i][j];
						}
				}
				else
				{
					c3.set_row(c1.row);
					c3.set_column(c1.column);
					c3.open_matrix();
					for (i = 0; i<c1.row; i++)
						for (j = 0; j<c1.column; j++)
						{
							if (j<c2.column)
								c3.matrix[i][j] = c1.matrix[i][j] + c2.matrix[i][j];
							else c3.matrix[i][j] = c1.matrix[i][j];
						}
				}
				break;
			}
			else if (a == "N")
			{
				c3.re = 0;	break;
			}
			else  cout << "请重新输入。" << endl;
		}
	}
	else if (c1.row != c2.row&&c1.column == c2.column)
	{
		cout << "这两个矩阵行数不同，确定要相加吗？(Y/N): ";//这里默认存到行数较大的矩阵之中。 
		while (a == "Y" || a == "N")
		{
			cin >> a;
			if (a == "Y")
			{
				if (c1.row<c2.row)
				{
					c3.set_row(c2.row);
					c3.set_column(c1.column);
					c3.open_matrix();
					for (j = 0; j<c1.column; j++)
						for (i = 0; i<c2.row; i++)
						{
							if (i<c1.row)
								c3.matrix[i][j] = c1.matrix[i][j] + c2.matrix[i][j];
							else
								c3.matrix[i][j] = c2.matrix[i][j];
						}
				}
				else
				{
					c3.set_row(c1.row);
					c3.set_column(c1.column);
					c3.open_matrix();
					for (j = 0; j<c1.column; j++)
						for (i = 0; i<c1.row; i++)
						{
							if (i<c2.row)
								c3.matrix[i][j] = c1.matrix[i][j] + c2.matrix[i][j];
							else
								c3.matrix[i][j] = c1.matrix[i][j];
						}
				}
				break;
			}
			else if (a == "N")
			{
				c3.re = 0;	break;
			}
			else  cout << "请重新输入。" << endl;
		}
	}
	else
	{
		c3.set_row(c1.row);
		c3.set_column(c1.column);
		c3.open_matrix();
		for (i = 0; i<c1.row; i++)
			for (j = 0; j<c1.column; j++)
				c3.matrix[i][j] = c1.matrix[i][j] + c2.matrix[i][j];
	}
	return c3;
	c3.delete_matrix();
}
Matrix operator-(Matrix &c1, Matrix &c2)//这里认为矩阵c1为被减矩阵,同样异常情况返回0值。 
{
	Matrix c3;
	c3.re = 1;
	string a = "Y";
	int i, j;
	if (c1.row != c2.row&&c1.column != c2.column)
	{
		cout << "这两个矩阵行列均不相等，无法相减。" << endl;
		c3.re = 0;
	}
	else if (c1.row == c2.row&&c1.column != c2.column)
	{
		cout << "这两个矩阵列数不同，确定要相减吗？(Y/N): ";//这里默认存到列数较大的矩阵之中。 
		while (a == "Y" || a == "N")
		{
			cin >> a;
			if (a == "Y")
			{
				if (c1.column<c2.column)
				{
					c3.set_row(c1.row);
					c3.set_column(c2.column);
					c3.open_matrix();
					for (i = 0; i<c1.row; i++)
						for (j = 0; j<c2.column; j++)
						{
							if (j<c1.column)
								c3.matrix[i][j] = c1.matrix[i][j] - c2.matrix[i][j];
							else c3.matrix[i][j] = -c2.matrix[i][j];
						}
				}
				else
				{
					c3.set_row(c1.row);
					c3.set_column(c1.column);
					c3.open_matrix();
					for (i = 0; i<c1.row; i++)
						for (j = 0; j<c1.column; j++)
						{
							if (j<c2.column)
								c3.matrix[i][j] = c1.matrix[i][j] - c2.matrix[i][j];
							else c3.matrix[i][j] = c1.matrix[i][j];
						}
				}
				break;
			}
			else if (a == "N")
			{
				c3.re = 0;	break;
			}
			else cout << "请重新输入。" << endl;
		}
	}
	else if (c1.row != c2.row&&c1.column == c2.column)
	{
		cout << "这两个矩阵行数不同，确定要相减吗？(Y/N): ";//这里默认存到行数较大的矩阵之中。 
		while (a == "Y" || a == "N")
		{
			cin >> a;
			if (a == "Y")
			{
				if (c1.row<c2.row)
				{
					c3.set_row(c2.row);
					c3.set_column(c1.column);
					c3.open_matrix();
					for (j = 0; j<c1.column; j++)
						for (i = 0; i<c2.row; i++)
						{
							if (i<c1.row)
								c3.matrix[i][j] = c1.matrix[i][j] - c2.matrix[i][j];
							else
								c3.matrix[i][j] = -c2.matrix[i][j];
						}
				}
				else
				{
					c3.set_row(c1.row);
					c3.set_column(c1.column);
					c3.open_matrix();
					for (j = 0; j<c1.column; j++)
						for (i = 0; i<c1.row; i++)
						{
							if (i<c2.row)
								c3.matrix[i][j] = c1.matrix[i][j] - c2.matrix[i][j];
							else
								c3.matrix[i][j] = c1.matrix[i][j];
						}
				}
				break;
			}
			else if (a == "N")
			{
				c3.re = 0;  break;
			}
			else cout << "请重新输入。" << endl;
		}
	}
	else
	{
		c3.set_row(c1.row);
		c3.set_column(c1.column);
		c3.open_matrix();
		for (i = 0; i<c1.row; i++)
			for (j = 0; j<c1.column; j++)
				c3.matrix[i][j] = c1.matrix[i][j] - c2.matrix[i][j];
	}
	return c3;
	c3.delete_matrix();
}
Matrix operator*(Matrix &c1, Matrix &c2)//默认乘为c1*c2。同样，异常情况返回0值。 
{
	Matrix c3;
	c3.re = 1;
	if (c1.column != c2.row)
	{
		cout << "第一个矩阵的列不等于第二个矩阵的行，无法相乘。" << endl;
		c3.re = 0;
	}
	else
	{
		int i, j, k;
		c3.set_row(c1.row);
		c3.set_column(c2.column);
		c3.open_matrix();
		for (i = 0; i<c3.row; i++)
			for (j = 0; j<c3.column; j++)
				for (k = 0; k<c1.column; k++)
					c3.matrix[i][j] = c3.matrix[i][j] + c1.matrix[i][k] * c2.matrix[k][j];
	}
	return c3;
	c3.delete_matrix();
}
class Rank :virtual public Matrix
{
protected:
	int rank;
	float **U;//即assistanct matrix,这样可以保证原来的矩阵不被破坏。 
	float **inv_matrix;
	float **P;
	float **L;
	float *record;
	int transform;
	int re1;//判断行数是否等于列数，如果不等于，就置为0；如果等于0，就置为1。如果为0，就不存在求行列式的过程。 
	int zh1;//判断是否需要开逆矩阵（有些地方不需要开逆矩阵，这样可以节省空间。） 
	int zh2; //判断是否需要执行PLU分解，再2功能中不需要执行，在4功能中需要执行。 
public:
	void set_rank();
	void set_U();
	void set_record();
	void set_inv_matrix();
	void set_re1();
	void delete_inv_matrix();
	void delete_U();
	void delete_record() { free(record); }
	void show_U();
	void show_record();
	void show_rank();
	void open_PL();
	void show_PL();
	void delete_PL();
	void set_zh1(int i) { zh1 = i; }
	void set_zh2(int i) { zh2 = i; }
};
void Rank::open_PL()
{
	int i, j;
	P = (float**)malloc(sizeof(float*)*row);
	L = (float**)malloc(sizeof(float*)*row);
	for (i = 0; i<row; i++)
	{
		P[i] = (float*)malloc(sizeof(float)*row);
		L[i] = (float*)malloc(sizeof(float)*row);
	}
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<row; j++)
		{
			if (i != j)
			{
				P[i][j] = 0;
				L[i][j] = 0;
			}
			else
			{
				P[i][j] = 1;
				L[i][j] = 1;
			}
		}
	}
}
void Rank::show_PL()
{
	int i, j;
	bool x = false;
	for (i = 0; i<row; i++)
		if (P[i][i] == 0)
			x = true;
	if (x == false)
		cout << "LU分解为: " << endl;
	else
	{
		cout << "PLU分解为: " << endl;
		cout << "P为: " << endl;
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<row; j++)
				cout << fixed << setprecision(4) << P[i][j] << "       ";
			cout << endl;
		}
	}
	cout << "L为: " << endl;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<row; j++)
		{
			if ((L[i][j]<0 && L[i][j]>-10) || L[i][j]>10 && L[i][j]<100)
				cout << fixed << setprecision(4) << L[i][j] << "      ";
			else if (L[i][j] >= 0 && L[i][j]<10)
				cout << fixed << setprecision(4) << L[i][j] << "       ";
			else if (L[i][j]<1000 && L[i][j] >= 100)
				cout << fixed << setprecision(4) << L[i][j] << "      ";
			else cout << fixed << setprecision(4) << L[i][j] << "      ";//其余数字过大，不再做处理 
		}
		cout << endl;
	}
}
void Rank::delete_PL()
{
	int i;
	for (i = 0; i<row; i++)
	{
		free(P[i]);
		free(L[i]);
	}
	free(P);
	free(L);
}
void Rank::set_re1()
{
	if (column == row) re1 = 1;
	else re1 = 0;
}
void Rank::show_record()
{
	int i;
	for (i = 0; i<column; i++)
		cout << record[i] << endl;
}
void Rank::show_U()
{
	cout << "U为: " << endl;
	int i, j;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<column; j++)
		{
			if ((U[i][j]<0 && U[i][j]>-10) || (U[i][j] >= 10 && U[i][j]<100))
				cout << fixed << setprecision(4) << U[i][j] << "      ";
			else if (U[i][j] >= 0 && U[i][j]<10)
				cout << fixed << setprecision(4) << U[i][j] << "       ";
			else if (U[i][j]<1000 && U[i][j] >= 100)
				cout << fixed << setprecision(4) << U[i][j] << "      ";
			else
				cout << fixed << setprecision(4) << U[i][j] << "      ";//其余数字过大，不再做处理 
		}
		cout << endl;
	}
}
void Rank::set_record()
{
	record = (float*)malloc(sizeof(float)*column);
	for (int i = 0; i<column; i++)
		record[i] = 1;
}
void Rank::set_inv_matrix()
{
	int i, j;
	inv_matrix = (float**)malloc(sizeof(float*)*row);
	for (i = 0; i<row; i++)
		inv_matrix[i] = (float*)malloc(sizeof(float)*column);
	for (i = 0; i<row; i++)
		for (j = 0; j<column; j++)
		{
			if (i == j) inv_matrix[i][i] = 1;
			else inv_matrix[i][j] = 0;
		}
}
void Rank::set_U()
{
	int i, j;
	U = (float**)malloc(sizeof(float*)*row);
	for (i = 0; i<row; i++)
		U[i] = (float*)malloc(sizeof(float)*column);
	for (i = 0; i<row; i++)
		for (j = 0; j<column; j++)
			U[i][j] = matrix[i][j];
}
void Rank::delete_U()
{
	int i;
	for (i = 0; i<row; i++)
	{
		free(U[i]);
	}
	free(U);
}
void Rank::delete_inv_matrix()
{
	ofstream outfile("inv.txt", ios::trunc);
	outfile.close();
	int i;
	for (i = 0; i<row; i++)
	{
		free(inv_matrix[i]);
	}
	free(inv_matrix);
}
void Rank::show_rank()
{
	cout << "矩阵的秩为: " << rank << endl;
}
void Rank::set_rank()
{
	transform = 1;
	int i, j, k, m, a_i, a_j;
	int s = 0;
	float e, f, *p;
	i = 0;
	if (row >= column)
	{
		for (j = 0; j<column; j++)
		{
			e = U[j - s][j];
			bool zero = false;
			if (e == 0)
			{
				for (i = j - s + 1; i<row; i++)
				{
					if (U[i][j] != 0)
					{
						p = U[i];
						U[i] = U[j - s];
						U[j - s] = p;
						if (zh1 == 1)
						{
							p = inv_matrix[i];
							inv_matrix[i] = inv_matrix[j - s];
							inv_matrix[j - s] = p;
						}
						if (zh2 == 1)
						{
							p = P[i];
							P[i] = P[j - s];
							P[j - s] = p;
						}
						zero = true;
						transform = -1 * transform;
						break;
					}
					else continue;
				}
				if (zero == false)
				{
					record[j] = 0;
					s += 1;
				}
			}
			if (e != 0 || (e == 0 && zero == true))
			{
				i = j;
				for (k = i + 1; k<row; k++)
				{
					if (U[k][j] == 0)
						continue;
					else
					{
						float t;
						t = U[k][j];
						for (m = j; m<column; m++)
						{
							U[k][m] = U[k][m] - (U[j - s][m] * t) / U[j - s][j];
							if (zh1 == 1)
								inv_matrix[k][m] = inv_matrix[k][m] - (inv_matrix[j - s][m] * t) / U[j - s][j];
							if (zh2 == 1)
								L[k][i] = t / U[j - s][j];
						}
					}
				}
			}
		}
		rank = column - s;
	}
	else
	{
		a_i = 0;
		rank = 0;
		for (j = 0; j<column; j++)
		{
			e = U[a_i][j];
			bool zero = false;
			bool zero1 = false;
			a_j = j;
			i = a_i;
			if (e == 0)
			{
				for (i = a_i + 1; i<row; i++)
				{
					if (U[i][j] != 0)
					{
						p = U[i];
						U[i] = U[a_i];
						U[a_i] = p;
						if (zh2 == 1)
						{
							p = P[i];
							P[i] = P[a_i];
							P[a_i] = p;
						}
						zero = true;
						break;
					}
					else continue;
				}
				if (zero == false)
				{
					record[j] = 0;
					for (a_j = j + 1; a_j<column; a_j++)
					{
						if (U[a_i][a_j] != 0)
						{
							zero1 = true;
							break;
						}
						else
						{
							for (i = a_i + 1; i<row; i++)
							{
								f = U[i][a_j];
								if (f != 0)
								{
									p = U[i];
									U[i] = U[a_i];
									U[a_i] = p;
									if (zh2 == 1)
									{
										p = P[i];
										P[i] = P[a_i];
										P[a_i] = p;
									}
									zero1 = true;
									break;
								}
							}
							if (zero1 == true)
								break;
							else record[a_j] = 0;
						}
					}
					j = a_j;
				}
			}
			if (e != 0 || (e == 0 && zero == true) || (e == 0 && zero == false && zero1 == true))
			{
				for (k = a_i + 1; k<row; k++)
				{
					if (U[k][a_j] == 0)  continue;
					else
					{
						float t;
						t = U[k][a_j];
						for (m = a_j; m<column; m++)
						{
							U[k][m] = U[k][m] - (t*U[a_i][m]) / U[a_i][a_j];
							if (zh2 == 1)
								L[k][a_i] = t / U[a_i][a_j];
						}
					}
				}
			}
			a_i = a_i + 1;
			if (a_i == row)
			{
				for (j = a_j + 1; j<column; j++)
					record[j] = 0;
			}
		}
		for (j = 0; j<column; j++)
			if (record[j] == 1)
				rank = rank + 1;
	}
}
class Nullvector :virtual public Rank
{
private:
	float **nullvector;
	int re2;//判断是否需要执行set_nullvector功能。如果rank=column是不需要执行的，因为一定没有非零向量。 
public:
	void open_nullvector();
	void set_nullvector();
	virtual void set_number();
	int get_re2() { return re2; }
	void show_nullvector();
	void delete_nullvector();
};
void Nullvector::set_number()
{
	if (row >= column)
		if (column == rank)  re2 = 0;
		else re2 = 1;
	else re2 = 1;
}
void Nullvector::open_nullvector()
{
	int i, j;
	nullvector = (float**)malloc(sizeof(float*)*(column - rank));
	for (i = 0; i<column - rank; i++)
	{
		nullvector[i] = (float*)malloc(sizeof(float)*column);
		for (j = 0; j<column; j++)
			nullvector[i][j] = 0;
	}
}
void Nullvector::set_nullvector()
{
	int i, j, i1, k;
	int s = 0;
	int e;
	int s2, s1 = 0;
	int *a;
	a = (int*)malloc(sizeof(int)*rank);
	for (i = 0; i < rank - 1; i++)
		a[i] = 0;
	for (i = 0; i<column - rank; i++)
	{
		s2 = rank - 1;
		s = 0;
		for (j = 0; j<column; j++)
		{
			if (record[j] == 0)
			{
				s = s + 1;
				if (s == i + 1)
				{
					nullvector[i][j] = 1;
					e = j;
					break;
				}
				else
					nullvector[i][j] = 0;
			}
		}
		j = 0;
		for (j = 0; j<column; j++)
		{
			if (record[j] == 1)
			{
				a[s1] = j; s1 = s1 + 1;
			}
			else continue;
		}
		for (i1 = rank - 1; i1 >= 0; i1--)
		{
			nullvector[i][a[i1]] = -U[s2][e];
			for (k = rank - 1; k>i1; k--)
				nullvector[i][a[i1]] = nullvector[i][a[i1]] - nullvector[i][a[k]] * U[s2][a[k]];
			nullvector[i][a[i1]] = nullvector[i][a[i1]] / U[s2][a[i1]];
			s2 = s2 - 1;
		}	
	}
}
void Nullvector::show_nullvector()
{   
	ofstream outfile("nullvector.txt",ios::out|ios::app|ios::binary);
	int i, j;
	for (i = 0; i<column - rank; i++)
	{
		cout << "x" << i << "为: ";

		for (j = 0; j<column; j++)
		{
			if ((nullvector[i][j]<0 && nullvector[i][j]>-10) || (nullvector[i][j] >= 10 && nullvector[i][j]<100))
				cout << fixed << setprecision(4) << nullvector[i][j] << "      ";
			else if (nullvector[i][j] >= 0 && nullvector[i][j]<10)
				cout << fixed << setprecision(4) << nullvector[i][j] << "       ";
			else if (nullvector[i][j]<1000 && nullvector[i][j] >= 100)
				cout << fixed << setprecision(4) << nullvector[i][j] << "      ";
			else
				cout << fixed << setprecision(4) << nullvector[i][j] << "      ";//其余数字过大，不再做处理。 
			outfile << nullvector[i][j] << " ";
		}
		outfile<<"\n";
		cout << endl;
	}
	outfile.close();
}
void Nullvector::delete_nullvector()
{
	ofstream outfile("nullvector.txt",ios::trunc);
	outfile.close();
	int i;
	for (i = 0; i<column - rank; i++)
		free(nullvector[i]);
	free(nullvector);
}
class Det :virtual public Rank
{
protected:
	float det;
public:
	void set_det();
	void show_det();
	int get_re1() { return re1; }
};
void Det::set_det()
{
	int i;
	float d = 1;
	for (i = 0; i<row; i++)
		d = d * U[i][i];
	det = transform * d;
}
void Det::show_det()
{
	cout << "行列式为: " << det << endl;
}
class Inv :virtual public Det
{  protected:
   int re3;
public:
	void set_inv();
	void show_inv();
	virtual void set_number();
	int get_re3() { return re3; }
};
void Inv::set_number()
{
	if (abs(det)<pow(10, -4)) re3 = 0;
	else re3 = 1;
}
void Inv::set_inv()
{
	int i, j, k;
	int s = 0;

	for (j = column - 1; j >= 0; j--)
	{
		for (i = j - 1; i >= 0; i--)
		{
			if (U[i][j] == 0)  continue;
			else
			{
				for (k = 0; k<column; k++)
					inv_matrix[i][k] = inv_matrix[i][k] - (U[i][j] / U[j][j])*inv_matrix[j][k];
				U[i][j] = 0;
			}
		}
	}
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<column; j++)
			inv_matrix[i][j] = inv_matrix[i][j] / U[i][i];
		U[i][i] = 1;
	}
}

void Inv::show_inv()
{
	ofstream outfile("inv.txt", ios::app|ios::out | ios::binary);
	cout << "逆矩阵为: " << endl;
	int i, j;
	for (i = 0; i<row; i++)
	{

		for (j = 0; j<column; j++)
		{
			if (inv_matrix[i][j]<0 || inv_matrix[i][j] >= 10 && inv_matrix[i][j]<100)
				cout << fixed << setprecision(4) << inv_matrix[i][j] << "      ";
			else if (inv_matrix[i][j] >= 0 && inv_matrix[i][j]<10)
				cout << fixed << setprecision(4) << inv_matrix[i][j] << "       ";
			else if (inv_matrix[i][j]<1000 && inv_matrix[i][j] >= 100)
				cout << fixed << setprecision(4) << inv_matrix[i][j] << "      ";
			else  cout << fixed << setprecision(4) << inv_matrix[i][j] << "     ";//其余数字过大，不再做处理 
			outfile << inv_matrix[i][j] << " ";
		}
		outfile<<"\n";
		cout << endl;
	}
	outfile.close();
}
class QR :virtual public Det
{
private:
	float **Q;
	float **R;
	int re4;
public:
	void open_QR();
	void set_QR();
	void show_QR();
	void delete_QR();
	float multiply(float *a, float *b, int n);
	virtual void set_number();
	int get_re4()  {return re4;} 
};
void QR::set_number()
{
	if (abs(det)<pow(10, -4)) re4 = 0;
	else re4 = 1;
}
float QR::multiply(float *a, float *b, int n)
{
	float x = 0;
	int i;
	for (i = 0; i<n; i++)
		x = x + a[i] * b[i];
	return x;
}
void QR::open_QR()
{
	int i, j;
	Q = (float**)malloc(sizeof(float*)*row);
	for (i = 0; i<row; i++)
		Q[i] = (float*)malloc(sizeof(float)*column);
	R = (float**)malloc(sizeof(float*)*row);
	for (i = 0; i<row; i++)
	{
		R[i] = (float*)malloc(sizeof(float)*column);
		for (j = 0; j < column; j++)
		{
			if (i == j)  R[i][j] = 1;
			else R[i][j] = 0;
		}
	}
}
void QR::set_QR()
{
	int i, j, k;
	float x, t;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<column; j++)
			Q[i][j] = matrix[j][i];
		for (k = 0; k<i; k++)
		{
			x = multiply(Q[k], Q[i], row) / multiply(Q[k], Q[k], row);
			R[k][i] = x;
			for (j = 0; j<column; j++)
				Q[i][j] = Q[i][j] - x * Q[k][j];
		}
	}
	for (i = 0; i<row; i++)
	{
		x = sqrt(multiply(Q[i], Q[i], row));
		for (j = 0; j<column; j++)
		{
			Q[i][j] = Q[i][j] / x;
			R[i][j] = R[i][j] * x;
		}
	}
	for (i = 1; i<row; i++)
		for (j = 0; j<i; j++)
		{
			t = Q[i][j];
			Q[i][j] = Q[j][i];
			Q[j][i] = t;
		}
}
void QR::show_QR()
{
	int i, j;
	cout << "Q为: " << endl;
	for (i = 0; i<row; i++)
	{

		for (j = 0; j<column; j++)
		{
			if ((Q[i][j]<0 && Q[i][j]>-10) || (Q[i][j] >= 10 && Q[i][j]<100))
				cout << fixed << setprecision(4) << Q[i][j] << "      ";
			else if (Q[i][j] >= 0 && Q[i][j]<10)
				cout << fixed << setprecision(4) << Q[i][j] << "       ";
			else if (Q[i][j]<1000 && Q[i][j] >= 100)
				cout << fixed << setprecision(4) << Q[i][j] << "      ";
			else
				cout << fixed << setprecision(4) << Q[i][j] << "      ";//其余数字过大，不再做处理 
		}
		cout << endl;
	}
	cout << "R为: " << endl;
	for (i = 0; i<row; i++)
	{

		for (j = 0; j<column; j++)
		{
			if ((R[i][j]<0 && R[i][j]>-10) || (R[i][j] >= 10 && R[i][j]<100))
				cout << fixed << setprecision(4) << R[i][j] << "      ";
			else if (R[i][j] >= 0 && R[i][j]<10)
				cout << fixed << setprecision(4) << R[i][j] << "       ";
			else if (R[i][j]<1000 && R[i][j] >= 100)
				cout << fixed << setprecision(4) << R[i][j] << "      ";
			else
				cout << fixed << setprecision(4) << R[i][j] << "      ";//其余数字过大，不再做处理 
		}
		cout << endl;
	}
}
void QR::delete_QR()
{
	int i;
	for (i = 0; i<row; i++)
	{
		free(Q[i]);
		free(R[i]);
	}
	free(Q);
	free(R);
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
	cout << setfill(' ') << setw(19) << "矩阵计算器" << endl;
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
	cout << setw(21) << "1.矩阵的简单运算" << endl;//包括矩阵的加减乘。 
	cout << setw(21) << "2.矩阵的性质运算" << endl;//包括矩阵的秩、行列式、逆矩阵。 
	cout << setw(20) << "3.矩阵的零向量" << endl;
	cout << setw(21) << "4.矩阵的分解运算" << endl;//包括矩阵LU分解和QR分解。 
	cout << setw(17) << "5.退出" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu1()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(18) << "子菜单1" << endl;
	cout << setw(19) << "1.编辑矩阵" << endl;
	cout << setw(19) << "2.矩阵相加" << endl;
	cout << setw(19) << "3.矩阵相减" << endl;
	cout << setw(19) << "4.矩阵相乘" << endl;
	cout << setw(19) << "5.删除矩阵" << endl;
	cout << setw(20) << "6.返回主菜单" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu2()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(18) << "子菜单2" << endl;
	cout << setw(19) << "1.编辑矩阵" << endl;
	cout << setw(19) << "2.矩阵的秩" << endl;
	cout << setw(18) << "3.行列式" << endl;
	cout << setw(19) << "4.矩阵的逆" << endl;
	cout << setw(19) << "5.删除矩阵" << endl;
	cout << setw(20) << "6.返回主菜单" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu3()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(18) << "子菜单3" << endl;
	cout << setw(19) << "1.编辑矩阵" << endl;
	cout << setw(21) << "2.矩阵的零向量" << endl;
	cout << setw(19) << "3.删除矩阵" << endl;
	cout << setw(20) << "4.返回主菜单" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu4()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(18) << "子菜单4" << endl;
	cout << setw(19) << "1.编辑矩阵" << endl;
	cout << setw(18) << "2.LU分解" << endl;
	cout << setw(18) << "3.QR分解" << endl;
	cout << setw(19) << "4.删除矩阵" << endl;
	cout << setw(20) << "5.返回主菜单" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
void submenu1_1()
{
	string a;
	a = " ";
	int i;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
	cout << setfill(' ') << setw(24) << "1.Mat1      2.Mat2 " << endl;
	cout << setfill(' ') << setw(24) << "3.Mat3      4.Mat4 " << endl;
	cout << setw(20) << "5.返回主菜单" << endl;
	for (i = 1; i <= 16; i++)
	{
		cout << setfill('#') << setw(2) << a;
	}
	cout << endl;
}
int main()
{
	string p = "0", q = "0";
	int i, m, n, w;
	int a[4], row1, column1;
	int inv_record = 0, nul_record = 0, qr_record = 0;
	int inv_record1 = 0, nul_record1 = 0, qr_record1 = 0;
	int inv_record2 = 0, inv_record3 = 0;
	Matrix mat[4], mat1;
	Inv inv;
	Nullvector nul;
	QR qr;
	title();
	for (i = 0; i<4; i++)
		a[i] = 0;
	while (q != "5")
	{
		menu();
		cout<<"请输入序号: ";
		cin >> q;
		if (q == "1")
		{   submenu1();
			p = "0";
			while (p != "6")
			{	cout<<"请输入序号: ";
		    	cin >> p;
			    if (p == "1")
				{   submenu1_1();
					w = 0;
					while (w != 5)
					{	cout<<"请输入序号: " ;
					    cin >> w;
					    if (w<1 || w>5)
							cout << "请重新输入。" << endl;
						else if (w != 5)
						{
							i = w - 1;
							cout << "请输入矩阵的行数: ";
							cin >> row1;
							mat[i].set_row(row1);
							cout << "请输入矩阵的列数: ";
							cin >> column1;
							mat[i].set_column(column1);
							mat[i].open_matrix();
							mat[i].set_matrix();
							a[i] = 1;
							cout << "已完成对矩阵" << w << "的编辑" << endl;
						}
						else 
						{  submenu1();
						   break;
						}
					}
				}
				else if (p == "2")
				{
					cout << "请输入你需要相加的矩阵的序号: ";
					cin >> m >> n;
					if (m>4 || m<1 || n>4 || n<1)
						cout << "矩阵不存在，无法相加。" << endl;
					else
					{
						if (a[m - 1] == 0)
							cout << "未定义第一个矩阵，无法相加。" << endl;
						else if (a[n - 1] == 0)
							cout << "未定义第二个矩阵，无法相加。" << endl;
						else
						{
							mat1 = mat[m - 1] + mat[n - 1];
							cout << "Mat" << m << "+Mat" << n << "=: " << endl;
							mat1.show_matrix();
						}
					}
				}
				else if (p == "3")//注意，第一个为被减的矩阵 
				{
					cout << "请输入你需要相减的矩阵的序号: ";
					cin >> m >> n;
					if (m>4 || m<1 || n>4 || n<1)
						cout << "矩阵不存在，无法相减。" << endl;
					else
					{
						if (a[m - 1] == 0)
							cout << "未定义第一个矩阵，无法相减。" << endl;
						else if (a[n - 1] == 0)
							cout << "未定义第二个矩阵，无法相减。" << endl;
						else
						{
							mat1 = mat[m - 1] - mat[n - 1];
							cout << "Mat" << m << "-Mat" << n << "=: " << endl;
							mat1.show_matrix();
						}
					}
				}
				else if (p == "4")
				{
					cout << "请输入你需要相乘的矩阵的序号: ";
					cin >> m >> n;
					if (m>4 || m<1 || n>4 || n<1)
						cout << "矩阵不存在，无法相乘。" << endl;
					else
					{
						if (a[m - 1] == 0)
							cout << "未定义第一个矩阵，无法相乘。" << endl;
						else if (a[n - 1] == 0)
							cout << "未定义第二个矩阵，无法相乘。" << endl;
						else
						{
							mat1 = mat[m - 1] * mat[n - 1];
							cout << "Mat" << m << "*Mat" << n << "=: " << endl;
							mat1.show_matrix();
						}
					}
				}
				else if (p == "5")
				{   submenu1_1();
					w = 0;
					while (w != 5)
					{
						cout << "请输入你要删除的矩阵的序号: ";
						cin >> w;
						if (w<1 || w>5)
							cout << "请重新输入。" << endl;
						else if (w != 5)
						{
							if (a[w - 1] == 0)  cout << "矩阵" << w << "未定义，不能删除。" << endl;
							else
							{
								mat[w - 1].delete_matrix();
								a[i] = 0;
								cout << "已完成对矩阵" << w << "的删除" << endl;
							}
						}
						else break;
					}
				}
				else if (p == "6")   break;
				else cout << "请重新输入。" << endl;
			}
		}
		else if (q == "2")
		{
			inv.set_zh1(1);
			inv.set_zh2(0);
			p = "0";
			submenu2();
			while (p != "6")
			{	cout<<"请输入序号: ";
			    cin >> p;
			    if (p == "1")
				{
					if (inv_record == 1) cout << "请先删除矩阵再重新定义矩阵。" << endl;
					else
					{
						cout << "请输入矩阵的行数: ";
						cin >> row1;
						inv.set_row(row1);
						cout << "请输入矩阵的列数: ";
						cin >> column1;
						inv.set_column(column1);
						inv.open_matrix();
						inv.set_matrix();
						inv_record = 1;
						cout << "矩阵已完成编辑。" << endl;
					}
				}
				else if (p == "2")
				{
					if (inv_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						if (inv_record1 == 0)
						{
							inv.set_U();
							inv.set_inv_matrix();
							inv.set_record();
							inv.set_rank();
							inv.show_rank();
							inv_record1 = 1;
						}
						else inv.show_rank();
					}
				}
				else if (p == "3")
				{
					if (inv_record == 0)  cout << "矩阵未定义，不能操作." << endl;
					else
					{
						if (inv_record1 == 0)
						{
							inv.set_re1();
							if (inv.get_re1() == 0)
								cout << "矩阵行列不相等，不能求行列式。" << endl;
							else
							{
								inv.set_U();
								inv.set_inv_matrix();
								inv.set_record();
								inv.set_rank();
								inv.set_det();
								inv.show_det();
								inv_record1 = 1;
								inv_record2 = 1;
							}
						}
						else if (inv_record1 == 1 && inv_record2 == 0)
						{
							inv.set_re1();
							if (inv.get_re1() == 0)
								cout << "矩阵行列不相等，不能求行列式。" << endl;
							else
							{
								inv.set_det();
								inv.show_det();
								inv_record2 = 1;
							}
						}
						else   inv.show_det();
					}
				}
				else if (p == "4")
				{
					if (inv_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						if (inv_record1 == 0)
						{
							inv.set_re1();
							if (inv.get_re1() == 0)  cout << "矩阵行列不相等，不能求逆矩阵。" << endl;
							else
							{
								inv.set_U();
								inv.set_inv_matrix();
								inv.set_record();
								inv.set_rank();
								inv.set_det();
								inv.set_number();
								if (inv.get_re3() == 0)
									cout << "矩阵行列式为0，不能求逆。" << endl;
								else
								{
									inv.set_inv();
									inv.show_inv();
									inv_record1 = 1;
									inv_record2 = 1;
									inv_record3 = 1;
								}
							}
						}
						else
						{
							inv.set_re1();
							if (inv.get_re1() == 0)  cout << "矩阵行列不相等，不能求逆矩阵。" << endl;
							else
							{
								inv.set_det();
								if (inv_record2 == 0)
								{
									inv.set_number();
									if (inv.get_re3() == 0)
										cout << "矩阵行列式为0，不能求逆。" << endl;
									else
									{
										inv.set_inv();
										inv.show_inv();
										inv_record2 = 1;
										inv_record3 = 1;
									}
								}
								else
								{
									inv.set_number();
									if (inv.get_re3() == 0)
										cout << "矩阵行列式为0，不能求逆。" << endl;
									else
									{
										if (inv_record3 == 0)
										{
											inv.set_inv();
											inv.show_inv();
											inv_record3 = 1;
										}
										else  inv.show_inv();
									}
								}
							}
						}
					}
				}
				else if (p == "5")
				{
					if (inv_record == 0) cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						inv.delete_matrix();
						if (inv_record1 == 1)
						{
							inv.delete_U();
							inv.delete_inv_matrix();
							inv.delete_record();
						}
						inv_record = 0;
						inv_record1 = 0;
						inv_record2 = 0;
						inv_record3 = 0;
						cout << "已完成矩阵的删除。" << endl;
					}
				}
				else if (p == "6")  break;
				else cout << "请重新输入。" << endl;
			}
		}
		else if (q == "3")
		{
			p = "0";
			nul.set_zh1(0);
			nul.set_zh2(0);
			submenu3();
			while (p != "4")
			{   cout<<"请输入序号: " ;
				cin >> p;
				if (p == "1")
				{
					if (nul_record == 1) cout << "请先删除矩阵再重新定义矩阵。" << endl;
					else
					{
						cout << "请输入矩阵的行数: ";
						cin >> row1;
						nul.set_row(row1);
						cout << "请输入矩阵的列数: ";
						cin >> column1;
						nul.set_column(column1);
						nul.open_matrix();
						nul.set_matrix();
						nul_record = 1;
						nul.set_U();
						nul.set_record();
						cout << "矩阵已完成编辑。" << endl;
					}
				}
				else if (p == "2")
				{
					if (nul_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						nul.set_rank();
						nul.set_number();
						if (nul.get_re2() == 0) cout << "该矩阵无非零向量。" << endl;
						else
						{
							if (nul_record1 == 0)
							{
								nul.open_nullvector();
								nul.set_nullvector();
								nul.show_nullvector();
								nul_record1 = 1;
							}
							else  nul.show_nullvector();
						}
					}
				}
				else if (p == "3")
				{
					if (nul_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						nul.delete_matrix();
						nul.delete_U();
						nul.delete_record();
						if (nul_record1 == 1)
							nul.delete_nullvector();
						nul_record = 0;
						nul_record1 = 0;
						cout << "已完成矩阵的删除。" << endl;
					}
				}
				else if (p == "4") break;
				else cout << "请重新输入。" << endl;
			}
		}
		else if (q == "4")
		{
			p = "0";
			qr.set_zh1(0);
			qr.set_zh2(1);
			submenu4();
			while (p != "5")
			{	cout<<"请输入序号: " ;
				cin >> p;
				if (p == "1")
				{
					if (qr_record == 1)  cout << "请先删除矩阵再重新定义矩阵。" << endl;
					else
					{
						cout << "请输入矩阵的行数: ";
						cin >> row1;
						qr.set_row(row1);
						cout << "请输入矩阵的列数: ";
						cin >> column1;
						qr.set_column(column1);
						qr.open_matrix();
						qr.set_matrix();
						qr.open_PL();
						qr.set_U();
						qr.set_record();
						qr_record = 1;
						cout << "矩阵已完成编辑。" << endl;
					}
				}
				else if (p == "2")
				{
					if (qr_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						qr.set_rank();
						qr.show_PL();
						qr.show_U();
					}
				}
				else if (p == "3")
				{
					if (qr_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						qr.set_re1();
						if (qr.get_re1() == 0)  cout << "矩阵的行列不相等，不能进行QR分解。" << endl;
						else
						{
							qr.set_rank();
							qr.set_det();
							qr.set_number();
							if (qr.get_re4() == 0)  cout << "矩阵的行列式为0，不能进行QR分解。" << endl;
							else
							{
								if (qr_record1 == 0)
								{
									qr.open_QR();
									qr.set_QR();
									qr.show_QR();
									qr_record1 = 1;
								}
								else  qr.show_QR();
							}
						}
					}
				}
				else if (p == "4")
				{
					if (qr_record == 0)  cout << "矩阵未定义，不能操作。" << endl;
					else
					{
						qr.delete_U();
						qr.delete_matrix();
						qr.delete_PL();
						qr.delete_record();
						if (qr_record1 == 1)
							qr.delete_QR();
						qr_record1 = 0;
						qr_record = 0;
						cout << "已完成矩阵的删除。" << endl;
					}
				}
				else if (p == "5")  break;
				else cout << "请重新输入。" << endl;
			}
		}
		else if (q == "5")  break;
		else cout << "请重新输入。" << endl;
	}
	system("pause");
	return 0;
}
