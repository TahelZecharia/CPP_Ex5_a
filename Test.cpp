#include "doctest.h"

#include "OrgChart.hpp"
using namespace ariel;

#include <stdexcept>
#include <exception>
using namespace std;

TEST_CASE("OrgChart"){
    
    OrgChart organization;
    CHECK_NOTHROW(OrgChart organization);
    CHECK_NOTHROW(organization.add_root("1"));
    
    CHECK_NOTHROW(organization.add_sub("1", "2"));
    CHECK_NOTHROW(organization.add_sub("1", "3"));
    CHECK_NOTHROW(organization.add_sub("1", "3"));
    CHECK_NOTHROW(organization.add_sub("1", "5"));
    CHECK_NOTHROW(organization.add_sub("1", "6"));
    CHECK_NOTHROW(organization.add_sub("1", "7"));
    CHECK_NOTHROW(organization.add_sub("1", "8"));

    CHECK_NOTHROW(organization.add_sub("2", "9"));
    CHECK_NOTHROW(organization.add_sub("2", "10"));
    CHECK_NOTHROW(organization.add_sub("2", "11"));

    CHECK_NOTHROW(organization.add_sub("3", "12"));
    CHECK_NOTHROW(organization.add_sub("3", "13"));
    CHECK_NOTHROW(organization.add_sub("3", "14"));
    CHECK_NOTHROW(organization.add_sub("3", "15"));
   
    vector<string> levelOrder = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
    vector<string> reverseOrder = {"9", "10", "11", "12", "13", "14", "15", "2", "3", "4", "5", "6", "7", "8", "1"};
    vector<string> preorder = {"1", "2", "9", "10", "11", "3", "12", "13", "14", "15", "4", "5", "6", "7", "8"};
    
    SUBCASE("levelOrder"){
        
        size_t i = 0;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){

            CHECK((*it) == levelOrder.at(i++));
            cout << (*it) << " " ;
        } // prints: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 

        cout << endl;
    }

    SUBCASE("reverseOrder"){
        
        size_t i = 0;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){

            CHECK((*it) == reverseOrder.at(i++));
            cout << (*it) << " " ;
        } // prints: 9 10 11 12 13 14 15 2 3 4 5 6 7 8 1

        cout << endl;
    }

    SUBCASE("preorder"){
        
        size_t i = 0;
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it){

            CHECK((*it) == preorder.at(i++));
            cout << (*it) << " " ;
            cout << (preorder.at(i++)) << " " ;
        } // prints: prints: 1 2 9 10 11 3 12 13 14 15 4 5 6 7 8  

        cout << endl;
    }
}