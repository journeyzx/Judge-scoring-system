#include <iostream>
#include <vector>
#include <deque>
#include<algorithm>

using namespace std;

//选手类
class Person
{
public:
    Person(string name,int score){

        this->m_name = name;
        this->m_score = score;
    }



    string m_name;
    int m_score;
};


void createPerson(vector<Person>&a)
{
    string nameseed = "ABCDE";
    for(int i = 0;i<5;i++){
        string name = "选手";
        name+=nameseed[i];

        int score  = 0;
        Person p (name,score);
        a.push_back(p);

    }

}
void setScore(vector<Person>&a)
{
    for(vector<Person>::iterator it = a.begin();it<a.end();it++){
        //将评委的分数放入到deque容器
        deque<int>d;
        for(int i = 0;i<10;i ++){
            int score = rand()%41+60;//60-100随机数
            d.push_back(score);

        }
        sort(d.begin(),d.end());
        //去除最高分和最低分
        d.pop_back();
        d.pop_front();
        //显示打分
        for(deque<int>::iterator dit = d.begin();dit!=d.end();dit++){
            cout<<"姓名"<<"    "<<it->m_name<<"    "<<"得分"<<"    "<<*dit<<endl;


        }
        //取平均分
        int sum = 0;
        for(deque<int>::iterator dit = d.begin();dit!=d.end();dit++){
            sum+=*dit;


        }

        int average  = sum/d.size();
//        cout<<average<<endl;
        it->m_score = average;



    }

}
void showScore(vector<Person>&a)
{
    for(vector<Person>::iterator it = a.begin();it!=a.end();it++){
        cout<<"姓名"<<"    "<<it->m_name<<"    "<<"平均分数"<<"    "<<it->m_score<<endl;
    }

}
int main() {
    //随机数种子
    srand((unsigned int)time(NULL));
    //1.创建5名选手
    vector<Person>v;//存放选手容器
    createPerson(v);
    //测试
//    for(vector<Person>::iterator it = v.begin();it<v.end();it++ ){
//
//        cout<<""<<it->m_name<<"    "<<"分数"<<it->m_score<<"\n"<<endl;
//    }





    //2.给5名选手打分
    setScore(v);



    //3.显示最后得分
    showScore(v);




    return 0;
}
