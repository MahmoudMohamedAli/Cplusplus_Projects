#include <bits/stdc++.h>

int main()
{
    std::fstream file1("../file1.txt", std::ios::in);
    std::fstream file2("../file2.txt", std::ios::in);
        
    std::ofstream file3("../file3.txt", std::ios::out);
    std::string line1, line2;
    int lines = 0;
     //cascading
    while (getline(file1, line1))
    {
        /* code */
       // std::cout << line1 << std::endl;
        file3 << line1 << std::endl;
    }
    file3 << " ========================================================== "<<std::endl;
    while (getline(file2, line2))
    {
        /* code */
      //  std::cout << line2 << std::endl;
        file3 << line2 << std::endl;
    }
    
    file1.clear();
    file1.seekg(0);//Move to start for reading
    file2.clear();
    file2.seekg(0);
    if(file1.good() && file2.good())
    {
        std::cout << "files are good" << std::endl;
    }
    else
    {
        std::cout << "files are not good" << std::endl;
    }
 file3 << " ========================================================== "<<std::endl;
    //concatenate files
    while (getline(file1, line1) && getline(file2, line2))
    {
        /* code */
       // std::cout << line1 << std::endl;
        file3 << line1 << " " << line2 << std::endl;
        lines++;
    }
    // if(!file1.eof())
    // {
       
    //    std::cout << "file1 is not empty" << std::endl;
    //    file3 <<line1 << std::endl;
    //    while(getline(file1, line1))
    //    {
    //        file3 <<line1 << std::endl;
    //    }
    // }
    //  if(!file2.eof())
    // {
    //     std::cout << "file2 is not empty" << std::endl;
    //     file3 <<line2 << std::endl;
    //     while(getline(file1, line1))
    //    {
    //        file3 <<line1 << std::endl;
    //    }
    // }
    
    file1.close();
    file2.close();
    file3.close();  
  
    return 0;
}