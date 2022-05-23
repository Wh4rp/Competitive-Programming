# Competitive-Programming

Repository where I upload everyting related to CP that I'm doing. 

## [Template I use](/Copy%20Paste/Template.cpp)
```cpp
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_(i, k, n) for (int i = k; i < n; ++i)
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  
  // Solution Here
  
  return 0;
}
```

## [Script to compile and run c++](/Copy%20Paste/CP.sh)

If you want run `HelloWorld.cpp` is such to done 
```bash
CP HelloWorld.cpp
``` 
Too acepts input and output file
```bash
CP HelloWorld.cpp in.txt out.txt
```
### Options
- `-f`: forces compilation.
- `-d`: uses Input and Output path defined on lines 6 and 7.

```bash
CP -fd HelloWorld.cpp
```
Executable files goes to `cache_path` defined in linea 5. 

Copy script on `.bashrc` or `.zshrc` to run script anywhere 😉.