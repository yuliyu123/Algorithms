using namespace std;

int myAtoi(string str)
{
    int i = 0;
    int ans = 0;
    int sigh = 1;

    for (; i < str.length() && str[i] == ' ';) {
        ++i;
    }

    if (str[i] == '-')
    {
        sigh = -1;
        ++i;
    }

    if (str[i] == '+')
    {
        ++i;
    }

    for (; i < str.length() && str[i] >= '0' && str[i] <= '9'; ) {
        int no = str[i] - '0';
        // ans*10 > INT_MAX - no这里必须这么写，因为ans*10 + no可能会整数overflow!!!
        if ((ans > INT_MAX/10) || (ans*10 > INT_MAX - no)) // 进位操作，ans * 10 + no 或者 ans * 10 > INT_MAX直接返回，no可能为0
            return sigh == 1 ? INT_MAX : INT_MIN;

        ans = ans * 10 + no;
        ++i;
    }

    return ans * sigh;
}

int main(void)
{
    cout << atoi("   -8xxx") << endl;
    cout << myAtoi("   -8xxx") << endl;
    cout << myAtoi("+42") << endl;
    cout << myAtoi("2") << endl;
    assert(myAtoi("+-2") == 0);
    return 0;
}
