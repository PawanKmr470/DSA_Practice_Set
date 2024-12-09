#include <iostream>
#include <string>
using namespace std;

int main() {

   // Default ctor
   string s;
   cout << "s size : " << s.size() << endl;

   // C-style string
   string str1{"Hello"};
   cout << "1. " << str1 << endl;

   // c_str() returns const char *pChar = str.c_str()
   cout << "2. " << str1.c_str() << endl;

   // Initializer list
   string substr1(3, 'x');
   cout << "3. " << substr1 << endl;

   // String arithmatic
   str1 += 'y';
   cout << "4. " << str1 << endl;

   // String assignment
   string str2 = str1;
   cout << "5. " << str2 << endl;

   // String comparision
   cout << "6. " << (str1 == str2) << endl;

   // Re-assigment & substrings. Last char is excluded i.e. [) format
   str1 = "Hello World";
   cout << "7. " << str1.substr(6) << endl;
   cout << "8. " << str1.substr(0,2) << endl;
   cout << "9. " << str1.substr(0,100) << endl;

   str1[0] = 'h';
   str1[6] = 'w';
   cout << "10. " << str1 << endl;

   // Initialize string variable from substring
   string str3(str1, 6);
   cout << "11. " << str3 << endl;
   string str4(str1, 0, 5);
   cout << "12. " << str4 << endl;

   // Find resturns first occurance of the character. Case sensitive.
   size_t pos = str1.find('o');
   cout << "13. " << pos << endl;
   pos = str1.find("or");
   cout << "14. " << pos << endl;
   pos = str1.find('O');
   cout << "15. " << pos << endl;
   cout << "16. " << string::npos << endl;
   if (pos != string::npos) {
      cout << "Found character." << endl;
   }
   else {
      cout << "Didn't find character." << endl;
   }

   // rfind
   pos = str1.rfind('o');
   cout << "17. " << pos << endl;

   // rfind searches character starting from the end OR
   // starting from the given index to left. Index is INCLUDED.
   str1 = "Hollo World";
   pos = str1.rfind('o', 6);
   cout << "18. " << pos << endl;

   // Find any of the character in the given string in source string.
   // find_first_of
   // find_last_of
   // find_first_not_of
   // find_last_not_of
   pos = str1.find_first_of("aeiou");
   cout << "19. " << pos << endl;

   // Append
   string str5{"First"};
   str5.append(" Word");
   cout << "20. " << str5 << endl;
   str5 += " Printed";
   cout << "20. " << str5 << endl;

   // Insert(pos, substr)
   // Insert(pos, substr, substr_start, substr_end)
   // Insert(pos, count, char)
   string str6{"for"};
   str6.insert(2, "lde");
   cout << "21. " << str6 << endl;

   string str7{"care"};
   string str8{"omp"};
   cout << "22. " << str7.insert(1, str8) << endl;

   // stirng can take iterator e.g. begin(), end()
   string str9{"word"};
   auto pos_itr = end(str9) - 1;
   str9.insert(pos_itr, 'l');       // str9.insert(pos_itr, 2, 'l'); // "worlld"
   cout << "23. " << str9 << endl;

   // Iterator Invalidation
   // Now causing string's memory buffer to reallocate due to increase in 
   // buffer size. Old data is copied to the new and old is deleted.
   // Once this allocation happens old iterators become invalid.
   string strA{"orld"};
   auto first = begin(strA);
   strA.insert(end(strA), 20, 'd');
   first = begin(strA);                // FIX
   strA.insert(first, 'w');            // segmentation fault. To fix, get first itr here
   cout << "24. " << strA << endl;

   // Erase(pos, num_of_chars)
   string strB{"Hello World"};
   strB.erase(5, 1);
   cout << "25. " << strB << endl;
   // Used with iterators
   strB.erase(begin(strB));
   cout << "26. " << strB << endl;
   strB = "Hello World";
   // Iterator range
   strB.erase(begin(strB)+1, end(strB)-1);
   cout << "27. " << strB << endl;

   // Replace(start_pos, num_of_char, "chars_to_be_replaced")
   string strC{"Say Hello"};
   strC.replace(4, 1, "h");
   cout << "28. " << strC << endl;
   strC.replace(4, 2, "h");            // also works
   cout << "29. " << strC << endl;
   strC.replace(4, 1, "hhhhhh");            // also works
   cout << "30. " << strC << endl;

   // Used with range
   string strD{"Say Goodbye"};
   strD.replace(begin(strD)+8, begin(strD)+3, "day");
   cout << "31. " << strD << endl;

   // Assign("new string") // Replaces all chars with new string
   string strE{"Hello"};
   strE.assign("Hola!");
   cout << "32. " << strE << endl;

   // C-style string to int : atoi()   // Risky, if errors then returns 0
   //    It expects char array not string class input (bcz inherited from C).
   // C++      string to int : stoi()
   // C++      int to string : to_string()
   char arr[] = "456";
   int x = atoi(arr);
   cout << "33. " << x + 1 << endl;

   // char *arr1 = "456";
   // int y = atoi(arr1);
   // cout << "34. " << y + 1 << endl;

   int z = stoi("456");
   cout << "35. " << z + 1 << endl;
   
   string strF{"Hello "};
   strF += to_string(3.14);
   cout << "36. " << strF << endl;

   // Swap(str1, str2)  // non-member method, slow operation as it copies data
   // str1.swap(str2)   // member method, fast operation as it swaps pointers
                        // so no memory operations and no data copy
   string strG{"hey"};
   string strH{"you"};
   strG.swap(strH);
   cout << "37. " << strG << " " << strH << endl;
   swap(strG, strH);
   cout << "38. " << strG << " " << strH << endl;

}