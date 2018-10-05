# Code Style

本文以 Google 的开源项目 [styleguide](https://github.com/google/styleguide) 为依据，可以使用 Google 的工具 [cpplint](https://github.com/google/styleguide/tree/gh-pages/cpplint) 来格式化自己的代码以符合这些规范。

## 代码缩进与换行

首先来看一份代码：

```C++
#include <stdio.h>

int main()
{ int a,b,c;
for(a=0;a<30;a++)
{
    printf("*");
    
}printf(" ");printf(" ");

for(b=0;b<10;b++)
    printf(" ");
printf("Very good!");
printf(" ");printf(" ");
for(c=0;c<30;c++)
{
    printf("*");
    
}  


 return 0;
}
```

再来看另一份代码：

```C++
#include <stdio.h>

int main()
{
    int a, b, c;
    for(a = 0; a < 30; a++)
    {
        printf("*");   
    }
    printf(" ");
    printf(" ");
    for(b = 0; b < 10; b++)
        printf(" ");
    printf("Very good!");
    printf(" ");
    printf(" ");
    for(c = 0; c < 30; c++)
    {
        printf("*");    
    }  
    return 0;
}
```

两份代码除了缩进与换行之外一模一样，但可读性有着巨大的差距。

Google 的风格指导中建议使用两空格缩进，Go 语言默认使用格式制表符（tab），主流编辑器大多使用四空格缩进。但无论使用什么，都应该遵循共有的标准：

### 不要混用

两空格、四空格、格式制表符缩进都是被允许的，除非你混用它们：

```C++
// 正确
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
// 正确
int main() {
  cout << "Hello World!" << endl;
  return 0;
}
// 错误
int main() {
    cout << "Hello World!" << endl;
  return 0;
}
```

### 一行中只放一条语句

不能出现 `printf("");printf("")` 这种写法，应该每行一句。

当使用 `if` 时，一般要进行换行，除非是极其简短的情况：

```C++
if (x == kFoo) return new Foo();
if (x == kBar) return new Bar();
```

但如果 `if` 有对应的 `else` 分支，则始终应该换行。

### 一行的长度不要超过 80 个字符

有时候会出现一条语句超过 80 个字符的情况，这种时候应该酌情进行拆行：

```C++
// 错误
printf("0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999");
// 正确
printf("0000000001111111111222222222233333333334444444444"
       "55555555556666666666777777777788888888889999999999");

// 错误
string Func(string arg1, string arg2, string arg3, string arg4, string arg5, string arg6, string arg7, string arg8);
// 正确
string Func(string arg1, string arg2, string arg3, string arg4,
            string arg5, string arg6, string arg7, string arg8);
```

### 操作符前后添加一个空格

```C++
// 错误
int a,b,c;
// 正确
int a, b, c;

// 错误
for(int i=0; i<n; i++);
// 正确
for (int i = 0; i < n; i++);

// 错误
dp[i]=dp[i-1]+dp[i-3];
// 正确
dp[i] = dp[i - 1] + dp[i - 3];

// 错误
cout<<"Hello World!"<< endl;
// 正确
cout << "Hello World!" << endl;
```

### 函数返回值的缩进

函数声明时的返回值是否需要独占一行，这个问题的答案是“都可以”：

```C++
// 正确
void Func();
// 正确
void
Func();
```

## 大括号的使用

### 省略大括号

当语句为 `if` 或者 `for`、`while` 且只有一条执行语句时，可以省略大括号：

```C++
if (i < j)
    i++;
else
    j--;

for (; i < j; i++);

while (i < j)
    i++;
```

当语句多于一条时或有 `if`、`else` 的嵌套时，则始终应该加上大括号：

```C++
// 错误，虽然它的结果相同
if (dp[i] < dp[j])
    int t = dp[i],
    dp[i] = dp[j],
    dp[j] = t;
// 正确
if (dp[i] < dp[j]) {
    int t = dp[i];
    dp[i] = dp[j];
    dp[j] = t;
}

// 错误
if (i == j)
    if (i == k)
        j++;
    else
        k++;
else
    i++;
// 正确
if (i == j) {
    if (i == k)
        j++;
    else
        k++;
} else {
    i++;
}
```

注意，如果 `if` 语句有大括号，那么即使 `else` 语句只有一行，也始终应该加上大括号。

### 大括号与换行

关于大括号是否换行的问题，网上一直争论不休，我们认为换行与否都是可以的，但你决不能混用：

```C++
// 正确
while (true) {
    Coding();
}
// 正确
while (true)
{
    Coding();
}

// 正确
if (i == j) {
    ans++;
} else {
    ans--;
}
// 正确
if (i == j)
{
    ans++;
}
else
{
    ans--;
}
// 错误！不要这样用！
if (i == j) {
    ans++;
}
else {
    ans--;
}
```