
//����
//С���ִ���ʦ���������˶�����������ʣ����������˽��������
//
//����������������������ǡ�ð������ֲ�ͬ��ʮ��������s��t��s����0������s�����г��־����������е�t��ǰ�档���磬44444411�Ƕ�������s��4��t��1����41��10000000��5555556Ҳ�ǡ���4444114��44444�����Ƕ�������
//
//��ʱ��ʦ��С���֣�����һ�������������n�����������n������n�ı�������С���������������С���ֽ��������⡣
//
//����������
//�������룬ÿ���������һ��������n(1 �� n �� 99999)
//
//��Ŀ��֤������������������500�飬������n = 0ʱ���������
//���������
//����ÿ��������������������n����������� : ��������𰸲����У�����n������n�ı�������С��������

#include <iostream>
using namespace std;
const int maxn = 10010;   //��ʾ����λ�����ȣ�����Ϊconst�����ɱ�Ĺ̶���С

int a[maxn], b[maxn];

int m, total, s, t, aptotal, apm, aps, apt, k;//������Ҫ�õ��ı�������¼����Ҫ�����С������
int n;
bool ck()//����Ϊbool���͵ĺ��������������Ƿ����n
{
	int p, r;
	if (total > 5)//��֦
		return 1;
	p = s;
	r = t;
	for (int q = 0; q<m; q++)
	{
		p = p * 10 + s;
	}

	for (int q = 0; q < total - m; q++)
		p = p * 10;
	for (int q = 1; q < total - m; q++)
		r = r * 10 + t;
	return p + r>n;
}
int main()
{
	while (cin >> n, n)
	{
		printf("%d: ", n);
		if (n == 1) {
			puts("10");
			continue;
		}

		a[0] = 1;
		b[0] = 1;
		for (int i = 1; i<9999; i++)//��ʼ������

			a[i] = (a[i - 1] * 10 + 1) % n;
		for (int i = 1; i < 999; i++)
			b[i] = b[i - 1] * 10 % n;

		for (total = 1, aps = 0; total < 9999; total++) {
			k = 0;
			if ((n % 10 == 0 || n % 25 == 0) && total> 11)
				k = total - 11;
			for (m = k; m < total; m++)
			for (s = 1; s < 10; s++)
			for (t = 0; t < (n % 10 ? 10 : 1); t++)
			if (t != s && (((long long)a[m]) * b[total - m] * s + a[total - m - 1] * t) % n == 0 && ck() &&
				(!aps || s<aps))
			{
				aptotal = total;
				apm = m;
				aps = s;
				apt = t;
			}
			if (aps)
				break;
		}
		for (int x = 0; x < apm + 1; x++)
			cout << aps;
		for (int x = 0; x < aptotal - apm; x++)
			cout << apt;
		cout << endl;
	}
	return 0;
}