#include <iostream>
#include <map>
using namespace std;
unsigned long long s[2][100000];
map <unsigned long long, int> mp[2];
int o[2][100000];
bool q;
int z1, z2;
int magic[24], index[24], g[24], tmp[24], h[2], t[2];
void initialize()
{
	int i;
	for (i = 0; i<24; i++)
		cin >> magic[i];
	for (i = 0; i<24; i++)
	{
		if ((magic[i] == 0) || (magic[i] == 3) || (magic[i] == 6) || (magic[i] == 9))
			index[i] = 0;
		if ((magic[i] == 1) || (magic[i] == 8) || (magic[i] == 14) || (magic[i] == 19))
			index[i] = 1;
		if ((magic[i] == 2) || (magic[i] == 4) || (magic[i] == 13) || (magic[i] == 17))
			index[i] = 2;
		if ((magic[i] == 5) || (magic[i] == 10) || (magic[i] == 16) || (magic[i] == 23))
			index[i] = 3;
		if ((magic[i] == 7) || (magic[i] == 11) || (magic[i] == 20) || (magic[i] == 22))
			index[i] = 4;
		if ((magic[i] == 12) || (magic[i] == 15) || (magic[i] == 18) || (magic[i] == 21))
			index[i] = 5;
	}
	q = false;
}
unsigned long long code(int a[])
{
	unsigned long long SUM = 0;
	int i;
	for (i = 0; i<24; i++)
		SUM = SUM * 6 + (unsigned long long)a[i];
	return SUM;
}
void decode(unsigned long long SUM, int a[])
{
	int i;
	for (i = 23; i >= 0; i--)
	{
		a[i] = SUM % 6;
		SUM = SUM / 6;
	}
}
int count(int x)
{
	int SUM = 0;
	for (; x != 0; x /= 10) SUM++;
	return SUM;
}
void F1(int a[])
{
	int tmp;
	tmp = a[0]; a[0] = a[6]; a[6] = a[9]; a[9] = a[3]; a[3] = tmp;
	tmp = a[1]; a[1] = a[7]; a[7] = a[10]; a[10] = a[4]; a[4] = tmp;
	tmp = a[8]; a[8] = a[11]; a[11] = a[5]; a[5] = a[2]; a[2] = tmp;
}
void F2(int a[])
{
	int tmp;
	tmp = a[0]; a[0] = a[9]; a[9] = tmp;
	tmp = a[6]; a[6] = a[3]; a[3] = tmp;
	tmp = a[1]; a[1] = a[10]; a[10] = tmp;
	tmp = a[7]; a[7] = a[4]; a[4] = tmp;
	tmp = a[8]; a[8] = a[5]; a[5] = tmp;
	tmp = a[11]; a[11] = a[2]; a[2] = tmp;
}
void F3(int a[])
{
	int tmp;
	tmp = a[0]; a[0] = a[3]; a[3] = a[9]; a[9] = a[6]; a[6] = tmp;
	tmp = a[1]; a[1] = a[4]; a[4] = a[10]; a[10] = a[7]; a[7] = tmp;
	tmp = a[8]; a[8] = a[2]; a[2] = a[5]; a[5] = a[11]; a[11] = tmp;
}
void R1(int a[])
{
	int tmp;
	tmp = a[5]; a[5] = a[10]; a[10] = a[23]; a[23] = a[16]; a[16] = tmp;
	tmp = a[4]; a[4] = a[9]; a[9] = a[22]; a[22] = a[15]; a[15] = tmp;
	tmp = a[3]; a[3] = a[11]; a[11] = a[21]; a[21] = a[17]; a[17] = tmp;
}
void R2(int a[])
{
	int tmp;
	tmp = a[5]; a[5] = a[23]; a[23] = tmp;
	tmp = a[10]; a[10] = a[16]; a[16] = tmp;
	tmp = a[4]; a[4] = a[22]; a[22] = tmp;
	tmp = a[9]; a[9] = a[15]; a[15] = tmp;
	tmp = a[3]; a[3] = a[21]; a[21] = tmp;
	tmp = a[11]; a[11] = a[17]; a[17] = tmp;
}
void R3(int a[])
{
	int tmp;
	tmp = a[5]; a[5] = a[16]; a[16] = a[23]; a[23] = a[10]; a[10] = tmp;
	tmp = a[4]; a[4] = a[15]; a[15] = a[22]; a[22] = a[9]; a[9] = tmp;
	tmp = a[3]; a[3] = a[17]; a[17] = a[21]; a[21] = a[11]; a[11] = tmp;
}
void U1(int a[])
{
	int tmp;
	tmp = a[2]; a[2] = a[4]; a[4] = a[17]; a[17] = a[13]; a[13] = tmp;
	tmp = a[1]; a[1] = a[3]; a[3] = a[16]; a[16] = a[12]; a[12] = tmp;
	tmp = a[0]; a[0] = a[5]; a[5] = a[15]; a[15] = a[14]; a[14] = tmp;
}
void U2(int a[])
{
	int tmp;
	tmp = a[2]; a[2] = a[17]; a[17] = tmp;
	tmp = a[4]; a[4] = a[13]; a[13] = tmp;
	tmp = a[1]; a[1] = a[16]; a[16] = tmp;
	tmp = a[3]; a[3] = a[12]; a[12] = tmp;
	tmp = a[0]; a[0] = a[15]; a[15] = tmp;
	tmp = a[5]; a[5] = a[14]; a[14] = tmp;
}
void U3(int a[])
{
	int tmp;
	tmp = a[2]; a[2] = a[13]; a[13] = a[17]; a[17] = a[4]; a[4] = tmp;
	tmp = a[1]; a[1] = a[12]; a[12] = a[16]; a[16] = a[3]; a[3] = tmp;
	tmp = a[0]; a[0] = a[14]; a[14] = a[15]; a[15] = a[5]; a[5] = tmp;
}
void Special_print(int a[])
{
	for (int i = 0; i < 24; i++) cout << a[i] << " ";
	cout << endl;
}
void p(int x1, int x2)
{
	int y1 = 0, b[24], y2 = 0, a[24];
	for (; x1 != 0; x1 /= 10) a[++y1] = x1 % 10;
	for (; x2 != 0; x2 /= 10) b[++y2] = x2 % 10;
	cout << y1 + y2 << endl; q = true;
	for (int i = y1; i >= 1; i--)
	{
		if (a[i] == 1) { F1(magic); cout << "F+" << endl; Special_print(magic); }
		if (a[i] == 2) { F2(magic); cout << "F2" << endl; Special_print(magic); }
		if (a[i] == 3) { F3(magic); cout << "F-" << endl; Special_print(magic); }
		if (a[i] == 4) { R1(magic); cout << "R+" << endl; Special_print(magic); }
		if (a[i] == 5) { R2(magic); cout << "R2" << endl; Special_print(magic); }
		if (a[i] == 6) { R3(magic); cout << "R-" << endl; Special_print(magic); }
		if (a[i] == 7) { U1(magic); cout << "U+" << endl; Special_print(magic); }
		if (a[i] == 8) { U2(magic);  cout << "U2" << endl; Special_print(magic); }
		if (a[i] == 9) { U3(magic); cout << "U-" << endl;  Special_print(magic); }
	}
	for (int i = 1; i <= y2; i++)
	{
		if (b[i] == 1) { F3(magic); cout << "F-" << endl; Special_print(magic); }
		if (b[i] == 2) { F2(magic); cout << "F2" << endl; Special_print(magic); }
		if (b[i] == 3) { F1(magic); cout << "F+" << endl; Special_print(magic); }
		if (b[i] == 4) { R3(magic); cout << "R-" << endl; Special_print(magic); }
		if (b[i] == 5) { R2(magic); cout << "R2" << endl; Special_print(magic); }
		if (b[i] == 6) { R1(magic); cout << "R+" << endl; Special_print(magic); }
		if (b[i] == 7) { U3(magic); cout << "U-" << endl; Special_print(magic); }
		if (b[i] == 8) { U2(magic); cout << "U2" << endl; Special_print(magic); }
		if (b[i] == 9) { U1(magic); cout << "U+" << endl; Special_print(magic); }
	}
}
void rotate(int x3, int a[], int x1, int x2)
{
	if (q) return;
	x1 = x1 * 10 + x2;
	unsigned long long  num = code(a);
	if (mp[x3].count(num) != 0)
		return;
	t[x3] = t[x3] + 1;
	s[x3][t[x3]] = num;
	o[x3][t[x3]] = x1;
	mp[x3][num] = t[x3];
	if (mp[1 - x3].count(num))
	{
		if (x3 == 0) p(x1, o[1 - x3][mp[1 - x3][num]]);
		if (x3 == 1) p(o[1 - x3][mp[1 - x3][num]], x1);
	}
}
int main()
{   initialize();
	int i;
	h[0] = 0, t[0] = 1; h[1] = 0, t[1] = 1;
	for (i = 0; i<24; i++)
	{
		if ((i == 0) || (i == 3) || (i == 6) || (i == 9))
			g[i] = 0;
		if ((i == 1) || (i == 8) || (i == 14) || (i == 19))
			g[i] = 1;
		if ((i == 2) || (i == 4) || (i == 13) || (i == 17))
			g[i] = 2;
		if ((i == 5) || (i == 10) || (i == 16) || (i == 23))
			g[i] = 3;
		if ((i == 7) || (i == 11) || (i == 20) || (i == 22))
			g[i] = 4;
		if ((i == 12) || (i == 15) || (i == 18) || (i == 21))
			g[i] = 5;
	}
	s[0][1] = code(index); 
	o[0][1] = 0;
	s[1][1] = code(g); 
	o[1][1] = 0;
	if (s[0][1] == s[1][1]) 
	{ cout << 0 << endl; 
	return 0; }
	mp[0][s[0][1]] = 1; 
	mp[1][s[1][1]] = 1;
	z1=z2 = 0;
	while (!q)
	{
		while ((h[0] < t[0]) && (z1< 6))
		{
			h[0]++;
			unsigned long long  x1 = s[0][h[0]]; 
			int x2 = o[0][h[0]];
			if (count(x2) != z1) 
			{ h[0]=h[0]-1; 
			  z1=z1+1; 
			  break; }
			decode(x1, index);
			for (i = 0; i < 24; i++) 
			tmp[i] = index[i];
			F1(tmp); 
			rotate(0, tmp, x2, 1);
			F1(tmp); 
			rotate(0, tmp, x2, 2);
			F1(tmp); 
			rotate(0, tmp, x2, 3);
			for (int i = 0; i < 24; i++) 
			tmp[i] = index[i];
			R1(tmp); 
			rotate(0, tmp, x2, 4);
			R1(tmp); 
			rotate(0, tmp, x2, 5);
			R1(tmp); 
			rotate(0, tmp, x2, 6);
			for (int i = 0; i < 24; i++) 
			tmp[i] = index[i];
			U1(tmp);
			rotate(0, tmp, x2, 7);
			U1(tmp); 
			rotate(0, tmp, x2, 8);
			U1(tmp); 
			rotate(0, tmp, x2, 9);
		}

		while ((h[1] < t[1]) && (z2 < 6))
		{
			h[1]=h[1]+1;
			unsigned long long  x1 = s[1][h[1]]; 
			int x2 = o[1][h[1]];
			if (count(x2) != z2) 
			{ h[1]=h[1]-1; 
			  z2=z2+1; 
			  break;
			}
			decode(x1, index);
			for (int i = 0; i < 24; i++) 
			tmp[i] = index[i];
			F1(tmp); 
			rotate(1, tmp, x2, 1);
			F1(tmp); 
			rotate(1, tmp, x2, 2);
			F1(tmp); 
			rotate(1, tmp, x2, 3);
			for (int i = 0; i < 24; i++) 
			tmp[i] = index[i];
			R1(tmp); 
			rotate(1, tmp, x2, 4);
			R1(tmp); 
			rotate(1, tmp, x2, 5);
			R1(tmp); 
			rotate(1, tmp, x2, 6);
			for (int i = 0; i < 24; i++) 
			tmp[i] = index[i];
			U1(tmp); 
			rotate(1, tmp, x2, 7);
			U1(tmp); 
			rotate(1, tmp, x2, 8);
			U1(tmp); 
			rotate(1, tmp, x2, 9);
		}
	}
 
	return 0;
}
