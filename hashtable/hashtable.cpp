#include <iostream>
#include <string>

using namespace std;

class BaseObject
{
public:
    long key;
    string value;

    BaseObject() : key(-1), value("") {}
    ~BaseObject() {}
    BaseObject(long key, string value) : key(key), value(value) {}
    BaseObject(const BaseObject& bo) : key(bo.key), value(bo.value) {}

    void Assign(long key, string value)
    {
        this->key = key;
        this->value = value;
    }

    void Reset()
    {
        key = -1;
        value = "";
    }
};

class HashTable
{
    BaseObject* arr;
    long size;

    int GenIndex(long key, long size, int counter = 0)
    {
        int index = (key + counter) % size;
        if (arr[index].key != -1)
            return GenIndex(key, size, counter + 1);
        return index;
    }

public:
    HashTable(int size) : size(size)
    {
        arr = new BaseObject[size];
    }

    ~HashTable()
    {
        delete[] arr;
    }

    void AddItem(long key, string value)
    {  
        arr[GenIndex(key, size)].Assign(key, value);
    }

    void Print(int counter)
    {
        if(counter > 0)
            cout << "\n";
        for (int i = 0; i < size; i++)
        {
            if (arr[i].key != -1)
            {
                cout << i << " " << arr[i].key << " " << arr[i].value;
                cout << "\n";
            } 
        } 
    }

    void Reassign()
    {
        for (int i = 0; i < size; i++)
        {
            BaseObject temp = arr[i];
            arr[i].Reset();
            AddItem(temp.key, temp.value);
        }
    }

    void Delete(long key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].key == key)
            {
                arr[i].Reset();
                break;
            }
        }
    }
};

int main()
{
    int s1 = 0, s2 = 0, counter = 0, tPlaces = 0, size = 0;
    string command = "", a1 = "", a2 = "", line = "";
    HashTable* ht = NULL;

    while (getline(cin, line))
    {
        s1 = 0, s2 = 0, command = "", a1 = "", a2 = "";

        if (line == "stop") {
            continue;
        }
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                if (s1 != 0) s2 = i;
                else s1 = i;
            }
        }
        if (s1 != 0) {
            command = line.substr(0, s1);
            a1 = line.substr(s1 + 1, s2 - s1 - 1);
        }
        else command = line;
        if (command == "size") {
            ht = new HashTable(stol(a1));
            size = stol(a1);
        }
        if (command == "add") {
            if (tPlaces == size) continue;
            a2 = line.substr(s2 + 1);
            ht->AddItem(stol(a1), a2);
            tPlaces++;
        } 
        if (command == "delete") {
            ht->Delete(stoi(a1));
            ht->Reassign();
            tPlaces--;
        }
        if (command == "print") {
            ht->Print(counter);
            counter++;
        }
    }
    delete ht;

    return 0;
}