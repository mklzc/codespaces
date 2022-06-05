# 题解

## T1

[妖梦拼木棒](https://www.luogu.com.cn/problem/P3799)

真签到。

注意数据范围，暴力枚举求解。

## T2

原题：[TROKUTI](https://www.luogu.com.cn/problem/P7676)

斜率不同的三条线必定会构成一个三角形。
相同斜率归为一类，枚举每一个类，答案每次加上 $cnt[currentK] \times cnt[smallerK] \times cnt[largerK]$

## T3

原题：[SDOI2008 沙拉公主的困惑](https://www.luogu.com.cn/problem/P2155)

字太多了，不想打了。

题意简述：求 $\frac{m!}{n!}\times \phi(m!)$

## T4

原创题。。。

构造组合事件：即用1，2，3，4组成的有偶数个1的n位数。

设为这个n位数为 $x_1,x_2,x_3\dots x_n$,共有 $a_n$ 种情况。

考察首位 $x_1$:

1. $x_1=1$，则后 $n-1$ 位有奇数个1，共 $4^{n-1}-a_{n-1}$ 种情况。

2. $x_1\neq 1$，则后 $n - 1$ 位中有偶数个1共 $3\times a_{n-1}$。

故 $a_n=a_{2n-1}+2^{n-1}$

然后就是高中数学题了。
