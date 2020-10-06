#include <iostream>
#include <list>  
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) 
    {
        m_capacity = capacity;
    }

    int get(int key) {
        int retValue = -1;

        list<pair<int, int>>::iterator it = findkey(key);

        //�����Cashe�У�����¼�ƶ����������ǰ��  
        if (it != caches.end())
        {
            retValue = it->second;
            //�ƶ�����ǰ��  
            list<pair<int, int>> ::iterator ptrPair = it;
            pair<int, int> tmpPair = *ptrPair;
            caches.erase(ptrPair);
            caches.push_front(tmpPair);
        }
        return retValue;
    }

    void set(int key, int value) 
    {
        list<pair<int, int>>::iterator it=findkey(key);

        if (it!=caches.end()) //�Ѿ���������  
        {
            caches.erase(it);
            pair<int, int > tmpPair = make_pair(key, value);
            caches.push_front(tmpPair);
        }
        else //����������  
        {
            pair<int, int > tmpPair = make_pair(key, value);


            if (m_capacity == caches.size()) //�Ѿ���  
            {
                caches.pop_back(); //ɾ�����һ��  
                                 
                cout << "����" << endl;
            }

            caches.push_front(tmpPair);
        }
    }

    //Ѱ���Ƿ����key
    list<pair<int, int> >::iterator findkey(int key)
    {
        for (list<pair<int, int> >::iterator it = caches.begin(); it != caches.end(); ++it)
        {
            if ((*it).first == key)
            {
                return it;
            }
        }
        return caches.end();
    }


private:
    int m_capacity;           //cashe�Ĵ�С  
    list<pair<int, int>> caches;    //��һ��˫����洢cashe������  
};


int main(int argc, char **argv)
{
    LRUCache s(2);
    s.set(1, 1);
    s.set(2, 3);
    cout << s.get(2) << endl;
    s.set(4, 1);
    s.set(5, 2);
    cout << s.get(5) << endl;
    cout << s.get(4) << endl;
    getchar();
    return 0;
}