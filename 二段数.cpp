
//描述
//小乐乐从老师口中听到了二段数这个名词，想更深入的了解二段数。
//
//二段数是这样的正整数：恰好包含两种不同的十进制数字s和t，s不是0，并且s的所有出现均排列在所有的t的前面。例如，44444411是二段数（s是4，t是1），41、10000000和5555556也是。但4444114和44444都不是二段数。
//
//这时老师问小乐乐：给你一个任意的正整数n，你能求出比n大并且是n的倍数的最小二段数吗？请你帮助小乐乐解答这个问题。
//
//输入描述：
//多组输入，每组输入包含一个正整数n(1 ≤ n ≤ 99999)
//
//题目保证测试数据总数不超过500组，当输入n = 0时程序结束。
//输出描述：
//对于每组测试用例，输出正整数n，后面紧跟“ : ”，输出答案并换行，即比n大且是n的倍数的最小二段数。

#include <iostream>
using namespace std;
const int maxn = 10010;   //表示最大的位数长度，定义为const，不可变的固定大小

int a[maxn], b[maxn];

int m, total, s, t, aptotal, apm, aps, apt, k;//先声明要用到的变量，记录符合要求的最小二段数
int n;
bool ck()//返回为bool类型的函数，检测二段数是否大于n
{
	int p, r;
	if (total > 5)//剪枝
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
		for (int i = 1; i<9999; i++)//初始化数组

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