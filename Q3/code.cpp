#include <iostream>
#include <map>
#include <ctime>
#include <unordered_map>

using namespace std;

int INPUTARRAY [] = {10,100,1000,10000,100000,150000,500000,700000};
typedef unordered_multimap<int, int>::iterator umit;

// return a random number between 1 and 500
int generateRandomNum () {
  
  int ret = rand() % 500 + 1;
  return ret;
}

// print out the unordered_multimap
void printUmm(unordered_multimap<int, int> umm)
{
    // begin() returns iterator to first element of map
    umit it = umm.begin();
 
    for (; it != umm.end(); it++)
        cout << "<" << it->first << ", " << it->second
             << ">  ";
 
    cout << endl;
}

int main() {
    multimap<int,int> gquiz1;
    unordered_multimap<int,int> unorder;
    //gquiz1.insert(pair <int, int> (1, 40));
    //unorder.insert(pair <int, int> (1, 40));
    
    for (int *i = INPUTARRAY; i != INPUTARRAY+sizeof(INPUTARRAY)/4; i ++){
        cout << endl << "input size is: " << *i << endl;
        clock_t total_time_multimap = 0;
        clock_t total_time_unorder = 0;
        for (int j = 0; j < *i ; j ++){
            // generate a random number
            int x = generateRandomNum();
            
            // insert into multimap
            clock_t start_time_multimap = clock();
            gquiz1.insert(pair<int,int>(x,x));
            clock_t end_time_multimap = clock();
            // add time cost in multimap cost
            total_time_multimap = total_time_multimap + end_time_multimap - start_time_multimap;
            
            // insert into unordered_multimap
            clock_t start_time_unorder = clock();
            unorder.insert(pair<int,int>(x,x));
            clock_t end_time_unorder = clock();
            // add time cost in multimap cost
            total_time_unorder = total_time_unorder + end_time_unorder - start_time_unorder;
            
        }
        std::cout << "MultiMap  Time: "
          << ((double) total_time_multimap) / (double) CLOCKS_PER_SEC
          << " seconds" << std::endl; 

        std::cout << "Unordered Time: "
          << ((double) total_time_unorder) / (double) CLOCKS_PER_SEC
          << " seconds" << std::endl; 
    }



    /*
    // printing multimap gquiz1
    multimap <int, int> :: iterator itr;
    cout << "\nThe multimap gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
    {
        cout  <<  '\t' << itr->first
              <<  '\t' << itr->second << '\n';
    }
    cout << endl;
    */
    

    // printing unordered_multimap unorder
    //printUmm(unorder);

    // print input array
    /*
    cout << "INPUT SIZE" << endl;
    for (int *i = INPUTARRAY;i!=INPUTARRAY+3;i++){
        cout << *i << endl;
    }
    cout << endl;
    */
    
}
