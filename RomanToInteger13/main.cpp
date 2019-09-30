//
//  main.cpp
//  RomanToInteger13
//
//  Created by Aj Gill on 9/29/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
    map<char,int> hashmap;
    hashmap.insert(make_pair('I',1));
    hashmap.insert(make_pair('V',5));
    hashmap.insert(make_pair('X',10));
    hashmap.insert(make_pair('L',50));
    hashmap.insert(make_pair('C',100));
    hashmap.insert(make_pair('D',500));
    hashmap.insert(make_pair('M',1000));
    int stringValue = 0;
    
    for(int i=0; i<s.size();i++){
        map<char,int>::iterator it;
        //It's a 4
        if(s[i] == 'I' && s[i+1] == 'V'){
            it = hashmap.find(s[i]);
            stringValue -= it->second;
        }
        //It's 40
        else if(s[i] == 'X' && s[i+1] == 'L'){
            it = hashmap.find(s[i]);
            stringValue -= it->second;
        }
        //It's 400
        else if(s[i] == 'C' && s[i+1] == 'D'){
            it = hashmap.find(s[i]);
            stringValue -= it->second;
        }
        //It's a 9
        else if(s[i] == 'I' && s[i+1] == 'X'){
            it = hashmap.find(s[i]);
            stringValue -= it->second;
        }
        //It's 90
        else if(s[i] == 'X' && s[i+1] == 'C'){
            it = hashmap.find(s[i]);
            stringValue -= it->second;
        }
        //It's 900
        else if(s[i] == 'C' && s[i+1] == 'M'){
            it = hashmap.find(s[i]);
            stringValue -= it->second;
        }
        //Otherwise
        else {
            it = hashmap.find(s[i]);
            stringValue += it->second;
        }
    }
    return stringValue;
}

int main() {
    string input = "MCMXCIV";
    cout << "The numerical equivalent of this string of Roman integers is " << romanToInt(input) << "\n";
}
