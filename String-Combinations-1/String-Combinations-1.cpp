// Given a string "abc", print all the possible combinations. Note that in combinations, ordering is immaterial ie. ab = ba. a ab ac abc b bc c

// Input Format
//      abc

// Constraints

// All characters in the string are unique.
// Output Format

//      a ab abc ac b bc c

// For the purposes of this challenge, just sort the output.
// Also sort the characters in every line; ie. instead of ba, output ab. Instead of bac, output abc.


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> output;

int genSeq(string input)
{
    if (input.empty())
    {
        output.push_back("");
        return 1;
    }
    string subString = input.substr(1);
    int subStringSize = genSeq(subString);
    for (int i=0; i<subStringSize; i++)
    {
        output.push_back(input[0]+output[i]);
    }
    return 2*subStringSize;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    cin>>s;
    int count = genSeq(s);
    for (int k=0; k<count; k++)
        sort(output[k].begin(), output[k].end());
    sort(output.begin(),output.end());
    for (int j=0; j<count; j++)
    {
        if(output[j] != "")
            cout<<output[j]<<endl;
    }
    return 0;
}