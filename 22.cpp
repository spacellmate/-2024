1:

#include <iostream>
using namespace std;

void foo(int &n)
{
    if (n > 0)
    {
        cout << n << endl;
        --n;
        foo(n);
    }

}

int main(){

    int num = 8;
    foo(num);

    return 0;
}

2:

//Даны два целых числа A и В (каждое в отдельной строке). Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае
#include <iostream>
using namespace std;

void foo(int &a, int &b)
{
    if (a < b)
    {
        if (a < b)
        {
            cout << a << endl;
            a++;
            foo(a, b);
        }
   
    }
    else if (a > b)
    {
        if (a > b)
        {
            cout << a << endl;
            a--;
            foo(a, b);
        }
    }
    else
    {
        cout << a << endl;
    }
   
}

int main(){

    int a = 15;
    int b = 15;
   
    foo(a, b);

    return 0;
}

3:

#include <iostream>
using namespace std;

int sum = 0;

void foo(int &n)
{

    if (n > 0)
    {
        sum = sum + n%10;
        n = n / 10;
        foo(n);
    }
    else
    {
        cout << sum << endl;
    }
   
}

int main(){
   
    int n_num = 8;
    foo(n_num);

    return 0;
}

4:

#include <iostream>
using namespace std;


void foo(int n, int div) {
    if (n <= 1)
    {
        return;
    }

    if (n % div == 0)
    {
        cout << div << " ";
        foo(n / div, div);
    }
    else
    {
        foo(n, div + 1);
    }
}

int main() {

    int number = 521;

    foo(number, 2);

    return 0;
}


