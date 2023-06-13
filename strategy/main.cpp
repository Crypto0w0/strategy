#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct comp{
    inline bool operator()(const string& f, const string& s) const{
        return f.size() < s.size();
    }
};

class SortStrategy{
public:
    virtual void Sort(vector<string>& v) = 0;
};

class STLSort : public SortStrategy{
public:
    void Sort(vector<string>& v) override{
        sort(v.begin(), v.end());
    }
};

class ShellSort : public SortStrategy{
public:
    void Sort(vector<string>& v) override{
        long step = v.size() / 2;
        while (step > 0){
            for (int i = 0; i < (v.size() - step); i++) {
                int j = i; while (j >= 0 && v[j] > v[j+ step]){
                    string temp = v[j];
                    v[j] = v[j+ step];
                    v[j+ step] = temp;
                    j--;
                }
            } step = step / 2;
        }
    }
};

class BubbleSort : public SortStrategy {
public:
    void Sort(vector<string>& v) override {
        for (long k = v.size() - 1; k> 0; k--){
            for (int i = 0; i < k; i++) {
                if (v[i] > v[i+1]){
                    string buf = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = buf;
                }
            }
        }
    }
};

class ShortToLongSort : public SortStrategy {
public:
    void Sort(vector<string>& v) override {
        comp c;
        sort(v.begin(), v.end(), c);
    }
};

class LongToShortSort : public SortStrategy {
public:
    void Sort(vector<string>& v) override {
        comp c;
        sort(v.begin(), v.end(), c);
        reverse(v.begin(), v.end());
    }
};


class SortedArray{
    vector<string> vector;
    SortStrategy* sortstrategy;
public:
    void SetSortStrategy (SortStrategy* sortstrategy){
        this->sortstrategy = sortstrategy;
    }
    void Add(string name){
        vector.push_back(name);
    }
    void Sort(){
        sortstrategy->Sort (vector);
        for (string name: vector){
            cout << " " + name << endl;
            cout << endl;
        }
    }
};

int main(){
    SortedArray ar;
    
    ar.Add("Strategy");
    ar.Add("Observer");
    ar.Add("Iterator");
    ar.Add("Mediator");
    /*
    ShellSort shell;
    ar.SetSortStrategy(&shell);
    ar.Sort();
    */
    ar.Add("Memento");
    ar.Add("Interpreter");
    /*
    STLSort stl;
    ar.SetSortStrategy(&stl);
    ar.Sort();
    */
    
    ar.Add("State");
    ar.Add("Command");
    
    BubbleSort bubble;
    ar.SetSortStrategy (&bubble);
    ar.Sort();
    
    ShortToLongSort stls;
    ar.SetSortStrategy(&stls);
    ar.Sort();
    
    LongToShortSort ltss;
    ar.SetSortStrategy(&ltss);
    ar.Sort();
}
