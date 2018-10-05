# Naming Style

关于命名风格，不同的流派有不同的规范，此处介绍的是 [Google 的规范](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/naming/)。

## 通用命名规则

函数命名，变量命名，文件命名要尽可能使用描述性的命名，多几个字符并不会导致你敲代码变慢。正相反，合理的命名可以让编辑器的自动补全功能发挥的更好。再加上对自己的提示效果，优雅而规范的命名绝对是可以提高你 coding 的效率的。

```C++
int price_count_reader;  // 无缩写
int num_errors;          // "num" 是一个常见的写法
```

在 ACM 中，应该少用 `a, b, c, d` 这样无意义的单字符变量命名，可以适当的使用一些常用的缩写，比如：

```C++
int len = str.length();  // 使用 len 来表示长度（length 的缩写）
int num = 0;             // 使用 num 来表示数量（number 的缩写）
int ans = dp[n];         // 使用 ans 来表示结果（answer 的缩写）
int cnt = arr.size();    // 使用 cnt 来表示计数（count 的缩写）
int pos = -1;            // 使用 pos 来表示位置（position 的缩写）
int cur = 0;             // 使用 cur 来表示当前（current 的缩写）
bool err = false;        // 使用 err 来表示错误与否（error 的缩写）
int arr[MAXLINE];        // 使用 arr 来表示数组（array 的缩写）
typedef long long LL;    // 使用 LL 来表示 long long
int dp[MAXLINE];         // 使用 dp 表示动态规划（dynamic planning）的过程数组
```

当然也有一些特例，比如：

```C++
// ACM 中常用 m 与 n 表示输入的组数与数据规模
// 有些古老的题目会使用多组的多组输入，这时可能会使用 t 作为最外层的多组标识
int n, m;

// i(item) 作为循环外层的变量是约定俗成的
for (int i = 0; i < n - 1; i++) {
    // j 作为第二层的循环变量也是约定俗成的，同理，如果有更多层的话，依次命名为 k、l 等
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            // 作为临时的交换变量，t(template) 是一个常用的变量命名
            int t = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = t;
        }
    }
}
```

## 变量命名

有些命名的规范要求在变量上体现其类型，于是就会出现类似 `m_pHeaderNode` 这样的变量命名。在我们的规范中是绝对不能使用这种变量命名的——（非特殊情况下）同一个变量名中不能同时出现大写字母与下划线。

### 普通变量命名

对于普通变量，命名规范为“小写字母加下划线”。不需要在变量命名时体现它的类型。

```C++
// 正确
int answer;
// 正确
int student_number;
// 正确
long long lastlogin;

// 错误
string userName;
// 错误
string NickName;
```

### 类数据成员

类的成员变量的命名基本规范与普通变量相同，但是最后要加一个下划线。

```C++
class TableInfo {
 private:
  string table_name_;  // 正确
  string tablename_;   // 正确
  static Pool<TableInfo>* pool_;  // 正确
};
```

### 结构体变量

虽然在 C++ 中，结构体与类实际上是同一种类型，但是两者在使用时通常代表了不同的意义。结构体一般表示数据的集合，而没有其他的操作。

结构体变量命名规范与普通变量相同，不需要在末尾添加下划线。

```C++
struct UrlTableProperties {
  string name;
  int num_entries;
  static Pool<UrlTableProperties>* pool;
};
```

## 类型命名

对于自己定义的类型（类、结构体、typedef、枚举等），规范是首字母大写，不使用下划线。

```C++
class Node {};
class UserDetail {};
struct DataNode {};
typedef long long LL;
enum UrlErrors {};
```

## 常量命名

这条是可选的规范。如果一个变量使用 `const` 或者在全局范围内始终保持不变，那么这个变量可以以小写的 `k` 开头，后接大写开头的变量名。

```C++
// 正确
const int kDaysInAWeek = 7;
// 正确
const int kMax = 112345;
// 正确，这条是可选的规范，也可以使用普通变量的命名
const bool flag = true;
```

## 函数命名

常规函数使用大小写混合：

```C++
// 正确
void MyExcitingFunction();
// 正确
int MyExcitingMethod();
```

对于首字母缩写的单词, 更倾向于将它们视作一个单词进行首字母大写：

```C++
// 正确
void MyFirstAcmProgram();
// 正确，但不是非常推荐
void MyFirstACMProgram();
```

## 宏定义

上面我们提到，同一个变量名中不能同时出现大写字母与下划线，但是宏定义不是变量名。

宏定义的规范是全大写字母加下划线。

```C++
#define MY_MACRO_THAT_SCARES_SMALL_CHILDREN
#define ROUND(x)
#define PI_ROUNDED 3.0
```