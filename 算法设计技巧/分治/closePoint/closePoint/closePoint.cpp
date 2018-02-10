// closePoint.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<math.h>
#include<Windows.h>
#define infine 10000
#define min(x,y)((x)>(y)?(y):(x))
#define N 6
typedef struct Point
{
	int x;
	int y;
}point;
point *set[N];
point *setX[N];
point *setY[N];
void init()
{
	point *p0 = new point();
	p0->x = 0;
	p0->y = 0;
	set[0] = p0;

	point *p1 = new point();
	p1->x = 0;
	p1->y = 2;
	set[1] = p1;

	point *p2 = new point();
	p2->x = 1;
	p2->y = 1;
	set[2] = p2;

	point *p3 = new point();
	p3->x = 2;
	p3->y = 1;
	set[3] = p3;

	point *p4 = new point();
	p4->x = 3;
	p4->y = 0;
	set[4] = p4;

	point *p5 = new point();
	p5->x = 4;
	p5->y = 1;
	set[5] = p5;
}
void sortByX()
{
	for (int i = 0; i < N; i++)
		setX[i] = set[i];

	int temp;
	int flag;
	point *tp;

	for (int i = 0; i < N; i++)
	{
		temp = setX[i]->x;
		flag = i;
		for (int j = i + 1; j < N; j++)
		{
			if ((setX[j]->x) < temp)
			{
				temp = setX[j]->x;
				flag = j;
			}
		}
		//change
		if (flag != i)
		{
			tp = setX[flag];
			setX[flag] = setX[i];
			setX[i] = tp;
		}
	}
}

void sortByY()
{
	for (int i = 0; i < N; i++)
		setY[i] = set[i];

	int temp;
	int flag;
	point *tp;

	for (int i = 0; i < N; i++)
	{
		temp = setY[i]->y;
		flag = i;
		for (int j = i + 1; j < N; j++)
		{
			if ((setY[j]->y) < temp)
			{
				temp = setY[j]->y;
				flag = j;
			}
		}
		//change
		if (flag != i)
		{
			tp = setY[flag];
			setY[flag] = setY[i];
			setY[i] = tp;
		}
	}
}
float calcul(point *p, point *t)
{
	float dis2 = (p->x - t->x)*(p->x - t->x) + (p->y - t->y)*(p->y - t->y);
	float dis = sqrt(dis2);
	return dis;
}
float combine(point *ql[],int yl,point *qr[],int yr,float delta,int xmid)
{
	point *left[100];
	point *right[100];
	int l=0;
	int r=0;
	for (int i = 0; i < yl; i++)
	{
		if (ql[i]->x<xmid - delta || ql[i]->x>xmid + delta)
		{
			continue;
		}
		else
		{
			left[l++] = ql[i];
		}
	}

	for (int i = 0; i < yr; i++)
	{
		if (qr[i]->x<xmid - delta || qr[i]->x>xmid + delta)
		{
			continue;
		}
		else
		{
			right[r++] = qr[i];
		}
	}
	int t = 0;
	for (int i = 0; i < l; i++)
	{
		while (right[t]->y < left[i]->y&&t < r)
		{
			t++;
		}
		for (int j = max(0, t - 3); j <= min(r-1, t + 3); j++)
		{
			if (calcul(left[i], right[j]) < delta)
			{
				delta = calcul(left[i], right[j]);
			}
		}
	}
	return delta;
}
float findClose(point *P[],int xlen,point *Q[],int ylen,float delta)
{
	float dis;
	if (xlen == 1)
	{
		delta = infine;
		return delta;
	}
	else if (xlen == 2)
	{
		delta = calcul(P[0], P[1]);
		return delta;
	}
	else
	{
		int xmid = xlen / 2;
		point *pl[100];
		point *pr[100];
		point *ql[100];
		point *qr[100];
		int xl = 0, xr = 0, yl = 0, yr = 0;
		for (int i = 0; i < xlen; i++)
		{
			if (i <= xmid)
			{
				pl[xl++] = P[i];
			}
			else
			{
				pr[xr++] = P[i];
			}
		}
		for (int i = 0; i < ylen; i++)
		{
			if (Q[i]->x <= P[xmid]->x)
			{
				ql[yl++] = Q[i];
			}
			else
			{
				qr[yr++] = Q[i];
			}
		}
		float left = findClose(pl, xl, ql, yl, delta);
		float right = findClose(pr, xr, qr, yr, delta);
		delta = min(left, right);
		float mid = combine(ql, yl, qr, yr, delta, P[xmid]->x);
		if (mid < delta);
		return mid;
		return delta;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	sortByX();
	sortByY();
	float close = findClose(setX,5, setY,5, infine);
	printf("%lf", close);
	system("pause");
	return 0;
}

