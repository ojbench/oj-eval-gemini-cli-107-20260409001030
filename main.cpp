#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        int data;
        NODE* next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = nullptr;
        len = 0;
    }
    NODE* move(int i) {
        if (i < 0 || i >= len) return nullptr;
        NODE* p = head;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        return p;
    }
    void insert(int i, int x) {
        NODE* new_node = new NODE;
        new_node->data = x;
        if (len == 0) {
            head = new_node;
            new_node->next = head;
        } else {
            if (i == 0) {
                NODE* tail = move(len - 1);
                new_node->next = head;
                head = new_node;
                tail->next = head;
            } else {
                NODE* prev = move(i - 1);
                new_node->next = prev->next;
                prev->next = new_node;
            }
        }
        len++;
    }
    void remove(int i) {
        if (i < 0 || i >= len) return;
        if (len == 1) {
            delete head;
            head = nullptr;
        } else {
            if (i == 0) {
                NODE* tail = move(len - 1);
                NODE* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            } else {
                NODE* prev = move(i - 1);
                NODE* temp = prev->next;
                prev->next = temp->next;
                delete temp;
            }
        }
        len--;
    }
    void remove_insert(int i) {
        if (i < 0 || i >= len) return;
        if (i == len - 1) return;
        
        NODE* target = nullptr;
        if (len == 1) {
            return;
        } else {
            if (i == 0) {
                NODE* tail = move(len - 1);
                target = head;
                head = head->next;
                tail->next = head;
            } else {
                NODE* prev = move(i - 1);
                target = prev->next;
                prev->next = target->next;
            }
        }
        NODE* tail = move(len - 2);
        tail->next = target;
        target->next = head;
    }
    void get_length() {
        cout << len << "\n";
    }
    void query(int i) {
        if (i < 0 || i >= len) {
            cout << -1 << "\n";
        } else {
            NODE* p = move(i);
            cout << p->data << "\n";
        }
    }
    void get_max() {
        if (len == 0) {
            cout << -1 << "\n";
        } else {
            int max_val = head->data;
            NODE* p = head->next;
            for (int j = 1; j < len; ++j) {
                if (p->data > max_val) {
                    max_val = p->data;
                }
                p = p->next;
            }
            cout << max_val << "\n";
        }
    }
    void clear() {
        if (len == 0) return;
        NODE* p = head;
        for (int j = 0; j < len; ++j) {
            NODE* temp = p;
            p = p->next;
            delete temp;
        }
        head = nullptr;
        len = 0;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}
