#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    //creation
    unordered_map<string,int> m;

    //insertion

    //1st way
    pair<string,int> p = make_pair("babbar", 3);
    m.insert(p);

    //2nd way
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    //3
    m["mera"] = 1;  //yaha pe (mera,1) bnega pair

    m["mera"] = 2;  //yaha pe wo (mera, 2) ho jyga means update ho jyga 

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    //cout<<m.at("unknown")<<endl;  //isse krne pe error aayga 
    cout<<m["unknown"]<<endl;   //isse krne pe ek entry bn jyge 0 ke corresponding

    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("drwo")<<endl;
    cout<<m.count("love")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    //traverse map
    for(auto i:m)
    {
        cout<<i.first << " " << i.second << endl;
    }

    //traverse using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    //unordered map me cheeze kisi order me nhi print hote 
    //or map me jis order me daaloge usme hi hogi
    

    while(it != m.end())
    {
        cout<<it->first << " " << it->second << endl;
        it++;
    }

    return 0;



}
