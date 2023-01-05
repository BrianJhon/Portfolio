#include <iostream>

using namespace std;

class HT
{
    public:
        HT();
        int Hash(int);
        int Add(int);
        int Find(int);

    private:
        int index[27];

};

HT::HT()
{
    for(int i = 0; i < 27; i++)
    {
        index[i] = -2; // -2 represents empty index
    }
}

int HT::Hash(int value)
{
    return value % 27;
}

int HT::Add(int value)
{
    if(value == -1)
    {
        return -11;
    }
    int mod;
    mod = Hash(value); //Holds the index for Value
    if(index[mod] == -2)
    {
        index[mod] = value;
        return mod;
    }
    //insert value into next index if index has value
    else          
    {
        for(int j = 0; j < 26; j++)
        {
            mod++;
            if(index[mod] == -2)
            {
                index[mod] = value;
                return mod;
            }
            else if(mod == 26)   //wrap around
            {
                mod = -1;
            }
        }
        return -1;
    }
}

int HT::Find(int value)
{
    if(value == -1)
    {
        return -11;
    }
    for(int i = 0; i < 27; i++)
    {
        if(value == index[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    HT myHT;
    int num;
    int result;
    do
    {
        cout << "\nEnter an Integer, enter -1 to exit: ";
        cin >> num;
        result = myHT.Add(num);
        if(result == -1)
        {
            cout << "Array is full." << endl;
            break;
        }
        if(result == -11)
        {
            break;
        }
        else
        {
            cout << "Value entered into index: " << result << endl;
        }

    } while (true);

    do
    {
        cout << "\nEnter a Value, enter -1 to exit: ";
        cin >> num;
        result = myHT.Find(num);
        if(result == -11)
        {
            break;
        }
        if(result == -1)
        {
            cout << "Value not found." << endl;
        }
        else
        {
            cout << "Value found at index: " << result << endl;
        }
    } while (true);
    


    return 0;
    

}
/*
Enter an Integer, enter -1 to exit: 17
Value entered into index: 17

Enter an Integer, enter -1 to exit: 12
Value entered into index: 12

Enter an Integer, enter -1 to exit: 5
Value entered into index: 5

Enter an Integer, enter -1 to exit: 27
Value entered into index: 0

Enter an Integer, enter -1 to exit: 26
Value entered into index: 26

Enter an Integer, enter -1 to exit: 81
Value entered into index: 1

Enter an Integer, enter -1 to exit: 55
Value entered into index: 2

Enter an Integer, enter -1 to exit: 34
Value entered into index: 7

Enter an Integer, enter -1 to exit: 56
Value entered into index: 3

Enter an Integer, enter -1 to exit: 64
Value entered into index: 10

Enter an Integer, enter -1 to exit: 32
Value entered into index: 6

Enter an Integer, enter -1 to exit: -1

Enter a Value, enter -1 to exit: 5
Value found at index: 5

Enter a Value, enter -1 to exit: 32
Value found at index: 6

Enter a Value, enter -1 to exit: 30
Value not found.

Enter a Value, enter -1 to exit: -1
*/